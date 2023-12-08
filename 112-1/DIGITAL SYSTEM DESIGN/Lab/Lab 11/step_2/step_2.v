module step_2(dir, clk, reset, led);
	input dir;
	input clk;
	input reset;
	output reg[3:0] led=4'b1000;
	
	initial begin
		led = 4'b1000;
	end
	
	always @(posedge clk, negedge reset) begin
		if (!reset) begin
			led <= 4'b1000; // Reset the shift register
		end
		else begin
			case (dir)
				1'b0:	led <= {led[0], led[3:1]}; // Shift right
				1'b1:	led <= {led[2:0], led[3]}; // Shift left
			endcase
		end
	end
endmodule