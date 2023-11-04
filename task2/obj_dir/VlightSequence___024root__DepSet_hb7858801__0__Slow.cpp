// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VlightSequence.h for the primary calling header

#include "verilated.h"

#include "VlightSequence___024root.h"

VL_ATTR_COLD void VlightSequence___024root___eval_initial(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VlightSequence___024root___combo__TOP__0(VlightSequence___024root* vlSelf);

VL_ATTR_COLD void VlightSequence___024root___eval_settle(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___eval_settle\n"); );
    // Body
    VlightSequence___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void VlightSequence___024root___final(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___final\n"); );
}

VL_ATTR_COLD void VlightSequence___024root___ctor_var_reset(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->out = VL_RAND_RESET_I(8);
    vlSelf->lightSequence__DOT__current_state = 0;
    vlSelf->lightSequence__DOT__next_state = 0;
}
