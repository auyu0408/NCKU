  
/*
 * This is the Arduino code 4 channel Infrared Obstacle Sendors  for smart car.
* watch YouTube video: https://youtu.be/6Qs4iFYm_lg
 * 
 *Written by Ahmad Nejrabi for Robojax.com
 *on Jan 15, 2018 at 21:04 in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.

 */
/*
4 Channel Infrared Obstacle Avoidance kit
Written by Ahmad Nejrabi for Robojax.com
on Jan 15, 2018 at 21:04 in Ajax, Ontario, Canada

What it does?
this module has 4 IR (infrared) sensors that sense obastacle and based on the position of
obstacle, you can program your arduino to take action. If you are using it for smart car, you 
change the direction of car, apply break or stop it.
 */
  // 4 Infrared Obstacle code for Robojax.com
#define FRONT_LEFT A1 // pin A1 for front-left sensor
#define FRONT_RIGHT A2 // pin A2 for front-right sensor
#define REAR_LEFT  A3 // pin A3 for rear-left sensor
#define REAR_RIGHT A4 // pin A4 for rear-right sensor
#define BREAK 13 // pin 8 to apply break or turn LED ON
#define FRONT_OB 9 // pin 9 when obstacle is at front
#define REAR_OB 10 // pin 10 when obstacle is at rear

void setup() {
  Serial.begin(9600);
  pinMode(FRONT_LEFT, INPUT);//define front-left input pin
  pinMode(FRONT_RIGHT, INPUT);//define front-right input pin
  // 4 Infrared Obstacle code for Robojax.com
  pinMode(REAR_LEFT, INPUT);//define rear-left input pin
  pinMode(REAR_RIGHT, INPUT);//define rear-right input pin 
  pinMode(BREAK, OUTPUT);// define pin for break
  pinMode(FRONT_OB,OUTPUT);// define front obstacle detection  pin
  pinMode(REAR_OB,OUTPUT);// define rear obstacle detection  pin
}

void loop() {
    // 4 Infrared Obstacle code for Robojax.com
  int FR = digitalRead(FRONT_RIGHT);// read FRONT_LEFT sensor
  int FL = digitalRead(FRONT_LEFT);// read FRONT_RIGHT sensor
  int RR = digitalRead(REAR_RIGHT);// read REAR_RIGHT sensor
  int RL = digitalRead(REAR_LEFT);// read REAR_LEFT sensor   

  if( FR == LOW || FL == LOW)
  {
    digitalWrite(FRONT_OB,HIGH);
    Serial.println("Front obstacle");
  }else{
    digitalWrite(FRONT_OB,LOW); 
    
  }


  if( RR == LOW || RL == LOW )
  {
    digitalWrite(REAR_OB,HIGH);
    Serial.println("Rear obstacle");
  }else{
    digitalWrite(REAR_OB,LOW); 
   
  } 

  delay(200);
}

 
