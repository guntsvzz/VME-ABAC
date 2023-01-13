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
  int number_45[2][7] = {{0,1,1,0,0,1,1}, //row0
                         {1,0,1,1,0,1,1} }; // a,b,c,d,e,f,g
  for (char row=0; row<2; row++)
  {                  
    for (char pin=2; pin<9; pin++) 
    {
    digitalWrite(pin, number_45[row][pin-2]);  
    }
    delay(1000);
  }
}
