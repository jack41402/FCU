module step_2(enable, control, clock, reset, data, relock, status, led, HEX3, clock_50M);
	input enable, control, clock, reset, data, relock;
	input clock_50M;
	output reg[1:0] status=2'b00;
	output reg[5:0] led=6'b111111;
	output reg[0:6] HEX3=7'b000000;
	
	reg Q=1'b0;
	reg [5:0] password=6'b111111;
	reg [2:0] state=0;
	integer count=0;
	
	always @(posedge clock or negedge reset) begin
		if (!reset) state = 0;
		else if (relock && state==6) state = 0; 
		else begin
			case (state)
				0:	state = (data==password[5]) ? 1 : 7;
				1:	state = (data==password[4]) ? 2 : 7;
				2:	state = (data==password[3]) ? 3 : 7;
				3:	state = (data==password[2]) ? 4 : 7;
				4:	state = (data==password[1]) ? 5 : 7;
				5:	state = (data==password[0]) ? 6 : 7;
			endcase
		end
	end
	
	always @(state) begin
		case (state)
			6: status = 2'b10;
			7: status = 2'b01;
			default: status = 2'b00;
		endcase
		case (state)
			0: HEX3 = 7'b0000001;	// 0
			1: HEX3 = 7'b1001111;	// 1
			2: HEX3 = 7'b0010010;	// 2
			3: HEX3 = 7'b0000110;	// 3
			4: HEX3 = 7'b1001100;	// 4
			5: HEX3 = 7'b0100100;	// 5
			6: HEX3 = 7'b0100000;	// 6
			7: HEX3 = 7'b0001101;	// 7
			default: HEX3 = 7'b1111111; 	// default
		endcase
	end
	
	always @(posedge Q or negedge reset) begin
		if (!reset) password <= 6'b100000;
		else if (enable) password <= {password[0]^password[2], password[5:1]};
	end
	
	always @(control) begin
		if (control) led <= password;
		else led <= 6'b000000;
	end
	
	always @(posedge clock_50M) begin
		if (count==24999999) begin
			Q <= !Q;
			count <= 0;
		end
		else count <= count + 1;
	end
endmodule