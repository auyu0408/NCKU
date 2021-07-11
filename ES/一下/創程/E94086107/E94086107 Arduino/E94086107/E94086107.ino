//*******************************************************************************
//    Arduino 小車 Multi-Sensors Control 
//   
//    開發環境：Arduino IDE 1.6.5 以上
//    測試使用開發板型號：Arduino UNO R3 / Arduino Genuino
//*******************************************************************************
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>
//#include <Servo.h>

// L298N 馬達驅動板
// 宣告 MotorA 為右邊
// 宣告 MotorB 為左邊

#define MotorA_I1     8  //宣告 I1 接腳
#define MotorA_I2     9  //宣告 I2 接腳
#define MotorB_I3    10  //宣告 I3 接腳
#define MotorB_I4    11  //宣告 I4 接腳
#define MotorA_PWMA    5  //宣告 ENA (PWM調速) 接腳
#define MotorB_PWMB    6  //宣告 ENB (PWM調速) 接腳

// IRremote 紅外線
#define IR_Recv      3   // 宣告紅外線接收接腳
IRrecv irrecv(IR_Recv);  // 宣告 IRrecv 物件來接收紅外線訊號　
decode_results results;  // 宣告解碼變數

// 抓取套件中紅外線遙控器所對應的 IR Code 請勿直接使用本範例中抓到的 IR Code
// 請務必先使用範例資料夾中 IRremote_Test 的範例碼燒入 Arduino 開發板後，使用套件內的紅外線遙控器實際去按下您所
// 要宣告的各按鈕，並透過序列埠監控視窗 Serial Monitor 所顯示對應的數值，實際抓出對應的 IR Code　再宣告下列指令參數

#define IR_Forwards    0x00FF629D  // 遙控器方向鍵 上, 前進
#define IR_Back        0x00FFA857  // 遙控器方向鍵 下, 後退
#define IR_Stop        0x00FF02FD  // 遙控器 OK 鍵, 停止
#define IR_Left        0x00FF22DD  // 遙控器方向鍵 左, 左轉
#define IR_Right       0x00FFC23D  // 遙控器方向鍵 右, 右轉

#define IR_Tracking    0x00FF42BD  // 遙控器 * 鍵, 循跡模式
#define IR_Ultrasonic  0x00FF52AD  // 遙控器 # 鍵, 超音波避障模式
#define Ring1          0x00FF6897  // 遙控器1, 小星星
#define Ring2          0x00FF9867  //遙控器2,小蜜蜂
#define Ring3          0x00FFB04F  //要控器3,兩隻老虎
#define Ring4          0x00FFB04E

// 循線模組
#define SensorLeft    A0  //宣告 左側感測器 輸入腳
#define SensorMiddle  A1  //宣告 中間感測器 輸入腳
#define SensorRight   A2  //宣告 右側感測器 輸入腳
int off_track = 0;        //宣告變數

//sonar HC-SR04 超音波測距模組 HC-SR04 
//sonar pins and datas
int US_Trig = A3;  //宣告超音波模組 Trig 腳位
int US_Echo = A4;  //宣告超音波模組 Echo 腳位
unsigned long sonar_previous_time = 0;
unsigned long sonar_current_time, sonar_pass_time;
float sonar_duty, sonar_distance = 0;

//Laser Module
int lasertrig = A5;
unsigned long laser_on_time = 0;
unsigned long laser_last_time;
bool laserOn= false;

//IR Obstacle pins
const int isObstaclePin = 2;            //紅外線模組 isObstaclePin(OUT) 腳位 連接至腳位2 will use interrupt
volatile bool isObstacle = false;      // HIGH MEANS NO OBSTACLE
const int ledPin = 13;     

void pinFalled()  //ISR for IR Obstacle Module
{
 isObstacle = true;
}  // end of ISR

//Buzzer
const int buzzerPin = 4;

float sonar(unsigned long delayTime){ 
  sonar_current_time = micros();
  sonar_pass_time = sonar_current_time - sonar_previous_time;
  digitalWrite(US_Trig, HIGH);
  if(sonar_pass_time >=delayTime*1000) {
    digitalWrite(US_Trig, LOW);
    sonar_previous_time = micros();
    sonar_duty = pulseIn(US_Echo,HIGH);
    sonar_distance = (sonar_duty/2)/29.4;
    }
  return sonar_distance;
}
void ringTone(int pin) {
  for (int i=0; i<2; i++) { //repeat 10 times
    tone(pin, 2000);
    delay(50);
    tone(pin, 1500);
    delay(50);
    }
  noTone(pin);
  } 

  char notes[] = "ccggaag ffeeddc ";
    unsigned long beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int length = sizeof(notes); 
    int w= 500;
    
void ringTone2(int pin) {
  
     for (int i = 0; i < length; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes[i] == ' ') {
      delay(beats[i] * w); // rest
    } else {

  // 呼叫 palySound() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playSound(buzzerPin,notes[i], beats[i] * w);
    } 

    // 每個音符之間的間隔，這邊設定的長短會有連音或斷音的效果
    delay(w/10); 
  }
    } 

    char notes1[] = "gee fdd cdefggg gee fdd cegge ";
    unsigned long beats1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int length1 = sizeof(notes1); 

void ringTone3(int pin){

  for (int i = 0; i < length1; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes1[i] == ' ') {
      delay(beats1[i] * w); // rest
    } else {

  // 呼叫 palySound() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playSound(buzzerPin,notes1[i], beats1[i] * w);
    } 

    // 每個音符之間的間隔，這邊設定的長短會有連音或斷音的效果
    delay(w/10); 
  }
     
}

char notes2[] = "cdeccdec efg efg fgfedc fgfedc eGceGc ";
    unsigned long beats2[] = {2,2,2,2,2,2,2,2,1,2,2,2,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
    int length2 = sizeof(notes2); 
    int w2=250;

void ringTone4(int pin){

  for (int i = 0; i < length2; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes2[i] == ' ') {
      delay(beats2[i] * w2); // rest
    } else {

  // 呼叫 palySound() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playSound(buzzerPin,notes2[i], beats2[i] * w2);
    } 

    // 每個音符之間的間隔，這邊設定的長短會有連音或斷音的效果
    delay(w2/10); 
  }
     
}

char notes3[] = "dddgaag eeddc dddgaag eeddc ";
    unsigned long beats3[] = {1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1};
    int length3 = sizeof(notes1); 

void ringTone5(int pin){

  for (int i = 0; i < length1; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes3[i] == ' ') {
      delay(beats3[i] * w); // rest
    } else {

  // 呼叫 palySound() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playSound(buzzerPin,notes3[i], beats3[i] * w);
    } 

    // 每個音符之間的間隔，這邊設定的長短會有連音或斷音的效果
    delay(w/10); 
  }
     
}


void playSound(int OutputPin, char note, unsigned long duration) {
   // 音符字元與對應的頻率由兩個矩陣表示
  char names[] = { 'G', 'c', 'd', 'e', 'f', 'g', 'a', 'b'};
  int tones[] = { 392,523,587, 659, 698, 784, 880, 988 };

  // 播放音符對應的頻率
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin,tones[i], duration);
  //下方的 delay() 及 noTone ()，因為Buzzer在播放音樂是有時間長度所以如果不停止等待會重覆播放
      delay(duration);
      noTone(OutputPin);
    }
  }
}

void laserfired(unsigned long delayTime) {
  if (!laserOn){
      digitalWrite(lasertrig, HIGH);
      digitalWrite(ledPin, HIGH);
      laser_on_time= micros();
      laserOn=true; 
   }    
  laser_last_time = micros()-laser_on_time;
  if(laser_last_time >= delayTime*1000)
   {
    digitalWrite(lasertrig, LOW);
    digitalWrite(ledPin, LOW);
    laserOn=false;
   } 
}

void advance(int a)    // 小車前進
{
    digitalWrite(MotorA_I1,HIGH);   //馬達（右）順時針轉動
    digitalWrite(MotorA_I2,LOW);
    digitalWrite(MotorB_I3,LOW);    //馬達（左）順時針轉動
    digitalWrite(MotorB_I4,HIGH);
    delay(a * 100);
}

void turnR(int d)    // 小車右轉
{
 
    digitalWrite(MotorA_I1,LOW);    //馬達（右）逆時針轉動
    digitalWrite(MotorA_I2,HIGH);
    digitalWrite(MotorB_I3,LOW);    //馬達（左）順時針轉動
    digitalWrite(MotorB_I4,HIGH);
    delay(10);
}

void turnL(int e)    // 小車左轉
{
    digitalWrite(MotorA_I1,HIGH); //馬達（右）順時針轉動
    digitalWrite(MotorA_I2,LOW);
    digitalWrite(MotorB_I3,HIGH);   //馬達（左）逆時針轉動
    delay(10);
}    

void stopRL(int f)  // 小車停止
{
    digitalWrite(MotorA_I1,HIGH);   //馬達（右）停止轉動
    digitalWrite(MotorA_I2,HIGH);
    digitalWrite(MotorB_I3,HIGH);   //馬達（左）停止轉動
    digitalWrite(MotorB_I4,HIGH);
    delay(f * 100);
}

void back(int g)    // 小車後退
{
    digitalWrite(MotorA_I1,LOW);    //馬達（右）逆時針轉動
    digitalWrite(MotorA_I2,HIGH);
    digitalWrite(MotorB_I3,HIGH);   //馬達（左）逆時針轉動
    digitalWrite(MotorB_I4,LOW);
    delay(g * 100);     
}
    

void setup()
{
  Serial.begin(9600); 
  
  pinMode(MotorA_I1,OUTPUT);
  pinMode(MotorA_I2,OUTPUT);
  pinMode(MotorB_I3,OUTPUT);
  pinMode(MotorB_I4,OUTPUT);
  pinMode(MotorA_PWMA,OUTPUT);
  pinMode(MotorB_PWMB,OUTPUT);
  
  pinMode(isObstaclePin, INPUT); //Receive IR Obstacle interrupt Signal
  pinMode(lasertrig, OUTPUT);
  digitalWrite (lasertrig, LOW);

  pinMode(US_Trig, OUTPUT);
  pinMode(US_Echo, INPUT);
 
  pinMode(SensorLeft,   INPUT); 
  pinMode(SensorMiddle, INPUT);
  pinMode(SensorRight,  INPUT);
  
//  myservo.attach(Servo_Pin);
  
  irrecv.enableIRIn();  // 啟動 IR Controller Receiver 解碼讀取
  
  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
  attachInterrupt (digitalPinToInterrupt (isObstaclePin), pinFalled, FALLING);  // attach interrupt handler
}


void loop()
{
   
    if(irrecv.decode(&results)) 
    {
        // 解碼成功，收到一組紅外線訊號
        Serial.print("\r\nIR Code: ");            
        Serial.print(results.value, HEX); 
        switch(results.value)
        {
          case IR_Forwards:
            Serial.print(" Forwards");
            advance(1);
            break;
            
          case IR_Back:
            Serial.print(" Back");
            back(1);
            break;
            
          case IR_Stop:
            Serial.print(" Stop");
            stopRL(1);
            break;
            
          case IR_Left:
            Serial.print(" Left");
            turnL(1);
            break;
            
          case IR_Right:
            Serial.print(" Right");
            turnR(1);
            break;

          case Ring1:
          {
          irrecv.resume();
          Serial.print("Star");
          advance(1);
          ringTone2(buzzerPin);
           if(irrecv.decode(&results)) //See if IR remote controller sent any command?
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Tracking Mode");
                  stopRL(1);
                  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                  break;
                }
              }
          break;
          }

          case Ring2:
          {
            irrecv.resume();
          Serial.print("Bee");
          advance(1);
          ringTone3(buzzerPin);
          if(irrecv.decode(&results)) //See if IR remote controller sent any command?
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Tracking Mode");
                  stopRL(1);
                  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                  break;
                }
              }
          break;
          }

          case Ring3:
           {
            irrecv.resume();
          Serial.print("Tiger");
          ringTone4(buzzerPin);
          if(irrecv.decode(&results)) //See if IR remote controller sent any command?
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Tracking Mode");
                  stopRL(1);
                  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                  break;
                }
              }
          break;
           }

           case Ring4:
          {
          irrecv.resume();
          Serial.print("Star");
          turnL(1);
          ringTone5(buzzerPin);
           if(irrecv.decode(&results)) //See if IR remote controller sent any command?
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Tracking Mode");
                  stopRL(1);
                  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                  break;
                }
              }
          break;
          }
            
          case IR_Tracking: //Enter Line Tracking mode
            Serial.print(" Tracking Mode");
            
            irrecv.resume();
            
            while(true)
            {
              // 讀取感測器狀態
              int SL = digitalRead(SensorLeft);
              int SM = digitalRead(SensorMiddle);
              int SR = digitalRead(SensorRight);
              
              if((SM == LOW) && (SL == LOW) && (SR == LOW))  // 小車脫離黑線
              {
                analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                
                // 小車有時會因為循線感測器誤判或黑線轉角太大, 認為脫離黑線了而停車
                // 加上尋回黑線機制, 避免小車誤動作
                // 您可以修改程式讓 循線/尋線 機制更完美
				
                if(off_track < 3)
                {
                  switch(off_track)
                  {
                    case 0:
                      back(1);
                      break;
                    
                    case 1:
                      turnR(1);
                      break;
                      
                    case 2:
                      turnL(2);
                      break;
                  }
                  
                  off_track++;
                }
                else
                {
                  stopRL(0);
                }
              }
              else
              {
                off_track = 0;
                               
                if(SM == HIGH)  //中感測器在黑色區域
                {
                  if((SL == LOW) && (SR == HIGH))  // 左白右黑, 車體偏右校正
                  {
                    analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                    analogWrite(MotorB_PWMB, 80);    //設定馬達 (左) 轉速
                    advance(0);
                  } 
                  else if((SL == HIGH) && (SR == LOW))  // 左黑右白, 車體偏左校正
                  {
                    analogWrite(MotorA_PWMA, 80);    //設定馬達 (右) 轉速
                    analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                    advance(0);
                  }
                  else  // 其他, 直走
                  {
                    analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                    analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                    advance(0);
                  }
                } 
                else // 中感測器在白色區域, 車體已大幅偏離黑線
                {
                  if((SL == LOW) && (SR == HIGH))  // 左白右黑, 車體快速右轉
                  {
                    analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                    analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                    turnR(0);
                  }
                  else if((SL == HIGH) && (SR == LOW))  // 左黑右白, 車體快速左轉
                  {
                    analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                    analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                    turnL(0);
                  }
                }
              }
              
              if(irrecv.decode(&results)) //See if IR remote controller sent any command?
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Tracking Mode");
                  stopRL(1);
                  analogWrite(MotorA_PWMA,200);    //設定馬達 (右) 轉速
                  analogWrite(MotorB_PWMB,200);    //設定馬達 (左) 轉速
                  break;
                }
              }
            }
            break;
            
          case IR_Ultrasonic:
            Serial.print("Begin Ultrasonic detector");
            
            irrecv.resume();
            
            while (true){
            if(sonar(2) < 15.0 || isObstacle)  // 超音波感測器偵測後得到的距離低於10.0公分或IR有訊號
              {
              stopRL(0); // Stop for a while  
              while (sonar(2) < 15.0 || digitalRead(isObstaclePin)==LOW){   //To see is the obatacles are still there?
                  laserfired(500);
                  ringTone(buzzerPin); 
                  }    
              if (digitalRead(isObstaclePin)!=LOW) isObstacle =false;
              }
            else
              {
                if(laserOn)
                laserfired(500);
                advance(0);                // 正常前進 
              }
               
              if(irrecv.decode(&results))
              {
                irrecv.resume();
                
                if(results.value == IR_Stop)
                {
                  Serial.print("\r\nStop Ultrasonic detector");
                  stopRL(1);
                  break;
                }
              }
            }
            break;
            
          default:
          Serial.print(" Unsupported");
        }
    
        irrecv.resume(); // Receive the next value
    }
 }
