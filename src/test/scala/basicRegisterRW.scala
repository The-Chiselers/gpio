package tech.rocksavage.chiselware.GPIO

import scala.math.pow
import scala.util.Random

import TestUtils._
import chisel3._
import chisel3.util._
import chiseltest._

object basicRegisterRW extends APBUtils {
  def directionRegister(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    println("Test: Write to DIRECTION register")
    gpioDataBuffer.foreach { data =>
      val randomAddr = dut.regs.DIRECTION_ADDR + Random.nextInt((dut.regs.DIRECTION_ADDR_MAX - dut.regs.DIRECTION_ADDR) + 1)
      writeAPB(dut, randomAddr.U, data)
      val directionData = readAPB(dut, randomAddr.U)
      println(s"Direction Register Read: ${directionData.toString()}")
      val shiftAddr = (randomAddr - (dut.regs.DIRECTION_ADDR)) * 8
      val expectedData = ((data.litValue << shiftAddr) & ((1L << myParams.dataWidth) - 1)).U   //Mask to keep answer dataWidth long
      require(directionData == expectedData.litValue)
    }
  }

  def outputRegister(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    println("Test: Write to OUTPUT register")
    gpioDataBuffer.foreach { data =>
      val randomAddr = dut.regs.OUTPUT_ADDR + Random.nextInt((dut.regs.OUTPUT_ADDR_MAX - dut.regs.OUTPUT_ADDR) + 1)
      writeAPB(dut, randomAddr.U, data)
      val outputData = readAPB(dut, randomAddr.U)
      println(s"Output Register Read: ${outputData.toString()}")
      val shiftAddr = (randomAddr - (dut.regs.OUTPUT_ADDR)) * 8
      val expectedData = ((data.litValue << shiftAddr) & ((1L << myParams.dataWidth) - 1)).U   //Mask to keep answer dataWidth long
      require(outputData == expectedData.litValue)
    }
  }

  def inputRegister(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    println("Test: Write to INPUT register")
    gpioDataBuffer.foreach { data =>
      dut.io.pins.gpioInput.poke(data)
      dut.clock.step(2) // Wait for synchronizer
      val inputData = readAPB(dut, dut.regs.INPUT_ADDR.U)
      println(s"Input Register Read: ${inputData.toString()}")
      require(inputData == data.litValue)
    }
  }

  def modeRegister(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    println("Test: Write to MODE register")
    gpioDataBuffer.foreach { data =>
      val randomAddr = dut.regs.MODE_ADDR + Random.nextInt((dut.regs.MODE_ADDR_MAX - dut.regs.MODE_ADDR) + 1)
      writeAPB(dut, randomAddr.U, data)
      val modeData = readAPB(dut, randomAddr.U)
      println(s"Mode Register Read: ${modeData.toString()}")
      val shiftAddr = (randomAddr - (dut.regs.MODE_ADDR)) * 8
      val expectedData = ((data.litValue << shiftAddr) & ((1L << myParams.dataWidth) - 1)).U   //Mask to keep answer dataWidth long
      require(modeData == expectedData.litValue)
    }
  }

  def invalidAddress(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    // Test: Invalid Address Handling
    println("Test: Invalid Address Handling")
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

  def basicRegisterRW(
      dut: GPIO,
      gpioDataBuffer: Seq[UInt],
      myParams: BaseParams,
  ): Unit = {
    directionRegister(dut, gpioDataBuffer, myParams)
    outputRegister(dut, gpioDataBuffer, myParams)
    inputRegister(dut, gpioDataBuffer, myParams)
    modeRegister(dut, gpioDataBuffer, myParams)
    invalidAddress(dut, gpioDataBuffer, myParams)
  }

}
