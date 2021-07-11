const int isObstaclePin = 3;    
const int ledPin =  13;     // Use the onboard Uno LED
volatile int isObstacle = HIGH;      // HIGH MEANS NO OBSTACLE

void obstacleDetected(){  
  isObstacle = LOW;
} 
void setup() {
 
  pinMode(ledPin, OUTPUT);
  pinMode(isObstaclePin, INPUT); 
  digitalWrite(ledPin, LOW); 
  Serial.begin(9600);
  attachInterrupt (digitalPinToInterrupt (isObstaclePin), obstacleDetected, FALLING);  // attach interrupt handler
}
 
void loop() {
  if (isObstacle == LOW) {
     while (digitalRead(isObstaclePin)==LOW){ //To see is the obatacles are still there?
      digitalWrite(ledPin, HIGH);
      Serial.print(" OBSTACLE!!, OBSTACLE!!");  Serial.print("\n");
      }    
     isObstacle =HIGH;
  } 
  else {
    digitalWrite(ledPin, LOW);   
    Serial.print(" Clear, Advancing");
  }
  Serial.print("\n");
}
// IR Obstacle Collision Detection Module
// T. I. WANG


