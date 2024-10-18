package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._
object interruptTriggers extends ApbUtils{

  def triggerHigh(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    // Test: Trigger Level When High
    println("Test: Trigger Level When High")
    writeApb(dut, dut.regs.IRQ_ENABLE_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 12.U)
    writeApb(dut, dut.regs.TRIGGER_LO_ADDR.U, 12.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 3.U)
    dut.io.in.poke(3.U)
    dut.clock.step(2) // Wait for synchronizer
    var triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
    require(triggerStatus == 3)
    var irqOutput = dut.io.irq.peekInt()
    println(s"irqOutput Read Value: ${irqOutput.toString()}")
    require(irqOutput == 1)

    clearInterrupt(dut, 0.U, 3.U)
  }

  def triggerLow(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    // Test: Trigger Level When Low
    println("Test: Trigger Level When Low")
    writeApb(dut, dut.regs.TRIGGER_LO_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 12.U)
    dut.io.in.poke(2.U)
    dut.clock.step(2) // Wait for synchronizer
    var triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
    require(triggerStatus == 1)
    var irqOutput = dut.io.irq.peekInt()
    println(s"irqOutput Read Value: ${irqOutput.toString()}")
    require(irqOutput == 1)

    clearInterrupt(
      dut,
      3.U,
      1.U
    ) // Write 1 to first 2 bits of input bc trigger level low is enabled
    // Otherwise trigger register will keep on getting updated (not cleared)
  }

  def triggerRising(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {

    // Test: Edge Trigger on Rising Edge
    println("Test: Edge Trigger on Rising Edge")
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_LO_ADDR.U, 0.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 3.U)
    dut.io.in.poke(0.U) // Need to go low to trigger edge det
    dut.clock.step(2) // Wait for synchronizer
    dut.io.in.poke(7.U)
    dut.clock.step(
      1
    ) // Wait for synchronizer, triggerStatus and irqOut only high for one clock cycle
    var triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
    require(triggerStatus == 3)
  }

  def triggerFalling(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    // Test: Edge Trigger on Falling Edge
    println("Test: Edge Trigger on Falling Edge")
    writeApb(dut, dut.regs.TRIGGER_LO_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 0.U)
    dut.io.in.poke(2.U) // Need to go high to trigger edge det
    dut.clock.step(2) // Wait for synchronizer
    dut.io.in.poke(0.U)
    dut.clock.step(
      1
    ) // Wait for synchronizer, triggerStatus and irqOut only high for one clock cycle
    var triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
    require(triggerStatus == 2)
  }

  def interruptTriggers(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    triggerHigh(dut, gpioDataBuffer, myParams)
    triggerLow(dut, gpioDataBuffer, myParams)
    triggerRising(dut, gpioDataBuffer, myParams)
    triggerFalling(dut, gpioDataBuffer, myParams)
  }
}
