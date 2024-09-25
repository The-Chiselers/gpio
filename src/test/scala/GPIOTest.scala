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
        dut.clock.step(1)
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
        dut.clock.step(1)
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

      // APB Tests
      // Test 1: Write to OUTPUT register and read back
      println("Test 1: Write to OUTPUT register")
      writeAPB(2.U, 10.U) // Write 0b1010 to OUTPUT
      val outputData = readAPB(2.U)
      println(
        s"Output Register Read: ${outputData.toString()}"
      ) // Should be 10
      require(outputData == 10)

      // Test 2: Write to DIRECTION register and read back
      println("Test 2: Write to DIRECTION register")
      writeAPB(1.U, 32.U) // Set DIRECTION to all outputs
      val gpioO = readAPB(1.U) // Read DIRECTION Register
      println(
        s"GPIO_O after DIRECTION set: ${gpioO.toString()}"
      )
      require(gpioO == 32)

      // Test 3: Write to MODE register and read back
      println("Test 3: Write to MODE register")
      writeAPB(0.U, 16.U) // Set DIRECTION to all outputs
      val MODE = readAPB(0.U) // Read DIRECTION Register
      println(
        s"After MODE set: ${MODE.toString()}"
      )
      require(MODE == 16)

      // Test 4: Test Push-Pull Mode
      // println("Test 4: Push/Pull Mode")
      // val GPIO_O = dut.GPIO_O.peek()
      // println(
      //  s"Push/Pull Mode: ${GPIO_O.toString()}"
      // )
      // require(MODE == 16)

      // Test 5: Invalid address handling
      println("Test 5: Invalid address handling")
      dut.io.apb.PADDR.poke(10.U) // Invalid address
      dut.clock.step(1)
      require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal

      /*
      // Test 4: Test reading of INPUT register
      println("Test 4: Read from INPUT register")
      val inputData = dut.io.pins.pads.poke(10.U) // Set GPIO_I input
      // val inputData = readAPB(3.U)
      println(
        s"Input Register Read: ${inputData.toString()}"
      ) // Should be 10
      require(inputData == 10)
       */

    }

  }
}
