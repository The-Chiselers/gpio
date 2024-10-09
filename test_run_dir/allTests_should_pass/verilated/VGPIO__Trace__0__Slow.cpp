// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VGPIO__Syms.h"


VL_ATTR_COLD void VGPIO___024root__trace_init_sub__TOP__0(VGPIO___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+116,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"io_apb_PSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"io_apb_PENABLE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"io_apb_PWRITE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"io_apb_PADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+122,0,"io_apb_PWDATA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+123,0,"io_apb_PRDATA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+124,0,"io_apb_PREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"io_apb_PSLVERR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"io_pins_gpioInput",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+127,0,"io_pins_gpioOutput",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+128,0,"io_pins_gpioOutputEnable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+129,0,"io_pins_irqOutput",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("GPIO", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+116,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"io_apb_PSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"io_apb_PENABLE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"io_apb_PWRITE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"io_apb_PADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+122,0,"io_apb_PWDATA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+123,0,"io_apb_PRDATA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+124,0,"io_apb_PREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"io_apb_PSLVERR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"io_pins_gpioInput",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+127,0,"io_pins_gpioOutput",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+128,0,"io_pins_gpioOutputEnable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+129,0,"io_pins_irqOutput",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"regs_DIRECTION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"regs_OUTPUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"regs_INPUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"regs_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"regs_ATOMIC_OPERATION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"regs_ATOMIC_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+7,0,"regs_ATOMIC_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"regs_virtualPortOutput",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"regs_virtualToPhysicalMap_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"regs_virtualToPhysicalMap_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"regs_virtualToPhysicalMap_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"regs_virtualToPhysicalMap_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+13,0,"regs_virtualToPhysicalMap_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"regs_virtualToPhysicalMap_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+15,0,"regs_virtualToPhysicalMap_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+16,0,"regs_virtualToPhysicalMap_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+17,0,"regs_virtualPortEnable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"regs_TRIGGER_TYPE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"regs_TRIGGER_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"regs_TRIGGER_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"regs_TRIGGER_STATUS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"regs_IRQ_ENABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+23,0,"gpioInputSyncPrev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+24,0,"gpioInputSync_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+25,0,"gpioInputSync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"shiftAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+130,0,"shiftAddr_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+131,0,"shiftAddr_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+132,0,"shiftAddr_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+133,0,"shiftAddr_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"shiftAddr_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"shiftAddr_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"shiftAddr_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"shiftAddr_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+139,0,"shiftAddr_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+140,0,"shiftAddr_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+141,0,"shiftAddr_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+26,0,"condition",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+27,0,"triggerStatusVec_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"condition_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+29,0,"triggerStatusVec_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"condition_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+31,0,"triggerStatusVec_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"condition_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+33,0,"triggerStatusVec_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"condition_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+35,0,"triggerStatusVec_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"condition_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"triggerStatusVec_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"condition_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+39,0,"triggerStatusVec_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"condition_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+41,0,"triggerStatusVec_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"condition_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+43,0,"triggerStatusVec_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"condition_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+45,0,"triggerStatusVec_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"condition_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+47,0,"triggerStatusVec_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"condition_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+49,0,"triggerStatusVec_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"condition_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+51,0,"triggerStatusVec_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"condition_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+53,0,"triggerStatusVec_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"condition_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+55,0,"triggerStatusVec_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"condition_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+57,0,"triggerStatusVec_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"TRIGGER_STATUS_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+59,0,"atomicOperationTruthTable_0_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"atomicOperationTruthTable_0_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"atomicOperationTruthTable_1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"atomicOperationTruthTable_1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"output_inner_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"output_inner_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"output_inner_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"output_inner_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"output_inner_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"output_inner_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"output_inner_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"output_inner_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"output_inner_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"output_inner_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"output_inner_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"output_inner_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"output_inner_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"output_inner_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"output_inner_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"output_inner_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"OUTPUT_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+80,0,"gpioOutputVec_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"gpioOutputEnableVec_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"gpioOutputVec_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"gpioOutputEnableVec_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"gpioOutputVec_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"gpioOutputEnableVec_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"gpioOutputVec_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"gpioOutputEnableVec_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"gpioOutputVec_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"gpioOutputEnableVec_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"gpioOutputVec_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"gpioOutputEnableVec_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"gpioOutputVec_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"gpioOutputEnableVec_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"gpioOutputVec_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"gpioOutputEnableVec_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"gpioOutputVec_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"gpioOutputEnableVec_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"gpioOutputVec_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"gpioOutputEnableVec_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"gpioOutputVec_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"gpioOutputEnableVec_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"gpioOutputVec_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"gpioOutputEnableVec_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"gpioOutputVec_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"gpioOutputEnableVec_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"gpioOutputVec_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"gpioOutputEnableVec_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"gpioOutputVec_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"gpioOutputEnableVec_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"gpioOutputVec_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"gpioOutputEnableVec_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"io_pins_gpioOutput_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+113,0,"io_pins_gpioOutput_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"io_pins_gpioOutputEnable_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+115,0,"io_pins_gpioOutputEnable_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VGPIO___024root__trace_init_top(VGPIO___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_init_top\n"); );
    // Body
    VGPIO___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VGPIO___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VGPIO___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VGPIO___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VGPIO___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VGPIO___024root__trace_register(VGPIO___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VGPIO___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VGPIO___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VGPIO___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VGPIO___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VGPIO___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_const_0\n"); );
    // Init
    VGPIO___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VGPIO___024root*>(voidSelf);
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VGPIO___024root__trace_full_0_sub_0(VGPIO___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VGPIO___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_full_0\n"); );
    // Init
    VGPIO___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VGPIO___024root*>(voidSelf);
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VGPIO___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VGPIO___024root__trace_full_0_sub_0(VGPIO___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->GPIO__DOT__regs_DIRECTION),16);
    bufp->fullSData(oldp+2,(vlSelf->GPIO__DOT__regs_OUTPUT),16);
    bufp->fullSData(oldp+3,(vlSelf->GPIO__DOT__regs_INPUT),16);
    bufp->fullSData(oldp+4,(vlSelf->GPIO__DOT__regs_MODE),16);
    bufp->fullCData(oldp+5,(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION),4);
    bufp->fullSData(oldp+6,(vlSelf->GPIO__DOT__regs_ATOMIC_MASK),16);
    bufp->fullBit(oldp+7,(vlSelf->GPIO__DOT__regs_ATOMIC_SET));
    bufp->fullCData(oldp+8,(vlSelf->GPIO__DOT__regs_virtualPortOutput),8);
    bufp->fullCData(oldp+9,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0),5);
    bufp->fullCData(oldp+10,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1),5);
    bufp->fullCData(oldp+11,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2),5);
    bufp->fullCData(oldp+12,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3),5);
    bufp->fullCData(oldp+13,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4),5);
    bufp->fullCData(oldp+14,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5),5);
    bufp->fullCData(oldp+15,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6),5);
    bufp->fullCData(oldp+16,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7),5);
    bufp->fullBit(oldp+17,(vlSelf->GPIO__DOT__regs_virtualPortEnable));
    bufp->fullSData(oldp+18,(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE),16);
    bufp->fullSData(oldp+19,(vlSelf->GPIO__DOT__regs_TRIGGER_LO),16);
    bufp->fullSData(oldp+20,(vlSelf->GPIO__DOT__regs_TRIGGER_HI),16);
    bufp->fullSData(oldp+21,(vlSelf->GPIO__DOT__regs_TRIGGER_STATUS),16);
    bufp->fullSData(oldp+22,(vlSelf->GPIO__DOT__regs_IRQ_ENABLE),16);
    bufp->fullSData(oldp+23,(vlSelf->GPIO__DOT__gpioInputSyncPrev),16);
    bufp->fullSData(oldp+24,(vlSelf->GPIO__DOT__gpioInputSync_REG),16);
    bufp->fullSData(oldp+25,(vlSelf->GPIO__DOT__gpioInputSync),16);
    bufp->fullCData(oldp+26,(vlSelf->GPIO__DOT__condition),3);
    bufp->fullBit(oldp+27,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition))
                                   ? (IData)(vlSelf->GPIO__DOT__gpioInputSync)
                                   : ((2U == (IData)(vlSelf->GPIO__DOT__condition))
                                       ? (~ (IData)(vlSelf->GPIO__DOT__gpioInputSync))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition))
                                              ? ((~ (IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev)) 
                                                 & (IData)(vlSelf->GPIO__DOT__gpioInputSync))
                                              : ((6U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition))
                                                  ? 
                                                 ((~ (IData)(vlSelf->GPIO__DOT__gpioInputSync)) 
                                                  & (IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev))
                                                  : 
                                                 ((7U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition)) 
                                                  & ((1U 
                                                      & (IData)(vlSelf->GPIO__DOT__gpioInputSync)) 
                                                     != 
                                                     (1U 
                                                      & (IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev))))))))))));
    bufp->fullCData(oldp+28,(vlSelf->GPIO__DOT__condition_1),3);
    bufp->fullBit(oldp+29,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_1))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 1U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_1))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 1U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_1)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_1))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 1U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 1U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_1))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 1U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 1U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_1)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 1U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 1U))))))))))));
    bufp->fullCData(oldp+30,(vlSelf->GPIO__DOT__condition_2),3);
    bufp->fullBit(oldp+31,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_2))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 2U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_2))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 2U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_2)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_2))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 2U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 2U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_2))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 2U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 2U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_2)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 2U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 2U))))))))))));
    bufp->fullCData(oldp+32,(vlSelf->GPIO__DOT__condition_3),3);
    bufp->fullBit(oldp+33,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_3))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 3U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_3))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 3U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_3)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_3))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 3U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 3U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_3))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 3U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 3U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_3)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 3U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 3U))))))))))));
    bufp->fullCData(oldp+34,(vlSelf->GPIO__DOT__condition_4),3);
    bufp->fullBit(oldp+35,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_4))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 4U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_4))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 4U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_4)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_4))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 4U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 4U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_4))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 4U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 4U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_4)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 4U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 4U))))))))))));
    bufp->fullCData(oldp+36,(vlSelf->GPIO__DOT__condition_5),3);
    bufp->fullBit(oldp+37,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_5))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 5U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_5))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 5U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_5)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_5))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 5U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 5U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_5))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 5U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 5U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_5)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 5U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 5U))))))))))));
    bufp->fullCData(oldp+38,(vlSelf->GPIO__DOT__condition_6),3);
    bufp->fullBit(oldp+39,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_6))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 6U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_6))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 6U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_6)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_6))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 6U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 6U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_6))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 6U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 6U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_6)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 6U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 6U))))))))))));
    bufp->fullCData(oldp+40,(vlSelf->GPIO__DOT__condition_7),3);
    bufp->fullBit(oldp+41,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_7))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 7U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_7))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 7U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_7)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_7))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 7U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 7U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_7))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 7U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 7U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_7)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 7U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 7U))))))))))));
    bufp->fullCData(oldp+42,(vlSelf->GPIO__DOT__condition_8),3);
    bufp->fullBit(oldp+43,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_8))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 8U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_8))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 8U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_8)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_8))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 8U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 8U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_8))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 8U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 8U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_8)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 8U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 8U))))))))))));
    bufp->fullCData(oldp+44,(vlSelf->GPIO__DOT__condition_9),3);
    bufp->fullBit(oldp+45,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_9))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 9U) : ((2U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition_9))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 9U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_9)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_9))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                       >> 9U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 9U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition_9))
                                                      ? 
                                                     ((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 9U)) 
                                                      & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 9U))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_9)) 
                                                      & ((1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                             >> 9U)) 
                                                         != 
                                                         (1U 
                                                          & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                             >> 9U))))))))))));
    bufp->fullCData(oldp+46,(vlSelf->GPIO__DOT__condition_10),3);
    bufp->fullBit(oldp+47,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_10))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xaU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_10))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xaU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_10)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_10))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xaU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xaU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_10))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xaU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xaU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_10)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xaU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xaU))))))))))));
    bufp->fullCData(oldp+48,(vlSelf->GPIO__DOT__condition_11),3);
    bufp->fullBit(oldp+49,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_11))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xbU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_11))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xbU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_11)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_11))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xbU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xbU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_11))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xbU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xbU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_11)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xbU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xbU))))))))))));
    bufp->fullCData(oldp+50,(vlSelf->GPIO__DOT__condition_12),3);
    bufp->fullBit(oldp+51,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_12))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xcU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_12))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xcU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_12)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_12))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xcU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xcU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_12))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xcU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xcU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_12)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xcU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xcU))))))))))));
    bufp->fullCData(oldp+52,(vlSelf->GPIO__DOT__condition_13),3);
    bufp->fullBit(oldp+53,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_13))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xdU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_13))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xdU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_13)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_13))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xdU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xdU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_13))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xdU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xdU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_13)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xdU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xdU))))))))))));
    bufp->fullCData(oldp+54,(vlSelf->GPIO__DOT__condition_14),3);
    bufp->fullBit(oldp+55,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_14))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xeU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_14))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xeU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_14)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_14))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xeU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xeU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_14))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xeU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xeU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_14)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xeU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xeU))))))))))));
    bufp->fullCData(oldp+56,(vlSelf->GPIO__DOT__condition_15),3);
    bufp->fullBit(oldp+57,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_15))
                                   ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                      >> 0xfU) : ((2U 
                                                   == (IData)(vlSelf->GPIO__DOT__condition_15))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xfU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition_15)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->GPIO__DOT__condition_15))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                         >> 0xfU)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xfU))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_15))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                          >> 0xfU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                           >> 0xfU))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->GPIO__DOT__condition_15)) 
                                                        & ((1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                               >> 0xfU)) 
                                                           != 
                                                           (1U 
                                                            & ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                               >> 0xfU))))))))))));
    bufp->fullCData(oldp+58,(vlSelf->GPIO__DOT__TRIGGER_STATUS_lo),8);
    bufp->fullBit(oldp+59,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                  >> 1U))));
    bufp->fullBit(oldp+60,((1U & (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION))));
    bufp->fullBit(oldp+61,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                  >> 3U))));
    bufp->fullBit(oldp+62,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                  >> 2U))));
    bufp->fullBit(oldp+63,((1U & ((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)) 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK)) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+64,((1U & ((2U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 1U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 1U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 1U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 1U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+65,((1U & ((4U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 2U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 2U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 2U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 2U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+66,((1U & ((8U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 3U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 3U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 3U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 3U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+67,((1U & ((0x10U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 4U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 4U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 4U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 4U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+68,((1U & ((0x20U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 5U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 5U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 5U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 5U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+69,((1U & ((0x40U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 6U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 6U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 6U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 6U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+70,((1U & ((0x80U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 7U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 7U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 7U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 7U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+71,((1U & ((0x100U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                             & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 8U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 8U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 8U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 8U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+72,((1U & ((0x200U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                             & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 9U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 9U)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 9U)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 9U)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+73,((1U & ((0x400U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                             & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xaU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xaU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xaU)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 0xaU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+74,((1U & ((0x800U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                             & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xbU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xbU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xbU)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 0xbU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+75,((1U & ((0x1000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                              & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xcU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xcU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xcU)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 0xcU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+76,((1U & ((0x2000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                              & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xdU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xdU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xdU)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 0xdU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+77,((1U & ((0x4000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                              & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((1U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xeU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xeU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       >> 0xeU)) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        >> 0xeU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+78,((1U & ((0x8000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                              & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                      >> 2U) : ((IData)(
                                                        ((~ 
                                                          ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                           >> 0xfU)) 
                                                         & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                            >> 0xfU)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 3U)
                                                 : 
                                                ((IData)(
                                                         ((~ 
                                                           ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                            >> 0xfU)) 
                                                          & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                             >> 0xfU)))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 1U)))))));
    bufp->fullCData(oldp+79,(vlSelf->GPIO__DOT__OUTPUT_lo),8);
    bufp->fullBit(oldp+80,((1U & ((~ (IData)(vlSelf->GPIO__DOT__regs_MODE)) 
                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))))));
    bufp->fullBit(oldp+81,((1U & ((1U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)) 
                                      & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                   : (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))));
    bufp->fullBit(oldp+82,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 1U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 1U)))));
    bufp->fullBit(oldp+83,((1U & ((2U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 1U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 1U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 1U)))));
    bufp->fullBit(oldp+84,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 2U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 2U)))));
    bufp->fullBit(oldp+85,((1U & ((4U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 2U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 2U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 2U)))));
    bufp->fullBit(oldp+86,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 3U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 3U)))));
    bufp->fullBit(oldp+87,((1U & ((8U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 3U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 3U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 3U)))));
    bufp->fullBit(oldp+88,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 4U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 4U)))));
    bufp->fullBit(oldp+89,((1U & ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 4U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 4U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 4U)))));
    bufp->fullBit(oldp+90,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 5U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 5U)))));
    bufp->fullBit(oldp+91,((1U & ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 5U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 5U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 5U)))));
    bufp->fullBit(oldp+92,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 6U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 6U)))));
    bufp->fullBit(oldp+93,((1U & ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 6U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 6U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 6U)))));
    bufp->fullBit(oldp+94,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 7U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 7U)))));
    bufp->fullBit(oldp+95,((1U & ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 7U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 7U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 7U)))));
    bufp->fullBit(oldp+96,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 8U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 8U)))));
    bufp->fullBit(oldp+97,((1U & ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 8U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 8U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 8U)))));
    bufp->fullBit(oldp+98,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                      >> 9U)) & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                 >> 9U)))));
    bufp->fullBit(oldp+99,((1U & ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                   ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          >> 9U)) & 
                                      ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 9U)) : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 9U)))));
    bufp->fullBit(oldp+100,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xaU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xaU)))));
    bufp->fullBit(oldp+101,((1U & ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xaU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xaU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xaU)))));
    bufp->fullBit(oldp+102,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xbU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xbU)))));
    bufp->fullBit(oldp+103,((1U & ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xbU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xbU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xbU)))));
    bufp->fullBit(oldp+104,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xcU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xcU)))));
    bufp->fullBit(oldp+105,((1U & ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xcU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xcU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xcU)))));
    bufp->fullBit(oldp+106,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xdU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xdU)))));
    bufp->fullBit(oldp+107,((1U & ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xdU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xdU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xdU)))));
    bufp->fullBit(oldp+108,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xeU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xeU)))));
    bufp->fullBit(oldp+109,((1U & ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xeU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xeU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xeU)))));
    bufp->fullBit(oldp+110,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                       >> 0xfU)) & 
                                   (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                    >> 0xfU)))));
    bufp->fullBit(oldp+111,((1U & ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                    ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           >> 0xfU)) 
                                       & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xfU))
                                    : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                       >> 0xfU)))));
    bufp->fullCData(oldp+112,(((0x80U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                              >> 7U)) 
                                          << 7U) & 
                                         ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                               | ((0x40U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                 >> 6U)) 
                                             << 6U) 
                                            & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                  | ((0x20U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 5U)) 
                                                << 5U) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                     | ((0x10U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 4U)) 
                                                   << 4U) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                        | ((8U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 3U)) 
                                                   << 3U) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                           | ((4U & 
                                               (((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                   >> 2U)) 
                                                 << 2U) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                              | ((2U 
                                                  & (((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                        >> 1U)) 
                                                      << 1U) 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                        & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                                 | (1U 
                                                    & ((~ (IData)(vlSelf->GPIO__DOT__regs_MODE)) 
                                                       & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))))))))))),8);
    bufp->fullCData(oldp+113,(((0x80U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                              >> 0xfU)) 
                                          << 7U) & 
                                         (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                           & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                          >> 8U))) 
                               | ((0x40U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                 >> 0xeU)) 
                                             << 6U) 
                                            & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                               >> 8U))) 
                                  | ((0x20U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 0xdU)) 
                                                << 5U) 
                                               & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                  >> 8U))) 
                                     | ((0x10U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 0xcU)) 
                                                   << 4U) 
                                                  & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                     >> 8U))) 
                                        | ((8U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 0xbU)) 
                                                   << 3U) 
                                                  & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                     >> 8U))) 
                                           | ((4U & 
                                               (((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                   >> 0xaU)) 
                                                 << 2U) 
                                                & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                   >> 8U))) 
                                              | ((2U 
                                                  & (((~ 
                                                       ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                        >> 9U)) 
                                                      << 1U) 
                                                     & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                         & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                        >> 8U))) 
                                                 | (1U 
                                                    & ((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                         >> 8U)) 
                                                       & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                           & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                          >> 8U))))))))))),8);
    bufp->fullCData(oldp+114,(((0x80U & (((0x80U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                           ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  >> 7U)) 
                                              & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 7U))
                                           : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                              >> 7U)) 
                                         << 7U)) | 
                               ((0x40U & (((0x40U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                            ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 6U)) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 6U))
                                            : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                               >> 6U)) 
                                          << 6U)) | 
                                ((0x20U & (((0x20U 
                                             & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                             ? ((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  >> 5U)) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 5U))
                                             : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                >> 5U)) 
                                           << 5U)) 
                                 | ((0x10U & (((0x10U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                ? (
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 4U)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 4U))
                                                : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 4U)) 
                                              << 4U)) 
                                    | ((8U & (((8U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                ? (
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 3U)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 3U))
                                                : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 3U)) 
                                              << 3U)) 
                                       | ((4U & (((4U 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                   ? 
                                                  ((~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 2U)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 2U))
                                                   : 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 2U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              (((2U 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 1U)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 1U))
                                                 : 
                                                ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 1U)) 
                                               << 1U)) 
                                             | (1U 
                                                & ((1U 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                    ? 
                                                   ((~ (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)) 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                                    : (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))))))))))),8);
    bufp->fullCData(oldp+115,(((0x80U & (((0x8000U 
                                           & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                           ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  >> 0xfU)) 
                                              & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 0xfU))
                                           : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                              >> 0xfU)) 
                                         << 7U)) | 
                               ((0x40U & (((0x4000U 
                                            & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                            ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 0xeU)) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 0xeU))
                                            : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                               >> 0xeU)) 
                                          << 6U)) | 
                                ((0x20U & (((0x2000U 
                                             & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                             ? ((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  >> 0xdU)) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 0xdU))
                                             : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                >> 0xdU)) 
                                           << 5U)) 
                                 | ((0x10U & (((0x1000U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                ? (
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 0xcU)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 0xcU))
                                                : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 0xcU)) 
                                              << 4U)) 
                                    | ((8U & (((0x800U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                ? (
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 0xbU)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 0xbU))
                                                : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 0xbU)) 
                                              << 3U)) 
                                       | ((4U & (((0x400U 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                   ? 
                                                  ((~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     >> 0xaU)) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                      >> 0xaU))
                                                   : 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 0xaU)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              (((0x200U 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 9U)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 9U))
                                                 : 
                                                ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 9U)) 
                                               << 1U)) 
                                             | (1U 
                                                & ((0x100U 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 8U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                       >> 8U))
                                                    : 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 8U))))))))))),8);
    bufp->fullBit(oldp+116,(vlSelf->clock));
    bufp->fullBit(oldp+117,(vlSelf->reset));
    bufp->fullBit(oldp+118,(vlSelf->io_apb_PSEL));
    bufp->fullBit(oldp+119,(vlSelf->io_apb_PENABLE));
    bufp->fullBit(oldp+120,(vlSelf->io_apb_PWRITE));
    bufp->fullCData(oldp+121,(vlSelf->io_apb_PADDR),8);
    bufp->fullSData(oldp+122,(vlSelf->io_apb_PWDATA),16);
    bufp->fullSData(oldp+123,(vlSelf->io_apb_PRDATA),16);
    bufp->fullBit(oldp+124,(vlSelf->io_apb_PREADY));
    bufp->fullBit(oldp+125,(vlSelf->io_apb_PSLVERR));
    bufp->fullSData(oldp+126,(vlSelf->io_pins_gpioInput),16);
    bufp->fullSData(oldp+127,(vlSelf->io_pins_gpioOutput),16);
    bufp->fullSData(oldp+128,(vlSelf->io_pins_gpioOutputEnable),16);
    bufp->fullBit(oldp+129,(vlSelf->io_pins_irqOutput));
    bufp->fullCData(oldp+130,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(2U)))),8);
    bufp->fullCData(oldp+131,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(6U)))),8);
    bufp->fullCData(oldp+132,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(8U)))),8);
    bufp->fullCData(oldp+133,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(9U)))),8);
    bufp->fullCData(oldp+134,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0xbU)))),8);
    bufp->fullCData(oldp+135,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0xcU)))),8);
    bufp->fullCData(oldp+136,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x14U)))),8);
    bufp->fullCData(oldp+137,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x15U)))),8);
    bufp->fullCData(oldp+138,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x16U)))),8);
    bufp->fullCData(oldp+139,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x18U)))),8);
    bufp->fullCData(oldp+140,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x1aU)))),8);
    bufp->fullCData(oldp+141,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                        - (IData)(0x1eU)))),8);
}
