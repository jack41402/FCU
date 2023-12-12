module step_1(x, clock, reset, state, op);
	input x, clock, reset;
	output reg[2:0] state;
	output op;
	parameter S0=
	
	// State Register
	always @(posedge clock or posedge reset) begin
		if (reset)
			state = S0;
		else
			state = next_state;
	end
	
	// Next State
	always @(x or state) begin
		case (state) begin
			S0: begin
				if (x)
					next_state = ;
				else
					next_state = ;
			end
			S1: begin
				if (x)
					next_state = ;
				else
					next_state = ;
			end
			S2: begin
				if (x)
					next_state = ;
				else
					next_state = ;
			end
			S3: begin
				if (x)
					next_state = ;
				else
					next_state = ;
			end
		endcase
	end
	
	// Output
	always @(state) begin
		case (state) begin
			S0: op = 0;
			S1: op = 0;
			S2: op = 0;
			S3: op = 0;
		end
	end
endmodule