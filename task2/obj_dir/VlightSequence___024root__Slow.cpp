// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VlightSequence.h for the primary calling header

#include "verilated.h"

#include "VlightSequence__Syms.h"
#include "VlightSequence___024root.h"

void VlightSequence___024root___ctor_var_reset(VlightSequence___024root* vlSelf);

VlightSequence___024root::VlightSequence___024root(VlightSequence__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VlightSequence___024root___ctor_var_reset(this);
}

void VlightSequence___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VlightSequence___024root::~VlightSequence___024root() {
}
