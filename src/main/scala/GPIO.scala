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
      val GPIO_I = Input(UInt(p.dataWidth.W))
      val GPIO_O = Output(UInt(p.dataWidth.W))
      val GPIO_OE = Output(UInt(p.dataWidth.W))
    }
  })

  val regs = new GPIORegs(p)

  // Intermediary Signals
  val GPIO_O_VEC = Wire(Vec(p.dataWidth, UInt(1.W)))
  val GPIO_OE_VEC = Wire(Vec(p.dataWidth, UInt(1.W)))

  io.apb.PRDATA := 0.U // Init value
  when(io.apb.PSEL && io.apb.PENABLE) {
    when(io.apb.PWRITE) { // Write Operation
      // switch(io.apb.PADDR) { // Address for OUTPUT Register
      //   is(0.U)(regs.MODE := io.apb.PWDATA)
      //   is(2.U)(regs.OUTPUT := io.apb.PWDATA)
      //   is(1.U) { // Address for DIRECTION Register
      //     regs.DIRECTION := io.apb.PWDATA // Takes LSB of PWDATA
      //   }
      // }
      registerDecodeWrite(io.apb.PADDR)
      io.apb.PREADY := true.B
    }.otherwise { // Read Operation
      // switch(io.apb.PADDR) {
      //   is(0.U)(io.apb.PRDATA := regs.MODE)
      //   is(2.U)(io.apb.PRDATA := regs.OUTPUT)
      //   is(1.U)(io.apb.PRDATA := regs.DIRECTION)
      //   is(3.U)(io.apb.PRDATA := regs.INPUT)
      // }
      registerDecodeRead(io.apb.PADDR)
      io.apb.PREADY := true.B

    }
  }.otherwise(io.apb.PREADY := false.B)

  // atomic set
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
    val output = Wire(Vec(p.dataWidth, UInt(1.W)))
    for (i <- 0 until p.dataWidth) output(i) :=
      atomicOperationTruthTable(regs.ATOMIC_MASK(i))(regs.OUTPUT(i))

    regs.OUTPUT := Cat(output)
  }

  for (i <- 0 until p.dataWidth) when(regs.MODE(i) === 1.U) { // AND each bit of DIRECTION to mask bits that are not set as OUTPUT in GPIO_O
    GPIO_O_VEC(p.dataWidth - i - 1) := regs.OUTPUT(i) & regs.DIRECTION(i)
    GPIO_OE_VEC(p.dataWidth - i - 1) := regs.DIRECTION(i)
  }.otherwise {
    GPIO_O_VEC(p.dataWidth - i - 1) := 0.U
    GPIO_OE_VEC(p.dataWidth - i - 1) := ~regs.OUTPUT(i) & regs.DIRECTION(i)
  }
  // Pads Implementation
  // io.pins.pads(i) := Mux(GPIO_OE(i) === 1.U, GPIO_O(i), 0.U)
  // GPIO_I(i) := Mux(GPIO_OE(i) === 0.U, io.pins.pads(i), 0.U)
  regs.INPUT := io.pins.GPIO_I
  io.pins.GPIO_O := Cat(GPIO_O_VEC)
  io.pins.GPIO_OE := Cat(GPIO_OE_VEC)

  // Handle invalid address case
  when(
    io.apb.PADDR =/= 0.U && io.apb.PADDR =/= 1.U && io.apb.PADDR =/= 2.U &&
      io.apb.PADDR =/= 3.U,
  ) {
    io.apb.PSLVERR := true.B // Set error signal
  }.otherwise {
    io.apb.PSLVERR := false.B // Clear error signal if valid
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeWrite(addr: UInt): Unit = {

    when(addr >= regs.DIRECTION_ADDR.U && addr <= regs.DIRECTION_ADDR_MAX.U) {
      printf(
        "Writing DIRECTION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.DIRECTION := io.apb.PWDATA(regs.DIRECTION_SIZE - 1, 0)
    }
    when(addr >= regs.OUTPUT_ADDR.U && addr <= regs.OUTPUT_ADDR_MAX.U) {
      printf(
        "Writing OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.OUTPUT := io.apb.PWDATA(regs.OUTPUT_SIZE - 1, 0)
    }
    when(addr >= regs.MODE_ADDR.U && addr <= regs.MODE_ADDR_MAX.U) {
      printf("Writing MODE Register, data: %x, addr: %x\n", io.apb.PWDATA, addr)
      regs.MODE := io.apb.PWDATA(regs.MODE_SIZE - 1, 0)
    }
    when(
      addr >= regs.ATOMIC_OPERATION_ADDR.U &&
        addr <= regs.ATOMIC_OPERATION_ADDR_MAX.U,
    ) {
      printf(
        "Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_OPERATION := io.apb.PWDATA(regs.ATOMIC_OPERATION_SIZE - 1, 0)
    }
    when(addr >= regs.ATOMIC_MASK_ADDR.U && addr <= regs.ATOMIC_MASK_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_MASK Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_MASK := io.apb.PWDATA(regs.ATOMIC_MASK_SIZE - 1, 0)
    }
    when(addr >= regs.ATOMIC_SET_ADDR.U && addr <= regs.ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_SET Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_SET := io.apb.PWDATA(regs.ATOMIC_SET_SIZE - 1, 0)
    }
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeRead(addr: UInt): Unit = {

    printf("Reading Register, addr: %x\n", addr)

    when(addr >= regs.DIRECTION_ADDR.U && addr <= regs.DIRECTION_ADDR_MAX.U) {

      printf(
        "Reading DIRECTION Register, data: %x, addr: %x\n",
        regs.DIRECTION,
        addr,
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
      addr >= regs.ATOMIC_OPERATION_ADDR.U &&
        addr <= regs.ATOMIC_OPERATION_ADDR_MAX.U,
    ) {
      printf(
        "Reading ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        regs.ATOMIC_OPERATION,
        addr,
      )
      printf(
        "ATOMIC_OPERATION_MIN: %x\nATOMIC_OPERATION_MAX: %x\n",
        regs.ATOMIC_OPERATION_ADDR.U,
        regs.ATOMIC_OPERATION_ADDR_MAX.U,
      )
      io.apb.PRDATA := regs.ATOMIC_OPERATION.asUInt
    }
    when(addr >= regs.ATOMIC_MASK_ADDR.U && addr <= regs.ATOMIC_MASK_ADDR_MAX.U) {
      printf(
        "Reading ATOMIC_MASK Register, data: %x, addr: %x\n",
        regs.ATOMIC_MASK,
        addr,
      )
      io.apb.PRDATA := regs.ATOMIC_MASK
    }
    when(addr >= regs.ATOMIC_SET_ADDR.U && addr <= regs.ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Reading ATOMIC_SET Register, data: %x, addr: %x\n",
        regs.ATOMIC_SET,
        addr,
      )
      io.apb.PRDATA := regs.ATOMIC_SET
    }

  }
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
  val ATOMIC_OPERATION_ADDR_MAX: Int = ATOMIC_OPERATION_ADDR +
    ATOMIC_OPERATION_REG_SIZE - 1

  val ATOMIC_MASK_ADDR: Int = ATOMIC_OPERATION_ADDR_MAX + 1
  val ATOMIC_MASK_REG_SIZE: Int = (ATOMIC_MASK_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_MASK_ADDR_MAX: Int = ATOMIC_MASK_ADDR + ATOMIC_MASK_REG_SIZE - 1

  val ATOMIC_SET_ADDR: Int = ATOMIC_MASK_ADDR_MAX + 1
  val ATOMIC_SET_REG_SIZE: Int = (ATOMIC_SET_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_SET_ADDR_MAX: Int = ATOMIC_SET_ADDR + ATOMIC_SET_REG_SIZE - 1
}
