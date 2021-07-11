const int isObstaclePin = 3;    
const int ledPin =  13;     // Use the onboard Uno LED
int isObstacle = HIGH;      // HIGH MEANS NO OBSTACLE
 
void setup() {
 
  pinMode(ledPin, OUTPUT);
  pinMode(isObstaclePin, INPUT); 
  digitalWrite(ledPin, LOW); 
  Serial.begin(115200);
}
 
void loop() {
 
  isObstacle = digitalRead(isObstaclePin);
  Serial.print("Read ");
  Serial.print(isObstacle);
  if (isObstacle == LOW) {
     digitalWrite(ledPin, HIGH);
     Serial.print(" OBSTACLE!!, OBSTACLE!!");
  } 
  else {
    digitalWrite(ledPin, LOW);   
    Serial.print(" Clear!!");
  }
  Serial.print("\n");
  delay(200);
}

// IR Obstacle Collision Detection Module



