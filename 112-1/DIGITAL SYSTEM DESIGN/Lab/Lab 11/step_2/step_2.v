module step_2(dir, clk, reset, led);
	input dir;
	input clk;
	input reset;
	output reg[3:0] led=4'b0000;
	
	reg [3:0] count=0;
	
	initial begin
		led = 4'b0000;
	end
	
	always @(posedge clk, negedge reset) begin
		if (!reset) begin
			count = 0;
		end
		else begin
			case (dir)
				1'b0: count = count - 1;
				1'b1: count = count + 1;
			endcase
		end
		led <= count;
	end
endmodule