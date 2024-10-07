// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGPIO.h for the primary calling header

#include "VGPIO__pch.h"
#include "VGPIO__Syms.h"
#include "VGPIO___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__stl(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VGPIO___024root___eval_triggers__stl(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VGPIO___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void VGPIO___024root___configure_coverage(VGPIO___024root* vlSelf, bool first) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___configure_coverage\n"); );
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "GPIO.sv", 1982, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "GPIO.sv", 1986, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "GPIO.sv", 1990, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "GPIO.sv", 1994, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "GPIO.sv", 1998, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "GPIO.sv", 2002, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "GPIO.sv", 2006, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "GPIO.sv", 2010, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "GPIO.sv", 2014, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "GPIO.sv", 2018, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "GPIO.sv", 2022, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "GPIO.sv", 2026, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "GPIO.sv", 2030, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "GPIO.sv", 2034, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "GPIO.sv", 2038, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "GPIO.sv", 2042, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "GPIO.sv", 2046, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "GPIO.sv", 2050, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "GPIO.sv", 2054, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "GPIO.sv", 2058, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "GPIO.sv", 2062, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "GPIO.sv", 2066, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "GPIO.sv", 2070, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "GPIO.sv", 2074, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "GPIO.sv", 2078, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "GPIO.sv", 2082, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "GPIO.sv", 2086, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "GPIO.sv", 2090, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "GPIO.sv", 2094, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "GPIO.sv", 2098, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "GPIO.sv", 2102, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "GPIO.sv", 2106, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "GPIO.sv", 2110, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "GPIO.sv", 2114, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "GPIO.sv", 2118, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "GPIO.sv", 2122, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "GPIO.sv", 2126, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "GPIO.sv", 2130, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "GPIO.sv", 2134, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "GPIO.sv", 2138, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "GPIO.sv", 2142, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "GPIO.sv", 2146, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "GPIO.sv", 2150, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "GPIO.sv", 2154, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "GPIO.sv", 2158, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "GPIO.sv", 2162, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "GPIO.sv", 2166, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "GPIO.sv", 2170, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "GPIO.sv", 2174, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "GPIO.sv", 2178, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "GPIO.sv", 2182, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "GPIO.sv", 2186, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "GPIO.sv", 2190, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "GPIO.sv", 2194, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "GPIO.sv", 2198, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "GPIO.sv", 2202, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "GPIO.sv", 2206, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "GPIO.sv", 2210, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "GPIO.sv", 2214, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "GPIO.sv", 2218, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "GPIO.sv", 2222, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "GPIO.sv", 2226, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "GPIO.sv", 2230, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "GPIO.sv", 2234, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "GPIO.sv", 2238, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "GPIO.sv", 2242, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "GPIO.sv", 2246, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "GPIO.sv", 2250, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "GPIO.sv", 2254, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "GPIO.sv", 2258, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "GPIO.sv", 2262, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "GPIO.sv", 2266, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "GPIO.sv", 2270, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "GPIO.sv", 2274, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "GPIO.sv", 2278, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "GPIO.sv", 2282, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "GPIO.sv", 2286, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "GPIO.sv", 2290, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "GPIO.sv", 2294, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "GPIO.sv", 2298, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "GPIO.sv", 2302, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "GPIO.sv", 2306, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "GPIO.sv", 2310, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "GPIO.sv", 2314, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "GPIO.sv", 2318, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "GPIO.sv", 2322, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "GPIO.sv", 2326, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "GPIO.sv", 2330, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "GPIO.sv", 2334, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "GPIO.sv", 2338, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "GPIO.sv", 2342, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "GPIO.sv", 2346, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "GPIO.sv", 2350, 7, ".GPIO", "v_user/GPIO", "cover", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "GPIO.sv", 2354, 7, ".GPIO", "v_user/GPIO", "cover", "");
}
