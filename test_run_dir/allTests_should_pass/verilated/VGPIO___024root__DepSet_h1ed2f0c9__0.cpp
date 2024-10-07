// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGPIO.h for the primary calling header

#include "VGPIO__pch.h"
#include "VGPIO___024root.h"

VL_INLINE_OPT void VGPIO___024root___ico_sequent__TOP__0(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___ico_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ GPIO__DOT___GEN_853;
    GPIO__DOT___GEN_853 = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    // Body
    vlSelf->io_apb_PSLVERR = (0x1fU < (IData)(vlSelf->io_apb_PADDR));
    vlSelf->GPIO__DOT___GEN_807 = (0x1fU & ((0U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0)));
    vlSelf->GPIO__DOT___GEN_808 = (0x1fU & ((1U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1)));
    vlSelf->GPIO__DOT___GEN_809 = (0x1fU & ((2U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2)));
    vlSelf->GPIO__DOT___GEN_810 = (0x1fU & ((3U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3)));
    vlSelf->GPIO__DOT___GEN_811 = (0x1fU & ((4U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4)));
    vlSelf->GPIO__DOT___GEN_812 = (0x1fU & ((5U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5)));
    vlSelf->GPIO__DOT___GEN_813 = (0x1fU & ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6)));
    vlSelf->GPIO__DOT___GEN_814 = (0x1fU & ((7U == 
                                             (7U & 
                                              ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                             ? (IData)(vlSelf->io_apb_PWDATA)
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7)));
    vlSelf->GPIO__DOT___T_948 = ((0x14U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x14U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_952 = ((0x15U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x15U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_956 = ((0x16U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x17U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_960 = ((0x18U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x19U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_964 = ((0x1aU <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x1bU >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_972 = ((0x1eU <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x1fU >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_943 = ((0xcU <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0x13U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_923 = ((2U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (3U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_927 = ((6U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (7U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_931 = ((8U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (8U >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_935 = ((9U <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0xaU >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->GPIO__DOT___T_939 = ((0xbU <= (IData)(vlSelf->io_apb_PADDR)) 
                                 & (0xbU >= (IData)(vlSelf->io_apb_PADDR)));
    vlSelf->io_apb_PREADY = ((IData)(vlSelf->io_apb_PENABLE) 
                             & (IData)(vlSelf->io_apb_PSEL));
    GPIO__DOT___GEN_853 = ((IData)(vlSelf->GPIO__DOT___T_943)
                            ? ((7U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                             - (IData)(4U))))
                                ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7)
                                : ((6U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                                 - (IData)(4U))))
                                    ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6)
                                    : ((5U == (7U & 
                                               ((IData)(vlSelf->io_apb_PADDR) 
                                                - (IData)(4U))))
                                        ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5)
                                        : ((4U == (7U 
                                                   & ((IData)(vlSelf->io_apb_PADDR) 
                                                      - (IData)(4U))))
                                            ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4)
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->io_apb_PADDR) 
                                                    - (IData)(4U))))
                                                ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3)
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & ((IData)(vlSelf->io_apb_PADDR) 
                                                        - (IData)(4U))))
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlSelf->io_apb_PADDR) 
                                                         - (IData)(4U))))
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1)
                                                     : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))))))))
                            : ((IData)(vlSelf->GPIO__DOT___T_939)
                                ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_SET)
                                : ((IData)(vlSelf->GPIO__DOT___T_935)
                                    ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK)
                                    : ((IData)(vlSelf->GPIO__DOT___T_931)
                                        ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                        : ((IData)(vlSelf->GPIO__DOT___T_927)
                                            ? (IData)(vlSelf->GPIO__DOT__regs_MODE)
                                            : (((4U 
                                                 <= (IData)(vlSelf->io_apb_PADDR)) 
                                                & (5U 
                                                   >= (IData)(vlSelf->io_apb_PADDR)))
                                                ? (IData)(vlSelf->GPIO__DOT__regs_INPUT)
                                                : ((IData)(vlSelf->GPIO__DOT___T_923)
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)
                                                    : 
                                                   ((1U 
                                                     >= (IData)(vlSelf->io_apb_PADDR))
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)
                                                     : 0U))))))));
    __Vtemp_3[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_4, __Vtemp_3, (0x3fU 
                                                  & VL_SHIFTL_III(6,6,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelf->io_apb_PADDR)), 3U)));
    __Vtemp_15[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_16, __Vtemp_15, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_26[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_26[1U] = 0U;
    __Vtemp_26[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_27, __Vtemp_26, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(1U))), 3U)));
    __Vtemp_37[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_37[1U] = 0U;
    __Vtemp_37[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_38, __Vtemp_37, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_48[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_48[1U] = 0U;
    __Vtemp_48[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_49, __Vtemp_48, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & (IData)(vlSelf->io_apb_PADDR)), 3U)));
    __Vtemp_59[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_60, __Vtemp_59, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_70[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_70[1U] = 0U;
    __Vtemp_70[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_71, __Vtemp_70, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    if (vlSelf->reset) {
        vlSelf->GPIO__DOT___GEN_1225[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1228 = 0ULL;
        vlSelf->GPIO__DOT___GEN_1229[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1230 = 0U;
        vlSelf->GPIO__DOT___GEN_1232 = 0U;
        vlSelf->GPIO__DOT___GEN_1233[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
    } else if (vlSelf->io_apb_PREADY) {
        if (vlSelf->io_apb_PWRITE) {
            if ((1U >= (IData)(vlSelf->io_apb_PADDR))) {
                vlSelf->GPIO__DOT___GEN_1225[0U] = 
                    __Vtemp_4[0U];
                vlSelf->GPIO__DOT___GEN_1225[1U] = 
                    __Vtemp_4[1U];
                vlSelf->GPIO__DOT___GEN_1225[2U] = 
                    (0x7fffU & __Vtemp_4[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
                vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_927) {
                vlSelf->GPIO__DOT___GEN_1227[0U] = 
                    __Vtemp_16[0U];
                vlSelf->GPIO__DOT___GEN_1227[1U] = 
                    __Vtemp_16[1U];
                vlSelf->GPIO__DOT___GEN_1227[2U] = 
                    (0x7fffU & __Vtemp_16[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
                vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
            }
            vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                            & ((IData)(vlSelf->GPIO__DOT___T_931)
                                                ? ((QData)((IData)(
                                                                   (0xfU 
                                                                    & (IData)(vlSelf->io_apb_PWDATA)))) 
                                                   << 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(5,5,32, 
                                                                    (1U 
                                                                     & (IData)(vlSelf->io_apb_PADDR)), 3U)))
                                                : (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION))));
            if (vlSelf->GPIO__DOT___T_935) {
                vlSelf->GPIO__DOT___GEN_1229[0U] = 
                    __Vtemp_27[0U];
                vlSelf->GPIO__DOT___GEN_1229[1U] = 
                    __Vtemp_27[1U];
                vlSelf->GPIO__DOT___GEN_1229[2U] = 
                    (0x7fffU & __Vtemp_27[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
                vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
            }
            vlSelf->GPIO__DOT___GEN_1230 = ((IData)(vlSelf->GPIO__DOT___T_939)
                                             ? ((1U 
                                                 & (IData)(vlSelf->io_apb_PWDATA)) 
                                                << 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (1U 
                                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                                     - (IData)(1U))), 3U)))
                                             : (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_SET));
            vlSelf->GPIO__DOT___GEN_1232 = ((IData)(vlSelf->GPIO__DOT___T_952)
                                             ? ((1U 
                                                 & (IData)(vlSelf->io_apb_PWDATA)) 
                                                << 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (1U 
                                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                                     - (IData)(1U))), 3U)))
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable));
            if (vlSelf->GPIO__DOT___T_956) {
                vlSelf->GPIO__DOT___GEN_1233[0U] = 
                    __Vtemp_38[0U];
                vlSelf->GPIO__DOT___GEN_1233[1U] = 
                    __Vtemp_38[1U];
                vlSelf->GPIO__DOT___GEN_1233[2U] = 
                    (0x7fffU & __Vtemp_38[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
                vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_960) {
                vlSelf->GPIO__DOT___GEN_1234[0U] = 
                    __Vtemp_49[0U];
                vlSelf->GPIO__DOT___GEN_1234[1U] = 
                    __Vtemp_49[1U];
                vlSelf->GPIO__DOT___GEN_1234[2U] = 
                    (0x7fffU & __Vtemp_49[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
                vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_964) {
                vlSelf->GPIO__DOT___GEN_1235[0U] = 
                    __Vtemp_60[0U];
                vlSelf->GPIO__DOT___GEN_1235[1U] = 
                    __Vtemp_60[1U];
                vlSelf->GPIO__DOT___GEN_1235[2U] = 
                    (0x7fffU & __Vtemp_60[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
                vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_972) {
                vlSelf->GPIO__DOT___GEN_1236[0U] = 
                    __Vtemp_71[0U];
                vlSelf->GPIO__DOT___GEN_1236[1U] = 
                    __Vtemp_71[1U];
                vlSelf->GPIO__DOT___GEN_1236[2U] = 
                    (0x7fffU & __Vtemp_71[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
                vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
            }
        } else {
            vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
            vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
            vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                            & (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)));
            vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
            vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1230 = vlSelf->GPIO__DOT__regs_ATOMIC_SET;
            vlSelf->GPIO__DOT___GEN_1232 = vlSelf->GPIO__DOT__regs_virtualPortEnable;
            vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
            vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
            vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
            vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
            vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
        }
    } else {
        vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
        vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
        vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                        & (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)));
        vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
        vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1230 = vlSelf->GPIO__DOT__regs_ATOMIC_SET;
        vlSelf->GPIO__DOT___GEN_1232 = vlSelf->GPIO__DOT__regs_virtualPortEnable;
        vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
        vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
        vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
        vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
        vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
    }
    vlSelf->io_apb_PRDATA = ((IData)(vlSelf->io_apb_PREADY)
                              ? ((IData)(vlSelf->io_apb_PWRITE)
                                  ? 0U : ((IData)(vlSelf->GPIO__DOT___T_972)
                                           ? (IData)(vlSelf->GPIO__DOT__regs_IRQ_ENABLE)
                                           : (((0x1cU 
                                                <= (IData)(vlSelf->io_apb_PADDR)) 
                                               & (0x1dU 
                                                  >= (IData)(vlSelf->io_apb_PADDR)))
                                               ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_STATUS)
                                               : ((IData)(vlSelf->GPIO__DOT___T_964)
                                                   ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI)
                                                   : 
                                                  ((IData)(vlSelf->GPIO__DOT___T_960)
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO)
                                                    : 
                                                   ((IData)(vlSelf->GPIO__DOT___T_956)
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE)
                                                     : 
                                                    ((IData)(vlSelf->GPIO__DOT___T_952)
                                                      ? (IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                                                      : 
                                                     ((IData)(vlSelf->GPIO__DOT___T_948)
                                                       ? (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)
                                                       : (IData)(GPIO__DOT___GEN_853)))))))))
                              : 0U);
}

void VGPIO___024root___eval_ico(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VGPIO___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VGPIO___024root___eval_triggers__ico(VGPIO___024root* vlSelf);

bool VGPIO___024root___eval_phase__ico(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VGPIO___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VGPIO___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VGPIO___024root___eval_act(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_act\n"); );
}

VL_INLINE_OPT void VGPIO___024root___nba_sequent__TOP__1(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*15:0*/ GPIO__DOT___GEN_853;
    GPIO__DOT___GEN_853 = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    // Body
    GPIO__DOT___GEN_853 = ((IData)(vlSelf->GPIO__DOT___T_943)
                            ? ((7U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                             - (IData)(4U))))
                                ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7)
                                : ((6U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                                 - (IData)(4U))))
                                    ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6)
                                    : ((5U == (7U & 
                                               ((IData)(vlSelf->io_apb_PADDR) 
                                                - (IData)(4U))))
                                        ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5)
                                        : ((4U == (7U 
                                                   & ((IData)(vlSelf->io_apb_PADDR) 
                                                      - (IData)(4U))))
                                            ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4)
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->io_apb_PADDR) 
                                                    - (IData)(4U))))
                                                ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3)
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & ((IData)(vlSelf->io_apb_PADDR) 
                                                        - (IData)(4U))))
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlSelf->io_apb_PADDR) 
                                                         - (IData)(4U))))
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1)
                                                     : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))))))))
                            : ((IData)(vlSelf->GPIO__DOT___T_939)
                                ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_SET)
                                : ((IData)(vlSelf->GPIO__DOT___T_935)
                                    ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK)
                                    : ((IData)(vlSelf->GPIO__DOT___T_931)
                                        ? (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)
                                        : ((IData)(vlSelf->GPIO__DOT___T_927)
                                            ? (IData)(vlSelf->GPIO__DOT__regs_MODE)
                                            : (((4U 
                                                 <= (IData)(vlSelf->io_apb_PADDR)) 
                                                & (5U 
                                                   >= (IData)(vlSelf->io_apb_PADDR)))
                                                ? (IData)(vlSelf->GPIO__DOT__regs_INPUT)
                                                : ((IData)(vlSelf->GPIO__DOT___T_923)
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)
                                                    : 
                                                   ((1U 
                                                     >= (IData)(vlSelf->io_apb_PADDR))
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)
                                                     : 0U))))))));
    __Vtemp_3[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_4, __Vtemp_3, (0x3fU 
                                                  & VL_SHIFTL_III(6,6,32, 
                                                                  (3U 
                                                                   & (IData)(vlSelf->io_apb_PADDR)), 3U)));
    __Vtemp_15[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_16, __Vtemp_15, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_26[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_26[1U] = 0U;
    __Vtemp_26[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_27, __Vtemp_26, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(1U))), 3U)));
    __Vtemp_37[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_37[1U] = 0U;
    __Vtemp_37[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_38, __Vtemp_37, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_48[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_48[1U] = 0U;
    __Vtemp_48[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_49, __Vtemp_48, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & (IData)(vlSelf->io_apb_PADDR)), 3U)));
    __Vtemp_59[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_60, __Vtemp_59, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    __Vtemp_70[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_70[1U] = 0U;
    __Vtemp_70[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_71, __Vtemp_70, 
                  (0x3fU & VL_SHIFTL_III(6,6,32, (3U 
                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                     - (IData)(2U))), 3U)));
    if (vlSelf->reset) {
        vlSelf->GPIO__DOT___GEN_1225[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1228 = 0ULL;
        vlSelf->GPIO__DOT___GEN_1229[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1232 = 0U;
        vlSelf->GPIO__DOT___GEN_1233[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[0U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1230 = 0U;
    } else if (vlSelf->io_apb_PREADY) {
        if (vlSelf->io_apb_PWRITE) {
            if ((1U >= (IData)(vlSelf->io_apb_PADDR))) {
                vlSelf->GPIO__DOT___GEN_1225[0U] = 
                    __Vtemp_4[0U];
                vlSelf->GPIO__DOT___GEN_1225[1U] = 
                    __Vtemp_4[1U];
                vlSelf->GPIO__DOT___GEN_1225[2U] = 
                    (0x7fffU & __Vtemp_4[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
                vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_927) {
                vlSelf->GPIO__DOT___GEN_1227[0U] = 
                    __Vtemp_16[0U];
                vlSelf->GPIO__DOT___GEN_1227[1U] = 
                    __Vtemp_16[1U];
                vlSelf->GPIO__DOT___GEN_1227[2U] = 
                    (0x7fffU & __Vtemp_16[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
                vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
            }
            vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                            & ((IData)(vlSelf->GPIO__DOT___T_931)
                                                ? ((QData)((IData)(
                                                                   (0xfU 
                                                                    & (IData)(vlSelf->io_apb_PWDATA)))) 
                                                   << 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(5,5,32, 
                                                                    (1U 
                                                                     & (IData)(vlSelf->io_apb_PADDR)), 3U)))
                                                : (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION))));
            if (vlSelf->GPIO__DOT___T_935) {
                vlSelf->GPIO__DOT___GEN_1229[0U] = 
                    __Vtemp_27[0U];
                vlSelf->GPIO__DOT___GEN_1229[1U] = 
                    __Vtemp_27[1U];
                vlSelf->GPIO__DOT___GEN_1229[2U] = 
                    (0x7fffU & __Vtemp_27[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
                vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
            }
            vlSelf->GPIO__DOT___GEN_1232 = ((IData)(vlSelf->GPIO__DOT___T_952)
                                             ? ((1U 
                                                 & (IData)(vlSelf->io_apb_PWDATA)) 
                                                << 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (1U 
                                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                                     - (IData)(1U))), 3U)))
                                             : (IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable));
            if (vlSelf->GPIO__DOT___T_956) {
                vlSelf->GPIO__DOT___GEN_1233[0U] = 
                    __Vtemp_38[0U];
                vlSelf->GPIO__DOT___GEN_1233[1U] = 
                    __Vtemp_38[1U];
                vlSelf->GPIO__DOT___GEN_1233[2U] = 
                    (0x7fffU & __Vtemp_38[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
                vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_960) {
                vlSelf->GPIO__DOT___GEN_1234[0U] = 
                    __Vtemp_49[0U];
                vlSelf->GPIO__DOT___GEN_1234[1U] = 
                    __Vtemp_49[1U];
                vlSelf->GPIO__DOT___GEN_1234[2U] = 
                    (0x7fffU & __Vtemp_49[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
                vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_964) {
                vlSelf->GPIO__DOT___GEN_1235[0U] = 
                    __Vtemp_60[0U];
                vlSelf->GPIO__DOT___GEN_1235[1U] = 
                    __Vtemp_60[1U];
                vlSelf->GPIO__DOT___GEN_1235[2U] = 
                    (0x7fffU & __Vtemp_60[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
                vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
            }
            if (vlSelf->GPIO__DOT___T_972) {
                vlSelf->GPIO__DOT___GEN_1236[0U] = 
                    __Vtemp_71[0U];
                vlSelf->GPIO__DOT___GEN_1236[1U] = 
                    __Vtemp_71[1U];
                vlSelf->GPIO__DOT___GEN_1236[2U] = 
                    (0x7fffU & __Vtemp_71[2U]);
            } else {
                vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
                vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
                vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
            }
            vlSelf->GPIO__DOT___GEN_1230 = ((IData)(vlSelf->GPIO__DOT___T_939)
                                             ? ((1U 
                                                 & (IData)(vlSelf->io_apb_PWDATA)) 
                                                << 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (1U 
                                                                  & ((IData)(vlSelf->io_apb_PADDR) 
                                                                     - (IData)(1U))), 3U)))
                                             : (IData)(vlSelf->GPIO__DOT__regs_ATOMIC_SET));
        } else {
            vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
            vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
            vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                            & (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)));
            vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
            vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1232 = vlSelf->GPIO__DOT__regs_virtualPortEnable;
            vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
            vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
            vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
            vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
            vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
            vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
            vlSelf->GPIO__DOT___GEN_1230 = vlSelf->GPIO__DOT__regs_ATOMIC_SET;
        }
    } else {
        vlSelf->GPIO__DOT___GEN_1225[0U] = vlSelf->GPIO__DOT__regs_DIRECTION;
        vlSelf->GPIO__DOT___GEN_1225[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1225[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[0U] = vlSelf->GPIO__DOT__regs_MODE;
        vlSelf->GPIO__DOT___GEN_1227[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1227[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1228 = (0x7ffffffffULL 
                                        & (QData)((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION)));
        vlSelf->GPIO__DOT___GEN_1229[0U] = vlSelf->GPIO__DOT__regs_ATOMIC_MASK;
        vlSelf->GPIO__DOT___GEN_1229[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1229[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1232 = vlSelf->GPIO__DOT__regs_virtualPortEnable;
        vlSelf->GPIO__DOT___GEN_1233[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_TYPE;
        vlSelf->GPIO__DOT___GEN_1233[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1233[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_LO;
        vlSelf->GPIO__DOT___GEN_1234[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1234[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[0U] = vlSelf->GPIO__DOT__regs_TRIGGER_HI;
        vlSelf->GPIO__DOT___GEN_1235[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1235[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[0U] = vlSelf->GPIO__DOT__regs_IRQ_ENABLE;
        vlSelf->GPIO__DOT___GEN_1236[1U] = 0U;
        vlSelf->GPIO__DOT___GEN_1236[2U] = 0U;
        vlSelf->GPIO__DOT___GEN_1230 = vlSelf->GPIO__DOT__regs_ATOMIC_SET;
    }
    vlSelf->io_apb_PRDATA = ((IData)(vlSelf->io_apb_PREADY)
                              ? ((IData)(vlSelf->io_apb_PWRITE)
                                  ? 0U : ((IData)(vlSelf->GPIO__DOT___T_972)
                                           ? (IData)(vlSelf->GPIO__DOT__regs_IRQ_ENABLE)
                                           : (((0x1cU 
                                                <= (IData)(vlSelf->io_apb_PADDR)) 
                                               & (0x1dU 
                                                  >= (IData)(vlSelf->io_apb_PADDR)))
                                               ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_STATUS)
                                               : ((IData)(vlSelf->GPIO__DOT___T_964)
                                                   ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI)
                                                   : 
                                                  ((IData)(vlSelf->GPIO__DOT___T_960)
                                                    ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO)
                                                    : 
                                                   ((IData)(vlSelf->GPIO__DOT___T_956)
                                                     ? (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE)
                                                     : 
                                                    ((IData)(vlSelf->GPIO__DOT___T_952)
                                                      ? (IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                                                      : 
                                                     ((IData)(vlSelf->GPIO__DOT___T_948)
                                                       ? (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)
                                                       : (IData)(GPIO__DOT___GEN_853)))))))))
                              : 0U);
}

void VGPIO___024root___nba_sequent__TOP__0(VGPIO___024root* vlSelf);

void VGPIO___024root___eval_nba(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VGPIO___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        VGPIO___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VGPIO___024root___eval_triggers__act(VGPIO___024root* vlSelf);

bool VGPIO___024root___eval_phase__act(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VGPIO___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VGPIO___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VGPIO___024root___eval_phase__nba(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VGPIO___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__ico(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__nba(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__act(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG

void VGPIO___024root___eval(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VGPIO___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("GPIO.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VGPIO___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VGPIO___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("GPIO.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VGPIO___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("GPIO.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VGPIO___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VGPIO___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VGPIO___024root___eval_debug_assertions(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_apb_PSEL & 0xfeU))) {
        Verilated::overWidthError("io_apb_PSEL");}
    if (VL_UNLIKELY((vlSelf->io_apb_PENABLE & 0xfeU))) {
        Verilated::overWidthError("io_apb_PENABLE");}
    if (VL_UNLIKELY((vlSelf->io_apb_PWRITE & 0xfeU))) {
        Verilated::overWidthError("io_apb_PWRITE");}
}
#endif  // VL_DEBUG
