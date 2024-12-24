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
    extends AnyFlatSpec
    with ChiselScalatestTester
    with Matchers
    with ApbUtils {

  val verbose = false
  val numTests = 2
  val testName = System.getProperty("testName")
  println(s"Argument passed: $testName")

  // System properties for flags
  val enableVcd = System.getProperty("enableVcd", "false").toBoolean
  val enableFst = System.getProperty("enableFst", "true").toBoolean
  val useVerilator = System.getProperty("useVerilator", "false").toBoolean

  val buildRoot = sys.env.get("BUILD_ROOT_RELATIVE")
  if (buildRoot.isEmpty) {
    println("BUILD_ROOT_RELATIVE not set, please set and run again")
    System.exit(1)
  }
  val testDir = buildRoot.get + "/test"

  println(
    s"Test: $testName, VCD: $enableVcd, FST: $enableFst, Verilator: $useVerilator"
  )

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
  if (testName == "regression") (1 to numTests).foreach { config => 
    main(s"GPIO_test_config_$config")
  }
  else {
    main(testName)
  }

  def main(testName: String): Unit = {
    behavior of testName

    // Randomize Input Variables
    // Randomize Input Variables
    val validGpioWidths = Seq(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
    val validPDataWidths = Seq(8, 16, 32)
    val validPAddrWidths = Seq(8, 16, 32)
    val PDATA_WIDTH = validPDataWidths(Random.nextInt(validPDataWidths.length))
    val PADDR_WIDTH = validPAddrWidths(Random.nextInt(validPAddrWidths.length))
    val gpioWidth = {
      val eligibleWidths = validGpioWidths.filter(_ <= PDATA_WIDTH)
      eligibleWidths(Random.nextInt(eligibleWidths.length))
    }
    // Ensure PDATA_WIDTH is equal to dataWidth
    assert(
      gpioWidth <= PDATA_WIDTH,
      s"PDATA_WIDTH ($PDATA_WIDTH) should be >= gpioWidth ($gpioWidth)"
    )

    // Pass in randomly selected values to DUT
    val myParams =
      BaseParams(8, gpioWidth, PDATA_WIDTH, PADDR_WIDTH, coverage = true)

    //it should "pass" in {
      info(s"Gpio Width = $gpioWidth")
      info(s"APB Data Width = $PDATA_WIDTH")
      info(s"Address Width = $PADDR_WIDTH")
      info("--------------------------------")
      //val cov = test(new Gpio(myParams))
      //  .withAnnotations(backendAnnotations) { dut =>
      //    dut.clock.setTimeout(0)

          // Reset Sequence
          //dut.reset.poke(true.B)
          //dut.clock.step()
          //dut.reset.poke(false.B)

          // Buffer of randomized test data to apply in the test

          val bufferLength = 5
          val gpioDataBuffer = Seq
            .fill(bufferLength)(randData(myParams.gpioWidth))
          val apbDataBuffer = Seq
            .fill(bufferLength)(randData(myParams.PDATA_WIDTH))

          testName match {
            case "directionRegister" =>
              it should "test directionRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.directionRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "modeRegister" =>
              it should "test modeRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.modeRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)                  
              }

            case "outputRegister" =>
              it should "test outputRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.outputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)                
              }

            case "inputRegister" =>
              it should "test inputRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.inputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "invalidAddress" =>
              it should "test invalidAddress" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.invalidAddress(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "basicRegisterRW" =>
              basicRegisterRWFull(gpioDataBuffer, apbDataBuffer, myParams)

            case "maskingAnd" =>
              it should "test maskingAnd" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    maskingRegisters.maskingAnd(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "maskingRegisters" =>
              maskingRegistersFull(gpioDataBuffer, apbDataBuffer, myParams)

            case "triggerHigh" =>
              it should "test triggerHigh" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerHigh(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "triggerLow" =>
              it should "test triggerLow" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerLow(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "triggerRising" =>
              it should "test triggerRising" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerRising(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "triggerFalling" =>
              it should "test triggerFalling" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerFalling(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "interruptTriggers" =>
              interruptTriggersFull(gpioDataBuffer, apbDataBuffer, myParams)

            case "virtualMapping" =>
              it should "test virtualMapping" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualMapping(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "virtualInput" =>
              it should "test virtualInput" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualInput(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "virtualToPhysical" =>
              it should "test virtualToPhysical" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualToPhysical(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "virtualWritting" =>
              it should "test virtualWritting" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualWritting(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "disableVirtual" =>
              it should "test disableVirtual" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.disableVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "invalidVirtual" =>
              it should "test invalidVirtual" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.invalidVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "disabledVirtualRead" =>
              it should "test disabledVirtualRead" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.disabledVirtualRead(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "overlappingVirtualPorts" =>
              it should "test overlappingVirtualPorts" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.overlappingVirtualPorts(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "virtualPorts" =>
              virtualPortsFull(gpioDataBuffer, apbDataBuffer, myParams)

            case "pushPullMode" =>
              it should "test pushPullMode" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    modeOperation.pushPullMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "openDrainMode" =>
              it should "test openDrainMode" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    modeOperation.drainMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollection(cov.getAnnotationSeq, myParams, testName)
              }

            case "modeOperation" =>
              modeOperationFull(gpioDataBuffer, apbDataBuffer, myParams)

            case "allTests" =>
              allTests(gpioDataBuffer, apbDataBuffer, myParams)

            case _ => allTests(gpioDataBuffer, apbDataBuffer, myParams)
          }
        }
      
    //}

  def allTests(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    basicRegisterRWFull(gpioDataBuffer, apbDataBuffer, myParams)
    modeOperationFull(gpioDataBuffer, apbDataBuffer, myParams)
    interruptTriggersFull(gpioDataBuffer, apbDataBuffer, myParams)
    maskingRegistersFull(gpioDataBuffer, apbDataBuffer, myParams)
    virtualPortsFull(gpioDataBuffer, apbDataBuffer, myParams)
  }

  def basicRegisterRWFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {

    it should "test directionRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.directionRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test modeRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.modeRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test outputRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.outputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test inputRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.inputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test invalidAddress" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
          basicRegisterRW.invalidAddress(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }
  }

  def interruptTriggersFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    it should "test triggerHigh" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerHigh(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test triggerLow" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerLow(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test triggerRising" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerRising(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test triggerFalling" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerFalling(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }
  }

  def maskingRegistersFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    it should "test maskingAnd" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          maskingRegisters.maskingAnd(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }
  }

  def virtualPortsFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    it should "test virtualMapping" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualMapping(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test virtualInput" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualInput(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test virtualToPhysical" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualToPhysical(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test virtualWritting" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualWritting(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test disableVirtual" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.disableVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test invalidVirtual" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.invalidVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test disabledVirtualRead" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.disabledVirtualRead(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test overlappingVirtualPorts" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.overlappingVirtualPorts(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }
  }

  def modeOperationFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    it should "test pushPullMode" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          modeOperation.pushPullMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }

    it should "test openDrainMode" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          modeOperation.drainMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollection(cov.getAnnotationSeq, myParams, testName)
    }
  }

  def coverageCollection(
    cov: Seq[Annotation],
    myParams: BaseParams,
    testName: String
    ): Unit = {
    if (myParams.coverage) {
      val coverage = cov
        .collectFirst { case a: TestCoverage => a.counts }
        .get
        .toMap

      val testConfig =
        myParams.gpioWidth.toString + "_" + myParams.PDATA_WIDTH.toString + "_" +
          myParams.PADDR_WIDTH.toString

      val buildRoot = sys.env.get("BUILD_ROOT")
      if (buildRoot.isEmpty) {
        println("BUILD_ROOT not set, please set and run again")
        System.exit(1)
      }
      // path join
      val scalaCoverageDir = new File(buildRoot.get + "/cov/scala")
      val verCoverageDir = new File(buildRoot.get + "/cov/verilog")
      verCoverageDir.mkdirs()
      val coverageFile = verCoverageDir.toString + "/" + testName + "_" +
        testConfig + ".cov"

      val stuckAtFault = checkCoverage(coverage, coverageFile)
      if (stuckAtFault)
        println(
          s"WARNING: At least one IO port did not toggle -- see $coverageFile"
        )
      info(s"Verilog Coverage report written to $coverageFile")
    }
  }
}


