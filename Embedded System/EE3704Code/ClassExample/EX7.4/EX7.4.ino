void blink() 
{
    digitalWrite(4,HIGH);
    delay(200);
    digitalWrite(4,LOW);
}

void setup()
{
  //attachInterrupt(digitalPinToInterrupt(pin), ISR ,mode);
  pinMode(4, OUTPUT);
  for (char i = 5; i<12; i++)
  {
    pinMode(i, OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), blink ,RISING);
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
