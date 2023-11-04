#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VlightSequence.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int step;

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VlightSequence* top = new VlightSequence;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sigdelay.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3:F1s");
  vbdSetMode(1);

  // initialize simulation input 
  top->clk = 1;
  top->rst = 1;

  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {

    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
      top->en = vbdFlag();
    }
 
    top -> rst = (simcyc < 2);

    // plot RAM input/output, send sample to DAC buffer, and print cycle count
    vbdBar(top->out);
    vbdCycle(simcyc);
        

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
