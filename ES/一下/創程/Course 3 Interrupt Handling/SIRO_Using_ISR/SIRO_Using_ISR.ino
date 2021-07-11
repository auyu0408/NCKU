#include <avr/interrupt.h>

const int irPin = 2;    
const int LaserPin = A5;      
volatile byte irState = HIGH;    
 
ISR (INT0_vect)
{
 Serial.println("Interrupted!");
 irState = LOW;    // Toggle LED on pin 13
}  // end of interrupt routine INT0__vect


void setup() {
  pinMode(LaserPin, OUTPUT);
  digitalWrite(LaserPin, LOW); 
  pinMode(irPin, INPUT); 
  Serial.begin(115200);
  EICRA |= (1 << ISC01);    // Trigger on falling edge, ISC01 defined in iom328p.h
  EIMSK |= (1 << INT0);     // Enable external interrupt INT0, constsnt INT0 defined in iom328p.h
  sei();
}
 
void loop() {
  if (irState == LOW) {
     while ( digitalRead(irPin) == LOW){ //To see is the obatacles are still there?
      digitalWrite(LaserPin, HIGH);
      Serial.print(" OBSTACLE!!, OBSTACLE!!");  Serial.print("\n");
      }    
     irState =HIGH;
  } 
  else {
    digitalWrite(LaserPin, LOW);   
    Serial.print(" Clear, Advancing");
  }
  Serial.print("\n");
}

