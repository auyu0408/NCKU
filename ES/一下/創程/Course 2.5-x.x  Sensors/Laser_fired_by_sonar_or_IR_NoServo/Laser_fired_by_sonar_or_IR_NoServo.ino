//sonar

//sonar pins and datas
int sonar_trig = A0;
int sonar_echo = A1;

unsigned long sonar_previous_time = 0;
unsigned long sonar_current_time, sonar_pass_time;
float sonar_duty, sonar_distance = 0;

int lasertrig = A2;
unsigned long laser_on_time = 0;
unsigned long laser_last_time;
bool laserOn= false;

//IR pins
const int buttonPin = A3;    
const int ledPin = 2;     
int buttonState = 0;    
//Buzzer
const int buzzerPin = 4;

bool IR(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
  digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);   
  }
return (buttonState==LOW);
}

float sonar(unsigned long delayTime){ 
  sonar_current_time = micros();
  sonar_pass_time = sonar_current_time - sonar_previous_time;
  digitalWrite(sonar_trig, HIGH);
  if(sonar_pass_time >=delayTime*1000) {
    digitalWrite(sonar_trig, LOW); 
	  sonar_previous_time = micros();
    sonar_duty = pulseIn(sonar_echo,HIGH);
    sonar_distance = (sonar_duty/2)/29.4;
   }
  return sonar_distance;
}
void ringTone(int pin) {
  for (int i=0; i<2; i++) { //repeat 10 times
    tone(pin, 1000);
    delay(50);
    tone(pin, 750);
    delay(50);
    }
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
  Serial.begin(115200);
//sonar setup
  pinMode(sonar_trig, OUTPUT);
  pinMode(sonar_echo,INPUT);
//laser setup
  pinMode(lasertrig, OUTPUT);
//IR setup
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  digitalWrite(ledPin, HIGH); 
}

void loop(){
  
 //trigger laser when sonar(2) < 15 || IR()
 if(sonar(2) < 15 || IR()){
    laserfired(1000);
    ringTone(4); 
    }
 else
    if(laserOn)
         laserfired(1000);
}
