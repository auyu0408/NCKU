#include "application.h"

SYSTEM_MODE(AUTOMATIC);

//Settings
int led1 = D0;
int led2 = D7;
int photoresistor = A0;
int power = A5;
int analogvalue;

void setup() {
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(photoresistor,INPUT);
    pinMode(power,OUTPUT);
    digitalWrite(power,HIGH);
    attachInterrupt(photoresistor, IncrementPulseCount, RISING);
}

void loop() {
    analogvalue = analogRead(photoresistor);
    if(analogvalue > 200) {
        digitalWrite(led1,HIGH);
    }
    else {
        digitalWrite(led1,LOW);
    }
}

void IncrementPulseCount() {
    digitalWrite(led2,HIGH);
}
