module step_2(clock, SW, led3, led2, led1, led0);
	input SW, clock;
	output reg [0:6] led3, led2, led1, led0;
	reg Q=1'b0;
	reg last_SW=0;
	integer count=0;
	parameter led_d=7'b1000010, led_E=7'b0110000, led_0=7'b0000001, led_NULL=7'b1111111;
	
	initial begin
		case (SW)
			0: begin led3 <= led_NULL; led2 <= led_d; led1 <= led_E; led0 <= led_0; end
			1: begin led3 <= led_d; led2 <= led_E; led1 <= led_0; led0 <= led_NULL; end
		endcase
	end
	
	always @(posedge Q) begin
		if (last_SW!=SW) begin
			case (SW)
				0: begin led3 <= led_NULL; led2 <= led_d; led1 <= led_E; led0 <= led_0; end
				1: begin led3 <= led_d; led2 <= led_E; led1 <= led_0; led0 <= led_NULL; end
			endcase
			last_SW <= SW;
		end
		else
			case (SW)
				0: begin led3 <= led2; led2 <= led1; led1 <= led0; led0 <= led3; end
				1: begin led3 <= led0; led2 <= led3; led1 <= led2; led0 <= led1; end
			endcase
	end
	
	always @(posedge clock) begin
		if (count==24999999) begin
			Q <= !Q;
			count <= 0;
		end
		else count <= count + 1;
	end
endmodule