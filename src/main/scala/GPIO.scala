// (c) 2024 Rocksavage Technology, Inc.
// This code is licensed under the Apache Software License 2.0 (see LICENSE.MD)
package tech.rocksavage.chiselware.GPIO

import java.io.File
import java.io.PrintWriter

import _root_.circt.stage.ChiselStage
import chisel3._
import chisel3.util._

class GPIO(p: BaseParams) extends Module {
  val io = IO(new Bundle {
    val apb = new ApbInterface(p)
    val pins = new Bundle {
      val gpioInput = Input(UInt(p.dataWidth.W))
      val gpioOutput = Output(UInt(p.dataWidth.W))
      val gpioOutputEnable = Output(UInt(p.dataWidth.W))
      val irqOutput = Output(UInt(1.W))
    }
  })

  val regs = new GPIORegs(p)
  // Intermediary Signals/Registers
  val gpioOutputVec = Wire(Vec(p.dataWidth, UInt(1.W)))
  val gpioOutputEnableVec = Wire(Vec(p.dataWidth, UInt(1.W)))
  val gpioInputSyncPrev = RegInit(0.U(p.dataWidth.W))
  // Synchronize GPIO Input
  val gpioInputSync = RegNext(RegNext(io.pins.gpioInput))

  // Main loop for assigning virtual ports to physical pins
  for (i <- 0 until p.dataWidth) when(regs.virtualPortEnable === 1.U) {
    for (v <- (p.numVirtualPorts - 1) to 0 by -1)
      when(regs.virtualToPhysicalMap(v) === i.U) {
        // Sync direction with the physical pin direction
        when(regs.DIRECTION(i) === 1.U) { // Output mode
          when(regs.virtualPortOutput(v) === 1.U) {
            regs.OUTPUT := regs.OUTPUT | (1.U << i.U)
          }.otherwise(regs.OUTPUT := regs.OUTPUT & ~(1.U << i.U))
        }.otherwise { // Input mode
          when(regs.INPUT(i) === 1.U) {
            regs.virtualPortOutput := regs.virtualPortOutput | (1.U << v)
          }.otherwise {
            regs.virtualPortOutput := regs.virtualPortOutput & ~(1.U << v)
          }
        }
      }
  }
  // APB
  io.apb.PRDATA := 0.U // Needs to be initialized
  when(io.apb.PSEL && io.apb.PENABLE) {
    when(io.apb.PWRITE) { // Write Operation
      registerDecodeWrite(io.apb.PADDR)
      io.apb.PREADY := true.B
    }.otherwise { // Read Operation
      registerDecodeRead(io.apb.PADDR)
      io.apb.PREADY := true.B
    }
  }.otherwise(io.apb.PREADY := false.B)

  // Interrupt Handling
  for (i <- 0 until p.dataWidth) {
    val condition = Cat(regs.TRIGGER_TYPE(i), regs.TRIGGER_LVL0(i), regs.TRIGGER_LVL1(i))
    regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (0.U << i.U) // Default Conditions
    io.pins.irqOutput := 0.U
    gpioInputSyncPrev := gpioInputSync // Edge Detection
    switch(condition) {
      is("b001".U) { // Level Trigger when High
        when(gpioInputSync(i) === 1.U) {
          regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
        }
      }
      is("b010".U) { // Level Trigger when Low
        when(gpioInputSync(i) === 0.U) {
          regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
        }
      }
      is("b011".U) { // Level Trigger when High or Low
        regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
      }
      is("b101".U) { // Edge Trigger on Rising Edge
        when(gpioInputSync(i) === 1.U && gpioInputSyncPrev(i) === 0.U) {
          regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
        }
      }
      is("b110".U) { // Edge Trigger on Falling Edge
        when(gpioInputSync(i) === 0.U && gpioInputSyncPrev(i) === 1.U) {
          regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
        }
      }
      is("b111".U) { // Edge Trigger on Rising or Falling Edge
        when(gpioInputSync(i) =/= gpioInputSyncPrev(i)) {
          regs.TRIGGER_STATUS := regs.TRIGGER_STATUS | (1.U << i.U)
        }
      }
    }
    when((regs.TRIGGER_STATUS(i) & regs.IRQ_ENABLE(i)) === 1.U) {
      io.pins.irqOutput := 1.U
    }
  }

  // ATOMIC
  val atomicOperationTruthTable = Wire(Vec(2, Vec(2, UInt(1.W))))
  atomicOperationTruthTable(0)(0) := regs.ATOMIC_OPERATION(1)
  atomicOperationTruthTable(0)(1) := regs.ATOMIC_OPERATION(0)
  atomicOperationTruthTable(1)(0) := regs.ATOMIC_OPERATION(3)
  atomicOperationTruthTable(1)(1) := regs.ATOMIC_OPERATION(2)
  when(regs.ATOMIC_SET === 1.U) {
    // truth table for atomic set from atomic operation
    // p3_p2_p1_p0 ->
    //
    //         Out
    //         0  1
    //  Mask 0 p1 p0
    //       1 p3 p2
    val output_inner = Wire(Vec(p.dataWidth, UInt(1.W)))
    for (i <- 0 until p.dataWidth)
      output_inner(i) :=
        atomicOperationTruthTable(regs.ATOMIC_MASK(i))(regs.OUTPUT(i))

    regs.OUTPUT := Reverse(Cat(output_inner))
  }

  // MODE
  for (i <- 0 until p.dataWidth)
    when(regs.MODE(i) === 1.U) { // AND each bit of DIRECTION to mask bits that are not set as OUTPUT in gpioOutput
      gpioOutputVec(p.dataWidth - i - 1) := regs.OUTPUT(i) & regs.DIRECTION(i)
      gpioOutputEnableVec(p.dataWidth - i - 1) := regs.DIRECTION(i)
    }.otherwise {
      gpioOutputVec(p.dataWidth - i - 1) := 0.U
      gpioOutputEnableVec(p.dataWidth - i - 1) := ~regs.OUTPUT(i) &
        regs.DIRECTION(i)
    }

  regs.INPUT := gpioInputSync
  io.pins.gpioOutput := Cat(gpioOutputVec)
  io.pins.gpioOutputEnable := Cat(gpioOutputEnableVec)

  // Handle invalid address case
  when(
    (io.apb.PADDR < regs.DIRECTION_ADDR.U) ||
      (io.apb.PADDR > regs.VIRTUAL_PORT_ENABLE_ADDR_MAX.U)
  ) {
    io.apb.PSLVERR := true.B // Set error signal
  }.otherwise {
    io.apb.PSLVERR := false.B // Clear error signal if valid
  }

  // Collect code coverage points
  if (p.coverage) {
    // count clock ticks to allow for coverage computation
    val tick = true.B

    for (bit <- 0 to p.dataWidth - 1) {
      cover(io.pins.gpioInput(bit)).suggestName(s"io_gpioInput_$bit")
      cover(io.pins.gpioOutput(bit)).suggestName(s"io_gpioOutput_$bit")
      cover(io.pins.gpioOutputEnable(bit))
        .suggestName(s"io_gpioOutputEnable_$bit")
    }

    for (bit <- 0 to p.PDATA_WIDTH - 1) {
      cover(io.apb.PRDATA(bit)).suggestName(s"apb_PRDATA_$bit")
      cover(io.apb.PWDATA(bit)).suggestName(s"apb_PWDATA_$bit")
    }

    for (bit <- 0 to p.PADDR_WIDTH - 1)
      cover(io.apb.PADDR(bit))
        .suggestName(s"apb_ADDR_$bit")

    cover(tick).suggestName("tick")
    cover(io.apb.PSEL).suggestName("io__PSEL")
    cover(io.apb.PENABLE).suggestName("io__PENABLE")
    cover(io.apb.PWRITE).suggestName("io__PWRITE")
    cover(io.apb.PREADY).suggestName("io__PREADY")
    cover(io.apb.PSLVERR).suggestName("io__PSLVERR")
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeWrite(addr: UInt): Unit = {

    when(addr >= regs.DIRECTION_ADDR.U && addr <= regs.DIRECTION_ADDR_MAX.U) {
      printf(
        "Writing DIRECTION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.DIRECTION := io.apb.PWDATA(regs.DIRECTION_SIZE - 1, 0)
    }
    when(addr >= regs.INPUT_ADDR.U && addr <= regs.INPUT_ADDR_MAX.U) {
      printf(
        "Writing INPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.INPUT := io.apb.PWDATA(regs.INPUT_SIZE - 1, 0)
    }
    when(addr >= regs.OUTPUT_ADDR.U && addr <= regs.OUTPUT_ADDR_MAX.U) {
      printf(
        "Writing OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.OUTPUT := io.apb.PWDATA(regs.OUTPUT_SIZE - 1, 0)
    }
    when(addr >= regs.MODE_ADDR.U && addr <= regs.MODE_ADDR_MAX.U) {
      printf("Writing MODE Register, data: %x, addr: %x\n", io.apb.PWDATA, addr)
      regs.MODE := io.apb.PWDATA(regs.MODE_SIZE - 1, 0)
    }
    when(
      addr >= regs.ATOMIC_OPERATION_ADDR.U && addr <= regs.ATOMIC_OPERATION_ADDR_MAX.U
    ) {
      printf(
        "Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.ATOMIC_OPERATION := io.apb.PWDATA(regs.ATOMIC_OPERATION_SIZE - 1, 0)
    }
    when(
      addr >= regs.ATOMIC_MASK_ADDR.U && addr <= regs.ATOMIC_MASK_ADDR_MAX.U
    ) {
      printf(
        "Writing ATOMIC_MASK Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.ATOMIC_MASK := io.apb.PWDATA(regs.ATOMIC_MASK_SIZE - 1, 0)
    }
    when(addr >= regs.ATOMIC_SET_ADDR.U && addr <= regs.ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_SET Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.ATOMIC_SET := io.apb.PWDATA(regs.ATOMIC_SET_SIZE - 1, 0)
    }
    when(
      addr >= regs.VIRTUAL_PORT_MAP_ADDR.U && addr <= regs.VIRTUAL_PORT_MAP_ADDR_MAX.U
    ) {
      printf(
        "Writing VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      // index into virtualToPhysicalMap based on address
      val index =
        (addr - regs.VIRTUAL_PORT_MAP_ADDR.U) / regs.VIRTUAL_PORT_MAP_REG_SIZE.U
      regs.virtualToPhysicalMap(index) := io.apb.PWDATA(
        regs.VIRTUAL_PORT_MAP_SIZE - 1,
        0
      )
    }
    when(
      addr >= regs.VIRTUAL_PORT_OUTPUT_ADDR.U && addr <= regs.VIRTUAL_PORT_OUTPUT_ADDR_MAX.U
    ) {
      printf(
        "Writing VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.virtualPortOutput := io.apb.PWDATA(
        regs.VIRTUAL_PORT_OUTPUT_SIZE - 1,
        0
      )
    }
    when(
      addr >= regs.VIRTUAL_PORT_ENABLE_ADDR.U && addr <= regs.VIRTUAL_PORT_ENABLE_ADDR_MAX.U
    ) {
      printf(
        "Writing VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.virtualPortEnable := io.apb.PWDATA(
        regs.VIRTUAL_PORT_ENABLE_SIZE - 1,
        0
      )
    }
    when(addr >= regs.TRIGGER_TYPE_ADDR.U && addr <= regs.TRIGGER_TYPE_ADDR.U) {
      printf(
        "Writing TRIGGER_TYPE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.TRIGGER_TYPE := io.apb.PWDATA(regs.TRIGGER_TYPE_SIZE - 1, 0)
    }
    when(addr >= regs.TRIGGER_LVL0_ADDR.U && addr <= regs.TRIGGER_LVL0_ADDR.U) {
      printf(
        "Writing TRIGGER_LVL0 Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.TRIGGER_LVL0 := io.apb.PWDATA(regs.TRIGGER_LVL0_SIZE - 1, 0)
    }
    when(addr >= regs.TRIGGER_LVL1_ADDR.U && addr <= regs.TRIGGER_LVL1_ADDR.U) {
      printf(
        "Writing TRIGGER_LVL1 Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.TRIGGER_LVL1 := io.apb.PWDATA(regs.TRIGGER_LVL1_SIZE - 1, 0)
    }
    when(
      addr >= regs.TRIGGER_STATUS_ADDR.U && addr <= regs.TRIGGER_STATUS_ADDR.U
    ) {
      printf(
        "Writing TRIGGER_STATUS Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.TRIGGER_STATUS := regs.TRIGGER_STATUS & ~io.apb.PWDATA(
        regs.TRIGGER_STATUS_SIZE - 1,
        0
      ) // Writing a 1 will clear the status, ignore writes of 0
    }
    when(addr >= regs.IRQ_ENABLE_ADDR.U && addr <= regs.IRQ_ENABLE_ADDR.U) {
      printf(
        "Writing IRQ_ENABLE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      regs.IRQ_ENABLE := io.apb.PWDATA(regs.IRQ_ENABLE_SIZE - 1, 0)
    }
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeRead(addr: UInt): Unit = {
    printf("Reading Register, addr: %x\n", addr)
    when(addr >= regs.DIRECTION_ADDR.U && addr <= regs.DIRECTION_ADDR_MAX.U) {
      printf(
        "Reading DIRECTION Register, data: %x, addr: %x\n",
        regs.DIRECTION,
        addr
      )
      io.apb.PRDATA := regs.DIRECTION
    }
    when(addr >= regs.OUTPUT_ADDR.U && addr <= regs.OUTPUT_ADDR_MAX.U) {
      printf("Reading OUTPUT Register, data: %x, addr: %x\n", regs.OUTPUT, addr)
      io.apb.PRDATA := regs.OUTPUT
    }
    when(addr >= regs.INPUT_ADDR.U && addr <= regs.INPUT_ADDR_MAX.U) {
      printf("Reading INPUT Register, data: %x, addr: %x\n", regs.INPUT, addr)
      io.apb.PRDATA := regs.INPUT
    }
    when(addr >= regs.MODE_ADDR.U && addr <= regs.MODE_ADDR_MAX.U) {
      printf("Reading MODE Register, data: %x, addr: %x\n", regs.MODE, addr)
      io.apb.PRDATA := regs.MODE
    }
    when(
      addr >= regs.ATOMIC_OPERATION_ADDR.U && addr <= regs.ATOMIC_OPERATION_ADDR_MAX.U
    ) {
      printf(
        "Reading ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        regs.ATOMIC_OPERATION,
        addr
      )
      printf(
        "ATOMIC_OPERATION_MIN: %x\nATOMIC_OPERATION_MAX: %x\n",
        regs.ATOMIC_OPERATION_ADDR.U,
        regs.ATOMIC_OPERATION_ADDR_MAX.U
      )
      io.apb.PRDATA := regs.ATOMIC_OPERATION.asUInt
    }
    when(
      addr >= regs.ATOMIC_MASK_ADDR.U && addr <= regs.ATOMIC_MASK_ADDR_MAX.U
    ) {
      printf(
        "Reading ATOMIC_MASK Register, data: %x, addr: %x\n",
        regs.ATOMIC_MASK,
        addr
      )
      io.apb.PRDATA := regs.ATOMIC_MASK
    }
    when(addr >= regs.ATOMIC_SET_ADDR.U && addr <= regs.ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Reading ATOMIC_SET Register, data: %x, addr: %x\n",
        regs.ATOMIC_SET,
        addr
      )
      io.apb.PRDATA := regs.ATOMIC_SET
    }
    when(
      addr >= regs.VIRTUAL_PORT_MAP_ADDR.U && addr <= regs.VIRTUAL_PORT_MAP_ADDR_MAX.U
    ) {
      printf(
        "Reading VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",
        regs.virtualToPhysicalMap(
          (addr - regs.VIRTUAL_PORT_MAP_ADDR.U) / regs.VIRTUAL_PORT_MAP_REG_SIZE.U
        ),
        addr
      )
      io.apb.PRDATA := regs.virtualToPhysicalMap(
        (addr - regs.VIRTUAL_PORT_MAP_ADDR.U) / regs.VIRTUAL_PORT_MAP_REG_SIZE.U
      )
    }
    when(
      addr >= regs.VIRTUAL_PORT_OUTPUT_ADDR.U && addr <= regs.VIRTUAL_PORT_OUTPUT_ADDR_MAX.U
    ) {
      printf(
        "Reading VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",
        regs.virtualPortOutput,
        addr
      )
      io.apb.PRDATA := regs.virtualPortOutput
    }
    when(
      addr >= regs.VIRTUAL_PORT_ENABLE_ADDR.U && addr <= regs.VIRTUAL_PORT_ENABLE_ADDR_MAX.U
    ) {
      printf(
        "Reading VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",
        regs.virtualPortEnable,
        addr
      )
      io.apb.PRDATA := regs.virtualPortEnable
    }
    when(addr >= regs.TRIGGER_TYPE_ADDR.U && addr <= regs.TRIGGER_TYPE_ADDR.U) {
      printf(
        "READING TRIGGER_TYPE Register, data: %x, addr: %x\n",
        regs.TRIGGER_TYPE,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_TYPE
    }
    when(
      addr >= regs.TRIGGER_LVL0_ADDR.asUInt && addr <= regs.TRIGGER_LVL0_ADDR.U
    ) {
      printf(
        "READING TRIGGER_LVL0 Register, data: %x, addr: %x\n",
        regs.TRIGGER_LVL0,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_LVL0
    }
    when(addr >= regs.TRIGGER_LVL1_ADDR.U && addr <= regs.TRIGGER_LVL1_ADDR.U) {
      printf(
        "READING TRIGGER_LVL1 Register, data: %x, addr: %x\n",
        regs.TRIGGER_LVL1,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_LVL1
    }
    when(
      addr >= regs.TRIGGER_STATUS_ADDR.U && addr <= regs.TRIGGER_STATUS_ADDR.U
    ) {
      printf(
        "READING TRIGGER_STATUS Register, data: %x, addr: %x\n",
        regs.TRIGGER_STATUS,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_STATUS
    }
    when(addr >= regs.IRQ_ENABLE_ADDR.U && addr <= regs.IRQ_ENABLE_ADDR.U) {
      printf(
        "READING IRQ_ENABLE Register, data: %x, addr: %x\n",
        regs.IRQ_ENABLE,
        addr
      )
      io.apb.PRDATA := regs.IRQ_ENABLE
    }
  }

  def edgeFSM(): Unit = {}
}

class GPIORegs(p: BaseParams) extends Bundle {

  // Internal Register Sizes
  val REG_SIZE: Int = p.wordWidth
  val DIRECTION_SIZE: Int = p.dataWidth
  val OUTPUT_SIZE: Int = p.dataWidth
  val INPUT_SIZE: Int = p.dataWidth
  val MODE_SIZE: Int = p.dataWidth

  val ATOMIC_OPERATION_SIZE: Int = 4
  val ATOMIC_MASK_SIZE: Int = p.dataWidth
  val ATOMIC_SET_SIZE: Int = 1

  val VIRTUAL_PORT_MAP_SIZE: Int = p.sizeOfVirtualPorts
  val VIRTUAL_PORT_OUTPUT_SIZE: Int = p.numVirtualPorts
  val VIRTUAL_PORT_ENABLE_SIZE: Int = 1

  val TRIGGER_TYPE_SIZE: Int = p.dataWidth
  val TRIGGER_LVL0_SIZE: Int = p.dataWidth
  val TRIGGER_LVL1_SIZE: Int = p.dataWidth
  val TRIGGER_STATUS_SIZE: Int = p.dataWidth
  val IRQ_ENABLE_SIZE: Int = p.dataWidth

  // #####################################################################
  // REGS
  // #####################################################################
  // User Accessible Control Registers
  val DIRECTION = RegInit(0.U(DIRECTION_SIZE.W)) // RW
  val OUTPUT = RegInit(0.U(OUTPUT_SIZE.W)) // RW
  val INPUT = RegInit(0.U(INPUT_SIZE.W)) // RO
  val MODE = RegInit(0.U(MODE_SIZE.W)) // RW

  // Atomic Operations
  val ATOMIC_OPERATION = RegInit(0.U(ATOMIC_OPERATION_SIZE.W))
  val ATOMIC_MASK = RegInit(0.U(ATOMIC_MASK_SIZE.W))
  val ATOMIC_SET = RegInit(0.U(ATOMIC_SET_SIZE.W))

  // Virtual Port Control Registers
  val virtualPortOutput = RegInit(0.U(VIRTUAL_PORT_OUTPUT_SIZE.W))
  // Virtual to Physical Pin Mapping
  val virtualToPhysicalMap =
    RegInit(
      VecInit(Seq.fill(VIRTUAL_PORT_OUTPUT_SIZE)(0.U(VIRTUAL_PORT_MAP_SIZE.W)))
    )
  // Virtual Port Enable
  val virtualPortEnable = RegInit(0.U(VIRTUAL_PORT_ENABLE_SIZE.W))

  // Interrupt Handling Registers
  val TRIGGER_TYPE = RegInit(0.U(TRIGGER_TYPE_SIZE.W))
  val TRIGGER_LVL0 = RegInit(0.U(TRIGGER_LVL0_SIZE.W))
  val TRIGGER_LVL1 = RegInit(0.U(TRIGGER_LVL1_SIZE.W))
  val TRIGGER_STATUS = RegInit(0.U(TRIGGER_STATUS_SIZE.W))
  val IRQ_ENABLE = RegInit(0.U(IRQ_ENABLE_SIZE.W))

  // #####################################################################

  val DIRECTION_ADDR: Int = 0
  val DIRECTION_REG_SIZE: Int = (DIRECTION_SIZE + REG_SIZE - 1) / REG_SIZE
  val DIRECTION_ADDR_MAX: Int = DIRECTION_ADDR + DIRECTION_REG_SIZE - 1

  val OUTPUT_ADDR: Int = DIRECTION_ADDR_MAX + 1
  val OUTPUT_REG_SIZE: Int = (OUTPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val OUTPUT_ADDR_MAX: Int = OUTPUT_ADDR + OUTPUT_REG_SIZE - 1

  val INPUT_ADDR: Int = OUTPUT_ADDR_MAX + 1
  val INPUT_REG_SIZE: Int = (INPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val INPUT_ADDR_MAX: Int = INPUT_ADDR + INPUT_REG_SIZE - 1

  val MODE_ADDR: Int = INPUT_ADDR_MAX + 1
  val MODE_REG_SIZE: Int = (MODE_SIZE + REG_SIZE - 1) / REG_SIZE
  val MODE_ADDR_MAX: Int = MODE_ADDR + MODE_REG_SIZE - 1

  val ATOMIC_OPERATION_ADDR: Int = MODE_ADDR_MAX + 1
  val ATOMIC_OPERATION_REG_SIZE: Int =
    (ATOMIC_OPERATION_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_OPERATION_ADDR_MAX: Int =
    ATOMIC_OPERATION_ADDR + ATOMIC_OPERATION_REG_SIZE - 1

  val ATOMIC_MASK_ADDR: Int = ATOMIC_OPERATION_ADDR_MAX + 1
  val ATOMIC_MASK_REG_SIZE: Int = (ATOMIC_MASK_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_MASK_ADDR_MAX: Int = ATOMIC_MASK_ADDR + ATOMIC_MASK_REG_SIZE - 1

  val ATOMIC_SET_ADDR: Int = ATOMIC_MASK_ADDR_MAX + 1
  val ATOMIC_SET_REG_SIZE: Int = (ATOMIC_SET_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_SET_ADDR_MAX: Int = ATOMIC_SET_ADDR + ATOMIC_SET_REG_SIZE - 1

  // virtual port registers
  val VIRTUAL_PORT_MAP_ADDR: Int = ATOMIC_SET_ADDR_MAX + 1
  val VIRTUAL_PORT_MAP_REG_SIZE: Int =
    (VIRTUAL_PORT_MAP_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_MAP_ADDR_MAX: Int =
    VIRTUAL_PORT_MAP_ADDR + VIRTUAL_PORT_OUTPUT_SIZE * VIRTUAL_PORT_MAP_REG_SIZE - 1

  val VIRTUAL_PORT_OUTPUT_ADDR: Int = VIRTUAL_PORT_MAP_ADDR_MAX + 1
  val VIRTUAL_PORT_OUTPUT_REG_SIZE: Int =
    (VIRTUAL_PORT_OUTPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_OUTPUT_ADDR_MAX: Int =
    VIRTUAL_PORT_OUTPUT_ADDR + VIRTUAL_PORT_OUTPUT_REG_SIZE - 1

  val VIRTUAL_PORT_ENABLE_ADDR: Int = VIRTUAL_PORT_OUTPUT_ADDR_MAX + 1
  val VIRTUAL_PORT_ENABLE_REG_SIZE: Int =
    (VIRTUAL_PORT_ENABLE_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_ENABLE_ADDR_MAX: Int =
    VIRTUAL_PORT_ENABLE_ADDR + VIRTUAL_PORT_ENABLE_REG_SIZE - 1

  // Interrupt Registers
  val TRIGGER_TYPE_ADDR: Int = VIRTUAL_PORT_ENABLE_ADDR_MAX + 1
  val TRIGGER_TYPE_REG_SIZE: Int = (TRIGGER_TYPE_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_TYPE_ADDR_MAX: Int = TRIGGER_TYPE_ADDR + TRIGGER_TYPE_REG_SIZE - 1

  val TRIGGER_LVL0_ADDR: Int = TRIGGER_TYPE_ADDR_MAX + 1
  val TRIGGER_LVL0_REG_SIZE: Int = (TRIGGER_LVL0_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_LVL0_ADDR_MAX: Int = TRIGGER_LVL0_ADDR + TRIGGER_LVL0_REG_SIZE - 1

  val TRIGGER_LVL1_ADDR: Int = TRIGGER_LVL0_ADDR_MAX + 1
  val TRIGGER_LVL1_REG_SIZE: Int = (TRIGGER_LVL1_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_LVL1_ADDR_MAX: Int = TRIGGER_LVL1_ADDR + TRIGGER_LVL1_REG_SIZE - 1

  val TRIGGER_STATUS_ADDR: Int = TRIGGER_LVL1_ADDR_MAX + 1
  val TRIGGER_STATUS_REG_SIZE: Int =
    (TRIGGER_STATUS_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_STATUS_ADDR_MAX: Int =
    TRIGGER_STATUS_ADDR + TRIGGER_STATUS_REG_SIZE - 1

  val IRQ_ENABLE_ADDR: Int = TRIGGER_STATUS_ADDR_MAX + 1
  val IRQ_ENABLE_REG_SIZE: Int = (IRQ_ENABLE_SIZE + REG_SIZE - 1) / REG_SIZE
  val IRQ_ENABLE_ADDR_MAX: Int = IRQ_ENABLE_ADDR + IRQ_ENABLE_REG_SIZE - 1
}
