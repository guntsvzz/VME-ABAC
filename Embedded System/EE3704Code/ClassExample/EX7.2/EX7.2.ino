void setup()
{
  pinMode(13, OUTPUT);
  //Initialize Timer
  noInterrupts(); //disable all interrupts
  //Make a timer as 4 s
  TCCR1A = 0; //timer 1
  TCCR1B = 0;
  TCNT1  = 0; //clear 0
  
  OCR1A  = 62500; //Set time value
  TCCR1B |=(1<<WGM12); // clear timer
  TCCR1B |=(1<<CS12);
  TCCR1B |=(1<<CS10); //Set prescaler as 1024 TIMSK1 |=(1<<OCIE1A); 
  TIMSK1 |=(1<<OCIE1A);//Enable timer compare
  interrupts(); //Enable interrupts
}
     
  ISR(TIMER1_COMPA_vect)
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }

void loop()
{
   digitalWrite(12,HIGH);
   delay(2000);
   digitalWrite(12,LOW);
   delay(2000);
}
