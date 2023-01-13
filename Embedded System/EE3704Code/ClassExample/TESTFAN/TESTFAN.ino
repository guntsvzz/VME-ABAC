void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT); //PWM
  setPwmFrequency(9,8); //Divisor by 8 we get 3.9kHz
  pinMode(4,OUTPUT); //DirA
  pinMode(13,OUTPUT); //DirB
}

void loop(){
  if(Serial.available()>0){
    char KBD = Serial.read();
    switch(KBD)
    {
    case 'a':
      analogWrite(9,255); //100%
      digitalWrite(4, LOW);
      digitalWrite(13, HIGH);
      Serial.println("A 100%CW");
    break;
    case 'b':
      analogWrite(9,153); //60%
      digitalWrite(4, LOW);
      digitalWrite(13, HIGH);     
      Serial.println("B 60%CW");
    break;
    case 's':
      analogWrite(9,0); //0%
      digitalWrite(4, LOW);
      digitalWrite(13, LOW);
      Serial.println("S 0%");
    break;
    case 'd':
      analogWrite(9,255); //100%   
      digitalWrite(4, HIGH);
      digitalWrite(13, LOW);
      Serial.println("D 100%CCW");
    break;
    case 'e':
      analogWrite(9,153); //60%
      digitalWrite(4, HIGH);
      digitalWrite(13, LOW);
      Serial.println("E 60%CCW");
    break;
    }
  }
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
