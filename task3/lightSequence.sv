module lightSequence (
    input logic clk,
    input logic en,
    input logic rst,
    output logic [7:0] out
);

    typedef enum {s0, s1, s2, s3, s4, s5, s6, s7, s8} states;

    states current_state, next_state;

    always_ff @(posedge clk)
        if (rst)    current_state <= s0;
        else        current_state <= next_state;
    
    always_comb 
        case(current_state)
            s0: if(en) next_state = s1;
            s1: if(en) next_state = s2;
            s2: if(en) next_state = s3;
            s3: if(en) next_state = s4;
            s4: if(en) next_state = s5;
            s5: if(en) next_state = s6;
            s6: if(en) next_state = s7;
            s7: if(en) next_state = s8;
            default: if(en) next_state = s0;
        endcase

    always_comb
        case(current_state)
            s0: if(en) out = 8'b0;
            s1: if(en) out = 8'b1;
            s2: if(en) out = 8'b11;
            s3: if(en) out = 8'b111;
            s4: if(en) out = 8'b1111;
            s5: if(en) out = 8'b11111;
            s6: if(en) out = 8'b111111;
            s7: if(en) out = 8'b1111111;
            s8: if(en) out = 8'b11111111;
            default: out = 8'b0;
        endcase

    
endmodule
