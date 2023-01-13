int s = 0;//To unrun 7 segment in the beginnig//
void setup() 
{
  Serial.begin(9600);
  setPwmFrequency(9,8);
  
  for( char a = 4; a < 17; a++)
    {
  pinMode(a, OUTPUT);
    }
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(A5, INPUT);//Pin 19//
  digitalWrite(5, HIGH);//7segment//
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);//7segment//
  attachInterrupt(digitalPinToInterrupt(3), blink, CHANGE);
}
void blink() 
{
digitalWrite(6, HIGH);
delay(1000);
digitalWrite(6, LOW);
}

void loop() 
{
  int x;
  int m;
  char H;
  char a;
  char l;
  char o;
  if (digitalRead(17) == LOW)
  {
    s = s+1;
  }
  digitalWrite(10, HIGH);
  x = analogRead(A5);
  delay(10);
  switch(x)
  {
    case 0 ... 500:
    m = 5000; 
    break;

    case 501 ... 1023:
    m = 10000;
    break;
  }
  if (s > 0)
  {
        analogWrite(9, 153);
        digitalWrite(4, LOW); //FAN
        digitalWrite(13, HIGH);
        digitalWrite(10, HIGH);//LED 1//
        digitalWrite(2, LOW);//LED 2//
        digitalWrite(5, HIGH);//7segment//
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);//7segment//
        Serial.println("H");
        delay(m);
                
        analogWrite(9, 0);
        digitalWrite(10, LOW);
        digitalWrite(2, LOW);
        digitalWrite(5, LOW);//7segment//
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);//7segment//
        Serial.println("a");
        delay(m);
        
        
        analogWrite(9, 230);
        digitalWrite(4, LOW); //FAN
        digitalWrite(13, HIGH);
        digitalWrite(10, HIGH);//LED 1//
        digitalWrite(2, LOW);//LED 2//
        digitalWrite(5, HIGH);//7segment//
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);//7segment//
        Serial.println("l");
        delay(m);
        
       
        analogWrite(9, 0);
        digitalWrite(10, HIGH);//LED 1//
        digitalWrite(2, HIGH);//LED 2//
        digitalWrite(5, HIGH);//7segment//
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);//7segment//
        Serial.println("0");
         delay(m);
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
