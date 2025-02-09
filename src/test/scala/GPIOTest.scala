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
//import TestUtils.checkCoverage
//import TestUtils.randData
import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import chiseltest.simulator._
import firrtl2.AnnotationSeq
import firrtl2.annotations.Annotation // Correct Annotation type for firrtl2
import firrtl2.options.TargetDirAnnotation
import tech.rocksavage.test._

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

    val covDir   = "./out/cov"
    val coverage = true
    // Randomize Input Variables
    // Randomize Input Variables
    val validGpioWidths = Seq(8, 16, 32)
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
    val configName = "8_" + gpioWidth.toString + "_" + PDATA_WIDTH.toString + "_" + PADDR_WIDTH.toString

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
            .fill(bufferLength)(TestUtils.randData(myParams.gpioWidth))
          val apbDataBuffer = Seq
            .fill(bufferLength)(TestUtils.randData(myParams.PDATA_WIDTH))

          testName match {
            case "directionRegister" =>
              it should "test directionRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.directionRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "modeRegister" =>
              it should "test modeRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.modeRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )                  
              }

            case "outputRegister" =>
              it should "test outputRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.outputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )                
              }

            case "inputRegister" =>
              it should "test inputRegister" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.inputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "invalidAddress" =>
              it should "test invalidAddress" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    basicRegisterRW.invalidAddress(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "basicRegisterRW" =>
              basicRegisterRWFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case "maskingAnd" =>
              it should "test maskingAnd" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    maskingRegisters.maskingAnd(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "maskingAndMode" =>
              it should "test maskingAndMode" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    maskingRegisters.maskingAndMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "maskingRegisters" =>
              maskingRegistersFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case "triggerHigh" =>
              it should "test triggerHigh" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerHigh(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "triggerLow" =>
              it should "test triggerLow" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerLow(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "triggerRising" =>
              it should "test triggerRising" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerRising(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "triggerFalling" =>
              it should "test triggerFalling" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.triggerFalling(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "combinedTriggerLevel" =>
              it should "test combinedTriggerLevel" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    interruptTriggers.combinedTriggerLevel(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                  coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "interruptTriggers" =>
              interruptTriggersFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case "virtualMapping" =>
              it should "test virtualMapping" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualMapping(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "virtualInput" =>
              it should "test virtualInput" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualInput(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "virtualToPhysical" =>
              it should "test virtualToPhysical" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualToPhysical(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "virtualWritting" =>
              it should "test virtualWritting" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.virtualWritting(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "disableVirtual" =>
              it should "test disableVirtual" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.disableVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "invalidVirtual" =>
              it should "test invalidVirtual" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.invalidVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "disabledVirtualRead" =>
              it should "test disabledVirtualRead" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.disabledVirtualRead(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "overlappingVirtualPorts" =>
              it should "test overlappingVirtualPorts" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    virtualPorts.overlappingVirtualPorts(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "virtualPorts" =>
              virtualPortsFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case "pushPullMode" =>
              it should "test pushPullMode" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    modeOperation.pushPullMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "openDrainMode" =>
              it should "test openDrainMode" in {
                val cov = test(new Gpio(myParams))
                  .withAnnotations(backendAnnotations) { dut =>
                    modeOperation.drainMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
                  }
                    coverageCollector.collectCoverage(
                    cov.getAnnotationSeq,
                    testName,
                    configName,
                    coverage,
                    covDir
                  )
              }

            case "modeOperation" =>
              modeOperationFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case "allTests" =>
              allTests(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)

            case _ => allTests(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
          }
          it should "generate cumulative coverage report" in {
            coverageCollector.saveCumulativeCoverage(coverage, covDir)
          }
        }


      
    //}

  def allTests(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {
    basicRegisterRWFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
    modeOperationFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
    interruptTriggersFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
    maskingRegistersFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
    virtualPortsFull(gpioDataBuffer, apbDataBuffer, myParams, configName, covDir, coverage)
  }

  def basicRegisterRWFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {

    it should "test directionRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.directionRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "directionRegister",
        configName,
        coverage,
        covDir
      )
    }

    it should "test modeRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.modeRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "modeRegister",
        configName,
        coverage,
        covDir
      )
    }

    it should "test outputRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.outputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "outputRegister",
        configName,
        coverage,
        covDir
      )
    }

    it should "test inputRegister" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
        basicRegisterRW.inputRegister(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "inputRegister",
        configName,
        coverage,
        covDir
      )
    }

    it should "test invalidAddress" in {
      val cov = test(new Gpio(myParams))
      .withAnnotations(backendAnnotations) { dut =>
          basicRegisterRW.invalidAddress(dut, gpioDataBuffer, apbDataBuffer, myParams)
      }
      coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "invalidAddress",
        configName,
        coverage,
        covDir
      )
    }
  }

  
  def interruptTriggersFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {
    it should "test triggerHigh" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerHigh(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "triggerHigh",
        configName,
        coverage,
        covDir
      )
    }

    it should "test triggerLow" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerLow(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "triggerLow",
        configName,
        coverage,
        covDir
      )
    }

    it should "test triggerRising" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerRising(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "triggerRising",
        configName,
        coverage,
        covDir
      )
    }

    it should "test triggerFalling" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.triggerFalling(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "triggerFalling",
        configName,
        coverage,
        covDir
      )
    }

    it should "test combinedTriggerLevel" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          interruptTriggers.combinedTriggerLevel(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "combinedTriggerLevel",
        configName,
        coverage,
        covDir
      )
    }
  }

  def maskingRegistersFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {
    it should "test maskingAnd" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          maskingRegisters.maskingAnd(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "maskingAnd",
        configName,
        coverage,
        covDir
      )
    }

    it should "test maskingAndMode" in {
     val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          maskingRegisters.maskingAndMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "maskingAndMode",
        configName,
        coverage,
        covDir
      )
    }
  }

  def virtualPortsFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {
    it should "test virtualMapping" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualMapping(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "virtualMapping",
        configName,
        coverage,
        covDir
      )
    }

    it should "test virtualInput" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualInput(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "virtualInput",
        configName,
        coverage,
        covDir
      )
    }

    it should "test virtualToPhysical" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualToPhysical(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "virtualToPhysical",
        configName,
        coverage,
        covDir
      )
    }

    it should "test virtualWriting" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.virtualWritting(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "virtualWriting",
        configName,
        coverage,
        covDir
      )
    }

    it should "test disableVirtual" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.disableVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "disableVirtual",
        configName,
        coverage,
        covDir
      )
    }

    it should "test invalidVirtual" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.invalidVirtual(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "invalidVirtual",
        configName,
        coverage,
        covDir
      )
    }

    it should "test disabledVirtualRead" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.disabledVirtualRead(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "disabledVirtualRead",
        configName,
        coverage,
        covDir
      )
    }

    it should "test overlappingVirtualPorts" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          virtualPorts.overlappingVirtualPorts(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "overlappingVirtualPorts",
        configName,
        coverage,
        covDir
      )
    }
  }

  def modeOperationFull(
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams,
      configName: String,
      covDir: String,
      coverage: Boolean
  ): Unit = {
    it should "test pushPullMode" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          modeOperation.pushPullMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "pushPullMode",
        configName,
        coverage,
        covDir
      )
    }

    it should "test openDrainMode" in {
      val cov = test(new Gpio(myParams))
        .withAnnotations(backendAnnotations) { dut =>
          modeOperation.drainMode(dut, gpioDataBuffer, apbDataBuffer, myParams)
        }
        coverageCollector.collectCoverage(
        cov.getAnnotationSeq,
        "openDrainMode",
        configName,
        coverage,
        covDir
      )
    }
  }
}


