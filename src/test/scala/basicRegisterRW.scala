package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._

object basicRegisterRW extends APBUtils{
  def directionRegister(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test 1: Write to DIRECTION register")
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.DIRECTION_ADDR.U, data)
      val directionData = readAPB(dut, dut.regs.DIRECTION_ADDR.U)
      println(s"Direction Register Read: ${directionData.toString()}")
      require(directionData == data.litValue)
    }
  }

  def outputRegister(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test 2: Write to OUTPUT register")
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.OUTPUT_ADDR.U, data)
      val outputData = readAPB(dut, dut.regs.OUTPUT_ADDR.U)
      println(s"Output Register Read: ${outputData.toString()}")
      require(outputData == data.litValue)
    }
  }

  def inputRegister(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test 3: Write to INPUT register")
    gpioDataBuffer.foreach { data =>
      dut.io.pins.gpioInput.poke(data)
      dut.clock.step(2) // Wait for synchronizer
      val inputData = readAPB(dut, dut.regs.INPUT_ADDR.U)
      println(s"Input Register Read: ${inputData.toString()}")
      require(inputData == data.litValue)
    }
  }

  def modeRegister(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test 4: Write to MODE register")
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.MODE_ADDR.U, data)
      val modeData = readAPB(dut, dut.regs.MODE_ADDR.U)
      println(s"Mode Register Read: ${modeData.toString()}")
      require(modeData == data.litValue)
    }
  }

  def invalidAddress(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    // Test 8: Invalid Address Handling
    println("Test 8: Invalid Address Handling")
    val invalidAddr = dut.regs.IRQ_ENABLE_ADDR_MAX + 1
    writeAPB(dut, invalidAddr.U, 15.U)
    dut.clock.step(1)
    require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal
    dut.clock.step(1)
    val readData = readAPB(dut, invalidAddr.U)
    dut.clock.step(1)
    require(dut.io.apb.PSLVERR.peekInt() == 1)
    require(readData == 0)
  }

  def basicRegisterRW(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    directionRegister(dut, gpioDataBuffer, myParams)
    outputRegister(dut, gpioDataBuffer, myParams)
    inputRegister(dut, gpioDataBuffer, myParams)
    modeRegister(dut, gpioDataBuffer, myParams)
    invalidAddress(dut, gpioDataBuffer, myParams)
  }

}
