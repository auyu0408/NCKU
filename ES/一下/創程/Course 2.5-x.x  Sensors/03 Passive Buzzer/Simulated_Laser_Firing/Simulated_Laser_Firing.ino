int lasertrig = A2;
unsigned long laser_on_time = 0;
unsigned long laser_last_time;
bool laserOn= false;

//Buzzer
const int buzzerPin = 4;

void ringTone(int pin) {
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
void laserfired(unsigned long delayTime) {
  if (!laserOn){
      digitalWrite(lasertrig, HIGH);
      laser_on_time= micros();
      laserOn=true; 
   }    
  laser_last_time = micros()-laser_on_time;
  if(laser_last_time >=delayTime*1000)
   {
    digitalWrite(lasertrig, LOW);
    laserOn=false;
   } 
}
void setup(){
//laser setup
  pinMode(lasertrig, OUTPUT);
}

void loop(){
 //trigger laser
    laserfired(1000);
    ringTone(buzzerPin); 
}
