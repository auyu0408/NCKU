int trig = A0;
int echo = A1;
int ini_time =300;
long current_time =0;
float duty,distance;

void setup(){
 Serial.begin(115200);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 }

void loop(){

  digitalWrite(trig,HIGH);
  delayMicroseconds(ini_time);
  digitalWrite(trig,LOW);
  duty = pulseIn(echo,HIGH);
  distance = (duty/2)/29.4; 
  delay(ini_time);
  Serial.print("data:");
  current_time = millis();
  Serial.print("NO. ");
  Serial.print (current_time/1000);
  Serial.print(", d = ");
  Serial.print(distance);
  Serial.println(" cm");
}

