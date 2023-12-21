module step_1(clock, SW, led);
	input SW, clock;
	output reg [0:5] led=6'b011111;
	reg Q=1'b0;
	integer count=0 ;
	
	always @(posedge Q) begin
		case (SW)
			0: led <= {led[5], led[0:4]};
			1: led <= {led[1:5], led[0]};
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