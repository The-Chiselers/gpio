package tech.rocksavage.chiselware.Gpio

import scala.math.pow
import scala.util.Random

//import TestUtils._
import chisel3._
import chisel3.util._
import chiseltest._

object virtualPorts extends ApbUtils {

  def virtualMapping(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test mapping of virtual ports to physical ports
    println("Test Virtual Port to Physical Port Mapping")
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_MAP_ADDR.U,
      5.U
    ) // Assign virtual port to physical port 5
    val virtualPortMapping = readApb(dut, dut.regs.VIRTUAL_PORT_MAP_ADDR.U)
    println(s"Virtual Port Mapping Read: ${virtualPortMapping.toString()}")
    require(virtualPortMapping == 5)
  }

  def virtualWritting(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test: output from a virtual port
    println("Test: Writing to a virtual port")
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U,
      1.U
    ) // Write 0b1 to the virtual port output
    val virtualPortOutput = readApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U
    ) // Read back the virtual port output
    println(s"Virtual Port Output: ${virtualPortOutput.toString()}")
    require(virtualPortOutput == 1)
  }

  def virtualToPhysical(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test: Verify the output of a physical port after writing to the virtual port
    println("Test: Verify physical port output after virtual port write")
    writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 0.U)
    writeApb(dut, dut.regs.OUTPUT_ADDR.U, 0.U) // Clear the physical port output
    writeApb(
      dut,
      dut.regs.DIRECTION_ADDR.U,
      32.U
    ) // Set the direction to output
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_MAP_ADDR.U,
      5.U
    ) // Map virtual port to physical port 5
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U,
      1.U
    ) // Enable virtual port 1
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U,
      1.U
    ) // Write to virtual port
    val physicalPortOutput =
      readApb(
        dut,
        dut.regs.OUTPUT_ADDR.U
      ) & 0x20 // Read back the physical port output
    println(s"Physical Port Output (Port 5): ${physicalPortOutput.toString()}")
    require(physicalPortOutput == 32) // Expect physical port output to be 1
  }

  def disableVirtual(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test: Disable virtual port and check physical port output
    println("Test: Disable virtual port and verify physical port output")
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U,
      0.U
    ) // Disable virtual port
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U,
      0.U
    ) // Write 0 to the virtual port output
    val disabledPhysicalPortOutput =
      readApb(
        dut,
        dut.regs.OUTPUT_ADDR.U
      ) & 0x20 // Read back the physical port output
    println(
      s"Physical Port Output after disabling virtual port: ${disabledPhysicalPortOutput.toString()}"
    )
    require(
      disabledPhysicalPortOutput == 0
    ) // Expect physical port output to be set back after disabling virtual port
  }

  def invalidVirtual(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {

    // Test: Invalid virtual port mapping (out of range)
    println("Test: Invalid virtual port mapping")
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_MAP_ADDR.U,
      32.U
    ) // Try to map virtual port to an invalid physical pin
    val invalidVirtualPortMapping =
      readApb(dut, dut.regs.VIRTUAL_PORT_MAP_ADDR.U)
    println(
      s"Invalid Virtual Port Mapping: ${invalidVirtualPortMapping.toString()}"
    )
    require(invalidVirtualPortMapping == 0) // Expect no mapping to occur (0)
  }

  def disabledVirtualRead(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test: Read from a disabled virtual port
    println("Test: Read from disabled virtual port")
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U,
      0.U
    ) // Disable virtual port
    val disabledVirtualPortRead =
      readApb(dut, dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U)
    println(
      s"Disabled Virtual Port Read: ${disabledVirtualPortRead.toString()}"
    )
    require(
      disabledVirtualPortRead == 0
    ) // Expect disabled virtual port to read as 0
  }

  def overlappingVirtualPorts(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {

    // Test: Overlapping virtual ports mapped to the same physical port
    println("Test: Overlapping virtual ports mapped to the same physical port")
    writeApb(dut, dut.regs.OUTPUT_ADDR.U, 0.U) // Clear physical port output
    writeApb(dut, dut.regs.DIRECTION_ADDR.U, 32.U) // Set direction to output
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_MAP_ADDR.U,
      5.U
    ) // Map virtual port 0 to physical port 5
    writeApb(
      dut,
      (dut.regs.VIRTUAL_PORT_MAP_ADDR + 1).U,
      5.U
    ) // Map virtual port 1 to physical port 5 (overlap)
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U,
      1.U
    ) // Enable virtual ports

    // Write to virtual port 0
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U,
      1.U
    ) // Write 1 to virtual port 0
    val physicalPortOutput0 =
      readApb(
        dut,
        dut.regs.OUTPUT_ADDR.U
      ) & 0x20 // Check physical port 5 output
    println(
      s"Physical Port Output after virtual port 0 write: ${physicalPortOutput0.toString()}"
    )
    require(physicalPortOutput0 == 32) // Expect physical port 5 to be 1

    // Write to virtual port 1 (overlapping port)
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U,
      0.U
    ) // Write 0 to virtual port 1
    val physicalPortOutput1 =
      readApb(dut, dut.regs.OUTPUT_ADDR.U) // Check physical port 5 output again
    println(
      s"Physical Port Output after virtual port 1 write: ${physicalPortOutput1.toString()}"
    )
    require(
      physicalPortOutput1 == 0
    ) // Expect physical port 5 to be 0 (overlap caused change)
  }

  def virtualInput(
      dut: Gpio,
      gpioDataBuffer: Seq[UInt],
      apbDataBuffer: Seq[UInt],
      myParams: BaseParams
  ): Unit = {
    // Test: when virtual port is input
    println("Test: Virtual Port as Input")
    writeApb(dut, dut.regs.DIRECTION_ADDR.U, 0.U) // Set direction to input
    dut.io.in.poke(32.U) // write 32 to input
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_MAP_ADDR.U,
      5.U
    ) // Map virtual port 0 to physical port 5
    writeApb(
      dut,
      dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U,
      1.U
    ) // Enable virtual port
    val physicalPortOutputInput =
      readApb(
        dut,
        dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U
      ) // Check physical port 5 output
    println(
      s"Physical Port Output when virtual port is input: ${physicalPortOutputInput.toString()}"
    )
    require(physicalPortOutputInput == 1) // Expect physical port 5 to be 0
  }

}
