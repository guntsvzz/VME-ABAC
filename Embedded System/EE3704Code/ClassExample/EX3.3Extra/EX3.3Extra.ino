void setup() {
  // put your setup code here, to run once:
 DDRD &=~(0x0C);  //Declare as Input
 DDRB |= 0x03;    //Declare as Output
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW1 = PIND & 0x04;
  bool SW2 = PIND & 0x08;
  if(SW1 == 1)
  {
     PORTB |= (0x01); //Force 1
  }
  else
  {
    PORTB &= ~(0x01); //Force 0
  }
   if(SW2 == 1)
  {
     PORTB |= (0x02); //Force 1
  }
  else
  {
    PORTB &= ~(0x02); //Force 0
  }
}
