void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);//a
pinMode(7,OUTPUT);//b
pinMode(8,OUTPUT);//c
pinMode(11,OUTPUT);//d
pinMode(12,OUTPUT);//e
pinMode(15,OUTPUT);//f
pinMode(16,OUTPUT);//g

pinMode(2,OUTPUT);//LED2AH
pinMode(10,OUTPUT);//LED1AL

pinMode(9,OUTPUT);//PWM
pinMode(4,OUTPUT);//dir
pinMode(13,OUTPUT);//dir
setPwmFrequency(9,8); //Divisor by 8


attachInterrupt(digitalPinToInterrupt(3), blink, RISING);//sw2
pinMode(17,INPUT);//sw1

pinMode(6,OUTPUT);//buzzer

pinMode(A0,INPUT);//pot
Serial.begin(9600);

}



int T;
bool sw1;
void loop() {
  sw1 = digitalRead(17);
  int data = analogRead(A0);
  //Serial.print("Read:");
  //Serial.print(data);
  if(data>500)
  {
    T = 10*1000;
    //Serial.print("T=");
    //Serial.println(T/1000);
  }
  else
  {
    T = 5*1000;
    //Serial.print("T=");
    //Serial.println(T/1000);
  }
  
    if(sw1 == LOW)
  {
   int x[4][12]={{1,0,0,0,0,1,1,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0,0,1,1,0},
                 {1,0,1,1,0,1,0,0,0,1,0,1},
                 {1,0,1,0,0,1,0,0,0,1,1,0}};
                             
  for (int row = 0; row<4; row++)
  {  
    
    for (int pin = 5; pin<17; pin++)
    {
       digitalWrite(pin,x[row][pin-5]); 
    }if(row == 0)
    {
      Serial.print("H");
      digitalWrite(4,HIGH);
      digitalWrite(13,LOW);
      analogWrite(9, 153);
      Serial.print("T=");
      Serial.println(T/1000);
    }
    else if(row == 1)
    {
      Serial.print("a");
      digitalWrite(4,LOW);
      digitalWrite(13,LOW);
      analogWrite(9, 0);
      digitalWrite(10,LOW);
      Serial.print("T=");
      Serial.println(T/1000);
    }
    else if(row == 2)
    {
      Serial.print("L");
      digitalWrite(4,LOW);
      digitalWrite(13,HIGH);
      analogWrite(9, 230);
      Serial.print("T=");
      Serial.println(T/1000);
    }
    else if(row == 3)
    {
      Serial.print("0");
      Serial.print("T=");
      Serial.println(T/1000);
      analogWrite(9, 0);
      digitalWrite(2,HIGH);
    }
    
    delay(T);
  }
  
  digitalWrite(2,LOW);
  }
   else
  {
    int x[12]={1,0,1,1,0,1,1,1,0,1,1,1};
    for (int pin = 5; pin<17; pin++)
    {
       digitalWrite(pin,x[pin-5]);
    }
   
  }
}

void blink(){
  digitalWrite(6,HIGH);
   delay(1000); 
   digitalWrite(6,LOW);
   delay(1000); 
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
