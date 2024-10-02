package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._

trait APBUtils {
  def writeAPB(dut: GPIO, addr: UInt, data: UInt): Unit = {
    dut.io.apb.PSEL.poke(1) // Select GPIO Slave
    dut.clock.step(1) // Simulate Second Phase
    dut.io.apb.PENABLE.poke(1) // Enable APB
    dut.io.apb.PWRITE.poke(1) // Write mode
    dut.io.apb.PADDR.poke(addr)
    dut.io.apb.PWDATA.poke(data)
    dut.clock.step(1)
    dut.io.apb.PSEL.poke(0) // Deselect GPIO Slave
    dut.io.apb.PENABLE.poke(0) // Disable APB
    dut.clock.step(2)
  }

  def readAPB(dut: GPIO, addr: UInt): BigInt = {
    dut.io.apb.PSEL.poke(1) // Select APB
    dut.clock.step(1)
    dut.io.apb.PENABLE.poke(1) // Enable APB
    dut.io.apb.PWRITE.poke(0) // Read mode
    dut.io.apb.PADDR.poke(addr)
    dut.clock.step(1)
    val readValue = dut.io.apb.PRDATA.peekInt() // Return read data
    dut.clock.step(1) // Step for the read operation
    dut.io.apb.PSEL.poke(0) // Deselect GPIO Slave
    dut.io.apb.PENABLE.poke(0) // Disable APB
    dut.clock.step(2)
    readValue
  }

  def clearInterrupt(dut: GPIO, inputWrite: UInt, data: UInt): Unit = {
    // Clearing Interrupt
    dut.io.pins.gpioInput.poke(inputWrite)
    writeAPB(dut, dut.regs.TRIGGER_STATUS_ADDR.U, data)
    readAPB(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    dut.clock.step(2) // Wait for synchronizer
    var irqOutput = dut.io.pins.irqOutput.peekInt()
    println(
      s"Clearing Interrupt, irqOutput Read Value: ${irqOutput.toString()}"
    )
    require(irqOutput == 0)
  }
}
