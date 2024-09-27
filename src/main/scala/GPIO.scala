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
    val REG_SIZE: Int = p.wordWidth

    val DIRECTION_SIZE: Int = p.dataWidth
    val OUTPUT_SIZE: Int = p.dataWidth
    val INPUT_SIZE: Int = p.dataWidth
    val MODE_SIZE: Int = p.dataWidth

    val ATOMIC_OPERATION_SIZE: Int = 4
    val ATOMIC_MASK_SIZE: Int = p.dataWidth
    val ATOPIC_SET_SIZE: Int = 1

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
    val ATOMIC_SET_REG_SIZE: Int = (ATOPIC_SET_SIZE + REG_SIZE - 1) / REG_SIZE
    val ATOMIC_SET_ADDR_MAX: Int = ATOMIC_SET_ADDR + ATOMIC_SET_REG_SIZE - 1

    when(addr >= DIRECTION_ADDR.U && addr <= DIRECTION_ADDR_MAX.U) {
      printf(
        "Writing DIRECTION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.DIRECTION := io.apb.PWDATA(DIRECTION_SIZE - 1, 0)
    }
    when(addr >= OUTPUT_ADDR.U && addr <= OUTPUT_ADDR_MAX.U) {
      printf(
        "Writing OUTPUT Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.OUTPUT := io.apb.PWDATA(OUTPUT_SIZE - 1, 0)
    }
    when(addr >= MODE_ADDR.U && addr <= MODE_ADDR_MAX.U) {
      printf("Writing MODE Register, data: %x, addr: %x\n", io.apb.PWDATA, addr)
      regs.MODE := io.apb.PWDATA(MODE_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_OPERATION_ADDR.U && addr <= ATOMIC_OPERATION_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_OPERATION := io.apb.PWDATA(ATOMIC_OPERATION_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_MASK_ADDR.U && addr <= ATOMIC_MASK_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_MASK Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_MASK := io.apb.PWDATA(ATOMIC_MASK_SIZE - 1, 0)
    }
    when(addr >= ATOMIC_SET_ADDR.U && addr <= ATOMIC_SET_ADDR_MAX.U) {
      printf(
        "Writing ATOMIC_SET Register, data: %x, addr: %x\n",
        io.apb.PWDATA,
        addr,
      )
      regs.ATOMIC_SET := io.apb.PWDATA(ATOPIC_SET_SIZE - 1, 0)
    }
  }

  // function to take addr and data from APB and write to gpio register space and or child modules if applicable
  def registerDecodeRead(addr: UInt): Unit = {
    val REG_SIZE: Int = p.wordWidth

    val DIRECTION_SIZE: Int = p.dataWidth
    val OUTPUT_SIZE: Int = p.dataWidth
    val INPUT_SIZE: Int = p.dataWidth
    val MODE_SIZE: Int = p.dataWidth

    val ATOMIC_OPERATION_SIZE: Int = 4
    val ATOMIC_MASK_SIZE: Int = p.dataWidth
    val ATOPIC_SET_SIZE: Int = 1

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
    val ATOMIC_SET_REG_SIZE: Int = (ATOPIC_SET_SIZE + REG_SIZE - 1) / REG_SIZE
    val ATOMIC_SET_ADDR_MAX: Int = ATOMIC_SET_ADDR + ATOMIC_SET_REG_SIZE - 1

    printf("Reading Register, addr: %x\n", addr)

    when(addr >= DIRECTION_ADDR.U && addr <= DIRECTION_ADDR_MAX.U) {

      printf(
        "Reading DIRECTION Register, data: %x, addr: %x\n",
        regs.DIRECTION,
        addr,
      )
      io.apb.PRDATA := regs.DIRECTION
    }
    when(addr >= OUTPUT_ADDR.U && addr <= OUTPUT_ADDR_MAX.U) {
      printf("Reading OUTPUT Register, data: %x, addr: %x\n", regs.OUTPUT, addr)
      io.apb.PRDATA := regs.OUTPUT
    }
    when(addr >= INPUT_ADDR.U && addr <= INPUT_ADDR_MAX.U) {
      printf("Reading INPUT Register, data: %x, addr: %x\n", regs.INPUT, addr)
      io.apb.PRDATA := regs.INPUT
    }
    when(addr >= MODE_ADDR.U && addr <= MODE_ADDR_MAX.U) {
      printf("Reading MODE Register, data: %x, addr: %x\n", regs.MODE, addr)
      io.apb.PRDATA := regs.MODE
    }
    when(addr >= ATOMIC_OPERATION_ADDR.U && addr <= ATOMIC_OPERATION_ADDR_MAX.U) {
      printf(
        "Reading ATOMIC_OPERATION Register, data: %x, addr: %x\n",
        regs.ATOMIC_OPERATION,
        addr,
      )
      printf(
        "ATOMIC_OPERATION_MIN: %x\nATOMIC_OPERATION_MAX: %x\n",
        ATOMIC_OPERATION_ADDR.U,
        ATOMIC_OPERATION_ADDR_MAX.U,
      )
      io.apb.PRDATA := regs.ATOMIC_OPERATION.asUInt
    }
    when(addr >= ATOMIC_MASK_ADDR.U && addr <= ATOMIC_MASK_ADDR_MAX.U) {
      printf(
        "Reading ATOMIC_MASK Register, data: %x, addr: %x\n",
        regs.ATOMIC_MASK,
        addr,
      )
      io.apb.PRDATA := regs.ATOMIC_MASK
    }
    when(addr >= ATOMIC_SET_ADDR.U && addr <= ATOMIC_SET_ADDR_MAX.U) {
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
