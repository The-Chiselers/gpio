package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._
import chiseltest._

trait ApbUtils {
  def writeApb(dut: Gpio, addr: UInt, data: UInt): Unit = {
    dut.io.apb.PSEL.poke(1) // Select Gpio Slave
    dut.clock.step(1) // Simulate Second Phase
    dut.io.apb.PENABLE.poke(1) // Enable Apb
    dut.io.apb.PWRITE.poke(1) // Write mode
    dut.io.apb.PADDR.poke(addr)
    dut.io.apb.PWDATA.poke(data)
    dut.clock.step(1)
    dut.io.apb.PSEL.poke(0) // Deselect Gpio Slave
    dut.io.apb.PENABLE.poke(0) // Disable Apb
    dut.clock.step(2)
  }

  def readApb(dut: Gpio, addr: UInt): BigInt = {
    dut.io.apb.PSEL.poke(1) // Select Apb
    dut.clock.step(1)
    dut.io.apb.PENABLE.poke(1) // Enable Apb
    dut.io.apb.PWRITE.poke(0) // Read mode
    dut.io.apb.PADDR.poke(addr)
    dut.clock.step(1)
    val readValue = dut.io.apb.PRDATA.peekInt() // Return read data
    dut.clock.step(1) // Step for the read operation
    dut.io.apb.PSEL.poke(0) // Deselect Gpio Slave
    dut.io.apb.PENABLE.poke(0) // Disable Apb
    dut.clock.step(2)
    readValue
  }

  def clearInterrupt(dut: Gpio, inputWrite: UInt, data: UInt): Unit = {
    // Clearing Interrupt
    dut.io.in.poke(inputWrite)
    writeApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U, data)
    readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    dut.clock.step(2) // Wait for synchronizer
    var irqOutput = dut.io.irq.peekInt()
    println(
      s"Clearing Interrupt, irqOutput Read Value: ${irqOutput.toString()}"
    )
    require(irqOutput == 0)
  }
}
