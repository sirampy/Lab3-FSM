My testbench and lfsr.sv follow the lecture notes, not the lab instruction's top level circuit diagram - hence they dont have an enable signal. this makes more sense as it allows me to verify that the reset works as intended (symcyc would quickly >= 2 otherwise):

```sv
module lfsr #()(
    input logic         clk,
    input logic         rst,
    output logic [4:1]  data_out
);

    logic [4:1] sreg;

always_ff @ (posedge clk)
    if(rst)
        sreg <= 4'b1;
    else
        sreg <= {sreg[3:1],sreg[4]^sreg[3]};
    
    assign data_out = sreg;

endmodule
```

I also made the following hoping to use it as part of the lfsr:
```sv
module sreg #(
    parameter WIDTH = 4'
) (
    input logic     clk,
    input logic     rst,
    input logic     data_in,
    output logic    data_out,
    input logic     [WIDTH-1:0] load,      
    input logic     [WIDTH-1:0] load_input,      
);
    logic [WIDTH:1] data;

    always_ff @(posedge clk) begin
        if(rst) 
            sreg <= WIDTH'b0;
        else begin
            data[1] <= data_in;
            for(in i = 2; i <= WIDTH; i ++)begin
                if(!load[i]) data[i] <= data[i -1];
                else data[i] <= load_input[i];
            end
        end
    assign data_out = data[WIDTH];
    end

endmodule
```

finally an 8 bit version following $1 + X^3 + X^7$:
```sv
module lfsr #()(
    input logic         clk,
    input logic         rst,
    output logic [4:1]  data_out
);

    logic [8:1] sreg;

always_ff @ (posedge clk)
    if(rst)
        sreg <= 4'b1;
    else
        sreg <= {sreg[7:1],sreg[3]^sreg[7]};
    
    assign data_out = sreg;

endmodule
```
