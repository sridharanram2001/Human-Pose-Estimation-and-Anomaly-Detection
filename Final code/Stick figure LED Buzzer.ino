int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int Buzz = 6;
int dataFromUser;
int previous=5;
int count=0;
void setup() 
{
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(Buzz,OUTPUT);
    Serial.begin(9600);
}

void loop()
 {
  while(Serial.available())
  {
  dataFromUser = Serial.read();
  if(dataFromUser == '1' && count==0)
  {
    //previous = 1;
    digitalWrite(LED1,HIGH);
    //delay(1000);
    count++;
  }
  else if(dataFromUser == '1' && count==1)
  {
    //previous = 1;
    digitalWrite(LED2,HIGH);
    //delay(1000);
    count++;
    
  }
  else if(dataFromUser == '1' && count==2)
  {
    digitalWrite(LED3,HIGH);
    //delay(1000);
    count++;
  }
  else if(dataFromUser == '1' && count==3)
  {
    //previous = 1;
    digitalWrite(Buzz,HIGH);
    //delay(1000); 
  }
  else if(dataFromUser == '2' )
  {
    //previous = 2;
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(Buzz,LOW);
    count=0;
  }

}
delay(10);
//Serial.print(dataFromUser);

}
