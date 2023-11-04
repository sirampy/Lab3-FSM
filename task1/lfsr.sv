module lfsr #()(
    input logic         clk,
    input logic         rst,
    output logic [8:1]  data_out
);

    logic [8:1] sreg;

always_ff @ (posedge clk)
    if(rst)
        sreg <= 4'b1;
    else
        sreg <= {sreg[7:1],sreg[3]^sreg[7]};
    
    assign data_out = sreg;

endmodule
