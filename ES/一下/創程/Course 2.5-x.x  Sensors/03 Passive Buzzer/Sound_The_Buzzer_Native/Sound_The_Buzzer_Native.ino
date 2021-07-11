int buzzerPin=4;                                                  

void setup()
{
  pinMode(buzzerPin,OUTPUT);                    
}

void loop()
{
  unsigned char i,j;                                      
  while(1)
  {
    for(i=0;i<80;i++);                            //One frequency
    {   
      digitalWrite(buzzerPin,HIGH);               //Sound
      delay(100);                                 //Delay100ms
      digitalWrite(buzzerPin,LOW);                //Stop
      delay(100);                                 //Delay100ms
      for(i=0;i<100;i++);                         //Another Frequency
      {  
        digitalWrite(buzzerPin,HIGH);             
        delay(200);                               
        digitalWrite(buzzerPin,LOW);                    
        delay(200);                               
      }
    }
  }
}
