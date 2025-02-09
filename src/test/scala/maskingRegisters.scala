package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
//import TestUtils._

object maskingRegisters extends ApbUtils {

  def maskingAnd(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    println("Test: Test Atomic AND Register")
    gpioDataBuffer.foreach { data =>
      writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 0.U)
      writeApb(dut, dut.regs.ATOMIC_OPERATION_ADDR.U, 4.U)
      writeApb(dut, dut.regs.ATOMIC_MASK_ADDR.U, data)
      val randomOutputData =
        Random.nextInt(Math.pow(2, myParams.PDATA_WIDTH).toInt)
      writeApb(dut, dut.regs.OUTPUT_ADDR.U, randomOutputData.U)
      val outputDataBeforeSet = readApb(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read Before Set: ${outputDataBeforeSet.toString()}"
      )
      require(outputDataBeforeSet == randomOutputData)
      writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 1.U)
      val outputDataAfterSet = readApb(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read After Set: ${outputDataAfterSet.toString()}"
      )
      val andOperation = data.litValue & randomOutputData
      require(outputDataAfterSet == andOperation)
    }
  }

  def maskingAndMode(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    println("Test: Random maskingAnd + PPL Mode Register")
    gpioDataBuffer.foreach { data =>
      writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 0.U)
      writeApb(dut, dut.regs.ATOMIC_OPERATION_ADDR.U, 4.U)
      writeApb(dut, dut.regs.ATOMIC_MASK_ADDR.U, data)
      val randomOutputData =
        Random.nextInt(Math.pow(2, myParams.PDATA_WIDTH).toInt)
      writeApb(dut, dut.regs.OUTPUT_ADDR.U, randomOutputData.U)
      val outputDataBeforeSet = readApb(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read Before Set: ${outputDataBeforeSet.toString()}"
      )
      require(outputDataBeforeSet == randomOutputData)
      writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 1.U)
      val outputDataAfterSet = readApb(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read After Set: ${outputDataAfterSet.toString()}"
      )
      val andOperation = data.litValue & randomOutputData
      require(outputDataAfterSet == andOperation)

      writeApb(
      dut,
      dut.regs.ATOMIC_SET_ADDR.U,
      0.U
    ) // When set to 1 it fails Push-Pull Mode, Interesting

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
      require(expectedValOutput == actualValOutput)
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
}
