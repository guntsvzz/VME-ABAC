void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available()>0)
  { 
  char KBD = Serial.read();
    switch(KBD)
    {
    case '1' :
    case 'd' :
      Serial.println("DO");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(478);
      digitalWrite(10, LOW);  
      delayMicroseconds(478);
      }
      delay(100);
      break;
    
    case '2' :
    case 'r' :
      Serial.println("RE");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(426);
      digitalWrite(10, LOW);  
      delayMicroseconds(426);
      }
      delay(100);
      break;

    case '3' :
    case 'm' :
      Serial.println("ME");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(379);
      digitalWrite(10, LOW);  
      delayMicroseconds(379);
      }
      delay(100);
      break;
      
    case '4' :
    case 'f' :
      Serial.println("FA");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(358);
      digitalWrite(10, LOW);  
      delayMicroseconds(358);
      }
      delay(100);
      break;
    
    case '5' :
    case 'z' :
      Serial.println("SO");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(319);
      digitalWrite(10, LOW);  
      delayMicroseconds(319);
      }
      delay(100);
      break;

    case '6' :
    case 'l' :
      Serial.println("LA");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(284);
      digitalWrite(10, LOW);  
      delayMicroseconds(284);
      }
      delay(100);
      break;

    case '7' :
    case 't' :
      Serial.println("TI");
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(10, HIGH);  
      delayMicroseconds(253);
      digitalWrite(10, LOW);  
      delayMicroseconds(253);
      }
      delay(100);
      break;
         
   default:
      digitalWrite(10, LOW);  
      break;
    }
  }
}
