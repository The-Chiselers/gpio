package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.Assertions._
import firrtl2.options.TargetDirAnnotation
import scala.util.Random
import scala.math.pow
import scala.collection.mutable.Stack
import scala.collection.immutable.ListMap
import java.io.{File, FileWriter, PrintWriter, BufferedWriter}
//import tech.rocksavage.chiselware.util.TestUtils.{randData, checkCoverage}
import TestUtils.{randData, checkCoverage}
import java.{util => ju}
import java.{util => ju}

/** Highly randomized test suite driven by configuration parameters. Includes
  * code coverage for all top-level ports. Inspired by the DynamicFifo
  */

class GPIORandom extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  val numTests = 50
  val vervose = false

  def main(testName: String): Unit = {
    behavior of testName

    val backendAnnotations = Seq(
      // WriteVcdAnnotation,
      // WriteFstAnnotation,
      VerilatorBackendAnnotation,
      // IcarusBackendAnnotation,
      // VcsBackendAnnotation,
      TargetDirAnnotation("generated")
    )

    // Randomize Input Variables
    val validDataWidths = Seq(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 24, 32)
    val validPDataWidths = Seq(8, 16, 32)
    val validPAddrWidths = Seq(2, 4, 8, 16, 32)
    val dataWidth = validDataWidths(Random.nextInt(validDataWidths.length))
    val PDATA_WIDTH = validPDataWidths(Random.nextInt(validPDataWidths.length))
    val PADDR_WIDTH = validPAddrWidths(Random.nextInt(validPAddrWidths.length))

    val myParams = BaseParams(
      dataWidth,
      PDATA_WIDTH,
      PADDR_WIDTH,
      coverage = true
    )

    it should "pass" in {
      info(s"Data Width = $dataWidth")
      info(s"PDATA_WIDTH = $PDATA_WIDTH")
      info(s"PADDR_WIDTH = $PADDR_WIDTH")
      info("--------------------------------")
    }

    val cov = test(new GPIO(myParams)).withAnnotations(backendAnnotations) {
      dut =>
        dut.clock.setTimeout(0)
    }
  }
}
