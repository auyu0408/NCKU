//*******************************************************************************
//    超音波避障實驗2 
//*******************************************************************************
// L298N 馬達驅動板
// 宣告 MotorA 為右邊
// 宣告 MotorB 為左邊

#define MotorA_I1     8  //定義 I1 接腳
#define MotorA_I2     9  //定義 I2 接腳
#define MotorB_I3    10  //定義 I3 接腳
#define MotorB_I4    11  //定義 I4 接腳
#define MotorA_PWMA    5  //定義 ENA (PWM調速) 接腳
#define MotorB_PWMB    6  //定義 ENB (PWM調速) 接腳
#define LaserPIN      A5
// HC-SR04 超音波測距模組
#define US_Trig  A0  //定義超音波模組 Trig 腳位
#define US_Echo  A1  //定義超音波模組 Echo 腳位

unsigned long sonar_previous_time = 0;
unsigned long sonar_current_time, sonar_pass_time;
float sonar_duty, sonar_distance = 0;

unsigned long laser_on_time = 0;
unsigned long laser_last_time;
bool laserOn= false;

//IR pins
const int buttonPin = A3;     
int buttonState = 0;   

//Buzzer
const int buzzerPin = 3;

bool IR(){
  buttonState = digitalRead(buttonPin);
return (buttonState==LOW);
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
  pinMode(LaserPIN,OUTPUT);     
  
  pinMode(US_Trig, OUTPUT);
  pinMode(US_Echo, INPUT);


}

void advance(int a)    // 小車前進
{
  analogWrite(MotorA_PWMA,100);    //設定馬達 (右) 轉速
  analogWrite(MotorB_PWMB,100);    //設定馬達 (左) 轉速
  digitalWrite(MotorA_I1,LOW);   //馬達（右）順時針轉動
  digitalWrite(MotorA_I2,HIGH);
  digitalWrite(MotorB_I3,LOW);   //馬達（左）逆時針轉動
  digitalWrite(MotorB_I4,HIGH);
//  delay(a * 100);
}

void stopRL(int s)  //小車停止
{
    digitalWrite(MotorA_I1,LOW);   //馬達（右）停止轉動
    digitalWrite(MotorA_I2,LOW);
    digitalWrite(MotorB_I3,LOW);   //馬達（左）停止轉動
    digitalWrite(MotorB_I4,LOW);
//    delay(s * 100);
}

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

void laserfired(unsigned long delayTime) {
  if (!laserOn){
      digitalWrite(LaserPIN, HIGH);
      laser_on_time= micros();
      laserOn=true; 
   }    
  laser_last_time = micros()-laser_on_time;
  if(laser_last_time >= delayTime*1000)
   {
    digitalWrite(LaserPIN, LOW);
    laserOn=false;
   } 
}
void ringTone2(int pin) {
    tone(pin, 4000);    delay(10);
    tone(pin, 3500);    delay(9);
    tone(pin, 3000);    delay(8);
    tone(pin, 3500);    delay(7);
    tone(pin, 3000);    delay(6);
    tone(pin, 2500);    delay(5);
    tone(pin, 2000);    delay(4);
    tone(pin, 1500);    delay(30);
    noTone(pin);
} 
void loop()
 {
    if(sonar(2) < 15 || IR())  // 超音波感測器偵測後得到的距離低於 10公分或紅外線測得障礙物
    {
        stopRL(1); // Stop for a while  
        laserfired(500);        
        ringTone2(buzzerPin);      
//        Serial.print(" Obstacle in 10 CM ");
    }
    else
    {
         advance(1);                // 正常前進      
         if(laserOn)
             laserfired(1000);
//        Serial.print(" Advance ");  //顯示方向(前進)
//        Serial.print("   ");  
    }
 }
