module step_2(clock, reset, HEX3);
	input clock, reset;
	output reg[0:6] HEX3;
	
	integer state=1;
	
	always @(posedge clock or negedge reset) begin
		if (!reset) state = 1;
		else if (state+1<=10) state = state + 1;
	end
	
	always @* begin
		case (state)
			4'b0000: HEX3 = 7'b0000001;	// 0
			4'b0001: HEX3 = 7'b1001111;	// 1
			4'b0010: HEX3 = 7'b0010010;	// 2
			4'b0011: HEX3 = 7'b0000110;	// 3
			4'b0100: HEX3 = 7'b1001100;	// 4
			4'b0101: HEX3 = 7'b0100100;	// 5
			4'b0110: HEX3 = 7'b0100000;	// 6
			4'b0111: HEX3 = 7'b0001101;	// 7
			4'b1000: HEX3 = 7'b0000000;	// 8
			4'b1001: HEX3 = 7'b0000100;	// 9
			4'b1010: HEX3 = 7'b0001000;	// A
			default: HEX3 = 7'b1111111; 	// default
		endcase
	end
endmodule