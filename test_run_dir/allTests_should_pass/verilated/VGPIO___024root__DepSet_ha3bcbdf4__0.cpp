// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGPIO.h for the primary calling header

#include "VGPIO__pch.h"
#include "VGPIO__Syms.h"
#include "VGPIO___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__ico(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG

void VGPIO___024root___eval_triggers__ico(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VGPIO___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VGPIO___024root___dump_triggers__act(VGPIO___024root* vlSelf);
#endif  // VL_DEBUG

void VGPIO___024root___eval_triggers__act(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VGPIO___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VGPIO___024root___nba_sequent__TOP__0(VGPIO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VGPIO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VGPIO___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ GPIO__DOT___GEN_4;
    GPIO__DOT___GEN_4 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_5;
    GPIO__DOT___GEN_5 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_10;
    GPIO__DOT___GEN_10 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_11;
    GPIO__DOT___GEN_11 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_16;
    GPIO__DOT___GEN_16 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_17;
    GPIO__DOT___GEN_17 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_22;
    GPIO__DOT___GEN_22 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_23;
    GPIO__DOT___GEN_23 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_28;
    GPIO__DOT___GEN_28 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_29;
    GPIO__DOT___GEN_29 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_34;
    GPIO__DOT___GEN_34 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_35;
    GPIO__DOT___GEN_35 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_40;
    GPIO__DOT___GEN_40 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_41;
    GPIO__DOT___GEN_41 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_48;
    GPIO__DOT___GEN_48 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_49;
    GPIO__DOT___GEN_49 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_54;
    GPIO__DOT___GEN_54 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_55;
    GPIO__DOT___GEN_55 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_60;
    GPIO__DOT___GEN_60 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_61;
    GPIO__DOT___GEN_61 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_66;
    GPIO__DOT___GEN_66 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_67;
    GPIO__DOT___GEN_67 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_72;
    GPIO__DOT___GEN_72 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_73;
    GPIO__DOT___GEN_73 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_78;
    GPIO__DOT___GEN_78 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_79;
    GPIO__DOT___GEN_79 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_84;
    GPIO__DOT___GEN_84 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_85;
    GPIO__DOT___GEN_85 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_90;
    GPIO__DOT___GEN_90 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_91;
    GPIO__DOT___GEN_91 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_98;
    GPIO__DOT___GEN_98 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_99;
    GPIO__DOT___GEN_99 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_104;
    GPIO__DOT___GEN_104 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_105;
    GPIO__DOT___GEN_105 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_110;
    GPIO__DOT___GEN_110 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_111;
    GPIO__DOT___GEN_111 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_116;
    GPIO__DOT___GEN_116 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_117;
    GPIO__DOT___GEN_117 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_122;
    GPIO__DOT___GEN_122 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_123;
    GPIO__DOT___GEN_123 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_128;
    GPIO__DOT___GEN_128 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_129;
    GPIO__DOT___GEN_129 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_134;
    GPIO__DOT___GEN_134 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_135;
    GPIO__DOT___GEN_135 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_140;
    GPIO__DOT___GEN_140 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_141;
    GPIO__DOT___GEN_141 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_148;
    GPIO__DOT___GEN_148 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_149;
    GPIO__DOT___GEN_149 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_154;
    GPIO__DOT___GEN_154 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_155;
    GPIO__DOT___GEN_155 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_160;
    GPIO__DOT___GEN_160 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_161;
    GPIO__DOT___GEN_161 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_166;
    GPIO__DOT___GEN_166 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_167;
    GPIO__DOT___GEN_167 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_172;
    GPIO__DOT___GEN_172 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_173;
    GPIO__DOT___GEN_173 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_178;
    GPIO__DOT___GEN_178 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_179;
    GPIO__DOT___GEN_179 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_184;
    GPIO__DOT___GEN_184 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_185;
    GPIO__DOT___GEN_185 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_190;
    GPIO__DOT___GEN_190 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_191;
    GPIO__DOT___GEN_191 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_198;
    GPIO__DOT___GEN_198 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_199;
    GPIO__DOT___GEN_199 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_204;
    GPIO__DOT___GEN_204 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_205;
    GPIO__DOT___GEN_205 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_210;
    GPIO__DOT___GEN_210 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_211;
    GPIO__DOT___GEN_211 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_216;
    GPIO__DOT___GEN_216 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_217;
    GPIO__DOT___GEN_217 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_222;
    GPIO__DOT___GEN_222 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_223;
    GPIO__DOT___GEN_223 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_228;
    GPIO__DOT___GEN_228 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_229;
    GPIO__DOT___GEN_229 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_234;
    GPIO__DOT___GEN_234 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_235;
    GPIO__DOT___GEN_235 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_240;
    GPIO__DOT___GEN_240 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_241;
    GPIO__DOT___GEN_241 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_248;
    GPIO__DOT___GEN_248 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_249;
    GPIO__DOT___GEN_249 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_254;
    GPIO__DOT___GEN_254 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_255;
    GPIO__DOT___GEN_255 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_260;
    GPIO__DOT___GEN_260 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_261;
    GPIO__DOT___GEN_261 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_266;
    GPIO__DOT___GEN_266 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_267;
    GPIO__DOT___GEN_267 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_272;
    GPIO__DOT___GEN_272 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_273;
    GPIO__DOT___GEN_273 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_278;
    GPIO__DOT___GEN_278 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_279;
    GPIO__DOT___GEN_279 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_284;
    GPIO__DOT___GEN_284 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_285;
    GPIO__DOT___GEN_285 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_290;
    GPIO__DOT___GEN_290 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_291;
    GPIO__DOT___GEN_291 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_298;
    GPIO__DOT___GEN_298 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_299;
    GPIO__DOT___GEN_299 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_304;
    GPIO__DOT___GEN_304 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_305;
    GPIO__DOT___GEN_305 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_310;
    GPIO__DOT___GEN_310 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_311;
    GPIO__DOT___GEN_311 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_316;
    GPIO__DOT___GEN_316 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_317;
    GPIO__DOT___GEN_317 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_322;
    GPIO__DOT___GEN_322 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_323;
    GPIO__DOT___GEN_323 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_328;
    GPIO__DOT___GEN_328 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_329;
    GPIO__DOT___GEN_329 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_334;
    GPIO__DOT___GEN_334 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_335;
    GPIO__DOT___GEN_335 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_340;
    GPIO__DOT___GEN_340 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_341;
    GPIO__DOT___GEN_341 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_348;
    GPIO__DOT___GEN_348 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_349;
    GPIO__DOT___GEN_349 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_354;
    GPIO__DOT___GEN_354 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_355;
    GPIO__DOT___GEN_355 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_360;
    GPIO__DOT___GEN_360 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_361;
    GPIO__DOT___GEN_361 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_366;
    GPIO__DOT___GEN_366 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_367;
    GPIO__DOT___GEN_367 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_372;
    GPIO__DOT___GEN_372 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_373;
    GPIO__DOT___GEN_373 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_378;
    GPIO__DOT___GEN_378 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_379;
    GPIO__DOT___GEN_379 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_384;
    GPIO__DOT___GEN_384 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_385;
    GPIO__DOT___GEN_385 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_390;
    GPIO__DOT___GEN_390 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_391;
    GPIO__DOT___GEN_391 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_398;
    GPIO__DOT___GEN_398 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_399;
    GPIO__DOT___GEN_399 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_404;
    GPIO__DOT___GEN_404 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_405;
    GPIO__DOT___GEN_405 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_410;
    GPIO__DOT___GEN_410 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_411;
    GPIO__DOT___GEN_411 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_416;
    GPIO__DOT___GEN_416 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_417;
    GPIO__DOT___GEN_417 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_422;
    GPIO__DOT___GEN_422 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_423;
    GPIO__DOT___GEN_423 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_428;
    GPIO__DOT___GEN_428 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_429;
    GPIO__DOT___GEN_429 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_434;
    GPIO__DOT___GEN_434 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_435;
    GPIO__DOT___GEN_435 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_440;
    GPIO__DOT___GEN_440 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_441;
    GPIO__DOT___GEN_441 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_448;
    GPIO__DOT___GEN_448 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_449;
    GPIO__DOT___GEN_449 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_454;
    GPIO__DOT___GEN_454 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_455;
    GPIO__DOT___GEN_455 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_460;
    GPIO__DOT___GEN_460 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_461;
    GPIO__DOT___GEN_461 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_466;
    GPIO__DOT___GEN_466 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_467;
    GPIO__DOT___GEN_467 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_472;
    GPIO__DOT___GEN_472 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_473;
    GPIO__DOT___GEN_473 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_478;
    GPIO__DOT___GEN_478 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_479;
    GPIO__DOT___GEN_479 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_484;
    GPIO__DOT___GEN_484 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_485;
    GPIO__DOT___GEN_485 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_490;
    GPIO__DOT___GEN_490 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_491;
    GPIO__DOT___GEN_491 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_498;
    GPIO__DOT___GEN_498 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_499;
    GPIO__DOT___GEN_499 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_504;
    GPIO__DOT___GEN_504 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_505;
    GPIO__DOT___GEN_505 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_510;
    GPIO__DOT___GEN_510 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_511;
    GPIO__DOT___GEN_511 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_516;
    GPIO__DOT___GEN_516 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_517;
    GPIO__DOT___GEN_517 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_522;
    GPIO__DOT___GEN_522 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_523;
    GPIO__DOT___GEN_523 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_528;
    GPIO__DOT___GEN_528 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_529;
    GPIO__DOT___GEN_529 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_534;
    GPIO__DOT___GEN_534 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_535;
    GPIO__DOT___GEN_535 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_540;
    GPIO__DOT___GEN_540 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_541;
    GPIO__DOT___GEN_541 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_548;
    GPIO__DOT___GEN_548 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_549;
    GPIO__DOT___GEN_549 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_554;
    GPIO__DOT___GEN_554 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_555;
    GPIO__DOT___GEN_555 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_560;
    GPIO__DOT___GEN_560 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_561;
    GPIO__DOT___GEN_561 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_566;
    GPIO__DOT___GEN_566 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_567;
    GPIO__DOT___GEN_567 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_572;
    GPIO__DOT___GEN_572 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_573;
    GPIO__DOT___GEN_573 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_578;
    GPIO__DOT___GEN_578 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_579;
    GPIO__DOT___GEN_579 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_584;
    GPIO__DOT___GEN_584 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_585;
    GPIO__DOT___GEN_585 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_590;
    GPIO__DOT___GEN_590 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_591;
    GPIO__DOT___GEN_591 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_598;
    GPIO__DOT___GEN_598 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_599;
    GPIO__DOT___GEN_599 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_604;
    GPIO__DOT___GEN_604 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_605;
    GPIO__DOT___GEN_605 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_610;
    GPIO__DOT___GEN_610 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_611;
    GPIO__DOT___GEN_611 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_616;
    GPIO__DOT___GEN_616 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_617;
    GPIO__DOT___GEN_617 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_622;
    GPIO__DOT___GEN_622 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_623;
    GPIO__DOT___GEN_623 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_628;
    GPIO__DOT___GEN_628 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_629;
    GPIO__DOT___GEN_629 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_634;
    GPIO__DOT___GEN_634 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_635;
    GPIO__DOT___GEN_635 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_640;
    GPIO__DOT___GEN_640 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_641;
    GPIO__DOT___GEN_641 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_648;
    GPIO__DOT___GEN_648 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_649;
    GPIO__DOT___GEN_649 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_654;
    GPIO__DOT___GEN_654 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_655;
    GPIO__DOT___GEN_655 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_660;
    GPIO__DOT___GEN_660 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_661;
    GPIO__DOT___GEN_661 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_666;
    GPIO__DOT___GEN_666 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_667;
    GPIO__DOT___GEN_667 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_672;
    GPIO__DOT___GEN_672 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_673;
    GPIO__DOT___GEN_673 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_678;
    GPIO__DOT___GEN_678 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_679;
    GPIO__DOT___GEN_679 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_684;
    GPIO__DOT___GEN_684 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_685;
    GPIO__DOT___GEN_685 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_690;
    GPIO__DOT___GEN_690 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_691;
    GPIO__DOT___GEN_691 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_698;
    GPIO__DOT___GEN_698 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_699;
    GPIO__DOT___GEN_699 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_704;
    GPIO__DOT___GEN_704 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_705;
    GPIO__DOT___GEN_705 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_710;
    GPIO__DOT___GEN_710 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_711;
    GPIO__DOT___GEN_711 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_716;
    GPIO__DOT___GEN_716 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_717;
    GPIO__DOT___GEN_717 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_722;
    GPIO__DOT___GEN_722 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_723;
    GPIO__DOT___GEN_723 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_728;
    GPIO__DOT___GEN_728 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_729;
    GPIO__DOT___GEN_729 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_734;
    GPIO__DOT___GEN_734 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_735;
    GPIO__DOT___GEN_735 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_740;
    GPIO__DOT___GEN_740 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_741;
    GPIO__DOT___GEN_741 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_748;
    GPIO__DOT___GEN_748 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_749;
    GPIO__DOT___GEN_749 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_754;
    GPIO__DOT___GEN_754 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_755;
    GPIO__DOT___GEN_755 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_760;
    GPIO__DOT___GEN_760 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_761;
    GPIO__DOT___GEN_761 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_766;
    GPIO__DOT___GEN_766 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_767;
    GPIO__DOT___GEN_767 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_772;
    GPIO__DOT___GEN_772 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_773;
    GPIO__DOT___GEN_773 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_778;
    GPIO__DOT___GEN_778 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_779;
    GPIO__DOT___GEN_779 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_784;
    GPIO__DOT___GEN_784 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_785;
    GPIO__DOT___GEN_785 = 0;
    SData/*15:0*/ GPIO__DOT___GEN_790;
    GPIO__DOT___GEN_790 = 0;
    CData/*7:0*/ GPIO__DOT___GEN_791;
    GPIO__DOT___GEN_791 = 0;
    SData/*15:0*/ GPIO__DOT___TRIGGER_STATUS_T_6;
    GPIO__DOT___TRIGGER_STATUS_T_6 = 0;
    SData/*15:0*/ GPIO__DOT___TRIGGER_STATUS_T_15;
    GPIO__DOT___TRIGGER_STATUS_T_15 = 0;
    SData/*15:0*/ GPIO__DOT___TRIGGER_STATUS_T_25;
    GPIO__DOT___TRIGGER_STATUS_T_25 = 0;
    SData/*15:0*/ GPIO__DOT___OUTPUT_T_644;
    GPIO__DOT___OUTPUT_T_644 = 0;
    SData/*15:0*/ GPIO__DOT___OUTPUT_T_653;
    GPIO__DOT___OUTPUT_T_653 = 0;
    SData/*15:0*/ GPIO__DOT___OUTPUT_T_663;
    GPIO__DOT___OUTPUT_T_663 = 0;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    // Body
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        ++(vlSymsp->__Vcoverage[88]);
        if (vlSelf->io_apb_PSLVERR) {
            ++(vlSymsp->__Vcoverage[93]);
        }
        if (vlSelf->io_apb_PSEL) {
            ++(vlSymsp->__Vcoverage[89]);
        }
        if (vlSelf->io_apb_PENABLE) {
            ++(vlSymsp->__Vcoverage[90]);
        }
        if ((8U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[83]);
        }
        if ((4U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[82]);
        }
        if ((2U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[81]);
        }
        if ((1U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[80]);
        }
        if ((0x10U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[84]);
        }
        if ((0x20U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[85]);
        }
        if ((0x40U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[86]);
        }
        if ((0x80U & (IData)(vlSelf->io_apb_PADDR))) {
            ++(vlSymsp->__Vcoverage[87]);
        }
        if (vlSelf->io_apb_PWRITE) {
            ++(vlSymsp->__Vcoverage[91]);
        }
        if ((0x8000U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[75]);
        }
        if ((0x4000U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[70]);
        }
        if ((0x2000U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[65]);
        }
        if ((0x1000U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[60]);
        }
        if ((0x800U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[55]);
        }
        if ((0x400U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[50]);
        }
        if ((0x200U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[45]);
        }
        if ((8U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[15]);
        }
        if ((4U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[10]);
        }
        if ((1U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[0]);
        }
        if ((2U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[5]);
        }
        if ((0x10U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[20]);
        }
        if ((0x20U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[25]);
        }
        if ((0x40U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[30]);
        }
        if ((0x80U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[35]);
        }
        if ((0x100U & (IData)(vlSelf->io_pins_gpioInput))) {
            ++(vlSymsp->__Vcoverage[40]);
        }
        if ((0x8000U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[77]);
        }
        if ((0x8000U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[76]);
        }
        if ((0x4000U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[72]);
        }
        if ((0x4000U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[71]);
        }
        if ((0x2000U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[67]);
        }
        if ((0x2000U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[66]);
        }
        if ((0x1000U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[62]);
        }
        if ((0x1000U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[61]);
        }
        if ((0x800U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[57]);
        }
        if ((0x800U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[56]);
        }
        if ((0x400U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[52]);
        }
        if ((0x400U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[51]);
        }
        if ((0x200U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[47]);
        }
        if ((0x200U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[46]);
        }
        if ((0x100U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[42]);
        }
        if ((8U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[16]);
        }
        if ((4U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[12]);
        }
        if ((4U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[11]);
        }
        if ((1U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[2]);
        }
        if ((1U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[1]);
        }
        if ((0x100U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[41]);
        }
        if ((8U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[17]);
        }
        if ((2U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[7]);
        }
        if ((2U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[6]);
        }
        if ((0x10U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[21]);
        }
        if ((0x10U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[22]);
        }
        if ((0x20U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[26]);
        }
        if ((0x20U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[27]);
        }
        if ((0x40U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[31]);
        }
        if ((0x40U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[32]);
        }
        if ((0x80U & (IData)(vlSelf->io_pins_gpioOutput))) {
            ++(vlSymsp->__Vcoverage[36]);
        }
        if ((0x80U & (IData)(vlSelf->io_pins_gpioOutputEnable))) {
            ++(vlSymsp->__Vcoverage[37]);
        }
        if ((0x8000U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[79]);
        }
        if ((0x4000U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[74]);
        }
        if ((0x2000U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[69]);
        }
        if ((0x1000U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[64]);
        }
        if ((0x800U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[59]);
        }
        if ((0x400U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[54]);
        }
        if ((0x200U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[49]);
        }
        if ((0x100U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[44]);
        }
        if ((4U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[14]);
        }
        if ((2U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[9]);
        }
        if ((1U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[4]);
        }
        if ((8U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[19]);
        }
        if ((0x10U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[24]);
        }
        if ((0x20U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[29]);
        }
        if ((0x40U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[34]);
        }
        if ((0x80U & (IData)(vlSelf->io_apb_PWDATA))) {
            ++(vlSymsp->__Vcoverage[39]);
        }
        if ((0x8000U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[78]);
        }
        if ((0x4000U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[73]);
        }
        if ((0x2000U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[68]);
        }
        if ((0x1000U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[63]);
        }
        if ((0x800U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[58]);
        }
        if ((0x400U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[53]);
        }
        if ((0x200U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[48]);
        }
        if ((0x100U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[43]);
        }
        if ((8U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[18]);
        }
        if ((4U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[13]);
        }
        if ((1U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[3]);
        }
        if ((2U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[8]);
        }
        if ((0x10U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[23]);
        }
        if ((0x20U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[28]);
        }
        if ((0x40U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[33]);
        }
        if ((0x80U & (IData)(vlSelf->io_apb_PRDATA))) {
            ++(vlSymsp->__Vcoverage[38]);
        }
        if (vlSelf->io_apb_PREADY) {
            ++(vlSymsp->__Vcoverage[92]);
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (1U >= (IData)(vlSelf->io_apb_PADDR))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing DIRECTION Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & ((4U <= (IData)(vlSelf->io_apb_PADDR)) 
                         & (5U >= (IData)(vlSelf->io_apb_PADDR)))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing INPUT Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_923)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing OUTPUT Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_927)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing MODE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_931)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_935)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing ATOMIC_MASK Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_939)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing ATOMIC_SET Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_943)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_948)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_952)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_956)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing TRIGGER_TYPE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_960)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing TRIGGER_LO Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_964)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing TRIGGER_HI Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & ((0x1cU <= (IData)(vlSelf->io_apb_PADDR)) 
                         & (0x1dU >= (IData)(vlSelf->io_apb_PADDR)))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing TRIGGER_STATUS Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->io_apb_PREADY) 
                       & (IData)(vlSelf->io_apb_PWRITE)) 
                      & (IData)(vlSelf->GPIO__DOT___T_972)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Writing IRQ_ENABLE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->io_apb_PWDATA,8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY((((IData)(vlSelf->io_apb_PREADY) 
                      & (~ (IData)(vlSelf->io_apb_PWRITE))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading Register, addr: %x\n",0,
                      8,vlSelf->io_apb_PADDR);
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (1U >= (IData)(vlSelf->io_apb_PADDR))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading DIRECTION Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_DIRECTION,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_923)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading OUTPUT Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_OUTPUT,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & ((4U <= (IData)(vlSelf->io_apb_PADDR)) 
                         & (5U >= (IData)(vlSelf->io_apb_PADDR)))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading INPUT Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_INPUT,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_927)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading MODE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_MODE,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_931)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading ATOMIC_OPERATION Register, data: %x, addr: %x\n",0,
                      4,vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_931)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"ATOMIC_OPERATION_MIN: 8\nATOMIC_OPERATION_MAX: 8\n",0);
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_935)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading ATOMIC_MASK Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_ATOMIC_MASK,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_939)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading ATOMIC_SET Register, data: %x, addr: %x\n",0,
                      1,vlSelf->GPIO__DOT__regs_ATOMIC_SET,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_943)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",0,
                      5,((7U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                       - (IData)(4U))))
                          ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7)
                          : ((6U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                           - (IData)(4U))))
                              ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6)
                              : ((5U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                               - (IData)(4U))))
                                  ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5)
                                  : ((4U == (7U & ((IData)(vlSelf->io_apb_PADDR) 
                                                   - (IData)(4U))))
                                      ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4)
                                      : ((3U == (7U 
                                                 & ((IData)(vlSelf->io_apb_PADDR) 
                                                    - (IData)(4U))))
                                          ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3)
                                          : ((2U == 
                                              (7U & 
                                               ((IData)(vlSelf->io_apb_PADDR) 
                                                - (IData)(4U))))
                                              ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2)
                                              : ((1U 
                                                  == 
                                                  (7U 
                                                   & ((IData)(vlSelf->io_apb_PADDR) 
                                                      - (IData)(4U))))
                                                  ? (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1)
                                                  : (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0)))))))),
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_948)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",0,
                      8,vlSelf->GPIO__DOT__regs_virtualPortOutput,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_952)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"Reading VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",0,
                      1,vlSelf->GPIO__DOT__regs_virtualPortEnable,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_956)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"READING TRIGGER_TYPE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_TRIGGER_TYPE,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_960)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"READING TRIGGER_LO Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_TRIGGER_LO,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_964)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"READING TRIGGER_HI Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_TRIGGER_HI,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & ((0x1cU <= (IData)(vlSelf->io_apb_PADDR)) 
                         & (0x1dU >= (IData)(vlSelf->io_apb_PADDR)))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"READING TRIGGER_STATUS Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_TRIGGER_STATUS,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->io_apb_PWRITE)) 
                       & (IData)(vlSelf->io_apb_PREADY)) 
                      & (IData)(vlSelf->GPIO__DOT___T_972)) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF_NX(0x80000002U,"READING IRQ_ENABLE Register, data: %x, addr: %x\n",0,
                      16,vlSelf->GPIO__DOT__regs_IRQ_ENABLE,
                      8,(IData)(vlSelf->io_apb_PADDR));
    }
    vlSelf->GPIO__DOT__regs_IRQ_ENABLE = (0xffffU & 
                                          vlSelf->GPIO__DOT___GEN_1236[0U]);
    vlSelf->GPIO__DOT__regs_MODE = (0xffffU & vlSelf->GPIO__DOT___GEN_1227[0U]);
    vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION = (0xfU 
                                                & (IData)(vlSelf->GPIO__DOT___GEN_1228));
    vlSelf->GPIO__DOT__regs_ATOMIC_MASK = (0xffffU 
                                           & vlSelf->GPIO__DOT___GEN_1229[0U]);
    vlSelf->GPIO__DOT__regs_TRIGGER_TYPE = (0xffffU 
                                            & vlSelf->GPIO__DOT___GEN_1233[0U]);
    vlSelf->GPIO__DOT__regs_TRIGGER_LO = (0xffffU & 
                                          vlSelf->GPIO__DOT___GEN_1234[0U]);
    vlSelf->GPIO__DOT__regs_TRIGGER_HI = (0xffffU & 
                                          vlSelf->GPIO__DOT___GEN_1235[0U]);
    vlSelf->GPIO__DOT__regs_virtualPortEnable = (1U 
                                                 & vlSelf->GPIO__DOT___GEN_1232);
    __Vtemp_4[0U] = vlSelf->io_apb_PWDATA;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0U;
    VL_SHIFTL_WWI(79,79,6, __Vtemp_5, __Vtemp_4, (0x3fU 
                                                  & VL_SHIFTL_III(6,6,32, 
                                                                  (3U 
                                                                   & ((IData)(vlSelf->io_apb_PADDR) 
                                                                      - (IData)(2U))), 3U)));
    if (vlSelf->reset) {
        vlSelf->GPIO__DOT__regs_TRIGGER_STATUS = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6 = 0U;
        vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7 = 0U;
        vlSelf->GPIO__DOT__regs_INPUT = 0U;
        vlSelf->GPIO__DOT__gpioInputSyncPrev = 0U;
        vlSelf->GPIO__DOT__regs_OUTPUT = 0U;
    } else {
        vlSelf->GPIO__DOT__regs_TRIGGER_STATUS = ((0x5555U 
                                                   & ((IData)(vlSelf->GPIO__DOT___TRIGGER_STATUS_T_35) 
                                                      >> 1U)) 
                                                  | (0xaaaaU 
                                                     & VL_SHIFTL_III(16,16,32, (IData)(vlSelf->GPIO__DOT___TRIGGER_STATUS_T_35), 1U)));
        if (((IData)(vlSelf->io_apb_PSEL) & (IData)(vlSelf->io_apb_PENABLE))) {
            if (vlSelf->io_apb_PWRITE) {
                if (vlSelf->GPIO__DOT___T_943) {
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0 
                        = vlSelf->GPIO__DOT___GEN_807;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1 
                        = vlSelf->GPIO__DOT___GEN_808;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2 
                        = vlSelf->GPIO__DOT___GEN_809;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3 
                        = vlSelf->GPIO__DOT___GEN_810;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4 
                        = vlSelf->GPIO__DOT___GEN_811;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5 
                        = vlSelf->GPIO__DOT___GEN_812;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6 
                        = vlSelf->GPIO__DOT___GEN_813;
                    vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7 
                        = vlSelf->GPIO__DOT___GEN_814;
                }
            }
        }
        vlSelf->GPIO__DOT__regs_INPUT = vlSelf->GPIO__DOT__gpioInputSync;
        vlSelf->GPIO__DOT__gpioInputSyncPrev = vlSelf->GPIO__DOT__gpioInputSync;
        vlSelf->GPIO__DOT__regs_OUTPUT = (0xffffU & 
                                          ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_SET)
                                            ? ((0x5555U 
                                                & ((IData)(vlSelf->GPIO__DOT___OUTPUT_T_673) 
                                                   >> 1U)) 
                                               | (0xaaaaU 
                                                  & VL_SHIFTL_III(16,16,32, (IData)(vlSelf->GPIO__DOT___OUTPUT_T_673), 1U)))
                                            : ((IData)(vlSelf->io_apb_PREADY)
                                                ? ((IData)(vlSelf->io_apb_PWRITE)
                                                    ? 
                                                   ((IData)(vlSelf->GPIO__DOT___T_923)
                                                     ? 
                                                    __Vtemp_5[0U]
                                                     : (IData)(vlSelf->GPIO__DOT___GEN_798))
                                                    : (IData)(vlSelf->GPIO__DOT___GEN_798))
                                                : (IData)(vlSelf->GPIO__DOT___GEN_798))));
    }
    vlSelf->GPIO__DOT__regs_DIRECTION = (0xffffU & 
                                         vlSelf->GPIO__DOT___GEN_1225[0U]);
    vlSelf->GPIO__DOT__regs_virtualPortOutput = (0xffU 
                                                 & (IData)(
                                                           ((IData)(vlSelf->reset)
                                                             ? 0ULL
                                                             : 
                                                            (0x7fffffffffULL 
                                                             & ((IData)(vlSelf->io_apb_PREADY)
                                                                 ? 
                                                                ((IData)(vlSelf->io_apb_PWRITE)
                                                                  ? 
                                                                 ((IData)(vlSelf->GPIO__DOT___T_948)
                                                                   ? 
                                                                  ((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->io_apb_PWDATA)))) 
                                                                   << 
                                                                   (0x1fU 
                                                                    & VL_SHIFTL_III(5,5,32, 
                                                                                (1U 
                                                                                & (IData)(vlSelf->io_apb_PADDR)), 3U)))
                                                                   : (QData)((IData)(vlSelf->GPIO__DOT___GEN_799)))
                                                                  : (QData)((IData)(vlSelf->GPIO__DOT___GEN_799)))
                                                                 : (QData)((IData)(vlSelf->GPIO__DOT___GEN_799)))))));
    vlSelf->io_pins_irqOutput = (1U <= ((IData)(vlSelf->GPIO__DOT__regs_IRQ_ENABLE) 
                                        & (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_STATUS)));
    vlSelf->GPIO__DOT__condition = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                           << 2U)) 
                                    | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                              << 1U)) 
                                       | (1U & (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI))));
    vlSelf->GPIO__DOT__condition_1 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             << 1U)) 
                                      | ((2U & (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 1U))));
    vlSelf->GPIO__DOT__condition_2 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 1U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 2U))));
    vlSelf->GPIO__DOT__condition_3 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 1U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 2U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 3U))));
    vlSelf->GPIO__DOT__condition_4 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 2U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 3U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 4U))));
    vlSelf->GPIO__DOT__condition_5 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 3U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 4U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 5U))));
    vlSelf->GPIO__DOT__condition_6 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 4U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 5U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 6U))));
    vlSelf->GPIO__DOT__condition_7 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 5U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 6U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 7U))));
    vlSelf->GPIO__DOT__condition_8 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 6U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 7U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 8U))));
    vlSelf->GPIO__DOT__condition_9 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                             >> 7U)) 
                                      | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                >> 8U)) 
                                         | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                  >> 9U))));
    vlSelf->GPIO__DOT__condition_10 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 8U)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 9U)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xaU))));
    vlSelf->GPIO__DOT__condition_11 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 9U)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 0xaU)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xbU))));
    vlSelf->GPIO__DOT__condition_12 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 0xaU)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 0xbU)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xcU))));
    vlSelf->GPIO__DOT__condition_13 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 0xbU)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 0xcU)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xdU))));
    vlSelf->GPIO__DOT__condition_14 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 0xcU)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 0xdU)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xeU))));
    vlSelf->GPIO__DOT__condition_15 = ((4U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_TYPE) 
                                              >> 0xdU)) 
                                       | ((2U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_LO) 
                                                 >> 0xeU)) 
                                          | (1U & ((IData)(vlSelf->GPIO__DOT__regs_TRIGGER_HI) 
                                                   >> 0xfU))));
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
    vlSelf->GPIO__DOT__gpioInputSync = vlSelf->GPIO__DOT__gpioInputSync_REG;
    vlSelf->GPIO__DOT__regs_ATOMIC_SET = (1U & vlSelf->GPIO__DOT___GEN_1230);
    vlSelf->GPIO__DOT__OUTPUT_lo = ((0x80U & (((0x100U 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                   >> 2U)
                                                : (
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
                                                     >> 1U)))) 
                                              << 7U)) 
                                    | ((0x40U & (((0x200U 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                   ? 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                   >> 2U)
                                                   : 
                                                  ((1U 
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
                                                     >> 1U)))) 
                                                 << 6U)) 
                                       | ((0x20U & 
                                           (((0x400U 
                                              & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                 & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                              ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 2U)
                                              : ((1U 
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
                                                   >> 1U)))) 
                                            << 5U)) 
                                          | ((0x10U 
                                              & (((0x800U 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                   ? 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                   >> 2U)
                                                   : 
                                                  ((1U 
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
                                                     >> 1U)))) 
                                                 << 4U)) 
                                             | ((8U 
                                                 & (((0x1000U 
                                                      & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                         & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                      ? 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                      >> 2U)
                                                      : 
                                                     ((1U 
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
                                                        >> 1U)))) 
                                                    << 3U)) 
                                                | ((4U 
                                                    & (((0x2000U 
                                                         & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                            & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                         ? 
                                                        ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                         >> 2U)
                                                         : 
                                                        ((1U 
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
                                                           >> 1U)))) 
                                                       << 2U)) 
                                                   | ((2U 
                                                       & (((0x4000U 
                                                            & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                            ? 
                                                           ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                            >> 2U)
                                                            : 
                                                           ((1U 
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
                                                              >> 1U)))) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & ((0x8000U 
                                                             & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                                & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                             ? 
                                                            ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                             >> 2U)
                                                             : 
                                                            ((IData)(
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
                                                               >> 1U))))))))))));
    vlSelf->io_pins_gpioOutput = (((0x8000U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 0xfU)) 
                                                << 0xfU) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                   | ((0x4000U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 0xeU)) 
                                                   << 0xeU) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                      | ((0x2000U & 
                                          (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                >> 0xdU)) 
                                            << 0xdU) 
                                           & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                              & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                         | ((0x1000U 
                                             & (((~ 
                                                  ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                   >> 0xcU)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                            | ((0x800U 
                                                & (((~ 
                                                     ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                      >> 0xbU)) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                      & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                               | ((0x400U 
                                                   & (((~ 
                                                        ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                         >> 0xaU)) 
                                                       << 0xaU) 
                                                      & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                         & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                                  | ((0x200U 
                                                      & (((~ 
                                                           ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                            >> 9U)) 
                                                          << 9U) 
                                                         & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                            & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                                     | (0x100U 
                                                        & (((~ 
                                                             ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                              >> 8U)) 
                                                            << 8U) 
                                                           & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                              & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))))))))))) 
                                  | ((0x80U & (((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 7U)) 
                                                << 7U) 
                                               & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                     | ((0x40U & ((
                                                   (~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 6U)) 
                                                   << 6U) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                        | ((0x20U & 
                                            (((~ ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                  >> 5U)) 
                                              << 5U) 
                                             & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                           | ((0x10U 
                                               & (((~ 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_MODE) 
                                                     >> 4U)) 
                                                   << 4U) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))) 
                                              | ((8U 
                                                  & (((~ 
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
                                                                & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))))))))))));
    vlSelf->io_pins_gpioOutputEnable = (((0x8000U & 
                                          (((0x8000U 
                                             & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                             ? ((~ 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                  >> 0xfU)) 
                                                & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                   >> 0xfU))
                                             : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                >> 0xfU)) 
                                           << 0xfU)) 
                                         | ((0x4000U 
                                             & (((0x4000U 
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
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & (((0x2000U 
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
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & (((0x1000U 
                                                        & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                          >> 0xcU)) 
                                                        & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                           >> 0xcU))
                                                        : 
                                                       ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                        >> 0xcU)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (((0x800U 
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
                                                         << 0xbU)) 
                                                     | ((0x400U 
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
                                                            << 0xaU)) 
                                                        | ((0x200U 
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
                                                               << 9U)) 
                                                           | (0x100U 
                                                              & (((0x100U 
                                                                   & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                                   ? 
                                                                  ((~ 
                                                                    ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                                     >> 8U)) 
                                                                   & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                                      >> 8U))
                                                                   : 
                                                                  ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                                   >> 8U)) 
                                                                 << 8U))))))))) 
                                        | ((0x80U & 
                                            (((0x80U 
                                               & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                               ? ((~ 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                    >> 7U)) 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                     >> 7U))
                                               : ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                  >> 7U)) 
                                             << 7U)) 
                                           | ((0x40U 
                                               & (((0x40U 
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
                                              | ((0x20U 
                                                  & (((0x20U 
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
                                                 | ((0x10U 
                                                     & (((0x10U 
                                                          & (IData)(vlSelf->GPIO__DOT__regs_MODE))
                                                          ? 
                                                         ((~ 
                                                           ((IData)(vlSelf->GPIO__DOT__regs_OUTPUT) 
                                                            >> 4U)) 
                                                          & ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                             >> 4U))
                                                          : 
                                                         ((IData)(vlSelf->GPIO__DOT__regs_DIRECTION) 
                                                          >> 4U)) 
                                                        << 4U)) 
                                                    | ((8U 
                                                        & (((8U 
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
                                                                    : (IData)(vlSelf->GPIO__DOT__regs_DIRECTION)))))))))));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_4 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                  ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                  : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_5 = vlSelf->GPIO__DOT__regs_virtualPortOutput;
        } else {
            GPIO__DOT___GEN_4 = vlSelf->GPIO__DOT__regs_OUTPUT;
            GPIO__DOT___GEN_5 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                  ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                  : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_4 = vlSelf->GPIO__DOT__regs_OUTPUT;
        GPIO__DOT___GEN_5 = vlSelf->GPIO__DOT__regs_virtualPortOutput;
    }
    GPIO__DOT___OUTPUT_T_644 = ((0x8000U & (((1U & 
                                              ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                               & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                              ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 2U)
                                              : ((1U 
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
                                                   >> 1U)))) 
                                            << 0xfU)) 
                                | ((0x4000U & (((2U 
                                                 & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                    & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                 ? 
                                                ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                 >> 2U)
                                                 : 
                                                ((1U 
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
                                                   >> 1U)))) 
                                               << 0xeU)) 
                                   | ((0x2000U & ((
                                                   (4U 
                                                    & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                       & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                    ? 
                                                   ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                    >> 2U)
                                                    : 
                                                   ((1U 
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
                                                      >> 1U)))) 
                                                  << 0xdU)) 
                                      | ((0x1000U & 
                                          (((8U & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                             ? ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                >> 2U)
                                             : ((1U 
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
                                                  >> 1U)))) 
                                           << 0xcU)) 
                                         | ((0x800U 
                                             & (((0x10U 
                                                  & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                     & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                  ? 
                                                 ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                  >> 2U)
                                                  : 
                                                 ((1U 
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
                                                    >> 1U)))) 
                                                << 0xbU)) 
                                            | ((0x400U 
                                                & (((0x20U 
                                                     & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                        & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                     ? 
                                                    ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                     >> 2U)
                                                     : 
                                                    ((1U 
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
                                                       >> 1U)))) 
                                                   << 0xaU)) 
                                               | ((0x200U 
                                                   & (((0x40U 
                                                        & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                        ? 
                                                       ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                        >> 2U)
                                                        : 
                                                       ((1U 
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
                                                          >> 1U)))) 
                                                      << 9U)) 
                                                  | ((0x100U 
                                                      & (((0x80U 
                                                           & ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_MASK) 
                                                              & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                                           ? 
                                                          ((IData)(vlSelf->GPIO__DOT__regs_ATOMIC_OPERATION) 
                                                           >> 2U)
                                                           : 
                                                          ((1U 
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
                                                             >> 1U)))) 
                                                         << 8U)) 
                                                     | (IData)(vlSelf->GPIO__DOT__OUTPUT_lo)))))))));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_10 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_11 = GPIO__DOT___GEN_5;
        } else {
            GPIO__DOT___GEN_10 = GPIO__DOT___GEN_4;
            GPIO__DOT___GEN_11 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_10 = GPIO__DOT___GEN_4;
        GPIO__DOT___GEN_11 = GPIO__DOT___GEN_5;
    }
    vlSelf->GPIO__DOT__gpioInputSync_REG = vlSelf->io_pins_gpioInput;
    vlSelf->GPIO__DOT__TRIGGER_STATUS_lo = ((0x80U 
                                             & (((1U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_8))
                                                  ? 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 8U)
                                                  : 
                                                 ((2U 
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
                                                               >> 8U))))))))) 
                                                << 7U)) 
                                            | ((0x40U 
                                                & (((1U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_9))
                                                     ? 
                                                    ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                     >> 9U)
                                                     : 
                                                    ((2U 
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
                                                                  >> 9U))))))))) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & (((1U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_10))
                                                        ? 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 0xaU)
                                                        : 
                                                       ((2U 
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
                                                                     >> 0xaU))))))))) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & (((1U 
                                                           == (IData)(vlSelf->GPIO__DOT__condition_11))
                                                           ? 
                                                          ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                           >> 0xbU)
                                                           : 
                                                          ((2U 
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
                                                                        >> 0xbU))))))))) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & (((1U 
                                                              == (IData)(vlSelf->GPIO__DOT__condition_12))
                                                              ? 
                                                             ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                              >> 0xcU)
                                                              : 
                                                             ((2U 
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
                                                                           >> 0xcU))))))))) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & (((1U 
                                                                 == (IData)(vlSelf->GPIO__DOT__condition_13))
                                                                 ? 
                                                                ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                                 >> 0xdU)
                                                                 : 
                                                                ((2U 
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
                                                                              >> 0xdU))))))))) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & (((1U 
                                                                    == (IData)(vlSelf->GPIO__DOT__condition_14))
                                                                    ? 
                                                                   ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                                    >> 0xeU)
                                                                    : 
                                                                   ((2U 
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
                                                                                >> 0xeU))))))))) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & ((1U 
                                                                     == (IData)(vlSelf->GPIO__DOT__condition_15))
                                                                     ? 
                                                                    ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                                     >> 0xfU)
                                                                     : 
                                                                    ((2U 
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
                                                                                >> 0xfU)))))))))))))))));
    GPIO__DOT___OUTPUT_T_653 = (0xffffU & (VL_SHIFTR_III(16,16,32, (IData)(GPIO__DOT___OUTPUT_T_644), 8U) 
                                           | (0xff00U 
                                              & VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___OUTPUT_T_644), 8U))));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_16 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_17 = GPIO__DOT___GEN_11;
        } else {
            GPIO__DOT___GEN_16 = GPIO__DOT___GEN_10;
            GPIO__DOT___GEN_17 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_16 = GPIO__DOT___GEN_10;
        GPIO__DOT___GEN_17 = GPIO__DOT___GEN_11;
    }
    GPIO__DOT___TRIGGER_STATUS_T_6 = ((0x8000U & ((
                                                   (1U 
                                                    == (IData)(vlSelf->GPIO__DOT__condition))
                                                    ? (IData)(vlSelf->GPIO__DOT__gpioInputSync)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition))
                                                     ? 
                                                    (~ (IData)(vlSelf->GPIO__DOT__gpioInputSync))
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelf->GPIO__DOT__condition)) 
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
                                                              & (IData)(vlSelf->GPIO__DOT__gpioInputSyncPrev))))))))) 
                                                  << 0xfU)) 
                                      | ((0x4000U & 
                                          (((1U == (IData)(vlSelf->GPIO__DOT__condition_1))
                                             ? ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                >> 1U)
                                             : ((2U 
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
                                                             >> 1U))))))))) 
                                           << 0xeU)) 
                                         | ((0x2000U 
                                             & (((1U 
                                                  == (IData)(vlSelf->GPIO__DOT__condition_2))
                                                  ? 
                                                 ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                  >> 2U)
                                                  : 
                                                 ((2U 
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
                                                               >> 2U))))))))) 
                                                << 0xdU)) 
                                            | ((0x1000U 
                                                & (((1U 
                                                     == (IData)(vlSelf->GPIO__DOT__condition_3))
                                                     ? 
                                                    ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                     >> 3U)
                                                     : 
                                                    ((2U 
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
                                                                  >> 3U))))))))) 
                                                   << 0xcU)) 
                                               | ((0x800U 
                                                   & (((1U 
                                                        == (IData)(vlSelf->GPIO__DOT__condition_4))
                                                        ? 
                                                       ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                        >> 4U)
                                                        : 
                                                       ((2U 
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
                                                                     >> 4U))))))))) 
                                                      << 0xbU)) 
                                                  | ((0x400U 
                                                      & (((1U 
                                                           == (IData)(vlSelf->GPIO__DOT__condition_5))
                                                           ? 
                                                          ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                           >> 5U)
                                                           : 
                                                          ((2U 
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
                                                                        >> 5U))))))))) 
                                                         << 0xaU)) 
                                                     | ((0x200U 
                                                         & (((1U 
                                                              == (IData)(vlSelf->GPIO__DOT__condition_6))
                                                              ? 
                                                             ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                              >> 6U)
                                                              : 
                                                             ((2U 
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
                                                                           >> 6U))))))))) 
                                                            << 9U)) 
                                                        | ((0x100U 
                                                            & (((1U 
                                                                 == (IData)(vlSelf->GPIO__DOT__condition_7))
                                                                 ? 
                                                                ((IData)(vlSelf->GPIO__DOT__gpioInputSync) 
                                                                 >> 7U)
                                                                 : 
                                                                ((2U 
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
                                                                              >> 7U))))))))) 
                                                               << 8U)) 
                                                           | (IData)(vlSelf->GPIO__DOT__TRIGGER_STATUS_lo)))))))));
    GPIO__DOT___OUTPUT_T_663 = ((0xf0fU & ((IData)(GPIO__DOT___OUTPUT_T_653) 
                                           >> 4U)) 
                                | (0xf0f0U & VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___OUTPUT_T_653), 4U)));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_22 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_23 = GPIO__DOT___GEN_17;
        } else {
            GPIO__DOT___GEN_22 = GPIO__DOT___GEN_16;
            GPIO__DOT___GEN_23 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_22 = GPIO__DOT___GEN_16;
        GPIO__DOT___GEN_23 = GPIO__DOT___GEN_17;
    }
    GPIO__DOT___TRIGGER_STATUS_T_15 = (0xffffU & (VL_SHIFTR_III(16,16,32, (IData)(GPIO__DOT___TRIGGER_STATUS_T_6), 8U) 
                                                  | (0xff00U 
                                                     & VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___TRIGGER_STATUS_T_6), 8U))));
    vlSelf->GPIO__DOT___OUTPUT_T_673 = ((0x3333U & 
                                         ((IData)(GPIO__DOT___OUTPUT_T_663) 
                                          >> 2U)) | 
                                        (0xccccU & 
                                         VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___OUTPUT_T_663), 2U)));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_28 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_29 = GPIO__DOT___GEN_23;
        } else {
            GPIO__DOT___GEN_28 = GPIO__DOT___GEN_22;
            GPIO__DOT___GEN_29 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_28 = GPIO__DOT___GEN_22;
        GPIO__DOT___GEN_29 = GPIO__DOT___GEN_23;
    }
    GPIO__DOT___TRIGGER_STATUS_T_25 = ((0xf0fU & ((IData)(GPIO__DOT___TRIGGER_STATUS_T_15) 
                                                  >> 4U)) 
                                       | (0xf0f0U & 
                                          VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___TRIGGER_STATUS_T_15), 4U)));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_34 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_35 = GPIO__DOT___GEN_29;
        } else {
            GPIO__DOT___GEN_34 = GPIO__DOT___GEN_28;
            GPIO__DOT___GEN_35 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_34 = GPIO__DOT___GEN_28;
        GPIO__DOT___GEN_35 = GPIO__DOT___GEN_29;
    }
    vlSelf->GPIO__DOT___TRIGGER_STATUS_T_35 = ((0x3333U 
                                                & ((IData)(GPIO__DOT___TRIGGER_STATUS_T_25) 
                                                   >> 2U)) 
                                               | (0xccccU 
                                                  & VL_SHIFTL_III(16,16,32, (IData)(GPIO__DOT___TRIGGER_STATUS_T_25), 2U)));
    if ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_40 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_41 = GPIO__DOT___GEN_35;
        } else {
            GPIO__DOT___GEN_40 = GPIO__DOT___GEN_34;
            GPIO__DOT___GEN_41 = ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_40 = GPIO__DOT___GEN_34;
        GPIO__DOT___GEN_41 = GPIO__DOT___GEN_35;
    }
    GPIO__DOT___GEN_48 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                           ? ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                               ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                   ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                       ? (1U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                       : (2U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   : (IData)(GPIO__DOT___GEN_40))
                               : (IData)(GPIO__DOT___GEN_40))
                           : (IData)(vlSelf->GPIO__DOT__regs_OUTPUT));
    GPIO__DOT___GEN_54 = ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                           ? ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                               ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                               : (IData)(GPIO__DOT___GEN_48))
                           : (IData)(GPIO__DOT___GEN_48));
    GPIO__DOT___GEN_49 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                           ? ((0U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                               ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                   ? (IData)(GPIO__DOT___GEN_41)
                                   : ((1U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                       ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                       : 0U)) : (IData)(GPIO__DOT___GEN_41))
                           : (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput));
    GPIO__DOT___GEN_55 = ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                           ? ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                               ? (IData)(GPIO__DOT___GEN_49)
                               : ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                           : (IData)(GPIO__DOT___GEN_49));
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_60 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_61 = GPIO__DOT___GEN_55;
        } else {
            GPIO__DOT___GEN_60 = GPIO__DOT___GEN_54;
            GPIO__DOT___GEN_61 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_60 = GPIO__DOT___GEN_54;
        GPIO__DOT___GEN_61 = GPIO__DOT___GEN_55;
    }
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_66 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_67 = GPIO__DOT___GEN_61;
        } else {
            GPIO__DOT___GEN_66 = GPIO__DOT___GEN_60;
            GPIO__DOT___GEN_67 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_66 = GPIO__DOT___GEN_60;
        GPIO__DOT___GEN_67 = GPIO__DOT___GEN_61;
    }
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_72 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_73 = GPIO__DOT___GEN_67;
        } else {
            GPIO__DOT___GEN_72 = GPIO__DOT___GEN_66;
            GPIO__DOT___GEN_73 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_72 = GPIO__DOT___GEN_66;
        GPIO__DOT___GEN_73 = GPIO__DOT___GEN_67;
    }
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_78 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_79 = GPIO__DOT___GEN_73;
        } else {
            GPIO__DOT___GEN_78 = GPIO__DOT___GEN_72;
            GPIO__DOT___GEN_79 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_78 = GPIO__DOT___GEN_72;
        GPIO__DOT___GEN_79 = GPIO__DOT___GEN_73;
    }
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_84 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_85 = GPIO__DOT___GEN_79;
        } else {
            GPIO__DOT___GEN_84 = GPIO__DOT___GEN_78;
            GPIO__DOT___GEN_85 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_84 = GPIO__DOT___GEN_78;
        GPIO__DOT___GEN_85 = GPIO__DOT___GEN_79;
    }
    if ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_90 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_91 = GPIO__DOT___GEN_85;
        } else {
            GPIO__DOT___GEN_90 = GPIO__DOT___GEN_84;
            GPIO__DOT___GEN_91 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                   ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                   : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_90 = GPIO__DOT___GEN_84;
        GPIO__DOT___GEN_91 = GPIO__DOT___GEN_85;
    }
    GPIO__DOT___GEN_98 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                           ? ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                               ? ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                   ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                       ? (2U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                       : (1U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                   : (IData)(GPIO__DOT___GEN_90))
                               : (IData)(GPIO__DOT___GEN_90))
                           : (IData)(GPIO__DOT___GEN_48));
    GPIO__DOT___GEN_104 = ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_98))
                            : (IData)(GPIO__DOT___GEN_98));
    GPIO__DOT___GEN_99 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                           ? ((1U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                               ? ((2U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                   ? (IData)(GPIO__DOT___GEN_91)
                                   : ((2U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                       ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                       : 0U)) : (IData)(GPIO__DOT___GEN_91))
                           : (IData)(GPIO__DOT___GEN_49));
    GPIO__DOT___GEN_105 = ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_99)
                                : ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_99));
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_110 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_111 = GPIO__DOT___GEN_105;
        } else {
            GPIO__DOT___GEN_110 = GPIO__DOT___GEN_104;
            GPIO__DOT___GEN_111 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_110 = GPIO__DOT___GEN_104;
        GPIO__DOT___GEN_111 = GPIO__DOT___GEN_105;
    }
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_116 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_117 = GPIO__DOT___GEN_111;
        } else {
            GPIO__DOT___GEN_116 = GPIO__DOT___GEN_110;
            GPIO__DOT___GEN_117 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_116 = GPIO__DOT___GEN_110;
        GPIO__DOT___GEN_117 = GPIO__DOT___GEN_111;
    }
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_122 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_123 = GPIO__DOT___GEN_117;
        } else {
            GPIO__DOT___GEN_122 = GPIO__DOT___GEN_116;
            GPIO__DOT___GEN_123 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_122 = GPIO__DOT___GEN_116;
        GPIO__DOT___GEN_123 = GPIO__DOT___GEN_117;
    }
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_128 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_129 = GPIO__DOT___GEN_123;
        } else {
            GPIO__DOT___GEN_128 = GPIO__DOT___GEN_122;
            GPIO__DOT___GEN_129 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_128 = GPIO__DOT___GEN_122;
        GPIO__DOT___GEN_129 = GPIO__DOT___GEN_123;
    }
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_134 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_135 = GPIO__DOT___GEN_129;
        } else {
            GPIO__DOT___GEN_134 = GPIO__DOT___GEN_128;
            GPIO__DOT___GEN_135 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_134 = GPIO__DOT___GEN_128;
        GPIO__DOT___GEN_135 = GPIO__DOT___GEN_129;
    }
    if ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_140 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_141 = GPIO__DOT___GEN_135;
        } else {
            GPIO__DOT___GEN_140 = GPIO__DOT___GEN_134;
            GPIO__DOT___GEN_141 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_140 = GPIO__DOT___GEN_134;
        GPIO__DOT___GEN_141 = GPIO__DOT___GEN_135;
    }
    GPIO__DOT___GEN_148 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (4U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xbU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_140))
                                : (IData)(GPIO__DOT___GEN_140))
                            : (IData)(GPIO__DOT___GEN_98));
    GPIO__DOT___GEN_154 = ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_148))
                            : (IData)(GPIO__DOT___GEN_148));
    GPIO__DOT___GEN_149 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((2U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((4U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_141)
                                    : ((4U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_141))
                            : (IData)(GPIO__DOT___GEN_99));
    GPIO__DOT___GEN_155 = ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_149)
                                : ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_149));
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_160 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_161 = GPIO__DOT___GEN_155;
        } else {
            GPIO__DOT___GEN_160 = GPIO__DOT___GEN_154;
            GPIO__DOT___GEN_161 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_160 = GPIO__DOT___GEN_154;
        GPIO__DOT___GEN_161 = GPIO__DOT___GEN_155;
    }
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_166 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_167 = GPIO__DOT___GEN_161;
        } else {
            GPIO__DOT___GEN_166 = GPIO__DOT___GEN_160;
            GPIO__DOT___GEN_167 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_166 = GPIO__DOT___GEN_160;
        GPIO__DOT___GEN_167 = GPIO__DOT___GEN_161;
    }
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_172 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_173 = GPIO__DOT___GEN_167;
        } else {
            GPIO__DOT___GEN_172 = GPIO__DOT___GEN_166;
            GPIO__DOT___GEN_173 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_172 = GPIO__DOT___GEN_166;
        GPIO__DOT___GEN_173 = GPIO__DOT___GEN_167;
    }
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_178 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_179 = GPIO__DOT___GEN_173;
        } else {
            GPIO__DOT___GEN_178 = GPIO__DOT___GEN_172;
            GPIO__DOT___GEN_179 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_178 = GPIO__DOT___GEN_172;
        GPIO__DOT___GEN_179 = GPIO__DOT___GEN_173;
    }
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_184 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_185 = GPIO__DOT___GEN_179;
        } else {
            GPIO__DOT___GEN_184 = GPIO__DOT___GEN_178;
            GPIO__DOT___GEN_185 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_184 = GPIO__DOT___GEN_178;
        GPIO__DOT___GEN_185 = GPIO__DOT___GEN_179;
    }
    if ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_190 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_191 = GPIO__DOT___GEN_185;
        } else {
            GPIO__DOT___GEN_190 = GPIO__DOT___GEN_184;
            GPIO__DOT___GEN_191 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_190 = GPIO__DOT___GEN_184;
        GPIO__DOT___GEN_191 = GPIO__DOT___GEN_185;
    }
    GPIO__DOT___GEN_198 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (8U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (7U & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_190))
                                : (IData)(GPIO__DOT___GEN_190))
                            : (IData)(GPIO__DOT___GEN_148));
    GPIO__DOT___GEN_204 = ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_198))
                            : (IData)(GPIO__DOT___GEN_198));
    GPIO__DOT___GEN_199 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((3U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((8U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_191)
                                    : ((8U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_191))
                            : (IData)(GPIO__DOT___GEN_149));
    GPIO__DOT___GEN_205 = ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_199)
                                : ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_199));
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_210 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_211 = GPIO__DOT___GEN_205;
        } else {
            GPIO__DOT___GEN_210 = GPIO__DOT___GEN_204;
            GPIO__DOT___GEN_211 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_210 = GPIO__DOT___GEN_204;
        GPIO__DOT___GEN_211 = GPIO__DOT___GEN_205;
    }
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_216 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_217 = GPIO__DOT___GEN_211;
        } else {
            GPIO__DOT___GEN_216 = GPIO__DOT___GEN_210;
            GPIO__DOT___GEN_217 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_216 = GPIO__DOT___GEN_210;
        GPIO__DOT___GEN_217 = GPIO__DOT___GEN_211;
    }
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_222 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_223 = GPIO__DOT___GEN_217;
        } else {
            GPIO__DOT___GEN_222 = GPIO__DOT___GEN_216;
            GPIO__DOT___GEN_223 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_222 = GPIO__DOT___GEN_216;
        GPIO__DOT___GEN_223 = GPIO__DOT___GEN_217;
    }
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_228 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_229 = GPIO__DOT___GEN_223;
        } else {
            GPIO__DOT___GEN_228 = GPIO__DOT___GEN_222;
            GPIO__DOT___GEN_229 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_228 = GPIO__DOT___GEN_222;
        GPIO__DOT___GEN_229 = GPIO__DOT___GEN_223;
    }
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_234 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_235 = GPIO__DOT___GEN_229;
        } else {
            GPIO__DOT___GEN_234 = GPIO__DOT___GEN_228;
            GPIO__DOT___GEN_235 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_234 = GPIO__DOT___GEN_228;
        GPIO__DOT___GEN_235 = GPIO__DOT___GEN_229;
    }
    if ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_240 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_241 = GPIO__DOT___GEN_235;
        } else {
            GPIO__DOT___GEN_240 = GPIO__DOT___GEN_234;
            GPIO__DOT___GEN_241 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_240 = GPIO__DOT___GEN_234;
        GPIO__DOT___GEN_241 = GPIO__DOT___GEN_235;
    }
    GPIO__DOT___GEN_248 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xefU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_240))
                                : (IData)(GPIO__DOT___GEN_240))
                            : (IData)(GPIO__DOT___GEN_198));
    GPIO__DOT___GEN_254 = ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_248))
                            : (IData)(GPIO__DOT___GEN_248));
    GPIO__DOT___GEN_249 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((4U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_241)
                                    : ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_241))
                            : (IData)(GPIO__DOT___GEN_199));
    GPIO__DOT___GEN_255 = ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_249)
                                : ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_249));
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_260 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_261 = GPIO__DOT___GEN_255;
        } else {
            GPIO__DOT___GEN_260 = GPIO__DOT___GEN_254;
            GPIO__DOT___GEN_261 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_260 = GPIO__DOT___GEN_254;
        GPIO__DOT___GEN_261 = GPIO__DOT___GEN_255;
    }
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_266 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_267 = GPIO__DOT___GEN_261;
        } else {
            GPIO__DOT___GEN_266 = GPIO__DOT___GEN_260;
            GPIO__DOT___GEN_267 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_266 = GPIO__DOT___GEN_260;
        GPIO__DOT___GEN_267 = GPIO__DOT___GEN_261;
    }
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_272 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_273 = GPIO__DOT___GEN_267;
        } else {
            GPIO__DOT___GEN_272 = GPIO__DOT___GEN_266;
            GPIO__DOT___GEN_273 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_272 = GPIO__DOT___GEN_266;
        GPIO__DOT___GEN_273 = GPIO__DOT___GEN_267;
    }
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_278 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_279 = GPIO__DOT___GEN_273;
        } else {
            GPIO__DOT___GEN_278 = GPIO__DOT___GEN_272;
            GPIO__DOT___GEN_279 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_278 = GPIO__DOT___GEN_272;
        GPIO__DOT___GEN_279 = GPIO__DOT___GEN_273;
    }
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_284 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_285 = GPIO__DOT___GEN_279;
        } else {
            GPIO__DOT___GEN_284 = GPIO__DOT___GEN_278;
            GPIO__DOT___GEN_285 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_284 = GPIO__DOT___GEN_278;
        GPIO__DOT___GEN_285 = GPIO__DOT___GEN_279;
    }
    if ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_290 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_291 = GPIO__DOT___GEN_285;
        } else {
            GPIO__DOT___GEN_290 = GPIO__DOT___GEN_284;
            GPIO__DOT___GEN_291 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_290 = GPIO__DOT___GEN_284;
        GPIO__DOT___GEN_291 = GPIO__DOT___GEN_285;
    }
    GPIO__DOT___GEN_298 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xdfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_290))
                                : (IData)(GPIO__DOT___GEN_290))
                            : (IData)(GPIO__DOT___GEN_248));
    GPIO__DOT___GEN_304 = ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_298))
                            : (IData)(GPIO__DOT___GEN_298));
    GPIO__DOT___GEN_299 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((5U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_291)
                                    : ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_291))
                            : (IData)(GPIO__DOT___GEN_249));
    GPIO__DOT___GEN_305 = ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_299)
                                : ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_299));
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_310 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_311 = GPIO__DOT___GEN_305;
        } else {
            GPIO__DOT___GEN_310 = GPIO__DOT___GEN_304;
            GPIO__DOT___GEN_311 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_310 = GPIO__DOT___GEN_304;
        GPIO__DOT___GEN_311 = GPIO__DOT___GEN_305;
    }
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_316 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_317 = GPIO__DOT___GEN_311;
        } else {
            GPIO__DOT___GEN_316 = GPIO__DOT___GEN_310;
            GPIO__DOT___GEN_317 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_316 = GPIO__DOT___GEN_310;
        GPIO__DOT___GEN_317 = GPIO__DOT___GEN_311;
    }
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_322 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_323 = GPIO__DOT___GEN_317;
        } else {
            GPIO__DOT___GEN_322 = GPIO__DOT___GEN_316;
            GPIO__DOT___GEN_323 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_322 = GPIO__DOT___GEN_316;
        GPIO__DOT___GEN_323 = GPIO__DOT___GEN_317;
    }
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_328 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_329 = GPIO__DOT___GEN_323;
        } else {
            GPIO__DOT___GEN_328 = GPIO__DOT___GEN_322;
            GPIO__DOT___GEN_329 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_328 = GPIO__DOT___GEN_322;
        GPIO__DOT___GEN_329 = GPIO__DOT___GEN_323;
    }
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_334 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_335 = GPIO__DOT___GEN_329;
        } else {
            GPIO__DOT___GEN_334 = GPIO__DOT___GEN_328;
            GPIO__DOT___GEN_335 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_334 = GPIO__DOT___GEN_328;
        GPIO__DOT___GEN_335 = GPIO__DOT___GEN_329;
    }
    if ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_340 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_341 = GPIO__DOT___GEN_335;
        } else {
            GPIO__DOT___GEN_340 = GPIO__DOT___GEN_334;
            GPIO__DOT___GEN_341 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_340 = GPIO__DOT___GEN_334;
        GPIO__DOT___GEN_341 = GPIO__DOT___GEN_335;
    }
    GPIO__DOT___GEN_348 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xbfU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_340))
                                : (IData)(GPIO__DOT___GEN_340))
                            : (IData)(GPIO__DOT___GEN_298));
    GPIO__DOT___GEN_354 = ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_348))
                            : (IData)(GPIO__DOT___GEN_348));
    GPIO__DOT___GEN_349 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((6U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_341)
                                    : ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_341))
                            : (IData)(GPIO__DOT___GEN_299));
    GPIO__DOT___GEN_355 = ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_349)
                                : ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_349));
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_360 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_361 = GPIO__DOT___GEN_355;
        } else {
            GPIO__DOT___GEN_360 = GPIO__DOT___GEN_354;
            GPIO__DOT___GEN_361 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_360 = GPIO__DOT___GEN_354;
        GPIO__DOT___GEN_361 = GPIO__DOT___GEN_355;
    }
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_366 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_367 = GPIO__DOT___GEN_361;
        } else {
            GPIO__DOT___GEN_366 = GPIO__DOT___GEN_360;
            GPIO__DOT___GEN_367 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_366 = GPIO__DOT___GEN_360;
        GPIO__DOT___GEN_367 = GPIO__DOT___GEN_361;
    }
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_372 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_373 = GPIO__DOT___GEN_367;
        } else {
            GPIO__DOT___GEN_372 = GPIO__DOT___GEN_366;
            GPIO__DOT___GEN_373 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_372 = GPIO__DOT___GEN_366;
        GPIO__DOT___GEN_373 = GPIO__DOT___GEN_367;
    }
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_378 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_379 = GPIO__DOT___GEN_373;
        } else {
            GPIO__DOT___GEN_378 = GPIO__DOT___GEN_372;
            GPIO__DOT___GEN_379 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_378 = GPIO__DOT___GEN_372;
        GPIO__DOT___GEN_379 = GPIO__DOT___GEN_373;
    }
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_384 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_385 = GPIO__DOT___GEN_379;
        } else {
            GPIO__DOT___GEN_384 = GPIO__DOT___GEN_378;
            GPIO__DOT___GEN_385 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_384 = GPIO__DOT___GEN_378;
        GPIO__DOT___GEN_385 = GPIO__DOT___GEN_379;
    }
    if ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_390 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_391 = GPIO__DOT___GEN_385;
        } else {
            GPIO__DOT___GEN_390 = GPIO__DOT___GEN_384;
            GPIO__DOT___GEN_391 = ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_390 = GPIO__DOT___GEN_384;
        GPIO__DOT___GEN_391 = GPIO__DOT___GEN_385;
    }
    GPIO__DOT___GEN_398 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_390))
                                : (IData)(GPIO__DOT___GEN_390))
                            : (IData)(GPIO__DOT___GEN_348));
    GPIO__DOT___GEN_404 = ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_398))
                            : (IData)(GPIO__DOT___GEN_398));
    GPIO__DOT___GEN_399 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((7U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_391)
                                    : ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_391))
                            : (IData)(GPIO__DOT___GEN_349));
    GPIO__DOT___GEN_405 = ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_399)
                                : ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_399));
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_410 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_411 = GPIO__DOT___GEN_405;
        } else {
            GPIO__DOT___GEN_410 = GPIO__DOT___GEN_404;
            GPIO__DOT___GEN_411 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_410 = GPIO__DOT___GEN_404;
        GPIO__DOT___GEN_411 = GPIO__DOT___GEN_405;
    }
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_416 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_417 = GPIO__DOT___GEN_411;
        } else {
            GPIO__DOT___GEN_416 = GPIO__DOT___GEN_410;
            GPIO__DOT___GEN_417 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_416 = GPIO__DOT___GEN_410;
        GPIO__DOT___GEN_417 = GPIO__DOT___GEN_411;
    }
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_422 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_423 = GPIO__DOT___GEN_417;
        } else {
            GPIO__DOT___GEN_422 = GPIO__DOT___GEN_416;
            GPIO__DOT___GEN_423 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_422 = GPIO__DOT___GEN_416;
        GPIO__DOT___GEN_423 = GPIO__DOT___GEN_417;
    }
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_428 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_429 = GPIO__DOT___GEN_423;
        } else {
            GPIO__DOT___GEN_428 = GPIO__DOT___GEN_422;
            GPIO__DOT___GEN_429 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_428 = GPIO__DOT___GEN_422;
        GPIO__DOT___GEN_429 = GPIO__DOT___GEN_423;
    }
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_434 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_435 = GPIO__DOT___GEN_429;
        } else {
            GPIO__DOT___GEN_434 = GPIO__DOT___GEN_428;
            GPIO__DOT___GEN_435 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_434 = GPIO__DOT___GEN_428;
        GPIO__DOT___GEN_435 = GPIO__DOT___GEN_429;
    }
    if ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_440 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfeffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_441 = GPIO__DOT___GEN_435;
        } else {
            GPIO__DOT___GEN_440 = GPIO__DOT___GEN_434;
            GPIO__DOT___GEN_441 = ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_440 = GPIO__DOT___GEN_434;
        GPIO__DOT___GEN_441 = GPIO__DOT___GEN_435;
    }
    GPIO__DOT___GEN_448 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x100U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xfeffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_440))
                                : (IData)(GPIO__DOT___GEN_440))
                            : (IData)(GPIO__DOT___GEN_398));
    GPIO__DOT___GEN_454 = ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_448))
                            : (IData)(GPIO__DOT___GEN_448));
    GPIO__DOT___GEN_449 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((8U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_441)
                                    : ((0x100U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_441))
                            : (IData)(GPIO__DOT___GEN_399));
    GPIO__DOT___GEN_455 = ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_449)
                                : ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_449));
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_460 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_461 = GPIO__DOT___GEN_455;
        } else {
            GPIO__DOT___GEN_460 = GPIO__DOT___GEN_454;
            GPIO__DOT___GEN_461 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_460 = GPIO__DOT___GEN_454;
        GPIO__DOT___GEN_461 = GPIO__DOT___GEN_455;
    }
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_466 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_467 = GPIO__DOT___GEN_461;
        } else {
            GPIO__DOT___GEN_466 = GPIO__DOT___GEN_460;
            GPIO__DOT___GEN_467 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_466 = GPIO__DOT___GEN_460;
        GPIO__DOT___GEN_467 = GPIO__DOT___GEN_461;
    }
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_472 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_473 = GPIO__DOT___GEN_467;
        } else {
            GPIO__DOT___GEN_472 = GPIO__DOT___GEN_466;
            GPIO__DOT___GEN_473 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_472 = GPIO__DOT___GEN_466;
        GPIO__DOT___GEN_473 = GPIO__DOT___GEN_467;
    }
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_478 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_479 = GPIO__DOT___GEN_473;
        } else {
            GPIO__DOT___GEN_478 = GPIO__DOT___GEN_472;
            GPIO__DOT___GEN_479 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_478 = GPIO__DOT___GEN_472;
        GPIO__DOT___GEN_479 = GPIO__DOT___GEN_473;
    }
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_484 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_485 = GPIO__DOT___GEN_479;
        } else {
            GPIO__DOT___GEN_484 = GPIO__DOT___GEN_478;
            GPIO__DOT___GEN_485 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_484 = GPIO__DOT___GEN_478;
        GPIO__DOT___GEN_485 = GPIO__DOT___GEN_479;
    }
    if ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_490 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfdffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_491 = GPIO__DOT___GEN_485;
        } else {
            GPIO__DOT___GEN_490 = GPIO__DOT___GEN_484;
            GPIO__DOT___GEN_491 = ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_490 = GPIO__DOT___GEN_484;
        GPIO__DOT___GEN_491 = GPIO__DOT___GEN_485;
    }
    GPIO__DOT___GEN_498 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x200U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xfdffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_490))
                                : (IData)(GPIO__DOT___GEN_490))
                            : (IData)(GPIO__DOT___GEN_448));
    GPIO__DOT___GEN_504 = ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_498))
                            : (IData)(GPIO__DOT___GEN_498));
    GPIO__DOT___GEN_499 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((9U == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_491)
                                    : ((0x200U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_491))
                            : (IData)(GPIO__DOT___GEN_449));
    GPIO__DOT___GEN_505 = ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_499)
                                : ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_499));
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_510 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_511 = GPIO__DOT___GEN_505;
        } else {
            GPIO__DOT___GEN_510 = GPIO__DOT___GEN_504;
            GPIO__DOT___GEN_511 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_510 = GPIO__DOT___GEN_504;
        GPIO__DOT___GEN_511 = GPIO__DOT___GEN_505;
    }
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_516 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_517 = GPIO__DOT___GEN_511;
        } else {
            GPIO__DOT___GEN_516 = GPIO__DOT___GEN_510;
            GPIO__DOT___GEN_517 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_516 = GPIO__DOT___GEN_510;
        GPIO__DOT___GEN_517 = GPIO__DOT___GEN_511;
    }
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_522 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_523 = GPIO__DOT___GEN_517;
        } else {
            GPIO__DOT___GEN_522 = GPIO__DOT___GEN_516;
            GPIO__DOT___GEN_523 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_522 = GPIO__DOT___GEN_516;
        GPIO__DOT___GEN_523 = GPIO__DOT___GEN_517;
    }
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_528 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_529 = GPIO__DOT___GEN_523;
        } else {
            GPIO__DOT___GEN_528 = GPIO__DOT___GEN_522;
            GPIO__DOT___GEN_529 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_528 = GPIO__DOT___GEN_522;
        GPIO__DOT___GEN_529 = GPIO__DOT___GEN_523;
    }
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_534 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_535 = GPIO__DOT___GEN_529;
        } else {
            GPIO__DOT___GEN_534 = GPIO__DOT___GEN_528;
            GPIO__DOT___GEN_535 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_534 = GPIO__DOT___GEN_528;
        GPIO__DOT___GEN_535 = GPIO__DOT___GEN_529;
    }
    if ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_540 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xfbffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_541 = GPIO__DOT___GEN_535;
        } else {
            GPIO__DOT___GEN_540 = GPIO__DOT___GEN_534;
            GPIO__DOT___GEN_541 = ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_540 = GPIO__DOT___GEN_534;
        GPIO__DOT___GEN_541 = GPIO__DOT___GEN_535;
    }
    GPIO__DOT___GEN_548 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x400U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xfbffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_540))
                                : (IData)(GPIO__DOT___GEN_540))
                            : (IData)(GPIO__DOT___GEN_498));
    GPIO__DOT___GEN_554 = ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_548))
                            : (IData)(GPIO__DOT___GEN_548));
    GPIO__DOT___GEN_549 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xaU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_541)
                                    : ((0x400U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_541))
                            : (IData)(GPIO__DOT___GEN_499));
    GPIO__DOT___GEN_555 = ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_549)
                                : ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_549));
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_560 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_561 = GPIO__DOT___GEN_555;
        } else {
            GPIO__DOT___GEN_560 = GPIO__DOT___GEN_554;
            GPIO__DOT___GEN_561 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_560 = GPIO__DOT___GEN_554;
        GPIO__DOT___GEN_561 = GPIO__DOT___GEN_555;
    }
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_566 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_567 = GPIO__DOT___GEN_561;
        } else {
            GPIO__DOT___GEN_566 = GPIO__DOT___GEN_560;
            GPIO__DOT___GEN_567 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_566 = GPIO__DOT___GEN_560;
        GPIO__DOT___GEN_567 = GPIO__DOT___GEN_561;
    }
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_572 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_573 = GPIO__DOT___GEN_567;
        } else {
            GPIO__DOT___GEN_572 = GPIO__DOT___GEN_566;
            GPIO__DOT___GEN_573 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_572 = GPIO__DOT___GEN_566;
        GPIO__DOT___GEN_573 = GPIO__DOT___GEN_567;
    }
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_578 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_579 = GPIO__DOT___GEN_573;
        } else {
            GPIO__DOT___GEN_578 = GPIO__DOT___GEN_572;
            GPIO__DOT___GEN_579 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_578 = GPIO__DOT___GEN_572;
        GPIO__DOT___GEN_579 = GPIO__DOT___GEN_573;
    }
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_584 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_585 = GPIO__DOT___GEN_579;
        } else {
            GPIO__DOT___GEN_584 = GPIO__DOT___GEN_578;
            GPIO__DOT___GEN_585 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_584 = GPIO__DOT___GEN_578;
        GPIO__DOT___GEN_585 = GPIO__DOT___GEN_579;
    }
    if ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_590 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xf7ffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_591 = GPIO__DOT___GEN_585;
        } else {
            GPIO__DOT___GEN_590 = GPIO__DOT___GEN_584;
            GPIO__DOT___GEN_591 = ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_590 = GPIO__DOT___GEN_584;
        GPIO__DOT___GEN_591 = GPIO__DOT___GEN_585;
    }
    GPIO__DOT___GEN_598 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x800U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xf7ffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_590))
                                : (IData)(GPIO__DOT___GEN_590))
                            : (IData)(GPIO__DOT___GEN_548));
    GPIO__DOT___GEN_604 = ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_598))
                            : (IData)(GPIO__DOT___GEN_598));
    GPIO__DOT___GEN_599 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xbU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_591)
                                    : ((0x800U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_591))
                            : (IData)(GPIO__DOT___GEN_549));
    GPIO__DOT___GEN_605 = ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_599)
                                : ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_599));
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_610 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_611 = GPIO__DOT___GEN_605;
        } else {
            GPIO__DOT___GEN_610 = GPIO__DOT___GEN_604;
            GPIO__DOT___GEN_611 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_610 = GPIO__DOT___GEN_604;
        GPIO__DOT___GEN_611 = GPIO__DOT___GEN_605;
    }
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_616 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_617 = GPIO__DOT___GEN_611;
        } else {
            GPIO__DOT___GEN_616 = GPIO__DOT___GEN_610;
            GPIO__DOT___GEN_617 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_616 = GPIO__DOT___GEN_610;
        GPIO__DOT___GEN_617 = GPIO__DOT___GEN_611;
    }
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_622 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_623 = GPIO__DOT___GEN_617;
        } else {
            GPIO__DOT___GEN_622 = GPIO__DOT___GEN_616;
            GPIO__DOT___GEN_623 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_622 = GPIO__DOT___GEN_616;
        GPIO__DOT___GEN_623 = GPIO__DOT___GEN_617;
    }
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_628 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_629 = GPIO__DOT___GEN_623;
        } else {
            GPIO__DOT___GEN_628 = GPIO__DOT___GEN_622;
            GPIO__DOT___GEN_629 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_628 = GPIO__DOT___GEN_622;
        GPIO__DOT___GEN_629 = GPIO__DOT___GEN_623;
    }
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_634 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_635 = GPIO__DOT___GEN_629;
        } else {
            GPIO__DOT___GEN_634 = GPIO__DOT___GEN_628;
            GPIO__DOT___GEN_635 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_634 = GPIO__DOT___GEN_628;
        GPIO__DOT___GEN_635 = GPIO__DOT___GEN_629;
    }
    if ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_640 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x1000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xefffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_641 = GPIO__DOT___GEN_635;
        } else {
            GPIO__DOT___GEN_640 = GPIO__DOT___GEN_634;
            GPIO__DOT___GEN_641 = ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_640 = GPIO__DOT___GEN_634;
        GPIO__DOT___GEN_641 = GPIO__DOT___GEN_635;
    }
    GPIO__DOT___GEN_648 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x1000U 
                                           | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xefffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_640))
                                : (IData)(GPIO__DOT___GEN_640))
                            : (IData)(GPIO__DOT___GEN_598));
    GPIO__DOT___GEN_654 = ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_648))
                            : (IData)(GPIO__DOT___GEN_648));
    GPIO__DOT___GEN_649 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xcU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_641)
                                    : ((0x1000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_641))
                            : (IData)(GPIO__DOT___GEN_599));
    GPIO__DOT___GEN_655 = ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_649)
                                : ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_649));
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_660 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_661 = GPIO__DOT___GEN_655;
        } else {
            GPIO__DOT___GEN_660 = GPIO__DOT___GEN_654;
            GPIO__DOT___GEN_661 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_660 = GPIO__DOT___GEN_654;
        GPIO__DOT___GEN_661 = GPIO__DOT___GEN_655;
    }
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_666 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_667 = GPIO__DOT___GEN_661;
        } else {
            GPIO__DOT___GEN_666 = GPIO__DOT___GEN_660;
            GPIO__DOT___GEN_667 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_666 = GPIO__DOT___GEN_660;
        GPIO__DOT___GEN_667 = GPIO__DOT___GEN_661;
    }
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_672 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_673 = GPIO__DOT___GEN_667;
        } else {
            GPIO__DOT___GEN_672 = GPIO__DOT___GEN_666;
            GPIO__DOT___GEN_673 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_672 = GPIO__DOT___GEN_666;
        GPIO__DOT___GEN_673 = GPIO__DOT___GEN_667;
    }
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_678 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_679 = GPIO__DOT___GEN_673;
        } else {
            GPIO__DOT___GEN_678 = GPIO__DOT___GEN_672;
            GPIO__DOT___GEN_679 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_678 = GPIO__DOT___GEN_672;
        GPIO__DOT___GEN_679 = GPIO__DOT___GEN_673;
    }
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_684 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_685 = GPIO__DOT___GEN_679;
        } else {
            GPIO__DOT___GEN_684 = GPIO__DOT___GEN_678;
            GPIO__DOT___GEN_685 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_684 = GPIO__DOT___GEN_678;
        GPIO__DOT___GEN_685 = GPIO__DOT___GEN_679;
    }
    if ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_690 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x2000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xdfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_691 = GPIO__DOT___GEN_685;
        } else {
            GPIO__DOT___GEN_690 = GPIO__DOT___GEN_684;
            GPIO__DOT___GEN_691 = ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_690 = GPIO__DOT___GEN_684;
        GPIO__DOT___GEN_691 = GPIO__DOT___GEN_685;
    }
    GPIO__DOT___GEN_698 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x2000U 
                                           | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xdfffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_690))
                                : (IData)(GPIO__DOT___GEN_690))
                            : (IData)(GPIO__DOT___GEN_648));
    GPIO__DOT___GEN_704 = ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_698))
                            : (IData)(GPIO__DOT___GEN_698));
    GPIO__DOT___GEN_699 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xdU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_691)
                                    : ((0x2000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_691))
                            : (IData)(GPIO__DOT___GEN_649));
    GPIO__DOT___GEN_705 = ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_699)
                                : ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_699));
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_710 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_711 = GPIO__DOT___GEN_705;
        } else {
            GPIO__DOT___GEN_710 = GPIO__DOT___GEN_704;
            GPIO__DOT___GEN_711 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_710 = GPIO__DOT___GEN_704;
        GPIO__DOT___GEN_711 = GPIO__DOT___GEN_705;
    }
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_716 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_717 = GPIO__DOT___GEN_711;
        } else {
            GPIO__DOT___GEN_716 = GPIO__DOT___GEN_710;
            GPIO__DOT___GEN_717 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_716 = GPIO__DOT___GEN_710;
        GPIO__DOT___GEN_717 = GPIO__DOT___GEN_711;
    }
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_722 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_723 = GPIO__DOT___GEN_717;
        } else {
            GPIO__DOT___GEN_722 = GPIO__DOT___GEN_716;
            GPIO__DOT___GEN_723 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_722 = GPIO__DOT___GEN_716;
        GPIO__DOT___GEN_723 = GPIO__DOT___GEN_717;
    }
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_728 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_729 = GPIO__DOT___GEN_723;
        } else {
            GPIO__DOT___GEN_728 = GPIO__DOT___GEN_722;
            GPIO__DOT___GEN_729 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_728 = GPIO__DOT___GEN_722;
        GPIO__DOT___GEN_729 = GPIO__DOT___GEN_723;
    }
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_734 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_735 = GPIO__DOT___GEN_729;
        } else {
            GPIO__DOT___GEN_734 = GPIO__DOT___GEN_728;
            GPIO__DOT___GEN_735 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_734 = GPIO__DOT___GEN_728;
        GPIO__DOT___GEN_735 = GPIO__DOT___GEN_729;
    }
    if ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_740 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x4000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0xbfffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_741 = GPIO__DOT___GEN_735;
        } else {
            GPIO__DOT___GEN_740 = GPIO__DOT___GEN_734;
            GPIO__DOT___GEN_741 = ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_740 = GPIO__DOT___GEN_734;
        GPIO__DOT___GEN_741 = GPIO__DOT___GEN_735;
    }
    GPIO__DOT___GEN_748 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? ((1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        ? (0x4000U 
                                           | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                        : (0xbfffU 
                                           & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                    : (IData)(GPIO__DOT___GEN_740))
                                : (IData)(GPIO__DOT___GEN_740))
                            : (IData)(GPIO__DOT___GEN_698));
    GPIO__DOT___GEN_754 = ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? ((0x80U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)))
                                : (IData)(GPIO__DOT___GEN_748))
                            : (IData)(GPIO__DOT___GEN_748));
    GPIO__DOT___GEN_749 = ((IData)(vlSelf->GPIO__DOT__regs_virtualPortEnable)
                            ? ((0xeU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))
                                ? ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                    ? (IData)(GPIO__DOT___GEN_741)
                                    : ((0x4000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                        ? (1U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                        : 0U)) : (IData)(GPIO__DOT___GEN_741))
                            : (IData)(GPIO__DOT___GEN_699));
    GPIO__DOT___GEN_755 = ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_7))
                            ? ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))
                                ? (IData)(GPIO__DOT___GEN_749)
                                : ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x80U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x7fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))))
                            : (IData)(GPIO__DOT___GEN_749));
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_6))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_760 = ((0x40U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_761 = GPIO__DOT___GEN_755;
        } else {
            GPIO__DOT___GEN_760 = GPIO__DOT___GEN_754;
            GPIO__DOT___GEN_761 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x40U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x3fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_760 = GPIO__DOT___GEN_754;
        GPIO__DOT___GEN_761 = GPIO__DOT___GEN_755;
    }
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_5))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_766 = ((0x20U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_767 = GPIO__DOT___GEN_761;
        } else {
            GPIO__DOT___GEN_766 = GPIO__DOT___GEN_760;
            GPIO__DOT___GEN_767 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x20U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0x1fU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_766 = GPIO__DOT___GEN_760;
        GPIO__DOT___GEN_767 = GPIO__DOT___GEN_761;
    }
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_4))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_772 = ((0x10U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_773 = GPIO__DOT___GEN_767;
        } else {
            GPIO__DOT___GEN_772 = GPIO__DOT___GEN_766;
            GPIO__DOT___GEN_773 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (0x10U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (0xfU & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_772 = GPIO__DOT___GEN_766;
        GPIO__DOT___GEN_773 = GPIO__DOT___GEN_767;
    }
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_3))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_778 = ((8U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_779 = GPIO__DOT___GEN_773;
        } else {
            GPIO__DOT___GEN_778 = GPIO__DOT___GEN_772;
            GPIO__DOT___GEN_779 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (8U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (7U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_778 = GPIO__DOT___GEN_772;
        GPIO__DOT___GEN_779 = GPIO__DOT___GEN_773;
    }
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_2))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_784 = ((4U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_785 = GPIO__DOT___GEN_779;
        } else {
            GPIO__DOT___GEN_784 = GPIO__DOT___GEN_778;
            GPIO__DOT___GEN_785 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (4U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (3U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_784 = GPIO__DOT___GEN_778;
        GPIO__DOT___GEN_785 = GPIO__DOT___GEN_779;
    }
    if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_1))) {
        if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
            GPIO__DOT___GEN_790 = ((2U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    ? (0x8000U | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                    : (0x7fffU & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
            GPIO__DOT___GEN_791 = GPIO__DOT___GEN_785;
        } else {
            GPIO__DOT___GEN_790 = GPIO__DOT___GEN_784;
            GPIO__DOT___GEN_791 = ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                    ? (2U | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                    : (1U & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput)));
        }
    } else {
        GPIO__DOT___GEN_790 = GPIO__DOT___GEN_784;
        GPIO__DOT___GEN_791 = GPIO__DOT___GEN_785;
    }
    if (vlSelf->GPIO__DOT__regs_virtualPortEnable) {
        if ((0xfU == (IData)(vlSelf->GPIO__DOT__regs_virtualToPhysicalMap_0))) {
            if ((0x8000U & (IData)(vlSelf->GPIO__DOT__regs_DIRECTION))) {
                vlSelf->GPIO__DOT___GEN_798 = ((1U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                                ? (0x8000U 
                                                   | (IData)(vlSelf->GPIO__DOT__regs_OUTPUT))
                                                : (0x7fffU 
                                                   & (IData)(vlSelf->GPIO__DOT__regs_OUTPUT)));
                vlSelf->GPIO__DOT___GEN_799 = GPIO__DOT___GEN_791;
            } else {
                vlSelf->GPIO__DOT___GEN_798 = GPIO__DOT___GEN_790;
                vlSelf->GPIO__DOT___GEN_799 = ((0x8000U 
                                                & (IData)(vlSelf->GPIO__DOT__regs_INPUT))
                                                ? (1U 
                                                   | (IData)(vlSelf->GPIO__DOT__regs_virtualPortOutput))
                                                : 0U);
            }
        } else {
            vlSelf->GPIO__DOT___GEN_798 = GPIO__DOT___GEN_790;
            vlSelf->GPIO__DOT___GEN_799 = GPIO__DOT___GEN_791;
        }
    } else {
        vlSelf->GPIO__DOT___GEN_798 = GPIO__DOT___GEN_748;
        vlSelf->GPIO__DOT___GEN_799 = GPIO__DOT___GEN_749;
    }
}
