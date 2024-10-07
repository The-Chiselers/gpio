// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VGPIO__Syms.h"


void VGPIO___024root__trace_chg_0_sub_0(VGPIO___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VGPIO___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_chg_0\n"); );
    // Init
    VGPIO___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VGPIO___024root*>(voidSelf);
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VGPIO___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VGPIO___024root__trace_chg_0_sub_0(VGPIO___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->GPIO__DOT__regs_DIRECTION),16);
        bufp->chgSData(oldp+1,(vlSelf->GPIO__DOT__regs_OUTPUT),16);
        bufp->chgSData(oldp+2,(vlSelf->GPIO__DOT__regs_INPUT),16);
        bufp->chgSData(oldp+3,(vlSelf->GPIO__DOT__regs_MODE),16);
        bufp->chgCData(oldp+4,(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION),4);
        bufp->chgSData(oldp+5,(vlSelf->GPIO__DOT__regs_ATOMIC_MASK),16);
        bufp->chgBit(oldp+6,(vlSelf->GPIO__DOT__regs_ATOMIC_SET));
        bufp->chgCData(oldp+7,(vlSelf->GPIO__DOT__regs_virtualPortOutput),8);
        bufp->chgCData(oldp+8,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0),5);
        bufp->chgCData(oldp+9,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1),5);
        bufp->chgCData(oldp+10,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2),5);
        bufp->chgCData(oldp+11,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3),5);
        bufp->chgCData(oldp+12,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4),5);
        bufp->chgCData(oldp+13,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5),5);
        bufp->chgCData(oldp+14,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6),5);
        bufp->chgCData(oldp+15,(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7),5);
        bufp->chgBit(oldp+16,(vlSelf->GPIO__DOT__regs_virtualPortEnable));
        bufp->chgSData(oldp+17,(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE),16);
        bufp->chgSData(oldp+18,(vlSelf->GPIO__DOT__regs_TRIGGER_LO),16);
        bufp->chgSData(oldp+19,(vlSelf->GPIO__DOT__regs_TRIGGER_HI),16);
        bufp->chgSData(oldp+20,(vlSelf->GPIO__DOT__regs_TRIGGER_STATUS),16);
        bufp->chgSData(oldp+21,(vlSelf->GPIO__DOT__regs_IRQ_ENABLE),16);
        bufp->chgSData(oldp+22,(vlSelf->GPIO__DOT__gpioInputSyncPrev),16);
        bufp->chgSData(oldp+23,(vlSelf->GPIO__DOT__gpioInputSync_REG),16);
        bufp->chgSData(oldp+24,(vlSelf->GPIO__DOT__gpioInputSync),16);
        bufp->chgCData(oldp+25,(vlSelf->GPIO__DOT__condition),3);
        bufp->chgBit(oldp+26,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition))
                                      ? (IData)(vlSelf->GPIO__DOT__gpioInputSync)
                                      : ((2U == (IData)(vlSelf->GPIO__DOT__condition))
                                          ? (~ (IData)(vlSelf->GPIO__DOT__gpioInputSync))
                                          : ((3U == (IData)(vlSelf->GPIO__DOT__condition)) 
                                             | ((5U 
                                                 == (IData)(vlSelf->GPIO__DOT__condition))
                                                 ? 
                                                ((~ (IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev)) 
                                                 & (IData)(vlSelf->GPIO__DOT__gpioInputSync))
                                                 : 
                                                ((6U 
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
        bufp->chgCData(oldp+27,(vlSelf->GPIO__DOT__condition_1),3);
        bufp->chgBit(oldp+28,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_1))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 1U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+29,(vlSelf->GPIO__DOT__condition_2),3);
        bufp->chgBit(oldp+30,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_2))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 2U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+31,(vlSelf->GPIO__DOT__condition_3),3);
        bufp->chgBit(oldp+32,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_3))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 3U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+33,(vlSelf->GPIO__DOT__condition_4),3);
        bufp->chgBit(oldp+34,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_4))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 4U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+35,(vlSelf->GPIO__DOT__condition_5),3);
        bufp->chgBit(oldp+36,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_5))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 5U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+37,(vlSelf->GPIO__DOT__condition_6),3);
        bufp->chgBit(oldp+38,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_6))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 6U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+39,(vlSelf->GPIO__DOT__condition_7),3);
        bufp->chgBit(oldp+40,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_7))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 7U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+41,(vlSelf->GPIO__DOT__condition_8),3);
        bufp->chgBit(oldp+42,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_8))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 8U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+43,(vlSelf->GPIO__DOT__condition_9),3);
        bufp->chgBit(oldp+44,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_9))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 9U) : (
                                                   (2U 
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
        bufp->chgCData(oldp+45,(vlSelf->GPIO__DOT__condition_10),3);
        bufp->chgBit(oldp+46,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_10))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xaU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_10))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xaU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_10)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_10))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xaU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xaU))
                                              : ((6U 
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
        bufp->chgCData(oldp+47,(vlSelf->GPIO__DOT__condition_11),3);
        bufp->chgBit(oldp+48,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_11))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xbU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_11))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xbU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_11)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_11))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xbU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xbU))
                                              : ((6U 
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
        bufp->chgCData(oldp+49,(vlSelf->GPIO__DOT__condition_12),3);
        bufp->chgBit(oldp+50,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_12))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xcU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_12))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xcU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_12)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_12))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xcU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xcU))
                                              : ((6U 
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
        bufp->chgCData(oldp+51,(vlSelf->GPIO__DOT__condition_13),3);
        bufp->chgBit(oldp+52,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_13))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xdU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_13))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xdU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_13)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_13))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xdU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xdU))
                                              : ((6U 
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
        bufp->chgCData(oldp+53,(vlSelf->GPIO__DOT__condition_14),3);
        bufp->chgBit(oldp+54,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_14))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xeU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_14))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xeU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_14)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_14))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xeU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xeU))
                                              : ((6U 
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
        bufp->chgCData(oldp+55,(vlSelf->GPIO__DOT__condition_15),3);
        bufp->chgBit(oldp+56,((1U & ((1U == (IData)(vlSelf->GPIO__DOT__condition_15))
                                      ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                         >> 0xfU) : 
                                     ((2U == (IData)(vlSelf->GPIO__DOT__condition_15))
                                       ? (~ ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                             >> 0xfU))
                                       : ((3U == (IData)(vlSelf->GPIO__DOT__condition_15)) 
                                          | ((5U == (IData)(vlSelf->GPIO__DOT__condition_15))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev) 
                                                   >> 0xfU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                    >> 0xfU))
                                              : ((6U 
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
        bufp->chgCData(oldp+57,(vlSelf->GPIO__DOT__TRIGGER_STATUS_lo),8);
        bufp->chgBit(oldp+58,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                     >> 1U))));
        bufp->chgBit(oldp+59,((1U & (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION))));
        bufp->chgBit(oldp+60,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                     >> 3U))));
        bufp->chgBit(oldp+61,((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                     >> 2U))));
        bufp->chgBit(oldp+62,((1U & ((1U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+63,((1U & ((2U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+64,((1U & ((4U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+65,((1U & ((8U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+66,((1U & ((0x10U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+67,((1U & ((0x20U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+68,((1U & ((0x40U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+69,((1U & ((0x80U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+70,((1U & ((0x100U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+71,((1U & ((0x200U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+72,((1U & ((0x400U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+73,((1U & ((0x800U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+74,((1U & ((0x1000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+75,((1U & ((0x2000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+76,((1U & ((0x4000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                      ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                         >> 2U) : (
                                                   (1U 
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
        bufp->chgBit(oldp+77,((1U & ((0x8000U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
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
        bufp->chgCData(oldp+78,(vlSelf->GPIO__DOT__OUTPUT_lo),8);
        bufp->chgBit(oldp+79,((1U & ((~ (IData)(vlSelf->GPIO__DOT__regs_MODE)) 
                                     & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                        & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))))));
        bufp->chgBit(oldp+80,((1U & ((1U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                      : (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))));
        bufp->chgBit(oldp+81,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 1U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 1U)))));
        bufp->chgBit(oldp+82,((1U & ((2U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 1U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 1U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 1U)))));
        bufp->chgBit(oldp+83,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 2U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 2U)))));
        bufp->chgBit(oldp+84,((1U & ((4U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 2U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 2U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 2U)))));
        bufp->chgBit(oldp+85,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 3U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 3U)))));
        bufp->chgBit(oldp+86,((1U & ((8U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 3U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 3U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 3U)))));
        bufp->chgBit(oldp+87,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 4U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 4U)))));
        bufp->chgBit(oldp+88,((1U & ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 4U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 4U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 4U)))));
        bufp->chgBit(oldp+89,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 5U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 5U)))));
        bufp->chgBit(oldp+90,((1U & ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 5U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 5U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 5U)))));
        bufp->chgBit(oldp+91,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 6U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 6U)))));
        bufp->chgBit(oldp+92,((1U & ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 6U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 6U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 6U)))));
        bufp->chgBit(oldp+93,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 7U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 7U)))));
        bufp->chgBit(oldp+94,((1U & ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 7U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 7U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 7U)))));
        bufp->chgBit(oldp+95,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 8U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 8U)))));
        bufp->chgBit(oldp+96,((1U & ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 8U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 8U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 8U)))));
        bufp->chgBit(oldp+97,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 9U)) & 
                                     (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                       & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                      >> 9U)))));
        bufp->chgBit(oldp+98,((1U & ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                      ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                             >> 9U)) 
                                         & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                            >> 9U))
                                      : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                         >> 9U)))));
        bufp->chgBit(oldp+99,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                         >> 0xaU)) 
                                     & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                         & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                        >> 0xaU)))));
        bufp->chgBit(oldp+100,((1U & ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xaU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xaU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xaU)))));
        bufp->chgBit(oldp+101,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                          >> 0xbU)) 
                                      & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                         >> 0xbU)))));
        bufp->chgBit(oldp+102,((1U & ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xbU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xbU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xbU)))));
        bufp->chgBit(oldp+103,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                          >> 0xcU)) 
                                      & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                         >> 0xcU)))));
        bufp->chgBit(oldp+104,((1U & ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xcU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xcU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xcU)))));
        bufp->chgBit(oldp+105,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                          >> 0xdU)) 
                                      & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                         >> 0xdU)))));
        bufp->chgBit(oldp+106,((1U & ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xdU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xdU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xdU)))));
        bufp->chgBit(oldp+107,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                          >> 0xeU)) 
                                      & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                         >> 0xeU)))));
        bufp->chgBit(oldp+108,((1U & ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xeU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xeU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xeU)))));
        bufp->chgBit(oldp+109,((1U & ((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                          >> 0xfU)) 
                                      & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                          & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                         >> 0xfU)))));
        bufp->chgBit(oldp+110,((1U & ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                       ? ((~ ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              >> 0xfU)) 
                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                             >> 0xfU))
                                       : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                          >> 0xfU)))));
        bufp->chgCData(oldp+111,(((0x80U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                 >> 7U)) 
                                             << 7U) 
                                            & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                  | ((0x40U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 6U)) 
                                                << 6U) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                     | ((0x20U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 5U)) 
                                                   << 5U) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                        | ((0x10U & 
                                            (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 4U)) 
                                              << 4U) 
                                             & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                           | ((8U & 
                                               (((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                   >> 3U)) 
                                                 << 3U) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                              | ((4U 
                                                  & (((~ 
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
        bufp->chgCData(oldp+112,(((0x80U & (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                 >> 0xfU)) 
                                             << 7U) 
                                            & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                               >> 8U))) 
                                  | ((0x40U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 0xeU)) 
                                                << 6U) 
                                               & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                  >> 8U))) 
                                     | ((0x20U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 0xdU)) 
                                                   << 5U) 
                                                  & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                     >> 8U))) 
                                        | ((0x10U & 
                                            (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 0xcU)) 
                                              << 4U) 
                                             & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                >> 8U))) 
                                           | ((8U & 
                                               (((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                   >> 0xbU)) 
                                                 << 3U) 
                                                & (((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)) 
                                                   >> 8U))) 
                                              | ((4U 
                                                  & (((~ 
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
        bufp->chgCData(oldp+113,(((0x80U & (((0x80U 
                                              & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 7U)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 7U))
                                              : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 7U)) 
                                            << 7U)) 
                                  | ((0x40U & (((0x40U 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 6U)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 6U))
                                                 : 
                                                ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 6U)) 
                                               << 6U)) 
                                     | ((0x20U & ((
                                                   (0x20U 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 5U)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                       >> 5U))
                                                    : 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 5U)) 
                                                  << 5U)) 
                                        | ((0x10U & 
                                            (((0x10U 
                                               & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                               ? ((~ 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    >> 4U)) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                     >> 4U))
                                               : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 4U)) 
                                             << 4U)) 
                                           | ((8U & 
                                               (((8U 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    >> 3U)) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                     >> 3U))
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 3U)) 
                                                << 3U)) 
                                              | ((4U 
                                                  & (((4U 
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
                                                 | ((2U 
                                                     & (((2U 
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
        bufp->chgCData(oldp+114,(((0x80U & (((0x8000U 
                                              & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                              ? ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 0xfU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 0xfU))
                                              : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 0xfU)) 
                                            << 7U)) 
                                  | ((0x40U & (((0x4000U 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   >> 0xeU)) 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 0xeU))
                                                 : 
                                                ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                 >> 0xeU)) 
                                               << 6U)) 
                                     | ((0x20U & ((
                                                   (0x2000U 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      >> 0xdU)) 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                       >> 0xdU))
                                                    : 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                    >> 0xdU)) 
                                                  << 5U)) 
                                        | ((0x10U & 
                                            (((0x1000U 
                                               & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                               ? ((~ 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    >> 0xcU)) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                     >> 0xcU))
                                               : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 0xcU)) 
                                             << 4U)) 
                                           | ((8U & 
                                               (((0x800U 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    >> 0xbU)) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                     >> 0xbU))
                                                  : 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 0xbU)) 
                                                << 3U)) 
                                              | ((4U 
                                                  & (((0x400U 
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
                                                 | ((2U 
                                                     & (((0x200U 
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
    }
    bufp->chgBit(oldp+115,(vlSelf->clock));
    bufp->chgBit(oldp+116,(vlSelf->reset));
    bufp->chgBit(oldp+117,(vlSelf->io_apb_PSEL));
    bufp->chgBit(oldp+118,(vlSelf->io_apb_PENABLE));
    bufp->chgBit(oldp+119,(vlSelf->io_apb_PWRITE));
    bufp->chgCData(oldp+120,(vlSelf->io_apb_PADDR),8);
    bufp->chgSData(oldp+121,(vlSelf->io_apb_PWDATA),16);
    bufp->chgSData(oldp+122,(vlSelf->io_apb_PRDATA),16);
    bufp->chgBit(oldp+123,(vlSelf->io_apb_PREADY));
    bufp->chgBit(oldp+124,(vlSelf->io_apb_PSLVERR));
    bufp->chgSData(oldp+125,(vlSelf->io_pins_gpioInput),16);
    bufp->chgSData(oldp+126,(vlSelf->io_pins_gpioOutput),16);
    bufp->chgSData(oldp+127,(vlSelf->io_pins_gpioOutputEnable),16);
    bufp->chgBit(oldp+128,(vlSelf->io_pins_irqOutput));
    bufp->chgCData(oldp+129,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(2U)))),8);
    bufp->chgCData(oldp+130,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(6U)))),8);
    bufp->chgCData(oldp+131,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(8U)))),8);
    bufp->chgCData(oldp+132,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(9U)))),8);
    bufp->chgCData(oldp+133,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0xbU)))),8);
    bufp->chgCData(oldp+134,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0xcU)))),8);
    bufp->chgCData(oldp+135,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x14U)))),8);
    bufp->chgCData(oldp+136,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x15U)))),8);
    bufp->chgCData(oldp+137,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x16U)))),8);
    bufp->chgCData(oldp+138,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x18U)))),8);
    bufp->chgCData(oldp+139,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x1aU)))),8);
    bufp->chgCData(oldp+140,((0xffU & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(0x1eU)))),8);
}

void VGPIO___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root__trace_cleanup\n"); );
    // Init
    VGPIO___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VGPIO___024root*>(voidSelf);
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
