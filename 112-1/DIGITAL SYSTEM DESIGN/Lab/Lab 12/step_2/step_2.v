module step_2(w, clock, reset, state, z);
	input w, clock, reset;
	output reg[3:0] state;
	output reg z;
	parameter S0=4'b0000, S1=4'b0001, S2=4'b0010, S3=4'b0011,
				 S4=4'b0100, S5=4'b0101, S6=4'b0110, S7=4'b0111, S8=4'b1000; 
	
	reg [3:0] next_state;
	
	// State Register
	always @(posedge clock or negedge reset) begin
		if (!reset)
			state = S0;
		else
			state = next_state;
	end
	
	// Next State
	always @(w or state) begin
		case (state)
			S0: next_state = (w==1) ? S1 : S5;
			S1: next_state = (w==1) ? S2 : S5;
			S2: next_state = (w==1) ? S3 : S5;
			S3: next_state = (w==1) ? S4 : S5;
			S4: next_state = (w==1) ? S4 : S5;
			S5: next_state = (w==0) ? S6 : S1;
			S6: next_state = (w==0) ? S7 : S1;
			S7: next_state = (w==0) ? S8 : S1;
			S8: next_state = (w==0) ? S8 : S1;
		endcase
	end
	
	// Output
	always @(state) begin
		case (state)
			S4, S8: z = 1'b1;
			default: z = 1'b0;
		endcase
	end
endmodule