  int s=0;
void setup() {
  //SW1
  pinMode(17, INPUT); //HIGH
  //SW2
  pinMode(3, INPUT); //LOW
  
  //LED1
  pinMode(2, OUTPUT); //HIGH
  //LED2
  pinMode(10, OUTPUT); //LOW
  
  //7-segment CA
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);

  //FAN
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT); //PWM
  setPwmFrequency(9,8);
    
  //Potentiometer
  pinMode(A0,INPUT);

  //Buzzer
  pinMode(6, OUTPUT);

  Serial.begin(9600);
  //Initialize Timer
  noInterrupts(); //disable all interrupts
  //Make a timer as 1 s
  TCCR1A = 0; //timer 1
  TCCR1B = 0;
  TCNT1  = 0; //clear 0
  
  OCR1A  = 15625; //Set time value 
  TCCR1B |=(1<<WGM12); // clear timer
  TCCR1B |=(1<<CS12);
  TCCR1B |=(1<<CS10); //Set prescaler as 1024 TIMSK1 |=(1<<OCIE1A); 
  TIMSK1 |=(1<<OCIE1A);//Enable timer compare
  interrupts(); //Enable interrupts
}
  ISR(TIMER1_COMPA_vect)
  {
    bool SW2 = digitalRead (3); //LOW
    if(SW2 == 1)
    {
      digitalWrite(6,HIGH);
      delay(200);
      digitalWrite(6,LOW);
    }
    else
    {
      digitalWrite(6,LOW);
    }
  }

void loop() {
  // put your main code here, to run repeatedly:
  int M;
  int Analog_Input_Value = analogRead(A0);
  switch(Analog_Input_Value)
  {
    case 0 ... 500:
      Serial.println("T = 5s");
      M = 5000;
      break;
    case 501 ... 1023:
      Serial.println("T = 10s");
      M = 10000;
      break;
    default:
      M = 0;
      break;  
  } 
   
  bool SW1 = digitalRead (17); //HiGH
  if(SW1 == 0)
  {
      s = s+1;
  }
    
    if (s > 0)
    { 
    //Code1
          Serial.println("H");
          //Motor
          digitalWrite(4, LOW);
          digitalWrite(13, HIGH);
          analogWrite(9, 153); //60%
          //LED
          digitalWrite(10, LOW); //HIGH
          digitalWrite(2, HIGH); //LOW
          //7-segment H
          digitalWrite(5, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(12, LOW);
          digitalWrite(15, LOW);
          digitalWrite(16, LOW);       
          delay(M);
          
    //Code2
          Serial.println("a");
          //Motor
          digitalWrite(4, LOW);
          digitalWrite(13, LOW);
          analogWrite(9, 0); //0%
          //LED
          digitalWrite(10, HIGH); //HIGH
          digitalWrite(2, HIGH); //LOW
          //7-segment a
          digitalWrite(5, LOW);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(15, HIGH);
          digitalWrite(16, LOW);
          delay(M);
          
    //Code3
          Serial.println("L");
          //Motor
          digitalWrite(4, LOW);
          digitalWrite(13, HIGH);
          analogWrite(9, 230); //90%
          //LED
          digitalWrite(10, LOW); //HIGH
          digitalWrite(2, HIGH); //LOW
          //7-segment L
          digitalWrite(5, HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(15, LOW);
          digitalWrite(16, HIGH);
          delay(M);
          
    //Code4
          Serial.println("0");
          //Motor
          digitalWrite(4, LOW);
          digitalWrite(13, LOW);
          analogWrite(9, 0); //0%
          //LED
          digitalWrite(10, LOW); //HIGH
          digitalWrite(2, LOW); //LOW
          //7-segment 0
          digitalWrite(5, HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(15, HIGH);
          digitalWrite(16, LOW);
          delay(M); 
    }
    else
    {
      //Motor
      digitalWrite(4, LOW);
      digitalWrite(13, LOW);
      analogWrite(9, 0); //0%
      //7-segment 0
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
    }
       
}

void setPwmFrequency(int pin, int divisor) 
{
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
