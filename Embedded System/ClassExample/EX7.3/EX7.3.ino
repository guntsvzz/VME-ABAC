void setup()
{
  pinMode(4, OUTPUT);
  for (char i = 5; i<12; i++)
  {
    pinMode(i, OUTPUT);
  }
  //Initialize Timer
  noInterrupts(); //disable all interrupts
  //Make a timer as 1s
  TCCR1A = 0; //timer 1
  TCCR1B = 0;
  TCNT1  = 0; //clear 0

  OCR1A  = 15625; //Compare match register 16MHz/1024/1Hz
  TCCR1B |=(1<<WGM12); //CTC mode
  TCCR1B |=(1<<CS12); //256 prescaler
  TCCR1B |=(1<<CS10); //1024 prescaler
  TIMSK1 |=(1<<OCIE1A); //Enable timer compare interrupt
  interrupts(); //Enable all interrupts
}
  
  ISR(TIMER1_COMPA_vect)
  {
    digitalWrite(4,HIGH);
    delay(200);
    digitalWrite(4,LOW);
  }
  
  void loop() //CA
  {
     int number_09[10][7] ={{0,0,0,0,0,0,1},  //row0
                          {1,0,0,1,1,1,1},  //row1 
                          {0,0,1,0,0,1,0},  //row2 
                          {0,0,0,0,1,1,0},  //row3
                          {1,0,0,1,1,0,0},  //row4
                          {0,1,0,0,1,0,0},  //row5
                          {0,1,0,0,0,0,0},  //row6
                          {0,0,0,1,1,1,1},  //row7
                          {0,0,0,0,0,0,0},  //row8
                          {0,0,0,0,1,0,0},};//row9 //a,b,c,d,e,f,g
                    
  for (char row=0; row<10; row++)
  {                  
    for (char pin=5; pin<12; pin++) 
    {
    digitalWrite(pin, number_09[row][pin-5]);  
    }
    delay(1000);
  }
  }
