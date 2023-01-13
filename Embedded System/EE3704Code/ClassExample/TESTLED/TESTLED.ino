void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW1 = digitalRead(3); //Boolean H
  bool SW2 = digitalRead(2); //Boolean L
  if(SW1 == 0)
  {
    Serial.println("3");
    digitalWrite(5,HIGH); //LED ON
  }
  else
  {
    Serial.println("3");
    digitalWrite(5,LOW); //LED OFF
  }
  if(SW2 == 1)
  {
    Serial.println("2");
    digitalWrite(4,LOW); //LED ON
  }
  else
  {
    Serial.println("2");
    digitalWrite(4,HIGH); //LED OFF
  }
}
