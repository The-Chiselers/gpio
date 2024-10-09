// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VGPIO__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VGPIO::VGPIO(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VGPIO__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_apb_PSEL{vlSymsp->TOP.io_apb_PSEL}
    , io_apb_PENABLE{vlSymsp->TOP.io_apb_PENABLE}
    , io_apb_PWRITE{vlSymsp->TOP.io_apb_PWRITE}
    , io_apb_PADDR{vlSymsp->TOP.io_apb_PADDR}
    , io_apb_PREADY{vlSymsp->TOP.io_apb_PREADY}
    , io_apb_PSLVERR{vlSymsp->TOP.io_apb_PSLVERR}
    , io_pins_irqOutput{vlSymsp->TOP.io_pins_irqOutput}
    , io_apb_PWDATA{vlSymsp->TOP.io_apb_PWDATA}
    , io_apb_PRDATA{vlSymsp->TOP.io_apb_PRDATA}
    , io_pins_gpioInput{vlSymsp->TOP.io_pins_gpioInput}
    , io_pins_gpioOutput{vlSymsp->TOP.io_pins_gpioOutput}
    , io_pins_gpioOutputEnable{vlSymsp->TOP.io_pins_gpioOutputEnable}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VGPIO::VGPIO(const char* _vcname__)
    : VGPIO(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VGPIO::~VGPIO() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VGPIO___024root___eval_debug_assertions(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG
void VGPIO___024root___eval_static(VGPIO___024root* vlSelf);
void VGPIO___024root___eval_initial(VGPIO___024root* vlSelf);
void VGPIO___024root___eval_settle(VGPIO___024root* vlSelf);
void VGPIO___024root___eval(VGPIO___024root* vlSelf);

void VGPIO::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VGPIO::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VGPIO___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VGPIO___024root___eval_static(&(vlSymsp->TOP));
        VGPIO___024root___eval_initial(&(vlSymsp->TOP));
        VGPIO___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VGPIO___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VGPIO::eventsPending() { return false; }

uint64_t VGPIO::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VGPIO::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VGPIO___024root___eval_final(VGPIO___024root* vlSelf);

VL_ATTR_COLD void VGPIO::final() {
    VGPIO___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VGPIO::hierName() const { return vlSymsp->name(); }
const char* VGPIO::modelName() const { return "VGPIO"; }
unsigned VGPIO::threads() const { return 1; }
void VGPIO::prepareClone() const { contextp()->prepareClone(); }
void VGPIO::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VGPIO::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VGPIO___024root__trace_decl_types(VerilatedVcd* tracep);

void VGPIO___024root__trace_init_top(VGPIO___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VGPIO___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VGPIO___024root*>(voidSelf);
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VGPIO___024root__trace_decl_types(tracep);
    VGPIO___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VGPIO___024root__trace_register(VGPIO___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VGPIO::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VGPIO::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VGPIO___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
