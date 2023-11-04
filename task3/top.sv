module top(
    input  logic             clk,      // clock 
    input  logic             rst,      // reset
    input  logic             en,       // enable signal
    input  logic [7:0]       N,     	 // clock divided by N+1
    output logic [7:0]       lights      // tick output
);

logic tick;

clktick clktick(
    .clk(clk),
    .rst(rst),
    .en(en),
    .N(N),
    .tick(tick)
);

lightSequence lightSequence(
    .clk(clk),
    .rst(rst),
    .en(tick),
    .out(lights)
);

endmodule
