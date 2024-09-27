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
    val DIRECTION_SIZE = p.dataWidth
    val OUTPUT_SIZE = p.dataWidth
    val INPUT_SIZE = p.dataWidth
    val MODE_SIZE = p.dataWidth

    val ATOMIC_OPERATION_SIZE = 4
    val ATOMIC_MASK_SIZE = p.dataWidth
    val ATOPIC_SET_SIZE = 1

    val DIRECTION_ADDR = 0.U
    val DIRECTION_ADDR_MAX = DIRECTION_ADDR + DIRECTION_SIZE.U - 1.U

    val OUTPUT_ADDR = DIRECTION_ADDR + DIRECTION_SIZE.U
    val OUTPUT_ADDR_MAX = OUTPUT_ADDR + OUTPUT_SIZE.U - 1.U

    val INPUT_ADDR = OUTPUT_ADDR + OUTPUT_SIZE.U
    val INPUT_ADDR_MAX = INPUT_ADDR + INPUT_SIZE.U - 1.U

    val MODE_ADDR = INPUT_ADDR + INPUT_SIZE.U
    val MODE_ADDR_MAX = MODE_ADDR + MODE_SIZE.U - 1.U

    val ATOMIC_OPERATION_ADDR = MODE_ADDR + MODE_SIZE.U
    val ATOMIC_OPERATION_ADDR_MAX = ATOMIC_OPERATION_ADDR +
      ATOMIC_OPERATION_SIZE.U - 1.U

    val ATOMIC_MASK_ADDR = ATOMIC_OPERATION_ADDR + ATOMIC_OPERATION_SIZE.U
    val ATOMIC_MASK_ADDR_MAX = ATOMIC_MASK_ADDR + ATOMIC_MASK_SIZE.U - 1.U

    val ATOMIC_SET_ADDR = ATOMIC_MASK_ADDR + ATOMIC_MASK_SIZE.U
    val ATOMIC_SET_ADDR_MAX = ATOMIC_SET_ADDR + ATOPIC_SET_SIZE.U - 1.U
    when(addr >= DIRECTION_ADDR && addr <= DIRECTION_ADDR_MAX) {
      regs.DIRECTION := io.apb.PWDATA(DIRECTION_SIZE - 1, 0)
    }
    when(addr >= OUTPUT_ADDR && addr <= OUTPUT_ADDR_MAX) {
      regs.OUTPUT := io.apb.PWDATA(OUTPUT_SIZE - 1, 0)
    }
    when(addr >= MODE_ADDR && addr <= MODE_ADDR_MAX) {
      regs.MODE := io.apb.PWDATA(MODE_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_OPERATION_ADDR && addr <= ATOMIC_OPERATION_ADDR_MAX) {
      regs.ATOMIC_OPERATION := io.apb.PWDATA(ATOMIC_OPERATION_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_MASK_ADDR && addr <= ATOMIC_MASK_ADDR_MAX) {
      regs.ATOMIC_MASK := io.apb.PWDATA(ATOMIC_MASK_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_SET_ADDR && addr <= ATOMIC_SET_ADDR_MAX) {
      regs.ATOMIC_SET := io.apb.PWDATA(ATOPIC_SET_SIZE - 1, 0)
    }
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeRead(addr: UInt): Unit = {
    val DIRECTION_SIZE = p.dataWidth
    val OUTPUT_SIZE = p.dataWidth
    val INPUT_SIZE = p.dataWidth
    val MODE_SIZE = p.dataWidth

    val ATOMIC_OPERATION_SIZE = 4
    val ATOMIC_MASK_SIZE = p.dataWidth
    val ATOPIC_SET_SIZE = 1

    val DIRECTION_ADDR = 0.U
    val DIRECTION_ADDR_MAX = DIRECTION_ADDR + DIRECTION_SIZE.U - 1.U

    val OUTPUT_ADDR = DIRECTION_ADDR + DIRECTION_SIZE.U
    val OUTPUT_ADDR_MAX = OUTPUT_ADDR + OUTPUT_SIZE.U - 1.U

    val INPUT_ADDR = OUTPUT_ADDR + OUTPUT_SIZE.U
    val INPUT_ADDR_MAX = INPUT_ADDR + INPUT_SIZE.U - 1.U

    val MODE_ADDR = INPUT_ADDR + INPUT_SIZE.U
    val MODE_ADDR_MAX = MODE_ADDR + MODE_SIZE.U - 1.U

    val ATOMIC_OPERATION_ADDR = MODE_ADDR + MODE_SIZE.U
    val ATOMIC_OPERATION_ADDR_MAX = ATOMIC_OPERATION_ADDR +
      ATOMIC_OPERATION_SIZE.U - 1.U

    val ATOMIC_MASK_ADDR = ATOMIC_OPERATION_ADDR + ATOMIC_OPERATION_SIZE.U
    val ATOMIC_MASK_ADDR_MAX = ATOMIC_MASK_ADDR + ATOMIC_MASK_SIZE.U - 1.U

    val ATOMIC_SET_ADDR = ATOMIC_MASK_ADDR + ATOMIC_MASK_SIZE.U
    val ATOMIC_SET_ADDR_MAX = ATOMIC_SET_ADDR + ATOPIC_SET_SIZE.U - 1.U

    when(addr >= DIRECTION_ADDR && addr <= DIRECTION_ADDR_MAX) {
      io.apb.PRDATA := regs.DIRECTION
    }
    when(addr >= OUTPUT_ADDR && addr <= OUTPUT_ADDR_MAX) {
      io.apb.PRDATA := regs.OUTPUT
    }
    when(addr >= INPUT_ADDR && addr <= INPUT_ADDR_MAX) {
      io.apb.PRDATA := regs.INPUT
    }
    when(addr >= MODE_ADDR && addr <= MODE_ADDR_MAX) {
      io.apb.PRDATA := regs.MODE
    }
    when(addr >= ATOMIC_OPERATION_ADDR && addr <= ATOMIC_OPERATION_ADDR_MAX) {
      io.apb.PRDATA := regs.ATOMIC_OPERATION.asUInt
    }
    when(addr >= ATOMIC_MASK_ADDR && addr <= ATOMIC_MASK_ADDR_MAX) {
      io.apb.PRDATA := regs.ATOMIC_MASK
    }
    when(addr >= ATOMIC_SET_ADDR && addr <= ATOMIC_SET_ADDR_MAX) {
      io.apb.PRDATA := regs.ATOMIC_SET
    }

  }
}

class GPIORegs(p: BaseParams) extends Bundle {
  // User Accessible Control Registers
  val DIRECTION = RegInit(0.U(p.dataWidth.W)) // RW
  val OUTPUT = RegInit(0.U(p.dataWidth.W)) // RW
  val INPUT = RegInit(0.U(p.dataWidth.W)) // RO
  val MODE = RegInit(0.U(p.dataWidth.W)) // RW

  // Atomic Operations
  val ATOMIC_OPERATION = RegInit(0.U(4.W))
  val ATOMIC_MASK = RegInit(0.U(p.dataWidth.W))
  val ATOMIC_SET = RegInit(0.U(1.W))
}
