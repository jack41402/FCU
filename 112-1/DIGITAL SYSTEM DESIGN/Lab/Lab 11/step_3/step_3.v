module step_3(EO, clk, reset, led);
	input EO;
	input clk;
	input reset;
	output reg[0:6] led;
	
	reg count;
	wire [0:6] converted_led; // Intermediate wire to store the converted LED value
	
	convert convert_inst (.number(count),.led(converted_led));
	
	initial begin
		case (EO)
			1'b0:	count = 0;	// initialize to 0
			1'b1:	count = 1;	// initialize to 1
			default: count = -1;
		endcase
		$display("count: %d", count);
	end
	
	always @(posedge clk, negedge reset) begin
		if (!reset) begin
			case (EO)
				1'b0:	count = 0;	// reset to 0
				1'b1:	count = 1;	// reset to 1
			endcase
		end
		else begin
			count = count + 2;
			count = count % 10;
		end
		$display("count: %d", count);
	end
	
	always @* begin
        led = converted_led;
    end
endmodule

module convert(number, led);
	input number;
	output reg[0:6] led;
	
	always @(number, led) begin
		case (number)
			0: led = 7'b0000001;	// 0
			1: led = 7'b1001111;	// 1
			2: led = 7'b0010010;	// 2
			3: led = 7'b0000110;	// 3
			4: led = 7'b1001100;	// 4
			5: led = 7'b0100100;	// 5
			6: led = 7'b0100000;	// 6
			7: led = 7'b0001101;	// 7
			8: led = 7'b0000000;	// 8
			9: led = 7'b0000100;	// 9
			default: led = 7'b1111111; 	// default
		endcase
	end
endmodule