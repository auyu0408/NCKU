#include "pitches.h"
int buzzerPin=4; 
// notes in the melody: 
int melody[] = { 
   NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6}; 
int duration = 500;  // 500 miliseconds 
   
void setup() { 
} 

void loop() {   
   for (int thisNote = 0; thisNote < 8; thisNote++) { 
     // Sound the note on Pin buzzerPin for the duration of 0.5 second
     tone(buzzerPin, melody[thisNote], duration);  
     delay(1000); 
   } 
   // stop for a while 
   delay(2000); 
}

