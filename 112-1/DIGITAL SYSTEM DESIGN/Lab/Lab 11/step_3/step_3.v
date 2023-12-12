module step_3(EO, clk, reset, led);
	input EO, clk;
	input reg reset;
	output reg[0:6] led;
	
	reg [3:0] count;
	
	initial begin
		case (EO)
			1'b0:	count = 0;	// initialize to 0
			1'b1:	count = 1;	// initialize to 1
		endcase
	end
	
	always @(posedge clk or negedge reset) begin
		if (!reset) begin
			case (EO)
				1'b0:	count = 0;	// reset to 0
				1'b1:	count = 1;	// reset to 1
			endcase
		end
		else begin
			count <= (count + 2) % 10;
		end
	end
	
	always @* begin
		led = converted_led(count);
   end
	
	always @(EO) begin
		reset = 1;
		reset = 0;
	end
	
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
endmodule