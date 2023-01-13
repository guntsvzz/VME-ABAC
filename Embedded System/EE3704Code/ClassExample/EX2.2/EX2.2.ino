void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  int a;
  for(a=0;a<5;a=a+1)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    delay(2000); 
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
