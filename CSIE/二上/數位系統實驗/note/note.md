reg:  
assign out=ina+inb; 等價於 and(out,ina,inb); 指定的對象要是wire形式  
and &;or |;xor ^;  
input與output身份可宣告在module();內  
有分成wire和reg訊號input必須是wire,output都可以  
wire表示用線拉起來,reg表示用暫存器儲存起來  
reg[7:0]A 宣告名字為A的8 bit暫存器  
reg[7:0]A[7:0]宣告8個名字為A的8 bit暫存器（使用方法和陣列很像）  
always 和assign很像,但是指定的對象是reg,用途比wire多  
counter<=0;把0存到counter內 
assign時reg可以assign給wire(直接宣告一個reg和wire同名)，但是不能什麼都不做直接把輸入值連成輸出值 
# 全加器  
寫法：  
(1) 直接寫a+b,out為2 bit
(2) 寫sum跟carry的邏輯組成  
(3) 把裡面每個組合產生的sum carry寫出來  
ex正確  
```Verilog
input ...;
output out,...;
reg tmp;
tmp=1;
assign out=tmp;
```
錯誤
```Verilog HDL
input ...;
output out,...;
out<=1;
out=1;
```
# always block  
(1)裡面變數要是reg  
(2)同一個變數只能出現在同一個always block  
ex.錯誤   
```Verilog HDL
always@(posedge clk) begin
	if(reset) counter<=0;
end
always@(posedge clk)begin;
	if(c1==1) counter<=counter+1;
end
```
這樣當兩者成立時,counter會不知道要做累加還是歸零  
即使合併也不行（意思不對的問題）  
但是如果是if else就可以  
```Verilog HDL
always@(posedge clk) begin  
	if(reset) counter<=0;  
	if(c1==1) counter<=counter+1;  
end   
```
always的觸發事件：always@(posdge clk)||always@(a or b)  
前者是當時脈產生上升緣時,（循序電路）後者則是當a或b有一個改變時（組合電路）  
ex.
```Verilog HDL
always@(posdege clk) begin  
c<=a+b;//改變要在下一個clock到來時  
end  
always(a or b) begin  
d=a+b;//近乎立即改變  
end  
```
而上面的always@(a or b)等同於always@(＊)是指只要運算式內有任何改變就會改變  
若是always@(a),即使b改變output也不會改變  
# if else  
ex
```Verilog
always@(posedge clk)begin
	if(reset)begin
		...
	end
	else if(statement 1)begin
		...
	end
	else if(statement 2)begin
		...
	end
	.  
	.  
	.  
	else begin
		...
	end
end
```
每個if statement後面都要接begin，結束也都要end(直觀的敘述)  
但是這樣代表多個二選一多功器,選項為statement的true與false,false的後面在連接下一個多功器,如此一來路線會變很長  
解決方法：if之後case或直接case   
ex
```Verilog
always@(posedge clk)begin
	if(reset)begin
		...
	end
	else begin
		case(狀態選擇)
	   	選擇一:
			敘述一
		選擇二：
			敘述二
		選擇三：
			敘述三
		.
		.
		.
		default:
			敘述x
		endcase
	end
end
```
```Verilog
 always @(*)
  begin
    case ({r_VAL_1, r_VAL_2, r_VAL_3})
      3'b000  : r_RESULT <= 0;
      3'b001  : r_RESULT <= 1;
      3'b010  : r_RESULT <= 2;
      default : r_RESULT <= 9;
    endcase
  end
```
相當於多選一多功器,,路線會很短，所以能寫一起盡量寫一起  
# for loop
in Verilog code,for loop meaning:  
1.
```Verilog
reg [8:0]M;
always@(posedge)begin
	if(reset)
		for(idx=0;idx<9)begin
			M[idx]<=0;
	end
end
```
equals to  
2.
```Verilog
reg[8:0]M;
always@(posedge)begin
	if(reset)begin
		M[0]<=0;
		M[1]<=0;
		M[2]<=0;
		M[3]<=0;
		M[4]<=0;
		M[5]<=0;
		M[6]<=0;
		M[7]<=0;
		M[8]<=0;
	end
end
always@
```
他會把for loop裡面的東東展開然後同時執行同一個block內的所有動作  
一般來說，C是長這樣  
```C
int M[9];
for(int i=0 i<9;i++)
	M[i]=0;
```
他是一次做一個動作,一個做完才做下一個,Verilog是一次做全部,所以如果想做累加的動作需要一個counter（計數器）  
in C, we want 累加1~10
```C
int tmp=0;
for(int idx=1;idx<=10;idx++)
	tmp+=idx;
```
在Verilog內錯誤的寫法  
```Verilog
reg tmp;
always@(posedge clk) begin
	for(int idx=1;idx<=10;i++) begin
		tmp<=tmp+idx;
	end
end
//他等同於
always@(posedge clk) begin
	tmp<=tmp+1;
	tmp<=tmp+2;
	tmp<=tmp+3;
	tmp<=tmp+4;
	tmp<=tmp+5;
	tmp<=tmp+6;
	tmp<=tmp+7;
	tmp<=tmp+8;
	tmp<=tmp+9;
	tmp<=tmp+10;
end
```
正確表達:  
```Verilog
reg tmp,counter;
always@(posedge clk) begin
	if(reset)
		counter=0;
	end
	else
		counter<=(counter==10)?counter:counter+1;
	end
end
alwats@(posedge clk) begin
	if(reset)
		tmp<=0;
	end
	else
		tmp<=tmp+counter;
	end
```
拆成兩部份動作做  
# 表示式 
```Verilog
wire[31:0]tmp;  
assign temp=32'd1000;  
```
宣告一個32bit、型態為wire的變數,指定一個32bit且為十進制值為100給temp  
所以32'd100，32=32 bit,d=decimal,100=value,而這樣是"一個變數(雖然裡面值可以分開操作)"  
意義等同於
```Verilog
assign temp=32'h64;
assign temp=32'b0000_0000_0000_0000_0000_0000_0110_0100;//0可省略
assign temp=32'h000000064';//0可省略，6個0是因為1個16進位=4個二進位,做代替
```
給值可以指定位置  
```Verilog
assign temp[3:0]=4'd7;//第0~3bit的值變成7
assign temp[7:4]=4'b1010;//第7654bit為1010
```
可以寫成
```Verilog
assign temp={4'b1010,4'd7};
assign temp={8'b10100111};
```
# 運算子  
|運算子			|意義							|  
|:-----			|:-----							|  
|+,-,\*,/,%		|加,減,乘,除,餘數				|
|>,>=,<=,<,==,!=|大(等)於,小(等)於,等於,不等於	|
|<<,>>			|邏輯左移,邏輯右移				|
|<<<,>>>		|算術左移,算術右移				|
|&,|,^,~		|and,or,xor,not					|
|&&,||			|邏輯and 邏輯or					|
&:邏輯閘的and和or  
&&:C語言內的條件判斷，某種程度上可被&代替(簡單運算式時)  
<<:以二進位的方式左移，最高為丟失，最低為補0  
<<<:依次左移一位，尾部補0，"符號保持不變" 
# Testbench  
用意：驗證電路正確性,負責產生input的訊號,給module定把output的值拿出來驗證正確性,也可稱為simu，執行方式和一般Verilog不像，比較像C，是由上往下執行  
在testbench，是負責把值給input並讀output的值，但並不是本身有input和output的，所以module sumu後的括號不用宣告input和output  
但還是要宣告你要連接的訊號線，input的話用reg方式，output用wire方式（可以接出來看）  
之後要放的是要模你的module（類似include的概念），打上module的名稱與名字，並在括號內把原本的input,output和reg,wire連上  
```Verilog
adder uut(
.clk(clk),
.reset(reset),
.a(a),
.b(b),
.c(c));
```
其中，左邊的變數是要模擬的module(這裡指adder)本身的input,output，括弧內則是testbench宣告的reg或wire  
之後，可以在initial block內放入自己想要的數據  
ex.  
clk=0;此時clk為0（通常clk只有一開始要這麼做）  
#10;代表過了10個單位時間  
中間就是偶爾會有reset=1或0以及給其他input的值（給的值是十進位）  
在initial block end後會有always #5 clk=~clk;表示每過5個單位時間clk就變成!clk  
之後模擬出來的結果在職的顯示值會以16進位表示（例如在c那欄寫0b，即表示c=11)  
由於執行方式比較像C，所以在for迴圈若是表現for(idx=0;idx<10;idx=idx+1)，執行方式就像C，一個迴圈一個迴圈執行  
範例說明  
```Verilog
//若是out_valid!=1，等下一個正源再偵測一次，在此之間啥都不做  
while(out_valid!=1)begin
@(posedge clk)
//out_vaild也可以換成有include的module內的變數
//下面test是module ALU的名字  
ALU test(
	...
	...
	);
	...
	...
	while(test.count>1)begin
	@(posedge clk)
//重複括號內行為n次
repeat(10)@(posedge clk);
//跟C的列印同功能，在vivado若是按run behavior，他的輸出會輸出在控制台(TCL console)上  
$display("result %d\n",result);
//同結束testbench，因為你後面可能接著你的task，所以會以finish判定    
$finish;
```
#task  
一個規模大的電路可能要用不同組測資模擬，為了方便閱讀，可以使用task，把要測試的pattern一塊塊包起來，然後在initial block內事實的呼叫他
兩個以上task的話不用在task宣告後面加begin  
形式  
```Verilog
task case1;
	...
	...(your statement)
	...
endtask;
task case2;
	...
	...(your statement)
	...
endtask;
```
訊號型態：  
高電位，低電位（1,0;綠色）  
未知（X;紅色）:可能是一開始沒有給初值或reset，如果把x做了一些運算，運算後也還是x  
高阻抗（Z;藍色）：像是訊號線沒有接好造成開路  
在寫時要注意邊界（會不會overflow)和特殊值（除0），像8-bit ALU要加減乘除都測試過，最好還要0~255不斷測試，常用方法時不斷random去測試 

# 電路簡介
1.循序電路：輸出除了和當前輸入有關，也和前一時刻輸入有關，用always block，會做出比較複雜的東西  
會使用flip-flop儲存前一時刻資料，然後把output傳給自己或下一層作為下一個input（可能是Combinational 1->output 1->Combinational 2->output 2->Combinational 1)  
必須有：clock、flip-flop  
```Verilog
always@(posedge clk)begin
	c<=a+b;
end
```
2.組合電路：輸出只和當前輸入有關，不受clock影響，不論用always block或assign都可以  
```Verilog
always@(*)begin
	c=a+b;
	x=c-y;
end
assign c=a+b;
assign x=c-y;
```
# 給值的方式
1.blocking：blocking內要照順序，"="，假設你的給值有相依關係，例如a=b,c=a,d=c，給值得時候依照程式打的先後順序執行  
```Verilog
always@(*)begin
	A1=IN;
	A2=A1;
	A3=A2;
end
always@(*)begin
	1.A1=IN+1;
	2.A2=A1+2;
	3.A3=A2+3;
end
```
觸發操作時機：IN改變時;執行順序：1->2->3，改變順序IN->A1->A2->A3（第二種，假設IN=7,A1=8,A2=10,A3=13)，但模擬時是預設邏輯閘之間沒有delay time，所以會一起改變  
但若是加上clock，值顯示的時間會變得不一樣  
```Verilog
always@(posedge clk)begin
	A1=IN;
	A2=A1;
	A3=A2;
end
//會是IN在他想改變時先改變，到下個clock其他值才改變  
```
2.nonblocking：不是blocking，不用照順序，"<="，給值的方法在執行上是同時的，而不是等前面執行完才執行下一行，依照rising edge時那瞬間的值  
```Verilog
always@(posedge clk)begin
	1.A1<=IN;
	2.A2<=A1;
	3.A3<=A2;
end
```
觸發時機，rising edge，執行順序：1=2=3  
IN:7->8->9  
A1:X->7->8->9  
A2:X->X->7->8->9(A1變成7的瞬間前還是X，所以A2偵測到的是X)  
A3:X->X->X->7->8->9  
同一個always block裡面只能選一種給值方式  
# 有限狀態機(Finite State Machine)
又稱FSM，在複雜電路時，若要控制每個always block，可以設定很多flag，當哪個flag成立時就做指定的block，會降低可讀性且不易debug，所以多用FSM來控制電路行為，在哪一個狀態該做什麼事情，其他狀態則保持不變  
模型  
```Verilog
always@(posedge clk)begin
	if(reset)
		FSM_STATE<=IDLE;
	Else
		FSM_STATE<=FSM_STATE_NEXT;
end

always@(*)begin
	case(FSM_STATE)
		IDLE:
			if(in_valid) FSM_STATE_NEXT=CALCULATE;
			else FSM_STATE_NEXT=IDLE;
		CALCULATE:
			if(done) FSM_STATE_NEXT=COMPLETE;
			else FSM_STATE_NEXT=CALULATE;
		COMPLETE:
			FSM_STATE_NEXT=IDLE;
		default:FSM_STATE_NEXT=IDLE;
	endcase
end
```
（很像x,y,z的current stage和next stage）  
這個電路得出使會在－IDLE，如果有in_valid，狀態會跑到CALCULATE，沒有就會一直停在IDLE，運算完後會跳到COMPLETE輸出，輸出完就回到IDLE繼續  
其中，IDLE,CALCULATE,COMPLETE等名字會換成更貼切的狀態名稱，且可以不只有三個狀態  
FSM之後便是將設定done,用FSM_STATE作為判斷，將各個運算變數在不同狀態下進行不同改變，可以一個變數一個always block，這樣比較清楚  
# coding style
程式開發人員所編寫原始碼的書寫風格，良好代碼風格的特點是使代碼易讀  
常見要素：名字使用,表達式與語句,常數使用（不要讓常數看起來像魔術數字）,註釋,縮排風格（宗教戰爭）,代碼的佈局  
(1) 變數名稱：在Verilog code內，尤其FSM的名稱要取好，才容易辨別  
(2) 給值的方式：同一個always block內只能有blocking"="或nonblocking"<="一種，同一個變數只能在同一個always block出現  
(3) 給初始值：一般習慣在宣告變數時給初始值，但在電路當中，我們會在適合的時機（像是轉變為某個state，或是reset）時給初始值，比較少在一開始，但是testberanch實記得給，不然有的東西無法整理  
(4) 動作別寫在同一個always block：為了增加可讀性,方便debug，一個always block寫一種變數，或是在相同情況判斷是都要改時，就寫同一個block;而且如果將所有變數擠在一起很容易產生latch而不自知  
(5) 適時下註解
(6) 適當括弧，增加表達力，而且括弧有時可以優化電路(ex.a<=b+c+d+e/a<=(b+c)+(d+e)，後面的可以比較快完成加法，前面是一層一層)  
(7) 使用FSM，根據不同應用去驅動各個FSM  
(8) nonblocking->循序邏輯;blocking->組合邏輯（並不一定，參考）  
(9) 乘法和除法可以用其他方式代替，像乘2的冪次方可以用移位代替：a<=b * 4 -> a<=b<<2  取餘數可以由a<=b%16 -> a<=b[3:0]  
# 儲存裝置(用於循序電路)  
(1) Flip-flop  
有D flip-flop,JK flip-flop,T flip-flop等;都是當正源時才會觸發的FF，D是一個輸入，JK是兩個(在化簡電路時有時更精簡)  
D:含Q,Qnext,clk,Data  
|Clk|D|Q|Qnext|
|:-|:-|:-|:-|
|0|X|1|1|
|0|X|0|0|
|1|0|X|0|
|1|1|X|1|  

JK:含J,K,Q,Qnext  
JK trurh table  
|Q|Qnext|J|K|  
|:-|:-|:-|:-|  
|0|0|0|X|
|0|1|1|X|
|1|0|X|1|
|1|1|X|0|  

(2) Latch 
![Latch image](https://ithelp.ithome.com.tw/upload/images/20171230/20107543MvOkCkFjwJ.png)
Latch's truth table(S:set,R:reset)
|S|R|Q|~Q|
|:-|:-|:-|:-|
|0|0|Q|~Q|
|0|1|0|1|
|1|0|1|0|
|1|1|0|0|  
若是在Verilog code內寫了latch會造成實際跑電路時有雜訊、會有訊號錯誤的問題，而flipflop比較沒有這個問題（因為不會突然改變，而是等正源來時才有改變），所以一般情況下部喜歡產生latch  
當然，latch的成本比較低，所以有的公司會要求工程師產生latch（進階的情況）  
通常是寫組合電路時會出現latch，產生的原因：
1. if & else 
```Verilog
always@(*)begin
	if(rst)
		a=0;
	else if(c1)
		a=in1;
end
or
always@(*)begin
	if(rst)
		a=0;
end
```
條件不完全，沒有寫如果以上條件都不是時會怎樣，應該要把條件寫滿或給初始值  
```
always@(*)begin
	if(rst)
		a=0;
	else if(c1)
		a=in1;
	else a=0;//可以改成其他的像是a=a;
end
or
always@(*)begin
a=0;
	if(rst)
		a=0;
	else if(c1)
		a=in1;
end
```
2. case  
case沒寫完整、沒補default也會產生latch（和第一點差不多感覺）  
```
always@(*)begin
	case(Q)
		0:Q_NEXT=1;
		1:Q_NEXT=2;
		default:Q_NEXT=0;//如果沒寫會產生latch  
	endcase
end
```
3. 回授：通常也是在組合語言出現，自己自己值，然後沒有初始值，會產生latch把值存起來  
```
assign a=a+1;//a沒有initial
always@(*)begin
	a=a+1;
end
```
## 波形圖
-> WLF
modelsim支持的波形文件，在波形窗口觀察波形時，彷真結束時都會生成一個\*.wtf的文件，可以用modelsim直接打開，生成和顯示都只能透過modelsim，並不通用  
-> VCD
一種ASCII文件，通用的文件格式  
包含標頭訊息、信號的變化訊息，因為包含了訊號的變化訊息，相當於紀錄了整個模擬的訊息，可以再現、顯示波形，還可以通過VCD文件來估計設計的功耗  
是Verilog語言標準的一部分（有內建函數實現），所以所有Verilog模擬器都可以查看
-> fsdb
Debussy/Verdi支持的波形文件，使用廣泛且較小，某些模擬器(ncsim,modelsim)可以通過加載Verdi的PLI來直接dump fsdb(dump:傾印小型的記憶體文件)文件 
類似於VCD，但只提出了模擬過程中有用的部份（所以比較小），可以提高模擬速度，透過verilog的PLI接口實現的，例如fileDumpfile("\*.fsdb")代表生成的fsdb文件名
-> shm
.shm是一個目錄，裡面包含了dsn和trn文件，使用NC Verilog對同一testcase和相同dump波形比較，產生此文件的時間最短，但就只有Cadance公司NC Verilog和Simvision支持
-> vpd
可以用$vcdpluson產生，Synopsys公司VCS DVE支持的波形文件  
