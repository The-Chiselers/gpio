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

class GPIOTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  val numTests = 5
  val verbose = false

  def main(testName: String): Unit = {
    behavior of testName

    val backendAnnotations = Seq(
      // WriteVcdAnnotation,
      // WriteFstAnnotation,
      VerilatorBackendAnnotation, // For using verilator simulator
      // IcarusBackendAnnotation,
      // VcsBackendAnnotation,
      TargetDirAnnotation(
        "generated"
      )
    )

    // Randomize Input Variables
    val validDataWidths = Seq(8, 16, 32)
    val validPDataWidths = Seq(8, 16, 32)
    val validPAddrWidths = Seq(8, 16, 32)
    val PDATA_WIDTH = validPDataWidths(Random.nextInt(validPDataWidths.length))
    val PADDR_WIDTH = validPAddrWidths(Random.nextInt(validPAddrWidths.length))
    val dataWidth = {
      val eligibleWidths = validDataWidths.filter(_ == PDATA_WIDTH)
      eligibleWidths(Random.nextInt(eligibleWidths.length))
    }
    // Ensure PDATA_WIDTH is equal to dataWidth
    assert(
      dataWidth == PDATA_WIDTH,
      s"PDATA_WIDTH ($PDATA_WIDTH) should be == dataWidth ($dataWidth)"
    )
    // Pass in randomly selected values to DUT
    val myParams = BaseParams(
      8,
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
      val cov = test(new GPIO(myParams)).withAnnotations(backendAnnotations) {
        dut =>
          dut.clock.setTimeout(0)

          def writeAPB(addr: UInt, data: UInt): Unit = {
            dut.io.apb.PSEL.poke(1) // Select GPIO Slave
            dut.clock.step(1) // Simulate Second Phase
            dut.io.apb.PENABLE.poke(1) // Enable APB
            dut.io.apb.PWRITE.poke(1) // Write mode
            dut.io.apb.PADDR.poke(addr)
            dut.io.apb.PWDATA.poke(data)
            dut.clock.step(1)
            dut.io.apb.PSEL.poke(0) // Deselect GPIO Slave
            dut.io.apb.PENABLE.poke(0) // Disable APB
            dut.clock.step(2)
          }

          def readAPB(addr: UInt): BigInt = {
            dut.io.apb.PSEL.poke(1) // Select APB
            dut.clock.step(1)
            dut.io.apb.PENABLE.poke(1) // Enable APB
            dut.io.apb.PWRITE.poke(0) // Read mode
            dut.io.apb.PADDR.poke(addr)
            dut.clock.step(1)
            val readValue = dut.io.apb.PRDATA.peekInt() // Return read data
            dut.clock.step(1) // Step for the read operation
            dut.io.apb.PSEL.poke(0) // Deselect GPIO Slave
            dut.io.apb.PENABLE.poke(0) // Disable APB
            dut.clock.step(2)
            readValue
          }

          // Reset Sequence
          dut.reset.poke(true.B)
          dut.clock.step()
          dut.reset.poke(false.B)

          // Buffer of randomized test data to apply in the test
          val gpioDataBuffer = Seq.fill(numTests)(randData(myParams.dataWidth))
          val apbDataBuffer = Seq.fill(numTests)(randData(myParams.PDATA_WIDTH))

          // Directed Tests
          println("Test 1: Write to DIRECTION register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.DIRECTION_ADDR.U, data)
            val directionData = readAPB(dut.regs.DIRECTION_ADDR.U)
            println(
              s"Direction Register Read: ${directionData.toString()}"
            )
            require(directionData == data.litValue)
          }

          println("Test 2: Write to OUTPUT register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val outputData = readAPB(dut.regs.OUTPUT_ADDR.U)
            println(
              s"Output Register Read: ${outputData.toString()}"
            )
            require(outputData == data.litValue)
          }

          println("Test 3: Write to INPUT register")
          gpioDataBuffer.foreach { data =>
            dut.io.pins.gpioInput.poke(data)
            val inputData = readAPB(dut.regs.INPUT_ADDR.U)
            println(
              s"Input Register Read: ${inputData.toString()}"
            )
            require(inputData == data.litValue)
          }

          println("Test 4: Write to MODE register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.MODE_ADDR.U, data)
            val modeData = readAPB(dut.regs.MODE_ADDR.U)
            println(s"Mode Register Read: ${modeData.toString()}")
            require(modeData == data.litValue)
          }

          println("Test 5: Test Atomic AND Register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 0.U)
            writeAPB(dut.regs.ATOMIC_OPERATION_ADDR.U, 4.U)
            writeAPB(dut.regs.ATOMIC_MASK_ADDR.U, data)
            val randomOutputData = Random.nextInt(1 << myParams.dataWidth)
            writeAPB(dut.regs.OUTPUT_ADDR.U, randomOutputData.U)
            val outputDataBeforeSet = readAPB(dut.regs.OUTPUT_ADDR.U)
            println(
              s"Output Register Read Before Set: ${outputDataBeforeSet.toString()}"
            )
            require(outputDataBeforeSet == randomOutputData)
            writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 1.U)
            val outputDataAfterSet = readAPB(dut.regs.OUTPUT_ADDR.U)
            println(
              s"Output Register Read After Set: ${outputDataAfterSet.toString()}"
            )
            val andOperation = data.litValue & randomOutputData
            require(outputDataAfterSet == andOperation)
          }

          // Test 8: Invalid Address Handling
          println("Test 8: Invalid Address Handling")
          val invalidAddr = (dut.regs.ATOMIC_SET_ADDR_MAX + 1)
          writeAPB(invalidAddr.U, 15.U)
          dut.clock.step(1)
          require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal
          dut.clock.step(1)
          val readData = readAPB(invalidAddr.U)
          dut.clock.step(1)
          require(dut.io.apb.PSLVERR.peekInt() == 1)
          require(readData == 0)

          /*
          val fullOnes = (BigInt(1) << myParams.PDATA_WIDTH) - 1
          println("Test 6: Push-Pull Mode Operation")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.MODE_ADDR.U, fullOnes.U)
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val randomDirectionData = Random.nextInt(1 << myParams.dataWidth)
            writeAPB(dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
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
           */

          /*
          val fullZeros = (BigInt(0) << myParams.PDATA_WIDTH) - 1
          println("Test 7: Drain Mode Operation")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.MODE_ADDR.U, fullZeros.U)
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val randomDirectionData = Random.nextInt(1 << myParams.dataWidth)
            writeAPB(dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
            val actualValOutput = dut.io.pins.gpioOutput.peekInt()
            println(
              s"Expected Output Register after PPL Set: ${expectedValOutput.toString()}"
            )
            println(
              s"Output Register after PPL Set: ${actualValOutput.toString()}"
            )
            require(0 == actualValOutput)
            for(i <- 0 until myParams.dataWidth) {
              val expectedValOutputEnable = ~data
            }
            val actualValOutputEnable = dut.io.pins.gpioOutputEnable.peekInt()
            println(
              s"Direction Register after PPL Set: ${actualValOutputEnable.toString()}"
            )
            require(randomDirectionData == actualValOutputEnable)
          }
           */
      }

      // Check that all ports have toggled and print report
      if (myParams.coverage) {
        val coverage = cov.getAnnotationSeq
          .collectFirst { case a: TestCoverage => a.counts }
          .get
          .toMap

        val testConfig =
          myParams.dataWidth.toString + "_" +
            myParams.PDATA_WIDTH.toString + "_" +
            myParams.PADDR_WIDTH.toString

        val verCoverageDir = new File("generated/verilogCoverage")
        verCoverageDir.mkdir()
        val coverageFile =
          verCoverageDir.toString + "/" + testName + "_" + testConfig + ".cov"

        val stuckAtFault = checkCoverage(coverage, coverageFile)
        if (stuckAtFault)
          println(
            s"WARNING: At least one IO port did not toggle -- see $coverageFile"
          )
        info(s"Verilog Coverage report written to $coverageFile")
      }

    }
  }

  // Create a directory for storing coverage reportsG
  val scalaCoverageDir = new File("generated/scalaCoverage")
  scalaCoverageDir.mkdir()

  // Execute the regressigiyon across a randomized range of configurations
  (1 to numTests).foreach { config =>
    main(s"GPIO_test_config_$config")
  }

}
