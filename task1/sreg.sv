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