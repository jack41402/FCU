module step1(I0, I1, I2, I3, I4, a, b, c, d, e, f, g);
	input I0, I1, I2, I3, I4;
	output a, b, c, d, e, f, g;
	reg [6:0] led;
	
	always @(I0, I1, I2, I3, I4) begin
		if (I4==0)
			case({I3, I2, I1, I0})
				4'b0000: led = 7'b0000001;	// 0
				4'b0001: led = 7'b1001111;	// 1
				4'b0010: led = 7'b0010010;	// 2
				4'b0011: led = 7'b0000110;	// 3
				4'b0100: led = 7'b1001100;	// 4
				4'b0101: led = 7'b0100100;	// 5
				4'b0110: led = 7'b0100000;	// 6
				4'b0111: led = 7'b0001101;	// 7
				4'b1000: led = 7'b0000000;	// 8
				4'b1001: led = 7'b0000100;	// 9
				4'b1010: led = 7'b0001000;	// A
				4'b1011: led = 7'b1100000;	// B
				4'b1100: led = 7'b0110001;	// C
				4'b1101: led = 7'b1000010;	// D
				4'b1110: led = 7'b0110000;	// E
				4'b1111: led = 7'b0111000;	// F
				default: led = 7'b1111111; // default
			endcase
		else
			case({I3, I2, I1, I0})
				4'b0000: led = 7'b0001000;	// A
				4'b0001: led = 7'b1100000;	// B
				4'b0010: led = 7'b0110001;	// C
				4'b0011: led = 7'b1000010;	// D
				4'b0100: led = 7'b0110000;	// E
				4'b0101: led = 7'b0111000;	// F
				4'b0110: led = 7'b0000100;	// G
				4'b0111: led = 7'b1001000;	// H
				4'b1000: led = 7'b0000011;	// J
				4'b1001: led = 7'b1110001;	// L
				4'b1010: led = 7'b1101010;	// N
				4'b1011: led = 7'b1100010;	// O
				4'b1100: led = 7'b0011000;	// P
				4'b1101: led = 7'b1111010;	// R
				4'b1110: led = 7'b1000001;	// U
				4'b1111: led = 7'b1000100;	// Y
				default: led = 7'b1111111; // default
			endcase
	end
	assign {a, b, c, d, e, f, g} = led;
	
endmodule