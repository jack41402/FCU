module step_1(clock, reset, BCD, HEX1, HEX0);
	input clock, reset;
	input [3:0] BCD;
	output reg[0:6] HEX1, HEX0;
	
	reg [7:0] sum=0, temp_sum=0;
	
	function [0:6] converted_led;
		input [3:0] number;
		
		begin
			case (number)
				0: converted_led = 7'b0000001;	// 0
				1: converted_led = 7'b1001111;	// 1
				2: converted_led = 7'b0010010;	// 2
				3: converted_led = 7'b0000110;	// 3
				4: converted_led = 7'b1001100;	// 4
				5: converted_led = 7'b0100100;	// 5
				6: converted_led = 7'b0100000;	// 6
				7: converted_led = 7'b0001101;	// 7
				8: converted_led = 7'b0000000;	// 8
				9: converted_led = 7'b0000100;	// 9
				default: converted_led = 7'b1111111; 	// default
			endcase
		end
	endfunction
	
	always @(posedge clock or negedge reset) begin
		if (!reset) sum <= 8'b00000000;
		else begin
			temp_sum = (sum[3:0]+BCD>9) ? sum + BCD + 6 : sum + BCD;
			if (temp_sum[7:4]>9) temp_sum = temp_sum + 8'b01100000;
			sum <= temp_sum;
		end
	end
	
	always @* begin
		HEX1 = converted_led(sum[7:4]);
		HEX0 = converted_led(sum[3:0]);
	end
	
endmodule
