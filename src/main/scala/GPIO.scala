// (c) 2024 Rocksavage Technology, Inc.
// This code is licensed under the Apache Software License 2.0 (see LICENSE.MD)
package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import java.io.{File, PrintWriter}
import _root_.circt.stage.ChiselStage

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

  io.apb.PRDATA := 0.U // Init value
  when(io.apb.PSEL && io.apb.PENABLE) {
    when(io.apb.PWRITE) { // Write Operation
      switch(io.apb.PADDR) { // Address for OUTPUT Register
        is(0.U) {
          OUTPUT := io.apb.PWDATA
        }
        is(4.U) { // Address for DIRECTION Register
          DIRECTION := io.apb.PWDATA // Takes LSB of PWDATA
        }
      }
      io.apb.PREADY := true.B
    }.otherwise { // Read Operation
      switch(io.apb.PADDR) {
        is(0.U) {
          io.apb.PRDATA := OUTPUT
        }
        is(4.U) {
          io.apb.PRDATA := DIRECTION
        }
        is(8.U) {
          io.apb.PRDATA := INPUT
        }
      }
      io.apb.PREADY := true.B
    }
  }.otherwise {
    io.apb.PREADY := false.B
  }

  io.pins.GPIO_O := OUTPUT & DIRECTION // AND each bit of DIRECTION to mask bits that are not set as OUTPUT in GPIO_O
  io.pins.GPIO_OE := DIRECTION
  INPUT := io.pins.GPIO_I

  // Handle invalid address case
  when(io.apb.PADDR =/= 0.U && io.apb.PADDR =/= 4.U && io.apb.PADDR =/= 8.U) {
    io.apb.PSLVERR := true.B // Set error signal
  }.otherwise {
    io.apb.PSLVERR := false.B // Clear error signal if valid
  }

}
