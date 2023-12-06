module step_1(clk, reset, led);
	input clk;
	input reset;
	output reg[7:0] led=8'b10000000;
	
	initial begin
		led = 8'b10000000;
	end
	
	always @(posedge clk, negedge reset) begin
		if (!reset) begin
			led <= 8'b10000000; // Reset the shift register
		end
		else begin
			led <= {led[0], led[7:1]}; // Shift right
		end
	end
endmodule