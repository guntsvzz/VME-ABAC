void setup() {
  // put your setup code here, to run once:
 DDRD &=~(0x1E);  //Declare as Input
 DDRB |= 0x0F;    //Declare as Output
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW1 = PIND & 0x04;
  bool SW2 = PIND & 0x08;
  bool SW3 = PIND & 0x10;
  bool SW4 = PIND & 0x20;
 if(SW1==1 && SW2==0 && SW3==0 && SW4==0)
  {
  PORTB = 0x01;
  }
  if(SW1==1 && SW2==1 && SW3==0 && SW4==0)
  {
  PORTB = 0x02;
  }
  if(SW1==1 && SW2==1 && SW3==1 && SW4==0)
  {
  PORTB = 0x04;
  }
  if(SW1==1 && SW2==1 && SW3==1 && SW4==1)
  {
  PORTB = 0x08;
  }
  else
  {
  PORTB = 0x00;
  }

}
