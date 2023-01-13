void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFC; //declare of Pin2-Pin7 of PortD
  DDRB = 0x01; //declare of Pin8 of PortB
}

void loop() {
  // put your main code here, to run repeatedly:
  //Use CC 7 segment 
  //0
  PORTD = (0x40)<<2; //shift by 2 as it is on PD2
  PORTB = (0x1);
  delay(1000);
  //1
  PORTD = (0x79)<<2; //shift by 2 as it is on PD2
  PORTB = (0x1);
  delay(1000);
  //2
  PORTD = (0x24)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000);
  //3
  PORTD = (0x30)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000);
  //4
  PORTD = (0x19)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000); 
  //5
  PORTD = (0x12)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000); 
  //6
  PORTD = (0x02)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000); 
   //7
  PORTD = (0x78)<<2; //shift by 2 as it is on PD2
  PORTB = (0x1);
  delay(1000); 
  //8
  PORTD = (0x00)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000); 
  //9
  PORTD = (0x10)<<2; //shift by 2 as it is on PD2
  PORTB = (0x0);
  delay(1000); 
}
