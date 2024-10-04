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
  val triggerStatusVec = Wire(Vec(p.dataWidth, UInt(1.W)))

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
    val condition = Cat(regs.TRIGGER_TYPE(i), regs.TRIGGER_LO(i), regs.TRIGGER_HI(i))
    triggerStatusVec(i) := 0.U
    gpioInputSyncPrev := gpioInputSync // Edge Detection
    switch(condition) {
      is("b001".U) { // Level Trigger when High
        when(gpioInputSync(i) === 1.U) {
          triggerStatusVec(i) := 1.U
        }
      }
      is("b010".U) { // Level Trigger when Low
        when(gpioInputSync(i) === 0.U) {
          triggerStatusVec(i) := 1.U
        }
      }
      is("b011".U) { // Level Trigger when High or Low
          triggerStatusVec(i) := 1.U
      }
      is("b101".U) { // Edge Trigger on Rising Edge
        when(gpioInputSync(i) & ~gpioInputSyncPrev(i)) {
          triggerStatusVec(i) := 1.U
        }
      }
      is("b110".U) { // Edge Trigger on Falling Edge
        when(~gpioInputSync(i) && gpioInputSyncPrev(i)) {
          triggerStatusVec(i) := 1.U
        }
      }
      is("b111".U) { // Edge Trigger on Rising or Falling Edge
        when(gpioInputSync(i) =/= gpioInputSyncPrev(i)) {
          triggerStatusVec(i) := 1.U
        }
      }
    }
  }
  when((regs.TRIGGER_STATUS & regs.IRQ_ENABLE) >= 1.U) {
    io.pins.irqOutput := 1.U
  }.otherwise{
    io.pins.irqOutput := 0.U
  }
  regs.TRIGGER_STATUS := Reverse(Cat(triggerStatusVec))

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
    when(regs.MODE(i) === 0.U) { // AND each bit of DIRECTION to mask bits that are not set as OUTPUT in gpioOutput
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
      (io.apb.PADDR > regs.IRQ_ENABLE_ADDR_MAX.U)
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
      cover(io.apb.PRDATA(bit)).suggestName(s"apb_PRDATA_$bit")
      cover(io.apb.PWDATA(bit)).suggestName(s"apb_PWDATA_$bit")
    }

    for (bit <- 0 to p.addrWidth - 1)
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
      val shiftAddr = (addr - regs.DIRECTION_ADDR.U) 
      regs.DIRECTION := (io.apb.PWDATA(regs.DIRECTION_SIZE - 1, 0) << (shiftAddr(regs.DIRECTION_REG_SIZE - 1, 0) * 8.U))
    }
    when(addr >= regs.INPUT_ADDR.U && addr <= regs.INPUT_ADDR_MAX.U) {
      printf(
        "Writing INPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.INPUT_ADDR.U) 
      regs.INPUT := (io.apb.PWDATA(regs.INPUT_SIZE - 1, 0) << (shiftAddr(regs.INPUT_REG_SIZE - 1, 0) * 8.U))
    }
    when(addr >= regs.OUTPUT_ADDR.U && addr <= regs.OUTPUT_ADDR_MAX.U) {
      printf(
        "Writing OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.OUTPUT_ADDR.U)
      regs.OUTPUT := (io.apb.PWDATA(regs.OUTPUT_SIZE - 1, 0) << (shiftAddr(regs.OUTPUT_REG_SIZE - 1, 0) * 8.U))
    }
    when(addr >= regs.MODE_ADDR.U && addr <= regs.MODE_ADDR_MAX.U) {
      printf("Writing MODE Register, data: %x, addr: %x\n", io.apb.PWDATA, addr)
      val shiftAddr = (addr - regs.MODE_ADDR.U)
      regs.MODE := (io.apb.PWDATA(regs.MODE_SIZE - 1, 0) << (shiftAddr(regs.MODE_REG_SIZE - 1, 0) * 8.U))
    }
    when(
      addr >= regs.ATOMIC_OPERATION_ADDR.U && addr <= regs.ATOMIC_OPERATION_ADDR_MAX.U
    ) {
      printf(
        "Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.ATOMIC_OPERATION_ADDR.U)
      regs.ATOMIC_OPERATION := (io.apb.PWDATA(regs.ATOMIC_OPERATION_SIZE - 1, 0) << (shiftAddr(regs.ATOMIC_OPERATION_REG_SIZE - 1, 0) * 8.U))
    }
    when(
      addr >= regs.ATOMIC_MASK_ADDR.U && addr <= regs.ATOMIC_MASK_ADDR_MAX.U
    ) {
      printf(
        "Writing ATOMIC_MASK Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.ATOMIC_MASK_ADDR.U)
      regs.ATOMIC_MASK := (io.apb.PWDATA(regs.ATOMIC_MASK_SIZE - 1, 0) << (shiftAddr(regs.ATOMIC_MASK_REG_SIZE - 1, 0) * 8.U))
    }
    when(addr >= regs.ATOMIC_SET_ADDR.U && addr <= regs.ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_SET Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.ATOMIC_SET_ADDR.U)
      regs.ATOMIC_SET := (io.apb.PWDATA(regs.ATOMIC_SET_SIZE - 1, 0) << (shiftAddr(regs.ATOMIC_SET_REG_SIZE - 1, 0) * 8.U))    
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
      val index = (addr - regs.VIRTUAL_PORT_MAP_ADDR.U) / regs.VIRTUAL_PORT_MAP_REG_SIZE.U
      regs.virtualToPhysicalMap(index) := io.apb.PWDATA(regs.VIRTUAL_PORT_MAP_SIZE - 1, 0)
    }
    when(
      addr >= regs.VIRTUAL_PORT_OUTPUT_ADDR.U && addr <= regs.VIRTUAL_PORT_OUTPUT_ADDR_MAX.U
    ) {
      printf(
        "Writing VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.VIRTUAL_PORT_OUTPUT_ADDR.U)
      regs.virtualPortOutput := (io.apb.PWDATA(regs.VIRTUAL_PORT_OUTPUT_SIZE - 1, 0) << (shiftAddr(regs.VIRTUAL_PORT_OUTPUT_REG_SIZE - 1, 0) * 8.U))
    }
    when(
      addr >= regs.VIRTUAL_PORT_ENABLE_ADDR.U && addr <= regs.VIRTUAL_PORT_ENABLE_ADDR_MAX.U
    ) {
      printf(
        "Writing VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.VIRTUAL_PORT_ENABLE_ADDR.U)
      regs.virtualPortEnable := (io.apb.PWDATA(regs.VIRTUAL_PORT_ENABLE_SIZE - 1, 0) << (shiftAddr(regs.VIRTUAL_PORT_ENABLE_REG_SIZE - 1, 0) * 8.U))
    }
    when(addr >= regs.TRIGGER_TYPE_ADDR.U && addr <= regs.TRIGGER_TYPE_ADDR_MAX.U) {
      printf(
        "Writing TRIGGER_TYPE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.TRIGGER_TYPE_ADDR.U)
      regs.TRIGGER_TYPE := (io.apb.PWDATA(regs.TRIGGER_TYPE_SIZE - 1, 0) << (shiftAddr(regs.TRIGGER_TYPE_REG_SIZE - 1, 0) * 8.U))  
    }
    when(addr >= regs.TRIGGER_LO_ADDR.U && addr <= regs.TRIGGER_LO_ADDR_MAX.U) {
      printf(
        "Writing TRIGGER_LO Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.TRIGGER_LO_ADDR.U)
      regs.TRIGGER_LO := (io.apb.PWDATA(regs.TRIGGER_LO_SIZE - 1, 0) << (shiftAddr(regs.TRIGGER_LO_REG_SIZE - 1, 0) * 8.U))  
    }
    when(addr >= regs.TRIGGER_HI_ADDR.U && addr <= regs.TRIGGER_HI_ADDR_MAX.U) {
      printf(
        "Writing TRIGGER_HI Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.TRIGGER_HI_ADDR.U)
      regs.TRIGGER_HI := (io.apb.PWDATA(regs.TRIGGER_HI_SIZE - 1, 0) << (shiftAddr(regs.TRIGGER_HI_REG_SIZE - 1, 0) * 8.U))      
    }
    when(
      addr >= regs.TRIGGER_STATUS_ADDR.U && addr <= regs.TRIGGER_STATUS_ADDR_MAX.U
    ) {
      printf(
        "Writing TRIGGER_STATUS Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.TRIGGER_STATUS_ADDR.U)
      regs.TRIGGER_STATUS := regs.TRIGGER_STATUS & ~(io.apb.PWDATA(regs.TRIGGER_STATUS_SIZE - 1, 0) << (shiftAddr(regs.TRIGGER_STATUS_REG_SIZE - 1, 0) * 8.U)) // Writing a 1 will clear the status, ignore writes of 0
    }
    when(addr >= regs.IRQ_ENABLE_ADDR.U && addr <= regs.IRQ_ENABLE_ADDR_MAX.U) {
      printf(
        "Writing IRQ_ENABLE Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr
      )
      val shiftAddr = (addr - regs.IRQ_ENABLE_ADDR.U)
      regs.IRQ_ENABLE := (io.apb.PWDATA(regs.IRQ_ENABLE_SIZE - 1, 0) << (shiftAddr(regs.IRQ_ENABLE_REG_SIZE - 1, 0) * 8.U))      
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
    when(addr >= regs.TRIGGER_TYPE_ADDR.U && addr <= regs.TRIGGER_TYPE_ADDR_MAX.U) {
      printf(
        "READING TRIGGER_TYPE Register, data: %x, addr: %x\n",
        regs.TRIGGER_TYPE,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_TYPE
    }
    when(
      addr >= regs.TRIGGER_LO_ADDR.asUInt && addr <= regs.TRIGGER_LO_ADDR_MAX.U
    ) {
      printf(
        "READING TRIGGER_LO Register, data: %x, addr: %x\n",
        regs.TRIGGER_LO,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_LO
    }
    when(addr >= regs.TRIGGER_HI_ADDR.U && addr <= regs.TRIGGER_HI_ADDR_MAX.U) {
      printf(
        "READING TRIGGER_HI Register, data: %x, addr: %x\n",
        regs.TRIGGER_HI,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_HI
    }
    when(
      addr >= regs.TRIGGER_STATUS_ADDR.U && addr <= regs.TRIGGER_STATUS_ADDR_MAX.U
    ) {
      printf(
        "READING TRIGGER_STATUS Register, data: %x, addr: %x\n",
        regs.TRIGGER_STATUS,
        addr
      )
      io.apb.PRDATA := regs.TRIGGER_STATUS
    }
    when(addr >= regs.IRQ_ENABLE_ADDR.U && addr <= regs.IRQ_ENABLE_ADDR_MAX.U) {
      printf(
        "READING IRQ_ENABLE Register, data: %x, addr: %x\n",
        regs.IRQ_ENABLE,
        addr
      )
      io.apb.PRDATA := regs.IRQ_ENABLE
    }
  }

}

