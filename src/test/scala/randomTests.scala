package tech.rocksavage.chiselware.Gpio

import scala.math.pow
import scala.util.Random

import TestUtils._
import chisel3._
import chisel3.util._
import chiseltest._

object randomTests extends ApbUtils {

    def combinedTriggerLevel(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Combined Trigger Level High and Low")
    writeApb(dut, dut.regs.IRQ_ENABLE_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 12.U)
    writeApb(dut, dut.regs.TRIGGER_LO_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 3.U)

    // Test high level trigger
    dut.io.in.poke(3.U)
    dut.clock.step(2)
    var triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status High: ${triggerStatus.toString()}")
    require(triggerStatus == 3)

    // Test low level trigger
    dut.io.in.poke(2.U)
    dut.clock.step(2)
    triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status Low: ${triggerStatus.toString()}")
    require(triggerStatus == 1)

    clearInterrupt(dut, 0.U, 3.U)
    }

    def edgeTriggerWithAtomicAnd(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Edge Trigger with Atomic AND Operation")
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 3.U)
    writeApb(dut, dut.regs.TRIGGER_HI_ADDR.U, 3.U)
    dut.io.in.poke(0.U)
    dut.clock.step(2)

    // Trigger on rising edge
    dut.io.in.poke(7.U)
    dut.clock.step(1)
    val triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status: ${triggerStatus.toString()}")
    require(triggerStatus == 3)

    // Perform atomic AND operation
    gpioDataBuffer.foreach { data =>
        writeApb(dut, dut.regs.ATOMIC_MASK_ADDR.U, data)
        val randomOutput = Random.nextInt(Math.pow(2, myParams.PDATA_WIDTH).toInt)
        writeApb(dut, dut.regs.OUTPUT_ADDR.U, randomOutput.U)
        writeApb(dut, dut.regs.ATOMIC_SET_ADDR.U, 1.U)
        val andResult = readApb(dut, dut.regs.OUTPUT_ADDR.U)
        require(andResult == (data.litValue & randomOutput))
    }
    }

    def pushPullAndDrain(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Push-Pull and Drain Mode Validation")
    gpioDataBuffer.foreach { data =>
        // Push-Pull Mode
        writeApb(dut, dut.regs.MODE_ADDR.U, 0.U)
        writeApb(dut, dut.regs.OUTPUT_ADDR.U, data)
        writeApb(dut, dut.regs.DIRECTION_ADDR.U, 0xF.U)
        val pushPullOutput = dut.io.out.peekInt()
        require(pushPullOutput == (data.litValue & 0xF))

        // Drain Mode
        writeApb(dut, dut.regs.MODE_ADDR.U, (1 << myParams.PDATA_WIDTH).U)
        val drainOutput = dut.io.out.peekInt()
        require(drainOutput == 0)
    }
    }

    def virtualPortAndTriggerTest(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Virtual Port to Physical Port with Edge Trigger")
    writeApb(dut, dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U)
    writeApb(dut, dut.regs.VIRTUAL_PORT_ENABLE_ADDR.U, 1.U)
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 1.U) // Rising edge trigger

    // Simulate rising edge on virtual port
    dut.io.in.poke(0.U)
    dut.clock.step(1)
    dut.io.in.poke(32.U)
    dut.clock.step(1)
    val triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status: ${triggerStatus.toString()}")
    require(triggerStatus == 1)
    }

    def overlappingVirtualPortsAndAtomic(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Overlapping Virtual Ports and Atomic Operations")
    writeApb(dut, dut.regs.OUTPUT_ADDR.U, 0.U) // Clear physical port output
    writeApb(dut, dut.regs.DIRECTION_ADDR.U, 32.U) // Set direction to output
    writeApb(dut, dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U) // Map virtual port 0
    writeApb(dut, (dut.regs.VIRTUAL_PORT_MAP_ADDR + 1).U, 5.U) // Overlap virtual port 1

    // Perform atomic AND operation
    gpioDataBuffer.foreach { data =>
        writeApb(dut, dut.regs.ATOMIC_MASK_ADDR.U, data)
        writeApb(dut, dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 1.U)
        val atomicResult = readApb(dut, dut.regs.OUTPUT_ADDR.U)
        println(s"Atomic AND Result: ${atomicResult.toString()}")
        require(atomicResult == (data.litValue & 32))
    }
    }

    // Additional tests added below
    def combinedModeAndTrigger(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Combined Mode Operation with Trigger")
    writeApb(dut, dut.regs.MODE_ADDR.U, 0.U)
    writeApb(dut, dut.regs.OUTPUT_ADDR.U, 5.U)
    writeApb(dut, dut.regs.TRIGGER_TYPE_ADDR.U, 3.U)

    // Simulate trigger
    dut.io.in.poke(3.U)
    dut.clock.step(1)
    val triggerStatus = readApb(dut, dut.regs.TRIGGER_STATUS_ADDR.U)
    println(s"Trigger Status: ${triggerStatus.toString()}")
    require(triggerStatus == 3)
    }

    def virtualAndDrain(
        dut: Gpio,
        gpioDataBuffer: Seq[UInt],
        apbDataBuffer: Seq[UInt],
        myParams: BaseParams
    ): Unit = {
    println("Test: Virtual Port with Drain Mode")
    writeApb(dut, dut.regs.VIRTUAL_PORT_MAP_ADDR.U, 5.U)
    writeApb(dut, dut.regs.MODE_ADDR.U, (1 << myParams.PDATA_WIDTH).U)
    writeApb(dut, dut.regs.VIRTUAL_PORT_OUTPUT_ADDR.U, 1.U)

    // Verify drain mode behavior
    val drainOutput = readApb(dut, dut.regs.OUTPUT_ADDR.U)
    println(s"Drain Mode Output: ${drainOutput.toString()}")
    require(drainOutput == 0)
    }

}