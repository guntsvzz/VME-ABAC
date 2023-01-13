void setup() {
  // put your setup code here, to run once:
  for (char i = 2; i<9; i++ )
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Use CC 7 segment 
  int number_09[10][7] ={ {1,1,1,1,1,1,0},  //row0
                          {0,1,1,0,0,0,0},  //row1 
                          {1,1,0,1,1,0,1},  //row2 
                          {1,1,1,1,0,0,1},  //row3
                          {0,1,1,0,0,1,1},  //row4
                          {1,0,1,1,0,1,1},  //row5
                          {1,0,1,1,1,1,1},  //row6
                          {1,1,1,0,0,0,0},  //row7
                          {1,1,1,1,1,1,1},  //row8
                          {1,1,1,1,0,1,1},};//row9 //a,b,c,d,e,f,g
                    
  for (char row=0; row<10; row++)
  {                  
    for (char pin=2; pin<9; pin++) 
    {
    digitalWrite(pin, number_09[row][pin-2]);  
    }
    delay(1000);
  }
}
