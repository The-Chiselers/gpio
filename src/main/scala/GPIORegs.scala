
package tech.rocksavage.chiselware.GPIO

import chisel3._
import chisel3.util._

class GPIORegs(p: BaseParams) extends Bundle {

  // Internal Register Sizes
  val REG_SIZE: Int = p.wordWidth
  val DIRECTION_SIZE: Int = p.dataWidth
  val OUTPUT_SIZE: Int = p.dataWidth
  val INPUT_SIZE: Int = p.dataWidth
  val MODE_SIZE: Int = p.dataWidth

  val ATOMIC_OPERATION_SIZE: Int = 4
  val ATOMIC_MASK_SIZE: Int = p.dataWidth
  val ATOMIC_SET_SIZE: Int = 1

  val VIRTUAL_PORT_MAP_SIZE: Int = p.sizeOfVirtualPorts
  val VIRTUAL_PORT_OUTPUT_SIZE: Int = p.numVirtualPorts
  val VIRTUAL_PORT_ENABLE_SIZE: Int = 1

  val TRIGGER_TYPE_SIZE: Int = p.dataWidth
  val TRIGGER_LO_SIZE: Int = p.dataWidth
  val TRIGGER_HI_SIZE: Int = p.dataWidth
  val TRIGGER_STATUS_SIZE: Int = p.dataWidth
  val IRQ_ENABLE_SIZE: Int = p.dataWidth

  // #####################################################################
  // REGS
  // #####################################################################
  // User Accessible Control Registers
  val DIRECTION = RegInit(0.U(DIRECTION_SIZE.W)) // RW
  val OUTPUT = RegInit(0.U(OUTPUT_SIZE.W)) // RW
  val INPUT = RegInit(0.U(INPUT_SIZE.W)) // RO
  val MODE = RegInit(0.U(MODE_SIZE.W)) // RW

  // Atomic Operations
  val ATOMIC_OPERATION = RegInit(0.U(ATOMIC_OPERATION_SIZE.W))
  val ATOMIC_MASK = RegInit(0.U(ATOMIC_MASK_SIZE.W))
  val ATOMIC_SET = RegInit(0.U(ATOMIC_SET_SIZE.W))

  // Virtual Port Control Registers
  val virtualPortOutput = RegInit(0.U(VIRTUAL_PORT_OUTPUT_SIZE.W))
  // Virtual to Physical Pin Mapping
  val virtualToPhysicalMap =
    RegInit(
      VecInit(Seq.fill(VIRTUAL_PORT_OUTPUT_SIZE)(0.U(VIRTUAL_PORT_MAP_SIZE.W)))
    )
  // Virtual Port Enable
  val virtualPortEnable = RegInit(0.U(VIRTUAL_PORT_ENABLE_SIZE.W))

  // Interrupt Handling Registers
  val TRIGGER_TYPE = RegInit(0.U(TRIGGER_TYPE_SIZE.W))
  val TRIGGER_LO = RegInit(0.U(TRIGGER_LO_SIZE.W))
  val TRIGGER_HI = RegInit(0.U(TRIGGER_HI_SIZE.W))
  val TRIGGER_STATUS = RegInit(0.U(TRIGGER_STATUS_SIZE.W))
  val IRQ_ENABLE = RegInit(0.U(IRQ_ENABLE_SIZE.W))

  // #####################################################################

  val DIRECTION_ADDR: Int = 0
  val DIRECTION_REG_SIZE: Int = (DIRECTION_SIZE + REG_SIZE - 1) / REG_SIZE
  val DIRECTION_ADDR_MAX: Int = DIRECTION_ADDR + DIRECTION_REG_SIZE - 1

  val OUTPUT_ADDR: Int = DIRECTION_ADDR_MAX + 1
  val OUTPUT_REG_SIZE: Int = (OUTPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val OUTPUT_ADDR_MAX: Int = OUTPUT_ADDR + OUTPUT_REG_SIZE - 1

  val INPUT_ADDR: Int = OUTPUT_ADDR_MAX + 1
  val INPUT_REG_SIZE: Int = (INPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val INPUT_ADDR_MAX: Int = INPUT_ADDR + INPUT_REG_SIZE - 1

  val MODE_ADDR: Int = INPUT_ADDR_MAX + 1
  val MODE_REG_SIZE: Int = (MODE_SIZE + REG_SIZE - 1) / REG_SIZE
  val MODE_ADDR_MAX: Int = MODE_ADDR + MODE_REG_SIZE - 1

  val ATOMIC_OPERATION_ADDR: Int = MODE_ADDR_MAX + 1
  val ATOMIC_OPERATION_REG_SIZE: Int =
    (ATOMIC_OPERATION_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_OPERATION_ADDR_MAX: Int =
    ATOMIC_OPERATION_ADDR + ATOMIC_OPERATION_REG_SIZE - 1

  val ATOMIC_MASK_ADDR: Int = ATOMIC_OPERATION_ADDR_MAX + 1
  val ATOMIC_MASK_REG_SIZE: Int = (ATOMIC_MASK_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_MASK_ADDR_MAX: Int = ATOMIC_MASK_ADDR + ATOMIC_MASK_REG_SIZE - 1

  val ATOMIC_SET_ADDR: Int = ATOMIC_MASK_ADDR_MAX + 1
  val ATOMIC_SET_REG_SIZE: Int = (ATOMIC_SET_SIZE + REG_SIZE - 1) / REG_SIZE
  val ATOMIC_SET_ADDR_MAX: Int = ATOMIC_SET_ADDR + ATOMIC_SET_REG_SIZE - 1

  // virtual port registers
  val VIRTUAL_PORT_MAP_ADDR: Int = ATOMIC_SET_ADDR_MAX + 1
  val VIRTUAL_PORT_MAP_REG_SIZE: Int =
    (VIRTUAL_PORT_MAP_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_MAP_ADDR_MAX: Int =
    VIRTUAL_PORT_MAP_ADDR + VIRTUAL_PORT_OUTPUT_SIZE * VIRTUAL_PORT_MAP_REG_SIZE - 1

  val VIRTUAL_PORT_OUTPUT_ADDR: Int = VIRTUAL_PORT_MAP_ADDR_MAX + 1
  val VIRTUAL_PORT_OUTPUT_REG_SIZE: Int =
    (VIRTUAL_PORT_OUTPUT_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_OUTPUT_ADDR_MAX: Int =
    VIRTUAL_PORT_OUTPUT_ADDR + VIRTUAL_PORT_OUTPUT_REG_SIZE - 1

  val VIRTUAL_PORT_ENABLE_ADDR: Int = VIRTUAL_PORT_OUTPUT_ADDR_MAX + 1
  val VIRTUAL_PORT_ENABLE_REG_SIZE: Int =
    (VIRTUAL_PORT_ENABLE_SIZE + REG_SIZE - 1) / REG_SIZE
  val VIRTUAL_PORT_ENABLE_ADDR_MAX: Int =
    VIRTUAL_PORT_ENABLE_ADDR + VIRTUAL_PORT_ENABLE_REG_SIZE - 1

  // Interrupt Registers
  val TRIGGER_TYPE_ADDR: Int = VIRTUAL_PORT_ENABLE_ADDR_MAX + 1
  val TRIGGER_TYPE_REG_SIZE: Int = (TRIGGER_TYPE_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_TYPE_ADDR_MAX: Int = TRIGGER_TYPE_ADDR + TRIGGER_TYPE_REG_SIZE - 1

  val TRIGGER_LO_ADDR: Int = TRIGGER_TYPE_ADDR_MAX + 1
  val TRIGGER_LO_REG_SIZE: Int = (TRIGGER_LO_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_LO_ADDR_MAX: Int = TRIGGER_LO_ADDR + TRIGGER_LO_REG_SIZE - 1

  val TRIGGER_HI_ADDR: Int = TRIGGER_LO_ADDR_MAX + 1
  val TRIGGER_HI_REG_SIZE: Int = (TRIGGER_HI_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_HI_ADDR_MAX: Int = TRIGGER_HI_ADDR + TRIGGER_HI_REG_SIZE - 1

  val TRIGGER_STATUS_ADDR: Int = TRIGGER_HI_ADDR_MAX + 1
  val TRIGGER_STATUS_REG_SIZE: Int =
    (TRIGGER_STATUS_SIZE + REG_SIZE - 1) / REG_SIZE
  val TRIGGER_STATUS_ADDR_MAX: Int =
    TRIGGER_STATUS_ADDR + TRIGGER_STATUS_REG_SIZE - 1

  val IRQ_ENABLE_ADDR: Int = TRIGGER_STATUS_ADDR_MAX + 1
  val IRQ_ENABLE_REG_SIZE: Int = (IRQ_ENABLE_SIZE + REG_SIZE - 1) / REG_SIZE
  val IRQ_ENABLE_ADDR_MAX: Int = IRQ_ENABLE_ADDR + IRQ_ENABLE_REG_SIZE - 1
}