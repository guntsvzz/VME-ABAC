void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD |= (0x3c);  //Pin2,3,4,5
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  { 
    char KBD = Serial.read();
    Serial.print("Number Read as :");
    Serial.println(KBD);
    delay(1000);
  }
}
