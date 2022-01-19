# 數位系統導論實驗

- bluster location: `C:\intelFPGA_lite\16.1\quartus\drivers`
- 專案名稱不要中文和數字開頭
## 10/28 Lab

#### Full Adder

* data flow
```verilog=
module FA(x,y,c_in,sum,c_out);

    input x,y,c_in;

    output sum,c_out;

    /* modify the code here*/
    wire sum_1,cout_1,cout_2;
    
    assign sum_1 = x^y;
    assign cout_1 = x&y;
    assign sum = sum_1^c_in;
    assign cout_2 = sum_1 & c_in;
    assign c_out = cout_1 | cout_2;

endmodule
```
* behavior
```verilog=
module FA(x,y,c_in,sum,c_out);

    input x,y,c_in;

    output reg sum,c_out;
    

    /* modify the code here*/
    always@(*)
    begin
        {c_out, sum} = x + y + c_in;
    end

endmodule
```
* structure
```verilog=
module FA(x,y,c_in,sum,c_out);

    input x,y,c_in;

    output sum,c_out;
    wire s, c1, c2;

    /* modify the code here*/
    HA half_adder1(x,y,s,c1);
    HA half_adder2(s,c_in,sum,c2);
    or(c_out , c1, c2);

endmodule
```

## 11/4

### Lab1
* adder subtrater

```verilog=
    always@(*)begin
    if (select == 1) begin 
        {overflow,out} = a+b;
        end
    else begin
        {overflow,out} = a-b;
    end
    
    end
```
### Lab2
* 忘記叫啥懶得看簡報
```verilog=
module encoder(in, valid, out);

input [3:0] in;
output reg valid;
output reg [1:0]out;

always@(*)begin
if(in == 4'b0001)begin
valid = 1;
out = 2'b00;
end
else if(in == 4'b0010)begin
valid = 1;
out = 2'b01;
end
else if(in == 4'b0100)begin
valid = 1;
out = 2'b10;
end
else if(in == 4'b1000)begin
valid = 1;
out = 2'b11;
end
else begin
valid = 0;
out = 2'b00;
end
end

endmodule
```
## 11/6
### arithmetic shift right
```verilog=
module shifter(in, out);


    input       [3:0]   in;

    output  reg    [3:0]   out;


    /* modify the code here*/
    always@(*)begin
        out = in>>1;
        out[3] = in[3];
    end


endmodule
```
### 3 to 8 decoder
```verilog=
module decoder(in, enable, out);


    input       [2:0]   in;

    input               enable;


    output reg  [7:0]   out;


    /* modify the code here*/    
    always@(*)begin
        out[7:0] = 0;
        case(enable)
            1'b0:   out = 0;
            1'b1:begin
                case(in)
                    3'b000: out[0] = 1;
                    3'b001: out[1] = 1;
                    3'b010: out[2] = 1;
                    3'b011: out[3] = 1;
                    3'b100: out[4] = 1;
                    3'b101: out[5] = 1;
                    3'b110: out[6] = 1;
                    3'b111: out[7] = 1;
                    default: out = 0;
                endcase
            end
            default: out = 0;
        endcase
    end

endmodule
```
## 11/10
### 學號顯示器
- 他題序跟去年相反然後我就寫掉一半了，抱歉
> 你寫好快 by bowling
```verilog=
module lab(out1, out2, out3);

	output reg [6:0]out1;
	output reg [6:0]out2;
	output reg [6:0]out3;
    //107
	always@(*)begin
	out1=7'b1111001;
	out2=7'b1000000;
	out3=7'b1111000;
	end

endmodule
```
### 3-bit adder
```verilog=
module lab(a,b,out);

input [2:0]a;
input [2:0]b;
output reg [6:0]out;
reg [3:0]ans;

always@(*)begin
    ans = a + b;
end

always@(*)begin
    case(ans)
        4'b0000: out = 7'b1000000;
        4'b0001: out = 7'b1111001;
        4'b0010: out = 7'b0100100;
        4'b0011: out = 7'b0110000;
        4'b0100: out = 7'b0011001;
        4'b0101: out = 7'b0010010;
        4'b0110: out = 7'b0000010;
        4'b0111: out = 7'b1111000;
        4'b1000: out = 7'b0000000;
        4'b1001: out = 7'b0010000;
        4'b1010: out = 7'b0001000;
        4'b1011: out = 7'b0000011;
        4'b1100: out = 7'b1000110;
        4'b1101: out = 7'b0100001;
        4'b1110: out = 7'b0000110;
        4'b1111: out = 7'b0001110;
        default: out = 7'b1111111;
    endcase        
end

endmodule
```
## 11/13 週末練習
```verilog=
module special_multiplier(num, result);

    input   [3:0]   num;

    output reg [6:0]   result;

    reg  [3:0] ans; 

    /* modify the code here */
    always @(*) begin
        case(num)
        4'b0000: ans = num;
        4'b0001: ans = num;
        4'b0010: ans = num;
        4'b0011: ans = ( num + 1 ) * 2;
        4'b0100: ans = ( num + 1 ) * 2;
        4'b0101: ans = ( num + 1 ) * 2;
        4'b0110: ans = ( num - 1 ) * 2;
        4'b0111: ans = ( num - 1 ) * 2;
        default: ans = 0;
        endcase
    end
    always @(*) begin
        case(ans)
        4'b0000: result = 7'b1000000;
        4'b0001: result = 7'b1111001;
        4'b0010: result = 7'b0100100;
        4'b0011: result = 7'b0110000;
        4'b0100: result = 7'b0011001;
        4'b0101: result = 7'b0010010;
        4'b0110: result = 7'b0000010;
        4'b0111: result = 7'b1111000;
        4'b1000: result = 7'b0000000;
        4'b1001: result = 7'b0010000;
        4'b1010: result = 7'b0001000;
        4'b1011: result = 7'b0000011;
        4'b1100: result = 7'b1000110;
        4'b1101: result = 7'b0100001;
        4'b1110: result = 7'b0000110;
        4'b1111: result = 7'b0001110;
        default: result = 7'b1000000;
        endcase
    end

endmodule
```
## 7段顯示器 數字對應表
```verilog=
7'b1000000 //0
7'b1111001 //1
7'b0100100 //2
7'b0110000 //3
7'b0011001 //4
7'b0010010 //5
7'b0000010 //6
7'b1111000 //7
7'b0000000 //8
7'b0010000 //9
7'b0001000 //A
7'b0000011 //b
7'b1000110 //c
7'b0100001 //d
7'b0000110 //E
7'b0001110 //F
```

## 11/18 Lab6 Sequential Circuit 計數器
* Note: module 呼叫不能放在always@裡面
* <= 代表同步改變
### Frequency Divider(clock)
> sequencial circuit
```verilog=
`define TimeExpire 32'd25000000//define寫法後面不能加分號

module Frequency_div(clk,rst,div_clk);
    input clk,rst;
    output div_clk;
    
    reg div_clk;
    reg [31:0] count;
    
    always@(posedge clk)
    begin
        if(!rst)
        begin
            count <= 32'd0;
            div_clk <= 1'b0;
        end
        else
        begin
            if(count == 32'd25000000)
            begin
                count <= 32'd0;
                div_clk <= ~div_clk;
            end
            else
            begin
                count <= count + 32'd1;
            end
        end          
    end
    
endmodule
```
* Counter
> sequencial circuit
```verilog=
module Counter(div_clk,rst,count);
    input div_clk;
    input rst;
    
    output reg [3:0]count;
    
    always@(posedge div_clk or negedge rst)//posedge clk vs. clk, 一個只會感受到一瞬間的變化，一個是半個週期
    begin
        if(!rst)
        begin
            count <= 4'd0;
        end
        else if(count == 4'd15)
        begin
            count <= 4'd0;
        end
        else begin
            count <= count + 4'd1;
        end          
    end
    
endmodule
```
* Seven Display
> combinatial circuit
```verilog=
module Seven_display(count,out);
    input [3:0] count;
    
    output reg [6:0] out;
    
    always@(count)
    begin
        case(count)
            4'b0000: out = 7'b1000000;
            4'b0001: out = 7'b1111001;
            4'b0010: out = 7'b0100100;
            4'b0011: out = 7'b0110000;
            4'b0100: out = 7'b0011001;
            4'b0101: out = 7'b0010010;
            4'b0110: out = 7'b0000010;
            4'b0111: out = 7'b1111000;
            4'b1000: out = 7'b0000000;
            4'b1001: out = 7'b0010000;
            4'b1010: out = 7'b0001000;
            4'b1011: out = 7'b0000011;
            4'b1100: out = 7'b1000110;
            4'b1101: out = 7'b0100001;
            4'b1110: out = 7'b0000110;
            4'b1111: out = 7'b0001110;
            default: out = 7'b1000000;
        endcase
    end
endmodule

```

* Top Module

```verilog=
module Top_module(clk,rst,out);//要加分號
    input clk;
    input rst;
    //port 對接 module 用wire連接
    //以判斷是否有用到always@為主，有always用reg
    output wire [6:0] out;//會默認wire
    
    wire div_clk;
    wire [3:0] count;
    
    Frequency_div u_FreqDiv (.clk(clk),.rst(rst),.div_clk(div_clk));
    Counter u_counter(.div_clk(div_clk),.rst(rst),.count(count));
    Seven_display u_display(.count(count),.out(out));

endmodule

```
## 11/20週末練習
其他部份和11/18要求差不多，counter變化大
除頻器在這邊可以不用用到rst(除頻器會留著rst是因為要初始化裝置，只是FPGA有幫你初始化)，不然最好設定2個rst
如果只有一個rst，在按按鈕的時候clk和div_clk都會一直是0，這樣div_clk沒有變化，沒辦法進行下一部份的歸0
* Frequency_div
```verilog=
module Frequency_div(clk,rst,div_clk);
    input clk,rst;
    output div_clk;
    
    reg div_clk;
    reg [31:0] count;
    
    always@(posedge clk)
    begin
        if(count == 32'd25000000)
        begin
            count <= 32'd0;
            div_clk <= ~div_clk;
        end
        else
        begin
            count <= count + 32'd1;
        end          
    end
    
endmodule
```
* Counter
```verilog=
module Counter(div_clk,rst,sel,count);
    input div_clk;
    input rst, sel;
    
    output reg [3:0]count;
    
    always@(posedge div_clk)//posedge clk vs. clk, 一個只會感受到一瞬間的變化，一個是半個週期
//需要同步重置，所以只需要管posedge即可
    begin
        if(!rst)//rst=0
        begin
            count = 4'd0;
        end
        else begin//rst = 1
            case(sel)
                1'd1:begin
                    if(count == 4'd15)
                    begin
                        count = 4'd0;
                    end
                    else begin
                        count = count + 1;
                    end
                end         
                1'd0:begin
                    if(count == 4'd0)
                    begin
                         count = 4'd15;
                    end
                    else begin
                        count = count - 1;
                    end
                end
            endcase
        end
    end
    
endmodule
```
* Top module
```verilog=
module Top_module(clk,rst,out);//要加分號
    input clk;
    input rst;
    //port 對接 module 用wire連接
    //以判斷是否有用到always@為主，有always用reg
    output wire [6:0] out;//會默認wire
    
    wire div_clk;
    wire [3:0] count;
    
    Frequency_div u_FreqDiv (.clk(clk),.rst(rst),.div_clk(div_clk));
    Counter u_counter(.div_clk(div_clk),.rst(rst),.count(count),.set(set));
    Seven_display u_display(.count(count),.out(out));

endmodule
```
## 11/25 Lab7
- frequency div
```verilog=
`define TimeExpire 32'd25000000//define不要用了啦 是一秒喔喔!!!!!

module clk_div(clk,rst,div_clk);
    input clk, rst;
    output reg div_clk;

    reg [31:0]count;

    always@(posedge clk)begin
        if (!rst)begin
            count <= 32'd0;
            div_clk <= 1'd0;
        end
        else begin
            if(count == 32'd25000000)begin
                count <= 32'd0;
                div_clk <= ~div_clk;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```
- state
```verilog=
module state(div_clk, rst, In, state);
    input div_clk, In, rst;
    output reg [2:0] state;
    reg [2:0] next;

    always@(posedge div_clk or negedge rst)begin
        if(!rst)begin
            state <= 3'd0;
        end
        else begin
            state <= next;
        end
    end
    
    always@(*)begin//不需要等到posedge再換，因為可能會來不及算
        case(state)
            3'd0:begin
                if(In == 1'd0)begin
                    next = 3'd1;
                end
                else begin
                    next = 3'd3;
                end
            end
            3'd1:begin
                if(In == 1'd0)begin
                    next = 3'd2;
                end
                else begin
                    next = 3'd5;
                end
            end
            3'd2:begin
                if(In == 1'd0)begin
                    next = 3'd3;
                end
                else begin
                    next = 3'd0;
                end
            end
            3'd3:begin
                if(In == 1'd0)begin
                    next = 3'd4;
                end
                else begin
                    next = 3'd1;
                end
            end
            3'd4:begin
                if(In == 1'd0)begin
                    next = 3'd5;
                end
                else begin
                    next = 3'd2;
                end
            end
            3'd5:begin
                if(In == 1'd0)begin
                    next = 3'd0;
                end
                else begin 
                    next = 3'd4;
                end
            end
                default: next = 3'd0;
        endcase
    end
endmodule
```
- seven display
```verilog=
module seven_display(state, out);
    input [2:0] state;
    output reg [6:0] out;
    
    always@(state)begin
        case(state)
            3'd0: out <= 7'b1000000;
            3'd1: out <= 7'b1111001;
            3'd2: out <= 7'b0100100;
            3'd3: out <= 7'b0110000;
            3'd4: out <= 7'b0011001;
            3'd5: out <= 7'b0010010;
            default: out <= 7'b1000000;
        endcase
    end
endmodule
```
- Top Module

```verilog=
module lab(clk,rst,In,out);//要加分號
    input clk;
    input rst;
    input In;
    //port 對接 module 用wire連接
    //以判斷是否有用到always@為主，有always用reg
    output wire [6:0] out;//會默認wire
    
    wire div_clk;
    wire [2:0] state;
    
    clk_div u_ClkDiv (.clk(clk),.rst(rst),.div_clk(div_clk));
    state u_state(.div_clk(div_clk),.rst(rst),.In(In), .state(state));
    //變數記得宣告
    seven_display u_display(.state(state),.out(out));

endmodule

```

---
### ~期中考
---

## 12/9 Lab8 Dot matrix display controller
- Top Module
```verilog=
module lab(clk,rst,dot_row,dot_col);
    input clk,rst;
    output reg [7:0]dot_row;
    output reg [7:0]dot_col;
    wire div_clk;
    
    clk_div u_ClkDiv (.clk(clk),.rst(rst),.div_clk(div_clk));
    dot u_dot(.div_clk(div_clk),.rst(rst),.dot_row(dot_row),.dot_col(dot_col));
endmodule
```

- frequency div (T = 1/10000sec)
```verilog=
`define TimeExpire 32'd2500//define不要用了啦 是1/10000秒喔喔!!!!!

module clk_div(clk,rst,div_clk);
    input clk, rst;
    output reg div_clk;

    reg [31:0]count;

    always@(posedge clk)begin
        if (!rst)begin
            count <= 32'd0;
            div_clk <= 1'd0;
        end
        else begin
            if(count == 32'd2500)begin
                count <= 32'd0;
                div_clk <= ~div_clk;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```
- dot matrix
```verilog=
module dot(div_clk,rst,dot_row,dot_col);
    input rst,div_clk;
    output reg [7:0]dot_row;
    output reg [7:0]dot_col;
    reg [2:0] row_count;
    
    always@(posedge div_clk or negedge rst)begin
        if(~rst)begin
            dot_row <= 8'b0;
            dot_col <= 8'b0;
            row_count <= 0;
        end
        else begin
            row_count <= row_count +1;
            case(row_count)
                3'd0:dot_row <= 8'b01111111;
                3'd1:dot_row <= 8'b10111111;
                3'd2:dot_row <= 8'b11011111;
                3'd3:dot_row <= 8'b11101111;
                3'd4:dot_row <= 8'b11110111;
                3'd5:dot_row <= 8'b11111011;
                3'd6:dot_row <= 8'b11111101;
                3'd7:dot_row <= 8'b11111110;
            endcase
            case(row_count)
                3'd0:dot_col <= 8'b00011000;
                3'd1:dot_col <= 8'b00100100;
                3'd2:dot_col <= 8'b01000010;
                3'd3:dot_col <= 8'b11000011;
                3'd4:dot_col <= 8'b01000010;
                3'd5:dot_col <= 8'b01000010;
                3'd6:dot_col <= 8'b01000010;
                3'd7:dot_col <= 8'b01111110;
            endcase
        end
    end
endmodule
```
## 12/15 Lab9
- Final version
- 7display
```verilog=
module display(count, out);
    input [3:0]count;
    output reg [6:0]out;
    
    always@(count)begin
        case(count)
            4'd0: out = 7'b1000000; //0
            4'd1: out = 7'b1111001; //1
            4'd2: out = 7'b0100100; //2
            4'd3: out = 7'b0110000; //3
            4'd4: out = 7'b0011001; //4
            4'd5: out = 7'b0010010; //5
            4'd6: out = 7'b0000010; //6
            4'd7: out = 7'b1111000; //7
            4'd8: out = 7'b0000000; //8
            4'd9: out = 7'b0010000; //9
            4'd10: out = 7'b0001000; //A
            4'd11: out = 7'b0000011; //b
            4'd12: out = 7'b1000110; //c
            4'd13: out = 7'b0100001; //d
            4'd14: out = 7'b0000110; //E
            4'd15: out = 7'b0001110; //F
        endcase
    end
endmodule
```
- dot matrix
```verilog=
module dot_matrix(state,rst, matrix_f, dot_row, dot_col);
    input [2:0]state;
    input matrix_f;
	 input rst;
    output reg [7:0]dot_row;
    output reg [7:0]dot_col;
    reg [2:0] row_count;
    
    always@(posedge matrix_f or negedge rst)begin//不確定要不要加or state
			if(!rst)begin
			dot_row <= 8'b11111111;
			row_count <= 3'd0;
			end
			else begin
			
        row_count <= row_count +1;
        case(row_count)
            3'd0:dot_row <= 8'b01111111;
            3'd1:dot_row <= 8'b10111111;
            3'd2:dot_row <= 8'b11011111;
            3'd3:dot_row <= 8'b11101111;
            3'd4:dot_row <= 8'b11110111;
            3'd5:dot_row <= 8'b11111011;
            3'd6:dot_row <= 8'b11111101;
            3'd7:dot_row <= 8'b11111110;
        endcase
        case(state)
            2'd0:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00001100;
                    3'd1:dot_col <= 8'b00001100;
                    3'd2:dot_col <= 8'b00011001;
                    3'd3:dot_col <= 8'b01111110;
                    3'd4:dot_col <= 8'b10011000;
                    3'd5:dot_col <= 8'b00011000;
                    3'd6:dot_col <= 8'b00101000;
                    3'd7:dot_col <= 8'b01001000;
                endcase
            end
            2'd1:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00000000;
                    3'd1:dot_col <= 8'b00100100;
                    3'd2:dot_col <= 8'b00111100;
                    3'd3:dot_col <= 8'b10111101;
                    3'd4:dot_col <= 8'b11111111;
                    3'd5:dot_col <= 8'b00111100;
                    3'd6:dot_col <= 8'b00111100;
                    3'd7:dot_col <= 8'b00000000;
                endcase
            end
            default:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00011000;
                    3'd1:dot_col <= 8'b00011000;
                    3'd2:dot_col <= 8'b00111100;
                    3'd3:dot_col <= 8'b00111100;
                    3'd4:dot_col <= 8'b01011010;
                    3'd5:dot_col <= 8'b00011000;
                    3'd6:dot_col <= 8'b00011000;
                    3'd7:dot_col <= 8'b00100100;
                endcase
            end
        endcase
		  end
    end
endmodule
```
- state change
```verilog=
module state_change(state_f, rst, state, count);
    input state_f, rst;
    output reg [1:0]state;
    output reg [3:0]count;
    
    always@(posedge state_f or negedge rst)begin
        if(!rst)begin
            count = 4'd15;//秒數初始化為15
            state = 2'd0;//綠燈
        end
        else begin
            if(count == 4'd0)begin
                case(state)//green
                    2'd0:begin
                        state = 2'd1;
                        count = 4'd5;
                    end
                    2'd1:begin//yellow
                        state = 2'd2;
                        count = 4'd10;
                    end
                    default:begin//red
                        state = 2'd0;
                        count = 4'd15;
                    end
                endcase
            end
            else begin
                count = count - 4'd1;
                state = state;
            end
        end
    end
endmodule     
```
- cloak2
```verilog=
module clk2(clk,rst,state_f);
    input clk, rst;
    output reg state_f;

    reg [31:0]count;

    always@(posedge clk or negedge rst)begin
        if (!rst)begin
            count <= 32'd0;
            state_f <= 1'd0;
        end
        else begin
            if(count == 32'd25000000)begin
                count <= 32'd0;
                state_f <= ~state_f;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```
- clock1
```verilog=
module clk1(clk,rst,matrix_f);
    input clk, rst;
    output reg matrix_f;

    reg [31:0]count;

    always@(posedge clk)begin
        if (!rst)begin
            count <= 32'd0;
            matrix_f <= 1'd0;
        end
        else begin
            if(count == 32'd2500)begin
                count <= 32'd0;
                matrix_f <= ~matrix_f;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```
- top module
```verilog=
module lab(clk,rst,dot_row, dot_col,out);
    input clk, rst;
    output  [7:0] dot_row;
    output  [7:0] dot_col;
    output  [6:0] out;
    
    wire matrix_f, state_f;
    wire [1:0] state;
    wire [3:0] count;
    
    clk1 u_clk1(.clk(clk), .rst(rst), .matrix_f(matrix_f));
    clk2 u_clk2(.clk(clk), .rst(rst), .state_f(state_f));
    state_change u_state_change(.state_f(state_f), .rst(rst), .state(state), .count(count));
    dot_matrix u_dot_matrix(.state(state), .rst(rst),.matrix_f(matrix_f), .dot_row(dot_row), .dot_col(dot_col));
    display u_display(.count(count),.out(out));
    
endmodule

```
## lab10
- top module
```verilog=
module lab(clk,rst,keypadRow,keypadCol,dot_row, dot_col);
    input clk, rst;
    output [3:0]keypadRow;
    input [3:0]keypadCol;
    output  [7:0] dot_row;
    output  [7:0] dot_col;
  
    wire [3:0]keypadBuf;
    wire matrix_f;
    wire [3:0] count;
    
    clk1 u_clk1(.clk(clk), .rst(rst), .matrix_f(matrix_f));
    dot_matrix u_dot_matrix(.keypadBuf(keypadBuf), .rst(rst),.matrix_f(matrix_f), .dot_row(dot_row), .dot_col(dot_col));
    checkkeypad u_checkkeypad(.clk(clk),.rst(rst),.keypadRow(keypadRow),.keypadCol(keypadCol),.keypadBuf(keypadBuf));
endmodule

```
- keypad
```verilog=
module checkkeypad(clk,rst,keypadRow,keypadCol,keypadBuf);
    input clk,rst;
    input [3:0]keypadCol;
    output reg [3:0]keypadRow;
    
    output reg [3:0]keypadBuf;
    reg [31:0]keypadDelay;
    
    always@(posedge clk)
    begin
        if(!rst)
        begin
           keypadRow <= 4'b1110; 
           keypadBuf <= 4'b0000; 
           keypadDelay <= 31'd0; 
        end
        else begin
            if(keypadDelay==250000)
            begin
                keypadDelay = 31'd0;
                case({keypadRow,keypadCol})
                    8'b1110_1110:keypadBuf <= 4'h7;
                    8'b1110_1101:keypadBuf <= 4'h4;
                    8'b1110_1011:keypadBuf <= 4'h1;
                    8'b1110_0111:keypadBuf <= 4'h0;
                    8'b1101_1110:keypadBuf <= 4'h8;
                    8'b1101_1101:keypadBuf <= 4'h5;
                    8'b1101_1011:keypadBuf <= 4'h2;
                    8'b1101_0111:keypadBuf <= 4'ha;
                    8'b1011_1110:keypadBuf <= 4'h9;
                    8'b1011_1101:keypadBuf <= 4'h6;
                    8'b1011_1011:keypadBuf <= 4'h3;
                    8'b1011_0111:keypadBuf <= 4'hb;
                    8'b0111_1110:keypadBuf <= 4'hc;
                    8'b0111_1101:keypadBuf <= 4'hd;
                    8'b0111_1011:keypadBuf <= 4'he;
                    8'b0111_0111:keypadBuf <= 4'hf;
                    default: keypadBuf<=keypadBuf;
                endcase
                case(keypadRow)
                    4'b1110:keypadRow<=4'b1101;
                    4'b1101:keypadRow<=4'b1011;
                    4'b1011:keypadRow<=4'b0111;
                    4'b0111:keypadRow<=4'b1110;
                    default:keypadRow<=4'b1110;
                endcase
            end
            else
              keypadDelay <= keypadDelay + 1'b1;  
        end
    end
endmodule    
```
- clock
```verilog=
module clk1(clk,rst,matrix_f);
    input clk, rst;
    output reg matrix_f;

    reg [31:0]count;

    always@(posedge clk)begin
        if (!rst)begin
            count <= 32'd0;
            matrix_f <= 1'd0;
        end
        else begin
            if(count == 32'd2500)begin
                count <= 32'd0;
                matrix_f <= ~matrix_f;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```

- dot matrix
```verilog=
module dot_matrix(keypadBuf,rst, matrix_f, dot_row, dot_col);
    input [3:0]keypadBuf;
	 input matrix_f;
	 input rst;
    output reg [7:0]dot_row;
    output reg [7:0]dot_col;
    reg [2:0] row_count;
    
always@(posedge matrix_f or negedge rst)begin//不確定要不要加or state
	if(!rst)begin
		dot_row <= 8'b11111111;
		row_count <= 3'd0;
	end
	else begin
        row_count <= row_count +1;
        case(row_count)
            3'd0:dot_row <= 8'b01111111;
            3'd1:dot_row <= 8'b10111111;
            3'd2:dot_row <= 8'b11011111;
            3'd3:dot_row <= 8'b11101111;
            3'd4:dot_row <= 8'b11110111;
            3'd5:dot_row <= 8'b11111011;
            3'd6:dot_row <= 8'b11111101;
            3'd7:dot_row <= 8'b11111110;
        endcase
        case(keypadBuf)
            4'd0:begin
                case(row_count)
                    3'd6:dot_col <= 8'b11000000;
                    3'd7:dot_col <= 8'b11000000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd1:begin
                case(row_count)
                    3'd6:dot_col <= 8'b00110000;
                    3'd7:dot_col <= 8'b00110000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd2:begin
                case(row_count)
                    3'd4:dot_col <= 8'b00110000;
                    3'd5:dot_col <= 8'b00110000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd3:begin
                case(row_count)
                    3'd2:dot_col <= 8'b00110000;
                    3'd3:dot_col <= 8'b00110000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd4:begin
                case(row_count)
                    3'd6:dot_col <= 8'b00001100;
                    3'd7:dot_col <= 8'b00001100;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd5:begin
                case(row_count)
                    3'd4:dot_col <= 8'b00001100;
                    3'd5:dot_col <= 8'b00001100;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd6:begin
                case(row_count)
                    3'd2:dot_col <= 8'b00001100;
                    3'd3:dot_col <= 8'b00001100;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd7:begin
                case(row_count)
                    3'd6:dot_col <= 8'b00000011;
                    3'd7:dot_col <= 8'b00000011;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd8:begin
                case(row_count)
                    3'd4:dot_col <= 8'b00000011;
                    3'd5:dot_col <= 8'b00000011;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd9:begin
                case(row_count)
                    3'd2:dot_col <= 8'b00000011;
                    3'd3:dot_col <= 8'b00000011;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd10:begin
                case(row_count)
                    3'd4:dot_col <= 8'b11000000;
                    3'd5:dot_col <= 8'b11000000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd11:begin
                case(row_count)
                    3'd2:dot_col <= 8'b11000000;
                    3'd3:dot_col <= 8'b11000000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd12:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00000011;
                    3'd1:dot_col <= 8'b00000011;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd13:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00001100;
                    3'd1:dot_col <= 8'b00001100;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd14:begin
                case(row_count)
                    3'd0:dot_col <= 8'b00110000;
                    3'd1:dot_col <= 8'b00110000;
                    default: dot_col <= 8'd0;
                endcase
            end
            4'd15:begin
                case(row_count)
                    3'd0:dot_col <= 8'b11000000;
                    3'd1:dot_col <= 8'b11000000;
                    default: dot_col <= 8'd0;
                endcase
            end
        endcase
	end
end
endmodule
```

## 12/15 Lab11 :-) VGA
> HSync 訊號為 active low (0)訊號，用來告知換行  
> VSync 訊號為 active low (0)訊號，用來告知換幀

- top module
```verilog=
module lab (clk,rst,btnR,btnG,btnB,r,g,b,HSync,VSync);
begin
    input clk,rst,btnR,btnG,btnB;
    output [3:0]r,[3:0]g,[3:0]b,HSync,VSync;
    wire clk_div;
    
    clk1 u_clk1(.clk(clk), .rst(rst), .clk_div(clk_div));
    counterH u_counterH(.clk_div(clk_div), .HSync(HSync));
    counterV u_counterV(.clk_div(clk_div), .VSync(VSync));
    RGB u_RGB(.HSync(HSync),.rst(rst),.btnR(btnR),.btnG(btnG),.btnB(btnB),.r(r),.g(g),.b(b));
	
end
```

- clock(50Mhz to 25Mhz)
```verilog=
module clk(clk,rst,clk_div);
    input clk, rst;
    output reg state_f;

    reg [31:0]count;

    always@(posedge clk or negedge rst)begin
        if (!rst)begin
            count <= 32'd0;
            clk_div <= 1'd0;
        end
        else begin
            if(count == 32'd1)begin
                count <= 32'd0;
                clk_div <= ~clk_div;
            end
            else begin
                count <= count + 32'd1;
            end
        end
    end
endmodule
```
-counter for HSync
```verilog=
module counterH(clk_div,HSync);
    input [31:0]clk_div;
    output reg HSync;
    reg [9:0]count;
    
    always@(clk_div)begin
        if(count == 10'd800)begin
             count = 10'd0;
             HSync = 1'b0;
        end
        else begin
            count = count + 10'd1;
            HSync = 1'b1;
        end
    end
    
endmodule
```

-counter for VSync
```verilog=
module counterV(clk_div,VSync);
    input [31:0]clk_div;
    output reg VSync;
    reg [31:0]count;
    
    always@(clk_div)begin
        if(count == 31'd420000)begin
             count = 31'd0;
             VSync = 1'b0;
        end
        else begin
            count = count + 31'd1;
            VSync = 1'b1;
        end
    end
    
endmodule
```

- RGB
```verilog=
module RGB(HSync,rst,btnR,btnG,btnB,r,g,b);
    input rst,HSync;
    input btnR,btnG,btnB;
    output reg [3:0]r,[3:0]g,[3:0]b;
    //for state
    reg [3:0]sr,[3:0]sg,[3:0]sb;
    
    always@(*)begin
        if(!rst)begin
            sr=4'd0;
            sg=4'd0;
            sb=4'd0;
        end
        else if(!HSync)begin
            r=4'd0;
            g=4'd0;
            b=4'd0;
            sr = sr;
            sg = sg;
            sb = sb;
        end
        else begin
            if (!btnR)begin 
                sr = sr + 4'd1;
                r = sr;
            end 
            else if (!btnG)begin 
                sg = sg + 4'd1;
                g = sg;
            end 
            else if(!btnB)begin 
                sb <= sb + 4'd1;
                b = sb;
            end
            else begin 
                sr = sr;
                sg = sg;
                sb = sb;
                r = r;
                g = g;
                b = b;
            end
        end
    end 
    
    
endmodule
```

```verilog=
module RGB(HSync,rst,btnR,btnG,btnB,r,g,b);
    input rst,HSync;
    input btnR,btnG,btnB;
    output reg [3:0]r;
	 output reg[3:0]g;
	 output reg[3:0]b;
    //for state
    reg state; 
    
    always@(*)begin
        if(!rst)begin
        end
        else begin
            if(!HSync)begin
            state = 
        end
        end
    end
    
endmodule
```