const int isObstaclePin = 2;    
const int LaserPin = A5;     // Use the Laser Gun
volatile int isObstacle = HIGH;      // HIGH MEANS NO OBSTACLE

void obstacleDetected(){  
  isObstacle = LOW;
} 
void setup() {
 
  pinMode(LaserPin, OUTPUT);
  pinMode(isObstaclePin, INPUT); 
  digitalWrite(LaserPin, LOW); 
  Serial.begin(115200);
  attachInterrupt (digitalPinToInterrupt (isObstaclePin), obstacleDetected, FALLING);  // attach interrupt handler
}
 
void loop() {
  if (isObstacle == LOW) {
     while (digitalRead(isObstaclePin)==LOW){ //To see is the obatacles are still there?
      digitalWrite(LaserPin, HIGH);
      Serial.print(" OBSTACLE!!, OBSTACLE!!");  Serial.print("\n");
      }    
     isObstacle =HIGH;
  } 
  else {
    digitalWrite(LaserPin, LOW);   
    Serial.print(" Clear, Advancing");
  }
  Serial.print("\n");
}
// IR Obstacle Collision Detection Module
// T. I. WANG


