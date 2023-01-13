void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  for(char a=0;a<5;a=a+1)
  {
    digitalWrite(13, HIGH);
    delay(2000); 
    digitalWrite(13, LOW);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
