module final(keypadRow, keypadCol, rst, clk, dot_row, dot_col, score_10,score_1, time_10, time_1);
input [3:0] keypadCol;
input rst;
input clk;
output reg [3:0] keypadRow;
output reg [7:0] dot_col;
output reg [7:0] dot_row;
output reg [6:0] time_1;
output reg [6:0] time_10;
output reg [6:0] score_1;
output reg [6:0] score_10;
integer rnd, index = 0;
reg [7:0] dot_col_key[0:7];
reg [7:0] dot_col_mole[0:7];
integer random_number[0:15];
integer score = 0;
integer time_left = 0;
reg flag=1;

initial begin
	random_number[0] = 12;
	random_number[1] = 4;
	random_number[2] = 8;
	random_number[3] = 13;
	random_number[4] = 0;
	random_number[5] = 3;
	random_number[6] = 1;
	random_number[7] = 7;
	random_number[8] = 14;
	random_number[9] = 5;
	random_number[10] = 9;
	random_number[11] = 2;
	random_number[12] = 11;
	random_number[13] = 6;
	random_number[14] = 10;
	random_number[15] = 15;
end

   reg key_clk;
   reg [31:0] key_time;
   always@(posedge clk or negedge rst) begin  
		if(~rst) begin
			key_clk =  32'b0;
			key_time = 1'b0;
		end
		else begin
			if(key_time == 32'd500000)begin                 //key_clk = 100 hz
				key_clk = ~key_clk;
				key_time = 32'b0;
			end
			else begin
				key_time = key_time + 32'b1;
			end
		end
	end
	
   reg mole_clk;
   reg [31:0] mole_time;
   always@(posedge clk or negedge rst) begin
      if(~rst) begin
         mole_clk = 0;
         mole_time = 0;
      end
      else begin
           if(mole_time == 25000000) begin               // mole_clk = 1hz
              mole_clk = ~mole_clk;
              mole_time = 0;
           end
           else
              mole_time = mole_time + 1;
      end
   end
		
		
	reg dot_clk;
   reg [31:0] dot_time;
   always@(posedge clk or negedge rst) begin
       if(~rst) begin
           dot_clk = 0;
           dot_time <= 0;
       end
       else begin
           if(dot_time == 2500) begin                  // mole_clk = 10000 hz
               dot_clk <= ~dot_clk;
               dot_time <= 0;
           end
           else
               dot_time <= dot_time + 1;
    end
end
	
	always@(posedge key_clk or negedge rst) begin      //scan keypad row
		if(~rst)begin
			keypadRow <= 4'b01111;
		end
		else begin
			case({keypadRow})
			4'b0111: keypadRow <= 4'b1011;
			4'b1011: keypadRow <= 4'b1101;
			4'b1101: keypadRow <= 4'b1110;
			4'b1110: keypadRow <= 4'b0111;
			default: keypadRow <= 4'b0111;
			endcase
		end
	end

	reg  clicked[0:15];
	reg [3:0] keypad_value;
	always@(posedge key_clk or negedge rst) begin     // detect the pressed keypad
		if(~rst) 
		   begin
		   score = 0;
		   keypad_value = 0;
	      end
	   else 
	     begin
		  case({keypadRow, keypadCol})                  // becomes 8 bit
		  8'b01110111:keypad_value <= 4'hf;                            
		  8'b01111011:keypad_value <= 4'he;
		  8'b01111101:keypad_value <= 4'hd;
		  8'b01111110:keypad_value <= 4'hc;    	
		  8'b10110111:keypad_value <= 4'hb;
		  8'b10111011:keypad_value <= 4'h3;       
		  8'b10111101:keypad_value <= 4'h6; 	
		  8'b10111110:keypad_value <= 4'h9; 
		  8'b11010111:keypad_value <= 4'ha;
		  8'b11011011:keypad_value <= 4'h2;   	
		  8'b11011101:keypad_value <= 4'h5;	
		  8'b11011110:keypad_value <= 4'h8;
		  8'b11100111:keypad_value <= 4'h0;     
		  8'b11101011:keypad_value <= 4'h1;
		  8'b11101101:keypad_value <= 4'h4;
		  8'b11101110:keypad_value <= 4'h7;
		  endcase                                     // get keypad_value
		  
		  if( keypad_value == 4'hf)                   
        begin    
		     if(rnd == 0 && clicked[0] == 0)
			  begin
                score = score + 1;
		          clicked[0] = 1;
			  end 
		  end	  
		  else
		      	 clicked[0] = 0;                    // if position is the smae  than socre++ one time
		  if( keypad_value == 4'he)
        begin    
		     if(rnd == 1 && clicked[1] == 0)
			  begin
                score = score + 1;
		          clicked[1] = 1;
			  end
		  end	  
		  else
		      	 clicked[1] = 0;  
		  if( keypad_value == 4'hd)
        begin    
		     if(rnd == 2 && clicked[2] == 0)
			  begin
                score = score + 1;
		          clicked[2] = 1;
			  end
		  end	  
		  else
		      	 clicked[2] = 0;  		 
		  if( keypad_value == 4'hc)
        begin    
		     if(rnd == 3 && clicked[3] == 0)
			  begin
                score = score + 1;
		          clicked[3] = 1;
			  end
		  end	  
		  else
		      	 clicked[3] = 0;  
		  if( keypad_value == 4'hb)
        begin    
		     if(rnd == 4 && clicked[4] == 0)
			  begin
                score = score + 1;
		          clicked[4] = 1;
			  end
		  end	  
		  else
		      	 clicked[4] = 0;  
		  if( keypad_value == 4'h3)
        begin    
		     if(rnd == 5 && clicked[5] == 0)
			  begin
                score = score + 1;
		          clicked[5] = 1;
			  end
		  end	  
		  else
		      	 clicked[5] = 0;  
			if( keypad_value == 4'h6)
        begin    
		     if(rnd == 6 && clicked[6] == 0)
			  begin
                score = score + 1;
		          clicked[6] = 1;
			  end
		  end	  
		  else
		      	 clicked[6] = 0;  		 
		  if( keypad_value == 4'h9)
        begin    
		     if(rnd == 7 && clicked[7] == 0)
			  begin
                score = score + 1;
		          clicked[7] = 1;
			  end
		  end	  
		  else
		      	 clicked[7] = 0;  
		  if( keypad_value == 4'ha)
        begin    
		     if(rnd == 8 && clicked[8] == 0)
			  begin
                score = score + 1;
		          clicked[8] = 1;
			  end
		  end	  
		  else
		      	 clicked[8] = 0;  
		  if( keypad_value == 4'h2)
        begin    
		     if(rnd == 9 && clicked[9] == 0)
			  begin
                score = score + 1;
		          clicked[9] = 1;
			  end
		  end	  
		  else
		      	 clicked[9] = 0;  
			if( keypad_value == 4'h5)
        begin    
		     if(rnd == 10 && clicked[10] == 0)
			  begin
                score = score + 1;
		          clicked[10] = 1;
			  end
		  end	  
		  else
		      	 clicked[10] = 0;  		 
		  if( keypad_value == 4'h8)
        begin    
		     if(rnd == 11 && clicked[11] == 0)
			  begin
                score = score + 1;
		          clicked[11] = 1;
			  end
		  end	  
		  else
		      	 clicked[11] = 0;  
		  if( keypad_value == 4'h0)
        begin    
		     if(rnd == 12 && clicked[12] == 0)
			  begin
                score = score + 1;
		          clicked[12] = 1;
			  end
		  end	  
		  else
		      	 clicked[12] = 0;  
		  if( keypad_value == 4'h1)
        begin    
		     if(rnd == 13 && clicked[13] == 0)
			  begin
                score = score + 1;
		          clicked[13] = 1;
			  end
		  end	  
		  else
		      	 clicked[13] = 0;  
			if( keypad_value == 4'h4)
        begin    
		     if(rnd == 14 && clicked[14] == 0)
			  begin
                score = score + 1;
		          clicked[14] = 1;
			  end
		  end	  
		  else
		      	 clicked[14] = 0;  
		  if( keypad_value == 4'h7)
        begin    
		     if(rnd == 15 && clicked[15] == 0)
			  begin
                score = score + 1;
		          clicked[15] = 1;
			  end
		  end	  
		  else
		      	 clicked[15] = 0;  			 
	   end
   end

reg [2:0] row_count;
always@(posedge dot_clk or negedge rst) begin
    if(~rst)begin
        dot_row <= 8'd0;
        dot_col <= 8'd0;
        row_count <= 3'd0;
    end
    else begin
        row_count <= row_count + 1;
		  if(flag)
             dot_col <= dot_col_mole[row_count] ;                      // display (move (dot_col_mole) to dot_col(output))
		  else
	     	    dot_col=0;
        case(row_count)
            3'd0: dot_row <= 8'b01111111;
            3'd1: dot_row <= 8'b10111111;
            3'd2: dot_row <= 8'b11011111;
            3'd3: dot_row <= 8'b11101111;
            3'd4: dot_row <= 8'b11110111;
            3'd5: dot_row <= 8'b11111011;
            3'd6: dot_row <= 8'b11111101;
            3'd7: dot_row <= 8'b11111110;
        endcase
    end
end

always@(posedge mole_clk or negedge rst) begin
    if(~rst) begin
        dot_col_mole[0] <= 8'b0;
        dot_col_mole[1] <= 8'b0;
        dot_col_mole[2] <= 8'b0;
        dot_col_mole[3] <= 8'b0;
        dot_col_mole[4] <= 8'b0;
        dot_col_mole[5] <= 8'b0;
        dot_col_mole[6] <= 8'b0;
        dot_col_mole[7] <= 8'b0;
    end
    else begin
        rnd = random_number[index];
	  	  index = (index + 1) % 16;                                    // choose one area to display  and store in dot_col_mole
        case(rnd)
            0: begin
                dot_col_mole[0] <= 8'b11000000;
                dot_col_mole[1] <= 8'b11000000;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            1: begin
                dot_col_mole[0] <= 8'b00110000;
                dot_col_mole[1] <= 8'b00110000;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            2: begin
                dot_col_mole[0] <= 8'b00001100;
                dot_col_mole[1] <= 8'b00001100;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            3: begin
                dot_col_mole[0] <= 8'b00000011;
                dot_col_mole[1] <= 8'b00000011;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            4: begin
                dot_col_mole[2] <= 8'b11000000;
                dot_col_mole[3] <= 8'b11000000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            5: begin
                dot_col_mole[2] <= 8'b00110000;
                dot_col_mole[3] <= 8'b00110000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            6: begin
                dot_col_mole[2] <= 8'b00001100;
                dot_col_mole[3] <= 8'b00001100;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            7: begin
                dot_col_mole[2] <= 8'b00000011;
                dot_col_mole[3] <= 8'b00000011;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            8: begin
                dot_col_mole[4] <= 8'b11000000;
                dot_col_mole[5] <= 8'b11000000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            9: begin
                dot_col_mole[4] <= 8'b00110000;
                dot_col_mole[5] <= 8'b00110000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            10: begin
                dot_col_mole[4] <= 8'b00001100;
                dot_col_mole[5] <= 8'b00001100;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            11: begin
                dot_col_mole[4] <= 8'b00000011;
                dot_col_mole[5] <= 8'b00000011;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[6] <= 8'b0;
                dot_col_mole[7] <= 8'b0;
            end
            12: begin
                dot_col_mole[6] <= 8'b11000000;
                dot_col_mole[7] <= 8'b11000000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
            end
            13: begin
                dot_col_mole[6] <= 8'b00110000;
                dot_col_mole[7] <= 8'b00110000;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
            end
            14: begin
                dot_col_mole[6] <= 8'b00001100;
                dot_col_mole[7] <= 8'b00001100;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
            end
            15: begin
                dot_col_mole[6] <= 8'b00000011;
                dot_col_mole[7] <= 8'b00000011;
                dot_col_mole[0] <= 8'b0;
                dot_col_mole[1] <= 8'b0;
                dot_col_mole[2] <= 8'b0;
                dot_col_mole[3] <= 8'b0;
                dot_col_mole[4] <= 8'b0;
                dot_col_mole[5] <= 8'b0;
            end
        endcase
    end
end

always@(score) begin
    score_1= dec_to_ssd(score % 10);                              // score_1  = score units digits
    score_10= dec_to_ssd(score / 10);                             // score_10 = score tens  digits
end

always@(time_left) begin
    time_1 = dec_to_ssd(time_left % 10);                          // time_1   = time_left units digits
    time_10 = dec_to_ssd(time_left / 10);                         // time_10  = time_left tens  digits
end

always@(posedge mole_clk or negedge rst)begin
  if(~rst) begin
      time_left <= 30;
		flag =1;
  end
  else begin
      if(time_left == 0)                                          // if time expire flag = 0
	       flag = 0;
	   else 
          time_left <= time_left-1;
	   end
end

function [6:0] dec_to_ssd;
	input integer dec;
	if(dec == -1)
		dec_to_ssd = 7'b1111111;
	if(dec == 1 || dec == 4 || dec == 11 || dec == 13)
		dec_to_ssd[0] = 1;
	if(dec == 5 || dec == 6 || dec == 11 || dec == 12 || dec == 14 || dec == 15)
		dec_to_ssd[1] = 1;
	if(dec == 2 || dec == 12 || dec == 14 || dec == 15)
		dec_to_ssd[2] = 1;
	if(dec == 1 || dec == 4 || dec == 7 || dec == 10 || dec == 15)
		dec_to_ssd[3] = 1;
	if(dec == 1 || dec == 3 || dec == 4 || dec == 5 || dec == 7 || dec == 9)
		dec_to_ssd[4] = 1;
	if(dec == 1 || dec == 2 || dec == 3 || dec == 7 || dec == 13)
		dec_to_ssd[5] = 1;
	if(dec == 0 || dec == 1 || dec == 7 || dec == 12)
		dec_to_ssd[6] = 1;
endfunction                                                       // seven segment display

endmodule