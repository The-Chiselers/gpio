package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._

object modeOperation extends APBUtils{

  def pushPullMode(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test: Push-Pull Mode Operation")
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.MODE_ADDR.U, 0.U(myParams.dataWidth.W))
      writeAPB(dut, dut.regs.OUTPUT_ADDR.U, data)
      val randomDirectionData =
        Random.nextInt(Math.pow(2, myParams.dataWidth).toInt)
      writeAPB(dut, dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
      val expectedValOutput = randomDirectionData & data.litValue
      val actualValOutput = dut.io.pins.gpioOutput.peekInt()
      println(
        s"Expected Output Register after PPL Set: ${expectedValOutput.toString()}"
      )
      println(
        s"Output Register after PPL Set: ${actualValOutput.toString()}"
      )
      require(expectedValOutput == actualValOutput) // Failing :(
      val actualValOutputEnable = dut.io.pins.gpioOutputEnable.peekInt()
      println(
        s"Direction Register after PPL Set: ${actualValOutputEnable.toString()}"
      )
      require(randomDirectionData == actualValOutputEnable)
    }
  }

  def drainMode(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test: Drain Mode Operation")
    val fullOnes = (BigInt(1) << myParams.dataWidth) - 1
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.MODE_ADDR.U, fullOnes.U)
      writeAPB(dut, dut.regs.OUTPUT_ADDR.U, data)
      val randomDirectionData = Random
        .nextInt(Math.pow(2, myParams.dataWidth).toInt)
      writeAPB(dut, dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
      val actualValOutput = dut.io.pins.gpioOutput.peekInt()
      println(s"Output after PPL Set: ${actualValOutput.toString()}")
      require(0 == actualValOutput)
      val expectedValOutputEnable = ~data.litValue & randomDirectionData
      val actualValOutputEnable = dut.io.pins.gpioOutputEnable.peekInt()
      println(
        s"Expected Output Enable after PPL Set: ${expectedValOutputEnable.toString()}"
      )
      println(
        s"Output Enable after PPL Set: ${actualValOutputEnable.toString()}"
      )
      require(expectedValOutputEnable == actualValOutputEnable)
    }
  }

  def modeOperation(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    pushPullMode(dut, gpioDataBuffer, myParams)
    drainMode(dut, gpioDataBuffer, myParams)
  }
}
