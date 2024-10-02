package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._

object maskingRegisters extends APBUtils{

  def maskingAnd(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    println("Test 5: Test Atomic AND Register")
    gpioDataBuffer.foreach { data =>
      writeAPB(dut, dut.regs.ATOMIC_SET_ADDR.U, 0.U)
      writeAPB(dut, dut.regs.ATOMIC_OPERATION_ADDR.U, 4.U)
      writeAPB(dut, dut.regs.ATOMIC_MASK_ADDR.U, data)
      val randomOutputData =
        Random.nextInt(Math.pow(2, myParams.dataWidth).toInt)
      writeAPB(dut, dut.regs.OUTPUT_ADDR.U, randomOutputData.U)
      val outputDataBeforeSet = readAPB(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read Before Set: ${outputDataBeforeSet.toString()}"
      )
      require(outputDataBeforeSet == randomOutputData)
      writeAPB(dut, dut.regs.ATOMIC_SET_ADDR.U, 1.U)
      val outputDataAfterSet = readAPB(dut, dut.regs.OUTPUT_ADDR.U)
      println(
        s"Output Register Read After Set: ${outputDataAfterSet.toString()}"
      )
      val andOperation = data.litValue & randomOutputData
      require(outputDataAfterSet == andOperation)
    }
    writeAPB(
      dut,
      dut.regs.ATOMIC_SET_ADDR.U,
      0.U
    ) // When set to 1 it affects Push-Pull Mode, Interesting
  }

  def maskingRegisters(dut: GPIO, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    maskingAnd(dut, gpioDataBuffer, myParams)
  }
}
