// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VGPIO.h for the primary calling header

#ifndef VERILATED_VGPIO___024ROOT_H_
#define VERILATED_VGPIO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class VGPIO__Syms;

class alignas(VL_CACHE_LINE_BYTES) VGPIO___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_apb_PSEL,0,0);
        VL_IN8(io_apb_PENABLE,0,0);
        VL_IN8(io_apb_PWRITE,0,0);
        VL_IN8(io_apb_PADDR,7,0);
        VL_OUT8(io_apb_PREADY,0,0);
        VL_OUT8(io_apb_PSLVERR,0,0);
        VL_OUT8(io_pins_irqOutput,0,0);
        CData/*3:0*/ GPIO__DOT__regs_ATOMIC_OPERATION;
        CData/*0:0*/ GPIO__DOT__regs_ATOMIC_SET;
        CData/*7:0*/ GPIO__DOT__regs_virtualPortOutput;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_0;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_1;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_2;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_3;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_4;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_5;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_6;
        CData/*4:0*/ GPIO__DOT__regs_virtualToPhysicalMap_7;
        CData/*0:0*/ GPIO__DOT__regs_virtualPortEnable;
        CData/*7:0*/ GPIO__DOT___GEN_799;
        CData/*0:0*/ GPIO__DOT___T_923;
        CData/*0:0*/ GPIO__DOT___T_927;
        CData/*0:0*/ GPIO__DOT___T_931;
        CData/*0:0*/ GPIO__DOT___T_935;
        CData/*0:0*/ GPIO__DOT___T_939;
        CData/*0:0*/ GPIO__DOT___T_943;
        CData/*4:0*/ GPIO__DOT___GEN_807;
        CData/*4:0*/ GPIO__DOT___GEN_808;
        CData/*4:0*/ GPIO__DOT___GEN_809;
        CData/*4:0*/ GPIO__DOT___GEN_810;
        CData/*4:0*/ GPIO__DOT___GEN_811;
        CData/*4:0*/ GPIO__DOT___GEN_812;
        CData/*4:0*/ GPIO__DOT___GEN_813;
        CData/*4:0*/ GPIO__DOT___GEN_814;
        CData/*0:0*/ GPIO__DOT___T_948;
        CData/*0:0*/ GPIO__DOT___T_952;
        CData/*0:0*/ GPIO__DOT___T_956;
        CData/*0:0*/ GPIO__DOT___T_960;
        CData/*0:0*/ GPIO__DOT___T_964;
        CData/*0:0*/ GPIO__DOT___T_972;
        CData/*2:0*/ GPIO__DOT__condition;
        CData/*2:0*/ GPIO__DOT__condition_1;
        CData/*2:0*/ GPIO__DOT__condition_2;
        CData/*2:0*/ GPIO__DOT__condition_3;
        CData/*2:0*/ GPIO__DOT__condition_4;
        CData/*2:0*/ GPIO__DOT__condition_5;
        CData/*2:0*/ GPIO__DOT__condition_6;
        CData/*2:0*/ GPIO__DOT__condition_7;
        CData/*2:0*/ GPIO__DOT__condition_8;
        CData/*2:0*/ GPIO__DOT__condition_9;
        CData/*2:0*/ GPIO__DOT__condition_10;
        CData/*2:0*/ GPIO__DOT__condition_11;
        CData/*2:0*/ GPIO__DOT__condition_12;
        CData/*2:0*/ GPIO__DOT__condition_13;
        CData/*2:0*/ GPIO__DOT__condition_14;
        CData/*2:0*/ GPIO__DOT__condition_15;
        CData/*7:0*/ GPIO__DOT__TRIGGER_STATUS_lo;
        CData/*7:0*/ GPIO__DOT__OUTPUT_lo;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        VL_IN16(io_apb_PWDATA,15,0);
        VL_OUT16(io_apb_PRDATA,15,0);
        VL_IN16(io_pins_gpioInput,15,0);
        VL_OUT16(io_pins_gpioOutput,15,0);
        VL_OUT16(io_pins_gpioOutputEnable,15,0);
        SData/*15:0*/ GPIO__DOT__regs_DIRECTION;
        SData/*15:0*/ GPIO__DOT__regs_OUTPUT;
        SData/*15:0*/ GPIO__DOT__regs_INPUT;
        SData/*15:0*/ GPIO__DOT__regs_MODE;
        SData/*15:0*/ GPIO__DOT__regs_ATOMIC_MASK;
        SData/*15:0*/ GPIO__DOT__regs_TRIGGER_TYPE;
        SData/*15:0*/ GPIO__DOT__regs_TRIGGER_LO;
        SData/*15:0*/ GPIO__DOT__regs_TRIGGER_HI;
        SData/*15:0*/ GPIO__DOT__regs_TRIGGER_STATUS;
        SData/*15:0*/ GPIO__DOT__regs_IRQ_ENABLE;
        SData/*15:0*/ GPIO__DOT__gpioInputSyncPrev;
        SData/*15:0*/ GPIO__DOT__gpioInputSync_REG;
        SData/*15:0*/ GPIO__DOT__gpioInputSync;
        SData/*15:0*/ GPIO__DOT___GEN_798;
        SData/*15:0*/ GPIO__DOT___TRIGGER_STATUS_T_35;
        SData/*15:0*/ GPIO__DOT___OUTPUT_T_673;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1225;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1227;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1229;
        IData/*31:0*/ GPIO__DOT___GEN_1230;
        IData/*31:0*/ GPIO__DOT___GEN_1232;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1233;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1234;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1235;
        VlWide<3>/*78:0*/ GPIO__DOT___GEN_1236;
        IData/*31:0*/ __VactIterCount;
        QData/*34:0*/ GPIO__DOT___GEN_1228;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VGPIO__Syms* const vlSymsp;

    // CONSTRUCTORS
    VGPIO___024root(VGPIO__Syms* symsp, const char* v__name);
    ~VGPIO___024root();
    VL_UNCOPYABLE(VGPIO___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
