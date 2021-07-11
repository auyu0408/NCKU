#define LaserPIN A5

void setup()
{
pinMode(LaserPIN,OUTPUT);     
}
void loop() 
{
digitalWrite(LaserPIN, HIGH);      
delay(1000);                      
digitalWrite(LaserPIN, LOW);    
delay(1000);                     
}

