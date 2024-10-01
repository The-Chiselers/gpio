package tech.rocksavage.chiselware.GPIO

import java.io.BufferedWriter
import java.io.File
import java.io.FileWriter
import java.io.PrintWriter
import java.{util => ju}

import scala.collection.immutable.ListMap
import scala.collection.mutable.Stack
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
import chiseltest.simulator.VerilatorCFlags
import firrtl2.options.TargetDirAnnotation

/** Highly randomized test suite driven by configuration parameters. Includes
  * code coverage for all top-level ports. Inspired by the DynamicFifo
  */

class GPIOTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  val numTests = 1
  val verbose = false

  def main(testName: String): Unit = {
    behavior of testName

    val backendAnnotations = Seq(
      // WriteVcdAnnotation,
      // WriteFstAnnotation,
      // VerilatorBackendAnnotation, // For using verilator simulator
      // IcarusBackendAnnotation,
      // VcsBackendAnnotation,
      TargetDirAnnotation("generated"),
      VerilatorBackendAnnotation,
      VerilatorCFlags(Seq("--std=c++17")),
      WriteFstAnnotation,
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
      s"PDATA_WIDTH ($PDATA_WIDTH) should be == dataWidth ($dataWidth)",
    )
    // Pass in randomly selected values to DUT
    val myParams =
      BaseParams(8, dataWidth, PDATA_WIDTH, PADDR_WIDTH, coverage = true)

    it should "pass" in {
      info(s"Data Width = $dataWidth")
      info(s"PDATA_WIDTH = $PDATA_WIDTH")
      info(s"PADDR_WIDTH = $PADDR_WIDTH")
      info("--------------------------------")
      val cov = test(new GPIO(myParams))
        .withAnnotations(backendAnnotations) { dut =>
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

          def clearInterrupt(inputWrite: UInt, data: UInt): Unit = {
            // Clearing Interrupt
            dut.io.pins.gpioInput.poke(inputWrite)
            writeAPB(dut.regs.TRIGGER_STATUS_ADDR.U, data)
            readAPB(dut.regs.TRIGGER_STATUS_ADDR.U)
            dut.clock.step(2) // Wait for synchronizer
            var irqOutput = dut.io.pins.irqOutput.peekInt()
            println(s"Clearing Interrupt, irqOutput Read Value: ${irqOutput.toString()}")
            require(irqOutput == 0)
          }

          // Reset Sequence
          dut.reset.poke(true.B)
          dut.clock.step()
          dut.reset.poke(false.B)

          // Buffer of randomized test data to apply in the test
          val bufferLength = 2
          val gpioDataBuffer = Seq
            .fill(bufferLength)(randData(myParams.dataWidth))
          val apbDataBuffer = Seq
            .fill(bufferLength)(randData(myParams.PDATA_WIDTH))

          // Directed Tests
          println("Test 1: Write to DIRECTION register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.DIRECTION_ADDR.U, data)
            val directionData = readAPB(dut.regs.DIRECTION_ADDR.U)
            println(s"Direction Register Read: ${directionData.toString()}")
            require(directionData == data.litValue)
          }

          println("Test 2: Write to OUTPUT register")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val outputData = readAPB(dut.regs.OUTPUT_ADDR.U)
            println(s"Output Register Read: ${outputData.toString()}")
            require(outputData == data.litValue)
          }

          println("Test 3: Write to INPUT register")
          gpioDataBuffer.foreach { data =>
            dut.io.pins.gpioInput.poke(data)
            dut.clock.step(2) // Wait for synchronizer
            val inputData = readAPB(dut.regs.INPUT_ADDR.U)
            println(s"Input Register Read: ${inputData.toString()}")
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
            println(s"Output Register Read Before Set: ${outputDataBeforeSet.toString()}")
            require(outputDataBeforeSet == randomOutputData)
            writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 1.U)
            val outputDataAfterSet = readAPB(dut.regs.OUTPUT_ADDR.U)
            println(s"Output Register Read After Set: ${outputDataAfterSet.toString()}")
            val andOperation = data.litValue & randomOutputData
            require(outputDataAfterSet == andOperation)
          }

          writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 0.U) // When set to 1 it affects Push-Pull Mode, Interesting

          val fullOnes = (BigInt(1) << myParams.PDATA_WIDTH) - 1
          println("Test 6: Push-Pull Mode Operation")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.MODE_ADDR.U, fullOnes.U)
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val randomDirectionData = Random
              .nextInt(Math.pow(2, myParams.dataWidth).toInt)
            writeAPB(dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
            val expectedValOutput = randomDirectionData & data.litValue
            val actualValOutput = dut.io.pins.gpioOutput.peekInt()
            println(s"Expected Output Register after PPL Set: ${expectedValOutput.toString()}")
            println(
              s"Output Register after PPL Set: ${actualValOutput.toString()}",
            )
            require(expectedValOutput == actualValOutput) // Failing :(
            val actualValOutputEnable = dut.io.pins.gpioOutputEnable.peekInt()
            println(s"Direction Register after PPL Set: ${actualValOutputEnable.toString()}")
            require(randomDirectionData == actualValOutputEnable)
          }

          println("Test 7: Drain Mode Operation")
          apbDataBuffer.foreach { data =>
            writeAPB(dut.regs.MODE_ADDR.U, 0.U(myParams.PDATA_WIDTH.W))
            writeAPB(dut.regs.OUTPUT_ADDR.U, data)
            val randomDirectionData = Random
              .nextInt(Math.pow(2, myParams.dataWidth).toInt)
            writeAPB(dut.regs.DIRECTION_ADDR.U, randomDirectionData.U)
            val actualValOutput = dut.io.pins.gpioOutput.peekInt()
            println(s"Output after PPL Set: ${actualValOutput.toString()}")
            require(0 == actualValOutput)
            val expectedValOutputEnable = ~data.litValue & randomDirectionData
            val actualValOutputEnable = dut.io.pins.gpioOutputEnable.peekInt()
            println(s"Expected Output Enable after PPL Set: ${expectedValOutputEnable.toString()}")
            println(s"Output Enable after PPL Set: ${actualValOutputEnable.toString()}")
            require(expectedValOutputEnable == actualValOutputEnable)
          }

          // Test 8: Invalid Address Handling
          println("Test 8: Invalid Address Handling")
          val invalidAddr = dut.regs.IRQ_ENABLE_ADDR_MAX + 1
          writeAPB(invalidAddr.U, 15.U)
          dut.clock.step(1)
          require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal
          dut.clock.step(1)
          val readData = readAPB(invalidAddr.U)
          dut.clock.step(1)
          require(dut.io.apb.PSLVERR.peekInt() == 1)
          require(readData == 0)

          // Test 9: Test mapping of virtual ports to physical ports
          println("Test 9: Virtual Port to Physical Port Mapping")
          writeAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U) // Assign virtual port to physical port 5
          val virtualPortMapping = readAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U)
          println(s"Virtual Port Mapping Read: ${virtualPortMapping.toString()}")
          require(virtualPortMapping == 5)

          // Test 10: Test output from a virtual port
          println("Test 10: Writing to a virtual port")
          writeAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 1.U) // Write 0b1 to the virtual port output
          val virtualPortOutput = readAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U) // Read back the virtual port output
          println(s"Virtual Port Output: ${virtualPortOutput.toString()}")
          require(virtualPortOutput == 1)

          // Test 11: Verify the output of a physical port after writing to the virtual port
          println(
            "Test 11: Verify physical port output after virtual port write",
          )
          writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 0.U)
          writeAPB(dut.regs.OUTPUT_ADDR.U, 0.U) // Clear the physical port output
          writeAPB(dut.regs.DIRECTION_ADDR.U, 32.U) // Set the direction to output
          writeAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U) // Map virtual port to physical port 5
          writeAPB(dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 1.U) // Enable virtual port 1
          writeAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 1.U) // Write to virtual port
          val physicalPortOutput = readAPB(dut.regs.OUTPUT_ADDR.U) & 0x20 // Read back the physical port output
          println(
            s"Physical Port Output (Port 5): ${physicalPortOutput.toString()}",
          )
          require(physicalPortOutput == 32) // Expect physical port output to be 1

          // Test 12: Disable virtual port and check physical port output
          println(
            "Test 12: Disable virtual port and verify physical port output",
          )
          writeAPB(dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 0.U) // Disable virtual port
          writeAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 0.U) // Write 0 to the virtual port output
          val disabledPhysicalPortOutput = readAPB(dut.regs.OUTPUT_ADDR.U) &
            0x20 // Read back the physical port output
          println(s"Physical Port Output after disabling virtual port: ${disabledPhysicalPortOutput.toString()}")
          require(disabledPhysicalPortOutput == 32) // Expect physical port output to be as before

          // Test 13: Invalid virtual port mapping (out of range)
          println("Test 13: Invalid virtual port mapping")
          writeAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 32.U) // Try to map virtual port to an invalid physical pin
          val invalidVirtualPortMapping =
            readAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U)
          println(s"Invalid Virtual Port Mapping: ${invalidVirtualPortMapping.toString()}")
          require(invalidVirtualPortMapping == 0) // Expect no mapping to occur (0)

          // Test 14: Read from a disabled virtual port
          println("Test 14: Read from disabled virtual port")
          writeAPB(dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 0.U) // Disable virtual port
          val disabledVirtualPortRead =
            readAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U)
          println(
            s"Disabled Virtual Port Read: ${disabledVirtualPortRead.toString()}",
          )
          require(disabledVirtualPortRead == 0) // Expect disabled virtual port to read as 0

          // Test 15: Overlapping virtual ports mapped to the same physical port
          println("Test 15: Overlapping virtual ports mapped to the same physical port")
          writeAPB(dut.regs.OUTPUT_ADDR.U, 0.U) // Clear physical port output
          writeAPB(dut.regs.DIRECTION_ADDR.U, 32.U) // Set direction to output
          writeAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U) // Map virtual port 0 to physical port 5
          writeAPB((dut.regs.VIRTUAL_PORT_MAP_ADDR + 1).U, 5.U) // Map virtual port 1 to physical port 5 (overlap)
          writeAPB(dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 1.U) // Enable virtual ports

          // Write to virtual port 0
          writeAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 1.U) // Write 1 to virtual port 0
          val physicalPortOutput0 = readAPB(dut.regs.OUTPUT_ADDR.U) & 0x20 // Check physical port 5 output
          println(s"Physical Port Output after virtual port 0 write: ${physicalPortOutput0.toString()}")
          require(physicalPortOutput0 == 32) // Expect physical port 5 to be 1

          // Write to virtual port 1 (overlapping port)
          writeAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 0.U) // Write 0 to virtual port 1
          val physicalPortOutput1 = readAPB(dut.regs.OUTPUT_ADDR.U) // Check physical port 5 output again
          println(s"Physical Port Output after virtual port 1 write: ${physicalPortOutput1.toString()}")
          require(physicalPortOutput1 == 0) // Expect physical port 5 to be 0 (overlap caused change)

          // Test 16: when virtual port is input
          println("Test 16: Virtual Port as Input")
          writeAPB(dut.regs.DIRECTION_ADDR.U, 0.U) // Set direction to input
          dut.io.pins.gpioInput.poke(32.U) // write 32 to input
          writeAPB(dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U) // Map virtual port 0 to physical port 5
          writeAPB(dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 1.U) // Enable virtual port
          val physicalPortOutputInput =
            readAPB(dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U) // Check physical port 5 output
          println(s"Physical Port Output when virtual port is input: ${physicalPortOutputInput.toString()}")
          require(physicalPortOutputInput == 1) // Expect physical port 5 to be 0

          // Test 17: Trigger Level When High
          println("Test 17: Trigger Level When High")
          writeAPB(dut.regs.IRQ_ENABLE_ADDR.U, 3.U)
          writeAPB(dut.regs.TRIGGER_TYPE_ADDR.U, 12.U)
          writeAPB(dut.regs.TRIGGER_LVL0_ADDR.U, 12.U)
          writeAPB(dut.regs.TRIGGER_LVL1_ADDR.U, 3.U)
          dut.io.pins.gpioInput.poke(3.U)
          dut.clock.step(2) // Wait for synchronizer
          var triggerStatus = readAPB(dut.regs.TRIGGER_STATUS_ADDR.U)
          println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
          require(triggerStatus == 3)
          var irqOutput = dut.io.pins.irqOutput.peekInt()
          println(s"irqOutput Read Value: ${irqOutput.toString()}")
          require(irqOutput == 1)

          clearInterrupt(0.U, 3.U)

          // Test 18: Trigger Level When Low
          println("Test 18: Trigger Level When Low")
          writeAPB(dut.regs.TRIGGER_LVL0_ADDR.U, 3.U)
          writeAPB(dut.regs.TRIGGER_LVL1_ADDR.U, 12.U)
          dut.io.pins.gpioInput.poke(2.U)
          dut.clock.step(2) // Wait for synchronizer
          triggerStatus = readAPB(dut.regs.TRIGGER_STATUS_ADDR.U)
          println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
          require(triggerStatus == 1)
          irqOutput = dut.io.pins.irqOutput.peekInt()
          println(s"irqOutput Read Value: ${irqOutput.toString()}")
          require(irqOutput == 1)

          clearInterrupt(3.U, 1.U) // Write 1 to first 2 bits of input bc trigger level low is enabled
          // Otherwise trigger register will keep on getting updated (not cleared)

          // Test 19: Edge Trigger on Rising Edge
          println("Test 19: Edge Trigger on Rising Edge")
          writeAPB(dut.regs.TRIGGER_TYPE_ADDR.U, 3.U)
          writeAPB(dut.regs.TRIGGER_LVL0_ADDR.U, 0.U)
          writeAPB(dut.regs.TRIGGER_LVL1_ADDR.U, 3.U)
          dut.io.pins.gpioInput.poke(0.U) // Need to go low to trigger edge det
          dut.clock.step(2) // Wait for synchronizer
          dut.io.pins.gpioInput.poke(7.U)
          dut.clock.step(1) // Wait for synchronizer, triggerStatus and irqOut only high for one clock cycle
          triggerStatus = readAPB(dut.regs.TRIGGER_STATUS_ADDR.U)
          println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
          require(triggerStatus == 3)

          // Test 20: Edge Trigger on Falling Edge
          println("Test 20: Edge Trigger on Falling Edge")
          writeAPB(dut.regs.TRIGGER_LVL0_ADDR.U, 3.U)
          writeAPB(dut.regs.TRIGGER_LVL1_ADDR.U, 0.U)
          dut.io.pins.gpioInput.poke(2.U) // Need to go high to trigger edge det
          dut.clock.step(2) // Wait for synchronizer
          dut.io.pins.gpioInput.poke(0.U)
          dut.clock.step(1) // Wait for synchronizer, triggerStatus and irqOut only high for one clock cycle
          triggerStatus = readAPB(dut.regs.TRIGGER_STATUS_ADDR.U)
          println(s"Trigger Status Read Value: ${triggerStatus.toString()}")
          require(triggerStatus == 2)

        }

      // Check that all ports have toggled and print report
      if (myParams.coverage) {
        val coverage = cov.getAnnotationSeq
          .collectFirst { case a: TestCoverage => a.counts }.get.toMap

        val testConfig = myParams.dataWidth.toString + "_" +
          myParams.PDATA_WIDTH.toString + "_" + myParams.PADDR_WIDTH.toString

        val verCoverageDir = new File("generated/verilogCoverage")
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

  // Create a directory for storing coverage reports
  val scalaCoverageDir = new File("generated/scalaCoverage")
  scalaCoverageDir.mkdir()

  // Execute the regressigiyon across a randomized range of configurations
  (1 to numTests).foreach(config => main(s"GPIO_test_config_$config"))

}
