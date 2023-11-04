// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VlightSequence.h for the primary calling header

#ifndef VERILATED_VLIGHTSEQUENCE___024ROOT_H_
#define VERILATED_VLIGHTSEQUENCE___024ROOT_H_  // guard

#include "verilated.h"

class VlightSequence__Syms;

class VlightSequence___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(out,7,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ lightSequence__DOT__current_state;
    IData/*31:0*/ lightSequence__DOT__next_state;

    // INTERNAL VARIABLES
    VlightSequence__Syms* const vlSymsp;

    // CONSTRUCTORS
    VlightSequence___024root(VlightSequence__Syms* symsp, const char* name);
    ~VlightSequence___024root();
    VL_UNCOPYABLE(VlightSequence___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
