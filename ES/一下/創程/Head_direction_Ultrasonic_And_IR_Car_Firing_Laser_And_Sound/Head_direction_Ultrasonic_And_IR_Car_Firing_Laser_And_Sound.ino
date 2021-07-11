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

int Ask_Distance()  // 測量距離 
{
    digitalWrite(US_Trig, LOW);   // 讓超聲波發射低電壓2μs
    delayMicroseconds(2);
    digitalWrite(US_Trig, HIGH);  // 讓超聲波發射高電壓10μs，這裡至少是10μs
    delayMicroseconds(10);
    digitalWrite(US_Trig, LOW);   // 維持超聲波發射低電壓
    float distance = pulseIn(US_Echo, HIGH);  // 讀取時間差
    distance = distance / 5.8 / 10;  // 將時間轉為距離距离（單位：公分）
//    Serial.print("Distance:"); //輸出距離（單位：公分）
//    Serial.println(distance); //顯示距離
//    Serial.print('\n');
    return distance;
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
    if(Ask_Distance() < 10 || IR())  // 超音波感測器偵測後得到的距離低於 10公分或紅外線測得障礙物
    {
        stopRL(1); // Stop for a while  
        ringTone2(buzzerPin); 
        digitalWrite(LaserPIN,HIGH);      
//        Serial.print(" Obstacle in 10 CM ");
    }
    else
    {
        advance(1);                // 正常前進  
        digitalWrite(LaserPIN,LOW);    
//        Serial.print(" Advance ");  //顯示方向(前進)
//        Serial.print("   ");  
    }
 }
