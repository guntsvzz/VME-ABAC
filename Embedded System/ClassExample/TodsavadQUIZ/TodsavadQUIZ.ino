void setup() {
  //P
  Serial.begin(9600);
  pinMode(A1,INPUT);
  
  //7
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  for (char i = 5; i<13; i++)
  {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // SW with 7-Segment
  bool SW1 = digitalRead(2);
  bool SW2 = digitalRead(3);
  bool SW3 = digitalRead(4);
  int number_09[4][7] ={{0,1,0,0,1,0,1},  //row0a
                        {0,0,0,0,0,0,1},  //row1b
                        {0,0,1,0,0,1,1},  //row2a                      
                       }; //a,b,c,d,e,f,g
  if(SW1==1 && SW2==0 && SW3==1)
  {
    digitalWrite(12, LOW);
    delay(2000);
    digitalWrite(12, HIGH);
  }    

  if(SW1==0 && SW2==0 && SW3==0)
  {
    int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g   
    for (char row=0; row<1; row++)
    {                  
      for (char pin=6; pin<13; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-6]);  
      } 
    }
    delay(1000);
  }

  
  //Potentiometer
  int Analog_Input_value = analogRead(A1);
  Serial.println(Analog_Input_value);
  delay(1000);
  
  switch(Analog_Input_value)
    {
    case 0 ... 205 :
      Serial.println("data = 1");
      Serial.print("Second");
      if(SW1==1 && SW2==1 && SW3==1)
  {
  int number_09[3][7] ={{1,0,1,1,0,1,0},  //row0a
                        {1,1,1,1,1,1,0},  //row1b
                        {1,1,0,1,1,0,0},  //row2a                      
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<3; row++)
    {                  
      for (char pin=5; pin<11; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-5]);  
      }
      delay(1000);
      for (char row=0; row<1; row++)
      {                      
      for (char pin=5; pin<11; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-5]);  
      } 
      delay(500);
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
      break;

      case 206 ... 410 :
      Serial.println("data = 2");
      Serial.print("Second");
      if(SW1==1 && SW2==1 && SW3==1)
  {
  int number_09[3][7] ={{1,0,1,1,0,1,0},  //row0a
                        {1,1,1,1,1,1,0},  //row1b
                        {1,1,0,1,1,0,0},  //row2a                      
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<3; row++)
    {                  
      for (char pin=5; pin<11; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-5]);  
      }
      delay(2000);
      for (char row=0; row<1; row++)
      {                      
      for (char pin=5; pin<11; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-5]);  
      } 
      delay(500);
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
      break;
  case 411 ... 615 :
      Serial.println("data = 3");
      Serial.print("Second");
      if(SW1==1 && SW2==1 && SW3==1)
  {
  int number_09[3][7] ={{1,0,1,1,0,1,0},  //row0a
                        {1,1,1,1,1,1,0},  //row1b
                        {1,1,0,1,1,0,0},  //row2a                      
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<3; row++)
    {                  
      for (char pin=5; pin<11; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-5]);  
      }
      delay(3000);
      for (char row=0; row<1; row++)
      {                      
      for (char pin=5; pin<11; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-5]);  
      } 
      delay(500);
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
      break;
      case 616 ... 820 :
      Serial.println("data = 4");
      Serial.print("Second");
      if(SW1==1 && SW2==1 && SW3==1)
  {
  int number_09[3][7] ={{1,0,1,1,0,1,0},  //row0a
                        {1,1,1,1,1,1,0},  //row1b
                        {1,1,0,1,1,0,0},  //row2a                      
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<3; row++)
    {                  
      for (char pin=5; pin<11; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-5]);  
      }
      delay(4000);
      for (char row=0; row<1; row++)
      {                      
      for (char pin=5; pin<11; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-5]);  
      } 
      delay(500);
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
      break;
    case 821 ... 1023 :
      Serial.println("data = 5");
      Serial.print("Second");
      if(SW1==1 && SW2==1 && SW3==1)
  {
  int number_09[3][7] ={{1,0,1,1,0,1,0},  //row0a
                        {1,1,1,1,1,1,0},  //row1b
                        {1,1,0,1,1,0,0},  //row2a                      
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1}; //a,b,c,d,e,f,g                     
                      
    for (char row=0; row<3; row++)
    {                  
      for (char pin=5; pin<11; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-5]);  
      }
      delay(5000);
      for (char row=0; row<1; row++)
      {                      
      for (char pin=5; pin<11; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-5]);  
      } 
      delay(500);
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
      break;  
    default : 
      Serial.println("data = 0");
      Serial.print("Second"); 
      break;    
    } 

}
