#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlfsr.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int step;

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vlfsr* top = new Vlfsr;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sigdelay.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T1:LFSR4");
  vbdSetMode(1);

  // initialize simulation input 
  top->clk = 1;
  top->rst = 1;

  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {

    step = 0;
    while(step == 0){ // this is cringe - infinite loops W/O timeout are a bad idea - plus there is defo a cleaner way to implement this
       step = vbdFlag();
    }
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
 
    top -> rst = (simcyc < 2);

    // plot RAM input/output, send sample to DAC buffer, and print cycle count
    vbdHex(4, (int(top->data_out) >> 16) & 0xF);
    vbdHex(3, (int(top->data_out) >> 8) & 0xF);
    vbdHex(2, (int(top->data_out) >> 4) & 0xF);
    vbdHex(1, (int(top->data_out)) & 0xF);
        

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
