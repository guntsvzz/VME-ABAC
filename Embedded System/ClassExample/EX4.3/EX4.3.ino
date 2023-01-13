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
    switch(KBD)
    {
    case '1' :
          Serial.println("1: LED1 is ON");
         PORTB = 0x01;
         break;
    case '2':
          Serial.println("2: LED2 is ON");
          PORTB = 0x02;
          break;
     case '3':
          Serial.println("3: LED3 is ON");
          PORTB = 0x04;
          break;
    case '4':
          Serial.println("4: LED4 is ON");
          PORTB = 0x08;
          break;
    default:
          PORTB = 0x00;
          Serial.println("Others: LEDs are OFF");
          break;
    }
  }
}
