package tech.rocksavage.chiselware.GPIO

import java.io.BufferedWriter
import java.io.File
import java.io.FileWriter
import java.io.PrintWriter

import scala.collection.immutable.ListMap
import scala.collection.mutable.Stack
import scala.math.pow
import scala.util.Random

import org.scalatest.Assertions._
import org.scalatest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import firrtl2.options.TargetDirAnnotation

class GPIOTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {

  val myParams = BaseParams(
    dataWidth = 32,
    coverage = false,
    physicalPorts = 1,
    virtualPorts = 1,
  )
  "GPIO" should "work" in test(new GPIO(myParams)) { dut =>
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
    writeAPB(2.U, 30.U) // Write 0b1010 to OUTPUT
    val outputData = readAPB(2.U)
    println(s"Output Register Read: ${outputData.toString()}") // Should be 10
    require(outputData == 30)

    // Test 2: Write to DIRECTION register and read back
    println("Test 2: Write to DIRECTION register")
    writeAPB(1.U, 31.U) // Set DIRECTION to all outputs
    val gpioO = readAPB(1.U) // Read DIRECTION Register
    println(s"GPIO_O after DIRECTION set: ${gpioO.toString()}")
    require(gpioO == 31)

    // Test 3: Write to MODE register and read back
    println("Test 3: Write to MODE register")
    writeAPB(0.U, 30.U) // Set DIRECTION to all outputs
    val MODE = readAPB(0.U) // Read DIRECTION Register
    println(s"After MODE set: ${MODE.toString()}")
    require(MODE == 30)

    // Test PPL and Open-Drain Mode:
    val PPL = dut.io.pins.GPIO_O.peekInt()
    println(s"Output Reg: ${outputData.toString(2)}")
    println(s"Direction Reg: ${gpioO.toString(2)}")
    println(s"Mode Reg: ${MODE.toString(2)}")
    println(s"GPIO_O: ${PPL.toString(2)}")
    println(s"GPIO_OE: ${dut.io.pins.GPIO_OE.peekInt().toString(2)}")

    /*
      val PPL: Array[BigInt] = new Array[BigInt](myParams.dataWidth)
      for (i <- 0 until myParams.dataWidth) {
        PPL(i) = dut.io.pins.GPIO_O(i).peekInt()
        println(
          s"${PPL(i)}"
        )
      }
     */

    // Test 4: Test reading of INPUT register
    println("Test 4: INPUT Register")
    dut.io.pins.GPIO_I.poke(16.U)
    val gpioI = readAPB(8.U) // Read DIRECTION Register
    println(s"GPIO_I after Input set: ${gpioI.toString()}")
    require(gpioI == 16)

    // Test 5: Invalid address handling
    println("Test 5: Invalid address handling")
    dut.io.apb.PADDR.poke(10.U) // Invalid address
    dut.clock.step(1)
    require(dut.io.apb.PSLVERR.peekInt() == 1) // Should set error signal

    // Test 6: Test Atomic Set
    println("Test 6: Atomic Set")
    writeAPB(dut.regs.ATOMIC_OPERATION_ADDR.U, 4.U) // Write 0b0010 to ATOMIC_OPERATION (AND bits to zero)
    writeAPB(dut.regs.ATOMIC_MASK_ADDR.U, 12.U) // Write 0b1100 to ATOMIC_MASK
    // set all regs to output 1
    writeAPB(dut.regs.OUTPUT_ADDR.U, 15.U) // Write 0b1111 to OUTPUT
    // require outputs to be 0b1100
    val outputDataBefore = readAPB(dut.regs.OUTPUT_ADDR.U)
    println(s"Output Register Read Before: ${outputDataBefore.toString()}") // Should be 12
    require(outputDataBefore == 15)
    writeAPB(dut.regs.ATOMIC_SET_ADDR.U, 1.U)
    val outputDataAfter = readAPB(dut.regs.OUTPUT_ADDR.U)
    println(s"Output Register Read After: ${outputDataAfter.toString()}") // Should be 12
    require(outputDataAfter == 12)
  }

}
