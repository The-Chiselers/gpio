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

  // User Accessible Control Registers
  val DIRECTION = RegInit(0.U(p.dataWidth.W)) // RW
  val OUTPUT = RegInit(0.U(p.dataWidth.W)) // RW
  val INPUT = RegInit(0.U(p.dataWidth.W)) // RO
  val MODE = RegInit(0.U(p.dataWidth.W)) // RW

  // Intermediary Signals
  val GPIO_O_VEC = Wire(Vec(p.dataWidth, UInt(1.W)))
  val GPIO_OE_VEC = Wire(Vec(p.dataWidth, UInt(1.W)))

  io.apb.PRDATA := 0.U // Init value
  when(io.apb.PSEL && io.apb.PENABLE) {
    when(io.apb.PWRITE) { // Write Operation
      switch(io.apb.PADDR) { // Address for OUTPUT Register
        is(0.U)(MODE := io.apb.PWDATA)
        is(2.U)(OUTPUT := io.apb.PWDATA)
        is(1.U) { // Address for DIRECTION Register
          DIRECTION := io.apb.PWDATA // Takes LSB of PWDATA
        }
      }
      io.apb.PREADY := true.B
    }.otherwise { // Read Operation
      switch(io.apb.PADDR) {
        is(0.U)(io.apb.PRDATA := MODE)
        is(2.U)(io.apb.PRDATA := OUTPUT)
        is(1.U)(io.apb.PRDATA := DIRECTION)
        is(3.U)(io.apb.PRDATA := INPUT)
      }
      io.apb.PREADY := true.B
    }
  }.otherwise(io.apb.PREADY := false.B)

  for (i <- 0 until p.dataWidth) when(MODE(i) === 1.U) { // AND each bit of DIRECTION to mask bits that are not set as OUTPUT in GPIO_O
    GPIO_O_VEC(p.dataWidth - i - 1) := OUTPUT(i) & DIRECTION(i)
    GPIO_OE_VEC(p.dataWidth - i - 1) := DIRECTION(i)
  }.otherwise {
    GPIO_O_VEC(p.dataWidth - i - 1) := 0.U
    GPIO_OE_VEC(p.dataWidth - i - 1) := ~OUTPUT(i) & DIRECTION(i)
  }
  // Pads Implementation
  // io.pins.pads(i) := Mux(GPIO_OE(i) === 1.U, GPIO_O(i), 0.U)
  // GPIO_I(i) := Mux(GPIO_OE(i) === 0.U, io.pins.pads(i), 0.U)
  INPUT := io.pins.GPIO_I
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

}
