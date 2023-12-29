module step_1(enable, control, set, clock, led);
	input enable, control, set, clock;
	output reg[5:0] led=6'b111111;
	reg [5:0] password=6'b111111;
	reg Q=1'b0;
	reg last_control=1'b0;
	integer count=0;
	
	always @(posedge Q, negedge set) begin
		if (!set) password <= 6'b100000;
		else if (enable) password <= {password[0]^password[2], password[5:1]};
	end
	
	always @(control) begin
		if (control) led <= password;
		else led <= 6'b000000;
	end
	
	always @(posedge clock) begin
		if (count==24999999) begin
			Q <= !Q;
			count <= 0;
		end
		else count <= count + 1;
	end
endmodule