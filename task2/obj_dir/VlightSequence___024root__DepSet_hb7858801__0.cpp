// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VlightSequence.h for the primary calling header

#include "verilated.h"

#include "VlightSequence___024root.h"

VL_INLINE_OPT void VlightSequence___024root___sequent__TOP__0(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->lightSequence__DOT__current_state = ((IData)(vlSelf->rst)
                                                  ? 0U
                                                  : vlSelf->lightSequence__DOT__next_state);
}

VL_INLINE_OPT void VlightSequence___024root___combo__TOP__0(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___combo__TOP__0\n"); );
    // Body
    if (((((((((0U == vlSelf->lightSequence__DOT__current_state) 
               | (1U == vlSelf->lightSequence__DOT__current_state)) 
              | (2U == vlSelf->lightSequence__DOT__current_state)) 
             | (3U == vlSelf->lightSequence__DOT__current_state)) 
            | (4U == vlSelf->lightSequence__DOT__current_state)) 
           | (5U == vlSelf->lightSequence__DOT__current_state)) 
          | (6U == vlSelf->lightSequence__DOT__current_state)) 
         | (7U == vlSelf->lightSequence__DOT__current_state))) {
        if ((0U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 1U;
                vlSelf->out = 0U;
            }
        } else if ((1U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 2U;
                vlSelf->out = 1U;
            }
        } else if ((2U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 3U;
                vlSelf->out = 3U;
            }
        } else if ((3U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 4U;
                vlSelf->out = 7U;
            }
        } else if ((4U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 5U;
                vlSelf->out = 0xfU;
            }
        } else if ((5U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 6U;
                vlSelf->out = 0x1fU;
            }
        } else if ((6U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->lightSequence__DOT__next_state = 7U;
                vlSelf->out = 0x3fU;
            }
        } else if (vlSelf->en) {
            vlSelf->lightSequence__DOT__next_state = 8U;
            vlSelf->out = 0x7fU;
        }
    } else {
        if (vlSelf->en) {
            vlSelf->lightSequence__DOT__next_state = 0U;
        }
        if ((8U == vlSelf->lightSequence__DOT__current_state)) {
            if (vlSelf->en) {
                vlSelf->out = 0xffU;
            }
        } else {
            vlSelf->out = 0U;
        }
    }
}

void VlightSequence___024root___eval(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VlightSequence___024root___sequent__TOP__0(vlSelf);
    }
    VlightSequence___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VlightSequence___024root___eval_debug_assertions(VlightSequence___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VlightSequence___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
