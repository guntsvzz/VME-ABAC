void setup()
{
  pinMode(A0,INPUT);
  pinMode(4,OUTPUT);
  pinMode(12,OUTPUT);
  for (char i=5; i<12; i++)
  {
    pinMode(i,OUTPUT); //CA
  }
  Serial.begin(9600);
  //Initialize Timer
  noInterrupts(); //disable all interrupts
  //Make a timer as 1 s
  TCCR1A = 0; //timer 1
  TCCR1B = 0;
  TCNT1  = 0; //clear 0
  
  OCR1A  = 15625; //Set time value 
  TCCR1B |=(1<<WGM12); // clear timer
  TCCR1B |=(1<<CS12);
  TCCR1B |=(1<<CS10); //Set prescaler as 1024 TIMSK1 |=(1<<OCIE1A); 
  TIMSK1 |=(1<<OCIE1A);//Enable timer compare
  interrupts(); //Enable interrupts
}
  ISR(TIMER1_COMPA_vect)
  {
    int X = analogRead(A0);
    Serial.println(X);
    if(X<400)
    {
    digitalWrite(4,HIGH);
    delay(200);
    digitalWrite(4,LOW);
    }
    else
    {
      digitalWrite(4,LOW);
    }
  }
  
void loop()
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
    digitalWrite(pin,number_09[row][pin-5]);
    }
    delay(1000);
  }  
}
