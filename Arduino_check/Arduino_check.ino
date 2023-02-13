int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int Buzz = 6;
int dataFromUser;
int count=0;
void setup() {
  // put your setup code here, to run once:
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(Buzz,OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0)
  {

    dataFromUser = Serial.read();
  }
  if(dataFromUser == '1' && count==0)
  {
    digitalWrite(LED1,HIGH);
    delay(1000);
    count++;
  }
  else if(dataFromUser == '1' && count==1)
  {
    digitalWrite(LED2,HIGH);
    delay(1000);
    count++;
    
  }
  else if(dataFromUser == '1' && count==2)
  {
    digitalWrite(LED3,HIGH);
    delay(1000);
    count++;
    
  }
  else if(dataFromUser == '1' && count==3)
  {
    digitalWrite(Buzz,HIGH);
    delay(1000);
    count++;
    
  }
  else if(dataFromUser == '2')
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(Buzz,LOW);
    count=0;
  }
Serial.print(dataFromUser);

}
