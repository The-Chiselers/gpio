package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import org.scalatest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.Assertions._
import firrtl2.options.TargetDirAnnotation
import scala.util.Random
import scala.math.pow
import scala.collection.mutable.Stack
import scala.collection.immutable.ListMap
import java.io.{File, FileWriter, PrintWriter, BufferedWriter}

class GPIOTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {

  val myParams = BaseParams(
    dataWidth = 32,
    coverage = false,
    physicalPorts = 1,
    virtualPorts = 1
  )
  "GPIO" should "work" in {

    test(new GPIO(myParams)) { dut =>
      def writeAPB(addr: UInt, data: UInt): Unit = {
        dut.io.apb.PSEL.poke(1) // Select GPIO Slave
        dut.io.apb.PENABLE.poke(1) // Enable APB
        dut.io.apb.PWRITE.poke(1) // Write mode
        dut.io.apb.PADDR.poke(addr)
        dut.io.apb.PWDATA.poke(data)
        dut.clock.step(1) // TODO: Should test this with variable wait states
        dut.io.apb.PSEL.poke(0) // Select GPIO Slave
        dut.io.apb.PENABLE.poke(0) // Enable APB
        dut.clock.step(2)
      }

      def readAPB(addr: UInt): BigInt = {
        dut.io.apb.PSEL.poke(1) // Select APB
        dut.io.apb.PENABLE.poke(1) // Enable APB
        dut.io.apb.PWRITE.poke(0) // Read mode
        dut.io.apb.PADDR.poke(addr)
        dut.clock.step(1)
        val readValue = dut.io.apb.PRDATA.peekInt() // Return read data
        dut.clock.step(1) // Step for the read operation
        dut.io.apb.PSEL.poke(0) // Select GPIO Slave
        dut.io.apb.PENABLE.poke(0) // Enable APB
        dut.clock.step(2)
        readValue
      }

      // Test 1: Write to OUTPUT register and read back
      println("Test 1: Write to OUTPUT register")
      writeAPB(0.U, 10.U) // Write 0b1010 to OUTPUT
      val outputData = readAPB(0.B)
      println(
        s"Output Register Read: ${outputData.toString()}"
      ) // Should be 10
      require(outputData == 10)

      // Test 2: Write to DIRECTION register and verify GPIO_O
      println("Test 2: Write to DIRECTION register")
      writeAPB(4.U, 15.U) // Set DIRECTION to all outputs
      val gpioO = dut.io.pins.GPIO_O.peekInt()
      println(
        s"GPIO_O after DIRECTION set: ${gpioO.toString()}"
      ) // Should reflect OUTPUT
      require(gpioO == 10) // Should match the last written OUTPUT

      // Test 3: Change OUTPUT and verify GPIO_O again
      println("Test 3: Change OUTPUT register")
      writeAPB(0.U, 12.U) // Write 0b1100 to OUTPUT
      val updatedGpioO = dut.io.pins.GPIO_O.peekInt()
      println(
        s"GPIO_O after OUTPUT update: ${updatedGpioO.toString()}"
      ) // Should be 12
      require(updatedGpioO == 12)

      // Test 4: Test reading of INPUT register
      println("Test 4: Read from INPUT register")
      dut.io.pins.GPIO_I.poke(10.U) // Set GPIO_I input
      val inputData = readAPB(8.U)
      println(
        s"Input Register Read: ${inputData.toString()}"
      ) // Should be 10
      require(inputData == 10)

      // Test 5: Invalid address handling
      println("Test 5: Invalid address handling")
      dut.io.apb.PADDR.poke(10.U) // Invalid address
      dut.clock.step(1)
      require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal
    }

  }
}
