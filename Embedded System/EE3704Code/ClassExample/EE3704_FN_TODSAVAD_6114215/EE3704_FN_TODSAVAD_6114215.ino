int s = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //RGB
  pinMode(5, OUTPUT);  //R
  pinMode(6, OUTPUT); //G
  pinMode(8, OUTPUT); //B

  //7Segment
  for (char i=12;i<19;i++)
  {
    pinMode(i,OUTPUT);
  }

  //BUZZER
  pinMode(11,OUTPUT);//buzzer

  //POTENTIOMETER  
  pinMode(A5,INPUT);
  
  //MOTOR
  pinMode(9,OUTPUT);//PWM
  pinMode(4,OUTPUT);//dir
  pinMode(3,OUTPUT);//dir
  setPwmFrequency(9,8); //Divisor by 8
  
  //SW
  //attachInterrupt(digitalPinToInterrupt(2), blink, RISING);//sw2
  pinMode(10,INPUT);//sw1
  pinMode(2,INPUT);//sw2  

  //LED1
  pinMode(7,OUTPUT);
}

  void blink(){
  digitalWrite(6,HIGH);
  delay(1000); 
  digitalWrite(6,LOW);
}

bool sw1;
bool sw2;
void loop() {
  // put your main code here, to run repeatedly:
  int Analog_Input_Value = analogRead(A5);
  int number_09[4][7] ={{0,1,0,0,1,0,0},  //Code1
                        {0,1,1,0,0,0,0},  //Code2
                        {1,1,1,0,0,0,0},  //Code3
                        {0,0,0,0,1,1,0},  //Code4                    
                       }; //a,b,c,d,e,f,g
  int number_00[1][7] ={1,1,1,1,1,1,1};                    
  sw1 = digitalRead(10);
  sw2 = digitalRead(2);
  
  if(sw1 == 1 && sw2==0) // LH SW0
  {
    digitalWrite(7,HIGH); 
    for (char row=0; row<4; row++)
    {                  
      for (char pin=12; pin<19; pin++) 
      {
      digitalWrite(pin, number_09[row][pin-12]);  
      }
      delay(2000);
    }
  } 
  else if(sw1 == 0 && sw2==0) //LH SW1
  {
    noc();
    for(char y=0;y<1;y++)
    { 
    for (char row=0; row<1; row++)
    {                  
      for (char pin=12; pin<19; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-12]);  
      } 
    }
    note(); 
    }  
  }
   
  else if(sw1 == 1 && sw2 == 1) //LH SW2
  {
    digitalWrite(7,HIGH); 
    for (char row=0; row<1; row++)
    {                  
      for (char pin=12; pin<19; pin++) 
      {
        digitalWrite(pin, number_00[row][pin-12]);  
      } 
    }
    
    Serial.println(Analog_Input_Value);
    delay(1000);   
    if(Analog_Input_Value>400)
    {
    Serial.println("NORMAL");  
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    analogWrite(9, 179);  
    blue();
    delay(5000);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    analogWrite(9, 0);
    }
    else  
    {
    Serial.println("DARK");
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    analogWrite(9, 115);    
    pink();
    delay(5000);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    analogWrite(9, 0);
    }
  }

  
}

void note()
{
  //DO
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(478);
      digitalWrite(11, LOW);  
      delayMicroseconds(478);
      }
      delay(100);

  //RE
    for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(426);
      digitalWrite(11, LOW);  
      delayMicroseconds(426);
      }
      delay(100);  

  //ME      
      for(int x = 0 ; x<500 ; x++)
      {
        digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(379);
      digitalWrite(11, LOW);  
      delayMicroseconds(379);
      }
      delay(100);

  //FA
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(358);
      digitalWrite(11, LOW);  
      delayMicroseconds(358);
      }
      delay(100);

  //Son
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(319);
      digitalWrite(11, LOW);  
      delayMicroseconds(319);
      }
      delay(100);

  //Ra
      for(int x = 0 ; x<500 ; x++)
      {
      digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(284);
      digitalWrite(11, LOW);  
      delayMicroseconds(284);
      }
      delay(100);
  //TE
      for(int x = 0 ; x<500 ; x++)
      {
        digitalWrite(7,LOW);  
      digitalWrite(11, HIGH);  
      delayMicroseconds(253);
      digitalWrite(11, LOW);  
      delayMicroseconds(253);
      }
      delay(100);
  }

void noc()
{
  analogWrite(5,0);  //NoC
  analogWrite(6,0); 
  analogWrite(8,0); 
}

void blue()
{
  analogWrite(5,  255-50);  //BLUE
  analogWrite(6, 255-14); 
  analogWrite(8, 255-209); 
}

void pink()
{
  analogWrite(5,  255-238); //PINK
  analogWrite(6, 255-36); 
  analogWrite(8, 255-135);   
}


void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
