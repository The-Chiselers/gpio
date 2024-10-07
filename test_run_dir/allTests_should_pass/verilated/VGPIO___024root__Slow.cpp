// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGPIO.h for the primary calling header

#include "VGPIO__pch.h"
#include "VGPIO__Syms.h"
#include "VGPIO___024root.h"

void VGPIO___024root___ctor_var_reset(VGPIO___024root* vlSelf);

VGPIO___024root::VGPIO___024root(VGPIO__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VGPIO___024root___ctor_var_reset(this);
}

void VGPIO___024root___configure_coverage(VGPIO___024root* vlSelf, bool first);

void VGPIO___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    VGPIO___024root___configure_coverage(this, first);
}

VGPIO___024root::~VGPIO___024root() {
}

// Coverage
void VGPIO___024root::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), VerilatedModule::name(), count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string{VerilatedModule::name()} + hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}
