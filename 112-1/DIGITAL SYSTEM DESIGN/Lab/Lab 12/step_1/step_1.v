module step_1(x, clock, reset, state, op);
	input x, clock, reset;
	output reg[2:0] state;
	output reg op;
	parameter S0=3'b000, S1=3'b001, S2=3'b010, S3=3'b011, S4=3'b100;
	
	reg [2:0] next_state;
	
	// State Register
	always @(posedge clock or negedge reset) begin
		if (!reset)
			state = S0;
		else
			state = next_state;
	end
	
	// Next State
	always @(x or state) begin
		case (state)
			S0: next_state = (x==1) ? S1 : S0;
			S1: next_state = (x==1) ? S1 : S2;
			S2: next_state = (x==1) ? S3 : S0;
			S3: next_state = (x==1) ? S4 : S2;
			S4: next_state = (x==1) ? S1 : S2;
		endcase
	end
	
	// Output
	always @(state) begin
		case (state)
			S4: op = 1'b1;
			default: op = 1'b0;
		endcase
	end
endmodule