void setup() {
  // put your setup code here, to run once:
   pinMode(5,INPUT);
   for (char i = 6; i<13; i++ )
  {
    pinMode(i, OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  bool SW1 = digitalRead(5);
  if(SW1 == 0)
  {
  int number_09[4][7] ={{0,0,0,1,0,0,0},  //row0a
                        {1,1,0,0,0,0,0},  //row1b
                        {0,0,0,0,0,1,0},  //row2a 
                        {0,1,1,0,0,0,1},  //row3c
                       }; //a,b,c,d,e,f,g
                       
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<4; row++)
    {                  
      for (char pin=6; pin<13; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-6]);  
      }
      delay(1000);
      
      for (char row=0; row<1; row++)
      {                      
      for (char pin=6; pin<13; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-6]);  
      } 
      delay(200);
      }
    }     
  }
  else
  {
    int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g   
    for (char row=0; row<1; row++)
    {                  
      for (char pin=6; pin<13; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-6]);  
      } 
    }
  }

  bool SW2 = digitalRead(2);
  if(SW2 == 0)
  {
      digitalWrite(3, HIGH);
  }
  else
  {
      digitalWrite(3, LOW);
  }
}
