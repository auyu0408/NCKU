#include <avr/interrupt.h>

const int irPin = 2;    
const int ledPin = 13;     
volatile byte irState = HIGH;    
 
ISR (INT0_vect)
{
 Serial.println("Interrupted!");
 irState = LOW;    // Toggle LED on pin 13
}  // end of interrupt routine INT0__vect


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); 
  pinMode(irPin, INPUT); 
  Serial.begin(115200);
//  pinMode(irPin, INPUT_PULLUP);
  EICRA |= (1 << ISC01);    // Trigger on falling edge, ISC01 defined in iom328p.h
  EIMSK |= (1 << INT0);     // Enable external interrupt INT0, constsnt INT0 defined in iom328p.h
  sei();
}
 
void loop() {
  if (irState == LOW) {
     while ( digitalRead(irPin) == LOW){ //To see is the obatacles are still there?
      digitalWrite(ledPin, HIGH);
      Serial.print(" OBSTACLE!!, OBSTACLE!!");  Serial.print("\n");
      }    
     irState =HIGH;
  } 
  else {
    digitalWrite(ledPin, LOW);   
    Serial.print(" Clear, Advancing");
  }
  Serial.print("\n");
}

