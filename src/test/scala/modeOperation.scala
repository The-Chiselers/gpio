package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._

object modeOperation extends ApbUtils {

  def pushPullMode(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    println("Test: Push-Pull Mode Operation")
    gpioDataBuffer.foreach { data =>
      writeApb(dut, dut.regs.MODE_ADDR.U, 0.U(myParams.PDATA_WIDTH.W))
      writeApb(dut, dut.regs.OUTPUT_ADDR.U, data)
      val randomDirectionData =
        Random.nextInt(Math.pow(2, myParams.gpioWidth).toInt)
      writeApb(dut, dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
      val expectedValOutput = randomDirectionData & data.litValue
      val actualValOutput = dut.io.out.peekInt()
      println(
        s"Expected Output Register after PPL Set: ${expectedValOutput.toString()}"
      )
      println(
        s"Output Register after PPL Set: ${actualValOutput.toString()}"
      )
      require(expectedValOutput == actualValOutput) // Failing :(
      val actualValOutputEnable = dut.io.enable.peekInt()
      println(
        s"Expected Direction Register after PPL Set: ${randomDirectionData.toString()}"
      )
      println(
        s"Direction Register after PPL Set: ${actualValOutputEnable.toString()}"
      )
      require(randomDirectionData == actualValOutputEnable)
    }
  }

  def drainMode(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    println("Test: Drain Mode Operation")
    val fullOnes = (BigInt(1) << myParams.PDATA_WIDTH) - 1
    gpioDataBuffer.foreach { data =>
      writeApb(dut, dut.regs.MODE_ADDR.U, fullOnes.U)
      writeApb(dut, dut.regs.OUTPUT_ADDR.U, data)
      val randomDirectionData = Random
        .nextInt(Math.pow(2, myParams.gpioWidth).toInt)
      writeApb(dut, dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
      val actualValOutput = dut.io.out.peekInt()
      println(s"Output after PPL Set: ${actualValOutput.toString()}")
      require(0 == actualValOutput)
      val expectedValOutputEnable = ~data.litValue & randomDirectionData
      val actualValOutputEnable = dut.io.enable.peekInt()
      println(
        s"Expected Output Enable after PPL Set: ${expectedValOutputEnable.toString()}"
      )
      println(
        s"Output Enable after PPL Set: ${actualValOutputEnable.toString()}"
      )
      require(expectedValOutputEnable == actualValOutputEnable)
    }
  }

}
