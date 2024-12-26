package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._
import chiseltest._
import scala.util.Random
import scala.math.pow
import TestUtils._

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
    writeApb(
      dut,
      dut.regs.ATOMIC_SET_ADDR.U,
      0.U
    ) // When set to 1 it affects Push-Pull Mode, Interesting
  }

}
