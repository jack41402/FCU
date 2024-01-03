module step_3(clock, set, control, led);
	input clock, set, control;
	output reg[3:0] led;
	
	reg [3:0] password=4'b1000;
	
	always @(posedge clock or negedge set) begin
		if (!set) password <= 4'b1000;
		else password <= {password[1]^password[0], password[3:1]};
	end
	
	always @(control) begin
		if (control) led <= password;
		else led <= 4'b0000;
	end

endmodule