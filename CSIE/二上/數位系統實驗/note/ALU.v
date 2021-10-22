module ALU(
input [31:0]a,
input [31:0]b,
input B_invert,
input mode,
input clk,
output reg [31:0]res,
);

reg [31:0]tmp;

always@(clk)
begin
	case(mode)
		0:begin
			tmp = a&b;
		end
		1:begin
			tmp = a|b;
		end
		2:begin
			if(B_invert==0)
				tmp = a+b;
			else
				tmp = a+(!b)+1;
		end
		3:begin
			tmp = a+(!b)+1;
		end
	endcase
end

always@(tmp)
begin
	case(mode)
		3:begin
			if (tmp[31]==0)
				res = 0;
			else
				res = 1;
		end
		default res = tmp;
	endcase
end

endmodule
