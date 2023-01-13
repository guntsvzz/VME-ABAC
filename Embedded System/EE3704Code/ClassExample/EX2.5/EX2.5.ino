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
  int number_5[7] = {1,0,1,1,0,1,1}; // a,b,c,d,e,f,g
  for (char pin=2; pin<9; pin++) //((char id=0; id<7; id++))
  {
   digitalWrite(pin, number_5[pin-2]);  
  }
}
