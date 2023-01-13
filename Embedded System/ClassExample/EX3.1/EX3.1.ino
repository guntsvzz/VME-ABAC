void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW = digitalRead(2); //Boolean
  if(SW == 1)
  {
    digitalWrite(13,HIGH); //LED ON
  }
  else
  {
    digitalWrite(13,LOW); //LED OFF
  }
}
