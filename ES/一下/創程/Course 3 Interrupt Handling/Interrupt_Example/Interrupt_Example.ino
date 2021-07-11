const byte LaserPin = A5;
const byte BUTTON = 2;
// Interrupt Service Routine (ISR)

void switchPressed ()
{
  if (digitalRead (BUTTON) == HIGH)
    digitalWrite (LaserPin, LOW);
  else
    digitalWrite (LaserPin,  HIGH);
}  // end of switchPressed

void setup ()
{
  pinMode (LaserPin, OUTPUT);  // so we can update the LED
  digitalWrite (LaserPin, LOW);
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);  // attach interrupt handler
}  // end of setup

void loop ()
{
  // loop doing nothing 
} 

