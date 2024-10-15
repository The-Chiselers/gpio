package tech.rocksavage.chiselware.Gpio

import java.io.BufferedWriter
import java.io.File
import java.io.FileWriter
import java.io.PrintWriter
import java.{util => ju}

import scala.math.pow
import scala.util.Random

import org.scalatest.Assertions._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

//import tech.rocksavage.chiselware.util.TestUtils.{randData, checkCoverage}
import TestUtils.checkCoverage
import TestUtils.randData
import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import chiseltest.simulator._
import firrtl2.AnnotationSeq
import firrtl2.annotations.Annotation // Correct Annotation type for firrtl2
import firrtl2.options.TargetDirAnnotation

/** Highly randomized test suite driven by configuration parameters. Includes
  * code coverage for all top-level ports. Inspired by the DynamicFifo
  */

class GpioTest
    extends AnyFlatSpec with ChiselScalatestTester with Matchers with APBUtils {

  val verbose = false
  val numTests = 1
  val testName = System.getProperty("testName")
  println(s"Argument passed: $testName")

  // System properties for flags
  val enableVcd = System.getProperty("enableVcd", "false").toBoolean
  val enableFst = System.getProperty("enableFst", "false").toBoolean
  val useVerilator = System.getProperty("useVerilator", "false").toBoolean

  val buildRoot = sys.env.get("BUILD_ROOT_RELATIVE")
  if (buildRoot.isEmpty) {
    println("BUILD_ROOT_RELATIVE not set, please set and run again")
    System.exit(1)
  }
  val testDir = buildRoot.get + "/test"

  println(s"Test: $testName, VCD: $enableVcd, FST: $enableFst, Verilator: $useVerilator")

  // Constructing the backend annotations based on the flags
  val backendAnnotations = {
    var annos: Seq[Annotation] = Seq() // Initialize with correct type

    if (enableVcd) annos = annos :+ chiseltest.simulator.WriteVcdAnnotation 
    if (enableFst) annos = annos :+ chiseltest.simulator.WriteFstAnnotation
    if (useVerilator) {
      annos = annos :+ chiseltest.simulator.VerilatorBackendAnnotation 
      annos = annos :+ VerilatorCFlags(Seq("--std=c++17"))
    }
    annos = annos :+ TargetDirAnnotation(testDir)

    annos
  }

  // Execute the regressigiyon across a randomized range of configurations
  if (testName == "regression") (1 to numTests).foreach(config => main(testName))
  else main(testName)

  def main(testName: String): Unit = {
    behavior of testName

    // Randomize Input Variables
    val validDataWidths = Seq(8, 16, 32)
    val validPAddrWidths = Seq(8, 16, 32)
    val dataWidth = validDataWidths(Random.nextInt(validDataWidths.length))
    val addrWidth = validPAddrWidths(Random.nextInt(validPAddrWidths.length))

    // Pass in randomly selected values to DUT
    val myParams = BaseParams(8, dataWidth, addrWidth, coverage = true)

    it should "pass" in {
      info(s"Data Width = $dataWidth")
      info(s"Address Width = $addrWidth")
      info("--------------------------------")
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          dut.clock.setTimeout(0)

          // Reset Sequence
          dut.reset.poke(true.B)
          dut.clock.step()
          dut.reset.poke(false.B)

          // Buffer of randomized test data to apply in the test

          val bufferLength = 5
          val gpioDataBuffer = Seq
            .fill(bufferLength)(randData(myParams.dataWidth))

          testName match {
            case "directionRegister" => basicRegisterRW
                .directionRegister(dut, gpioDataBuffer, myParams)
            case "modeRegister" => basicRegisterRW
                .modeRegister(dut, gpioDataBuffer, myParams)
            case "outputRegister" => basicRegisterRW
                .outputRegister(dut, gpioDataBuffer, myParams)
            case "inputRegister" => basicRegisterRW
                .inputRegister(dut, gpioDataBuffer, myParams)
            case "invalidAddress" => basicRegisterRW
                .invalidAddress(dut, gpioDataBuffer, myParams)
            case "basicRegisterRW" => basicRegisterRW
                .basicRegisterRW(dut, gpioDataBuffer, myParams)

            case "maskingAnd" => maskingRegisters
                .maskingAnd(dut, gpioDataBuffer, myParams)
            case "maskingRegisters" => maskingRegisters
                .maskingRegisters(dut, gpioDataBuffer, myParams)

            case "triggerHigh" => interruptTriggers
                .triggerHigh(dut, gpioDataBuffer, myParams)
            case "triggerLow" => interruptTriggers
                .triggerLow(dut, gpioDataBuffer, myParams)
            case "triggerRising" => interruptTriggers
                .triggerRising(dut, gpioDataBuffer, myParams)
            case "triggerFalling" => interruptTriggers
                .triggerFalling(dut, gpioDataBuffer, myParams)
            case "interruptTriggers" => interruptTriggers
                .interruptTriggers(dut, gpioDataBuffer, myParams)

            case "virtualMapping" => virtualPorts
                .virtualMapping(dut, gpioDataBuffer, myParams)
            case "virtualInput" => virtualPorts
                .virtualInput(dut, gpioDataBuffer, myParams)
            case "virtualToPhysical" => virtualPorts
                .virtualToPhysical(dut, gpioDataBuffer, myParams)
            case "virtualWritting" => virtualPorts
                .virtualWritting(dut, gpioDataBuffer, myParams)
            case "disableVirtual" => virtualPorts
                .disableVirtual(dut, gpioDataBuffer, myParams)
            case "invalidVirtual" => virtualPorts
                .invalidVirtual(dut, gpioDataBuffer, myParams)
            case "disabledVirtualRead" => virtualPorts
                .disabledVirtualRead(dut, gpioDataBuffer, myParams)
            case "overlappingVirtualPorts" => virtualPorts
                .overlappingVirtualPorts(dut, gpioDataBuffer, myParams)
            case "virtualPorts" => virtualPorts
                .virtualPorts(dut, gpioDataBuffer, myParams)

            case "pushPullMode" => modeOperation
                .pushPullMode(dut, gpioDataBuffer, myParams)
            case "openDrainMode" => modeOperation
                .drainMode(dut, gpioDataBuffer, myParams)
            case "modeOperation" => modeOperation
                .modeOperation(dut, gpioDataBuffer, myParams)

            case "allTests" => allTests(dut, gpioDataBuffer, myParams)
            case "regression" => allTests(dut, gpioDataBuffer, myParams)
            case _ => println("Invalid group specified.")
          }
        }

      // Check that all ports have toggled and print report
      if (myParams.coverage) {
        val coverage = cov.getAnnotationSeq
          .collectFirst { case a: TestCoverage => a.counts }.get.toMap

        val testConfig = myParams.dataWidth.toString + "_" +
          myParams.addrWidth.toString

        val buildRoot = sys.env.get("BUILD_ROOT")
        if (buildRoot.isEmpty) {
          println("BUILD_ROOT not set, please set and run again")
          System.exit(1)
        }
        // path join
        val scalaCoverageDir = new File(buildRoot.get + "/cov/scala")
        val verCoverageDir = new File(buildRoot.get + "/cov/verilog")
        verCoverageDir.mkdir()
        val coverageFile = verCoverageDir.toString + "/" + testName + "_" +
          testConfig + ".cov"

        val stuckAtFault = checkCoverage(coverage, coverageFile)
        if (stuckAtFault) println(
          s"WARNING: At least one IO port did not toggle -- see $coverageFile",
        )
        info(s"Verilog Coverage report written to $coverageFile")
      }

    }
  }

  def allTests(dut: Gpio, gpioDataBuffer: Seq[UInt], myParams: BaseParams): Unit = {
    basicRegisterRW.basicRegisterRW(dut, gpioDataBuffer, myParams)
    modeOperation.modeOperation(dut, gpioDataBuffer, myParams)
    interruptTriggers.interruptTriggers(dut, gpioDataBuffer, myParams)
    maskingRegisters.maskingRegisters(dut, gpioDataBuffer, myParams)
    virtualPorts.virtualPorts(dut, gpioDataBuffer, myParams)
    virtualPorts.virtualPorts(dut, gpioDataBuffer, myParams)
  }
}
