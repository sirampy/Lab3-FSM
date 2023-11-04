// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VlightSequence.h"
#include "VlightSequence__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VlightSequence::VlightSequence(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VlightSequence__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , rst{vlSymsp->TOP.rst}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VlightSequence::VlightSequence(const char* _vcname__)
    : VlightSequence(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VlightSequence::~VlightSequence() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VlightSequence___024root___eval_initial(VlightSequence___024root* vlSelf);
void VlightSequence___024root___eval_settle(VlightSequence___024root* vlSelf);
void VlightSequence___024root___eval(VlightSequence___024root* vlSelf);
#ifdef VL_DEBUG
void VlightSequence___024root___eval_debug_assertions(VlightSequence___024root* vlSelf);
#endif  // VL_DEBUG
void VlightSequence___024root___final(VlightSequence___024root* vlSelf);

static void _eval_initial_loop(VlightSequence__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VlightSequence___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VlightSequence___024root___eval_settle(&(vlSymsp->TOP));
        VlightSequence___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VlightSequence::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VlightSequence::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VlightSequence___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VlightSequence___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VlightSequence::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VlightSequence::final() {
    VlightSequence___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VlightSequence::hierName() const { return vlSymsp->name(); }
const char* VlightSequence::modelName() const { return "VlightSequence"; }
unsigned VlightSequence::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VlightSequence::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VlightSequence___024root__trace_init_top(VlightSequence___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VlightSequence___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VlightSequence___024root*>(voidSelf);
    VlightSequence__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VlightSequence___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VlightSequence___024root__trace_register(VlightSequence___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VlightSequence::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VlightSequence___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
