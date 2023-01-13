void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Initialize Timer
  noInterrupts(); //disable all interrupts
  //Make a timer as 0.5s
  TCCR1A = 0; //timer 1
  TCCR1B = 0;
  TCNT1  = 0; //clear 0

  OCR1A  = 31250; //Compare match register 16MHz/256/2Hz
  TCCR1B |=(1<<WGM12); //CTC mode
  TCCR1B |=(1<<CS12); //256 prescaler
  TIMSK1 |=(1<<OCIE1A); //Enable timer compare interrupt
  interrupts(); //Enable all interrupts
}
  
  ISR(TIMER1_COMPA_vect)
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
  }
  
  void loop()
  {
    digitalWrite(12,HIGH);
    delay(2000);
    digitalWrite(12,LOW);
    delay(2000);
  }
