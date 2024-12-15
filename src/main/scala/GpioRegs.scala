package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._

class GpioRegs(p: BaseParams) extends Bundle {

  val addressSpaceSize = 0x10000
  val memCells = VecInit(Seq.fill(addressSpaceSize)(0.U(p.PDATA_WIDTH.W)))

  // #####################################################################
  // REGS
  // #####################################################################
  // User Accessible Control Registers
  val DIRECTION = RegInit(0.U(p.PDATA_WIDTH.W)) // RW
  val OUTPUT = RegInit(0.U(p.PDATA_WIDTH.W)) // RW
  val INPUT = RegInit(0.U(p.PDATA_WIDTH.W)) // RO
  val MODE = RegInit(0.U(p.PDATA_WIDTH.W)) // RW

  // Atomic Operations
  val ATOMIC_OPERATION = RegInit(0.U(4.W))
  val ATOMIC_MASK = RegInit(0.U(p.PDATA_WIDTH.W))
  val ATOMIC_SET = RegInit(0.U(1.W))

  // Virtual Port Control Registers
  val virtualPortOutput = RegInit(0.U(p.numVirtualPorts.W))
  // Virtual to Physical Pin Mapping
  val virtualToPhysicalMap =
    RegInit(
      VecInit(Seq.fill(p.numVirtualPorts)(0.U(p.sizeOfVirtualPorts.W)))
    )
  // Virtual Port Enable
  val virtualPortEnable = RegInit(0.U(1.W))

  // Interrupt Handling Registers
  val TRIGGER_TYPE = RegInit(0.U(p.PDATA_WIDTH.W))
  val TRIGGER_LO = RegInit(0.U(p.PDATA_WIDTH.W))
  val TRIGGER_HI = RegInit(0.U(p.PDATA_WIDTH.W))
  val TRIGGER_STATUS = RegInit(0.U(p.PDATA_WIDTH.W))
  val IRQ_ENABLE = RegInit(0.U(p.PDATA_WIDTH.W))

  // #####################################################################

  val DIRECTION_REG_SIZE: Int = 1
  val OUTPUT_REG_SIZE: Int = 1
  val INPUT_REG_SIZE: Int = 1
  val MODE_REG_SIZE: Int = 1
  val ATOMIC_OPERATION_REG_SIZE: Int = 1
  val ATOMIC_MASK_REG_SIZE: Int = 1
  val ATOMIC_SET_REG_SIZE: Int = 1
  val VIRTUAL_PORT_MAP_REG_SIZE: Int = (p.sizeOfVirtualPorts + p.wordWidth - 1) / p.wordWidth
  val VIRTUAL_PORT_OUTPUT_REG_SIZE: Int = (p.numVirtualPorts + p.wordWidth - 1) / p.wordWidth
  val VIRTUAL_PORT_OUTPUT_ADDR_MAX: Int =
    VIRTUAL_PORT_OUTPUT_ADDR + VIRTUAL_PORT_OUTPUT_REG_SIZE - 1

  val VIRTUAL_PORT_ENABLE_ADDR: Int = VIRTUAL_PORT_OUTPUT_ADDR_MAX + 1
  val VIRTUAL_PORT_ENABLE_REG_SIZE: Int =
    (1 + p.wordWidth - 1) / p.wordWidth
  val VIRTUAL_PORT_ENABLE_ADDR_MAX: Int =
    VIRTUAL_PORT_ENABLE_ADDR + VIRTUAL_PORT_ENABLE_REG_SIZE - 1

  // Interrupt Registers
  val TRIGGER_TYPE_ADDR: Int = VIRTUAL_PORT_ENABLE_ADDR_MAX + 1
  val TRIGGER_TYPE_REG_SIZE: Int = (p.PDATA_WIDTH + p.wordWidth - 1) / p.wordWidth
  val TRIGGER_TYPE_ADDR_MAX: Int = TRIGGER_TYPE_ADDR + TRIGGER_TYPE_REG_SIZE - 1

  val TRIGGER_LO_ADDR: Int = TRIGGER_TYPE_ADDR_MAX + 1
  val TRIGGER_LO_REG_SIZE: Int = (p.PDATA_WIDTH + p.wordWidth - 1) / p.wordWidth
  val TRIGGER_LO_ADDR_MAX: Int = TRIGGER_LO_ADDR + TRIGGER_LO_REG_SIZE - 1

  val TRIGGER_HI_ADDR: Int = TRIGGER_LO_ADDR_MAX + 1
  val TRIGGER_HI_REG_SIZE: Int = (p.PDATA_WIDTH + p.wordWidth - 1) / p.wordWidth
  val TRIGGER_HI_ADDR_MAX: Int = TRIGGER_HI_ADDR + TRIGGER_HI_REG_SIZE - 1

  val TRIGGER_STATUS_ADDR: Int = TRIGGER_HI_ADDR_MAX + 1
  val TRIGGER_STATUS_REG_SIZE: Int =
    (p.PDATA_WIDTH + p.wordWidth - 1) / p.wordWidth
  val TRIGGER_STATUS_ADDR_MAX: Int =
    TRIGGER_STATUS_ADDR + TRIGGER_STATUS_REG_SIZE - 1

  val IRQ_ENABLE_ADDR: Int = TRIGGER_STATUS_ADDR_MAX + 1
  val IRQ_ENABLE_REG_SIZE: Int = (p.PDATA_WIDTH + p.wordWidth - 1) / p.wordWidth
  val IRQ_ENABLE_ADDR_MAX: Int = IRQ_ENABLE_ADDR + IRQ_ENABLE_REG_SIZE - 1
}
