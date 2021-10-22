module LU(clk, rst_n, in_valid, in_data, out_valid, invertible, decomposable, out_l, out_u);

input clk;
input rst_n;
input in_valid;
input in_data;

output reg out_valid;
output reg invertible;
output reg decomposable;
output reg signed[2:0] out_l;
output reg signed[2:0] out_u;

//***********************************			  
// parameter	  
//***********************************	  
parameter IDLE       =  3'd0;
parameter INPUT      =  3'd1;
parameter CHECK_INV	 =  3'd2;
parameter SWAP       =  3'd3;
parameter CAL        =  3'd4;
parameter EMPTY      =  3'd5;
parameter OUTPUT_1   =  3'd6;
parameter OUTPUT_2   =  3'd7;
		

//****************************************
//State Machine	  
//****************************************
reg [2:0]cstate;
reg [2:0]nstate;
reg [8:0]counter;

//****************************************
//Reg Daclaration		  
//****************************************		  			  
reg       A [8:0];
reg signed[2:0] L [8:0];
reg signed[2:0] U [8:0];

wire[3:0]det;
assign det = A[0]*(A[4]*A[8]-A[5]*A[7])+(A[1]*(A[5]*A[6]-A[3]*A[8]))+(A[2]*(A[3]*A[7]-A[4]*A[6]));	
//************************************
//		  FSM_sample code
//************************************
// Current State
always@(posedge clk or negedge rst_n)
begin
	if(!rst_n) 
		cstate <= IDLE;
	else
		cstate <= nstate;
end

//Next State
always@(*)
begin
	//if(!rst_n) 
		//nstate = IDLE;
	//else
		//begin
			case(cstate)
			IDLE:
				nstate = (in_valid)? INPUT:IDLE; 
				
			INPUT:
				nstate = (counter == 8) ? CHECK_INV:INPUT;	  
				
			CHECK_INV:
				begin
					if(det != 0) 
						nstate = SWAP;
					else if(det == 0) 
						nstate = OUTPUT_1;
					else 
						nstate = CHECK_INV;
				end 
			
			SWAP:
				nstate =  (A[0] == 0) ? SWAP:CAL;
				
			CAL:
				nstate =  EMPTY;
			
			OUTPUT_1:
				nstate =  IDLE;
			
			EMPTY:
				nstate = OUTPUT_2;	
			OUTPUT_2:
				nstate =  (counter !=8 ) ? OUTPUT_2:IDLE;
			
			default nstate = IDLE;		 
			endcase
end

// Output Reg 
always @(posedge clk or negedge rst_n) 
begin
	if (!rst_n)
	begin
		out_valid <= 1'd0;
		invertible <= 1'd0;
		decomposable <= 1'd0;
		out_l <= 3'd0;
		out_u <= 3'd0;
	end	
	else if (cstate == CHECK_INV && det ==0)
	begin
		out_valid <= 1'd1;
		invertible <= 1'd0;
		decomposable <= 1'd0;
		out_l <= 3'd0;
		out_u <= 3'd0;
	end
	else if(cstate == EMPTY)
	begin
		out_valid <= 1'd1;
		invertible <= 1'd1;
		decomposable <= 1'd1;
		out_l <= L[0];
		out_u <= U[0];
	end
	else if(cstate == OUTPUT_1)
	begin
		out_valid <= 1'd0;
		invertible <= 1'd0;
		decomposable <= 1'd0;
		out_l <= 3'd0;
		out_u <= 3'd0;	
	end
	else if(cstate == OUTPUT_2)
	begin
		if (counter == 4'd8) begin
			out_valid <= 1'd0;
			invertible <= 1'd0;
			decomposable <= 1'd0;
			out_l <= 3'd0;
			out_u <= 3'd0;
		end
		else begin
			out_valid <= 1'd1;
			invertible <= 1'd1;
			decomposable <= 1'd1;
			out_l <= L[counter+1];
			out_u <= U[counter+1];			
		end

	end	
	else
	begin
		out_valid <= 1'd0;
		invertible <= 1'd0;
		decomposable <= 1'd0;
		out_l <= 3'd0;
		out_u <= 3'd0;
	end
end

//************************************
//		  counter
//************************************
always@(posedge clk or negedge rst_n)
begin
	if(!rst_n)
	counter<=0;
	else if(counter == 4'd8)
	counter<=0;
	else if(cstate==INPUT)
	counter<=counter+1;
	else if(cstate==OUTPUT_2)
	counter<=counter+1;
	else 
	counter<=0;	
end

//************************************
//		  A
//************************************
always@(posedge clk)
begin
	if(cstate == IDLE)
	A[0] <= in_data; 
	else if(cstate == INPUT)
	A[counter+1] <= in_data;

	else if(cstate == SWAP)
		begin
			if(A[0] == 0 && A[3] != 0)
			begin 
				A[0] <= A[3];
				A[1] <= A[4];
				A[2] <= A[5];

				A[3] <= A[0];
				A[4] <= A[1];
				A[5] <= A[2];
			end
			else if(A[0] == 0 && A[6] !=0) 
			begin 
				A[0] <= A[6];
				A[1] <= A[7];
				A[2] <= A[8];
				
				A[6] <= A[0];
				A[7] <= A[1];
				A[8] <= A[2];
			end
		end

end 	

always@(posedge clk)
begin
	if(cstate == CAL)
	begin
			L[0] <= 1;
			L[4] <= 1;
			L[8] <= 1;

			L[1] <= 0;
			L[2] <= 0;
			L[5] <= 0;	

			L[3] <= A[3];
			L[6] <= A[6];
			L[7] <= (A[7]-A[6]*A[1])/(A[4]-A[3]*A[1]);
	end
	
end

always@(posedge clk)
begin
	if(cstate == CAL)
	begin
			U[0] <= 1;
			U[3] <= 0;
			U[6] <= 0;
			U[7] <= 0;

			U[1] <= A[1];
			U[4] <= A[4]-A[3]*A[1];
			U[2] <= A[2];
			U[5] <= A[5]-A[3]*A[2];
			
			U[8] <= A[8]-A[6]*A[2]-((A[7]-A[6]*A[1])/(A[4]-A[3]*A[1]))*(A[5]-A[3]*A[2]);
	end
end
endmodule
