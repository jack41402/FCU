module step2(I0, I1, I2, I3, I4, I5, I6, I7, a, b, c ,d, e, f, g);
	input I0, I1, I2, I3, I4, I5, I6, I7;
	output a, b, c, d, e, f, g;
	reg [6:0] led;
	
	always @(I0, I1, I2, I3, I4, I5, I6, I7) begin
		if (I0==0)
			led = 7'b1000001;						// U
		else
			casez({I7, I6, I5, I4, I3, I2, I1})
				7'b0000001: led = 7'b1001111;	// 1
				7'b000001?: led = 7'b0010010;	// 2
				7'b00001??: led = 7'b0000110;	// 3
				7'b0001???: led = 7'b1001100;	// 4
				7'b001????: led = 7'b0100100;	// 5
				7'b01?????: led = 7'b0100000;	// 6
				7'b1??????: led = 7'b0001101;	// 7
				default: led = 7'b0001000;		// A
			endcase
	end
	assign {a, b, c, d, e, f, g} = led ;
endmodule