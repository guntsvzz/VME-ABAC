void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFC; //declare of Pin2-Pin7 of PortD
  DDRB = 0x01; //declare of Pin8 of PortB
}

void loop() {
  // put your main code here, to run repeatedly:
  //Use CC 7 segment 
  PORTD = (0x26)<<2; //shift by 2 as it is on PD2
  PORTB = (0x01); 
}
