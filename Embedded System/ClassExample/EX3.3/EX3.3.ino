void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW1 = digitalRead(2); //Boolean
  bool SW2 = digitalRead(3); //Boolean
  if(SW1 == 1)
  {
    digitalWrite(8,HIGH); //LED ON
  }
  else
  {
    digitalWrite(8,LOW); //LED OFF
  }
  if(SW2 == 1)
  {
    digitalWrite(9,HIGH); //LED ON
  }
  else
  {
    digitalWrite(9,LOW); //LED OFF
  }
}
