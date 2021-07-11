const byte LaserPin = A5;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(LaserPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(LaserPin, state);
}
// Interrupt Service Routine (ISR)
void blink() {
  state = !state;
}
