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
  int number_09[7][7] ={ {1,0,0,0,0,0,0},  //row0a
                         {1,1,0,0,0,0,0},  //row1b
                         {1,1,1,0,0,0,0},  //row2c 
                         {1,1,1,1,0,0,0},  //row3d
                         {1,1,1,1,1,0,0},  //row4e
                         {1,1,1,1,1,1,0},  //row5f
                         {1,1,1,1,1,1,1},  //row6g              
                         }; //a,b,c,d,e,f,g
                    
  for (char row=0; row<7; row++)
  {                  
    for (char pin=2; pin<9; pin++) 
    {
    digitalWrite(pin, number_09[row][pin-2]);  
    }
    delay(1000);
  }
    for (char row=6; row>=0; row--)
  {                  
    for (char pin=2; pin<9; pin++) 
    {
    digitalWrite(pin, number_09[row][pin-2]);  
    }
    delay(1000);
  }

}
