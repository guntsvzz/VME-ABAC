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

void blink(){
  digitalWrite(6,HIGH);
   delay(1000); 
   digitalWrite(6,LOW);
}
int data;
int T;
bool sw1;
void loop() {
  // put your main code here, to run repeatedly:
sw1 = digitalRead(17);

data = analogRead(A0);
  
  if(data>500)
  {
    T = 10*1000;
  }
  else
  {
    T = 5*1000;
    
  }
  if(sw1==LOW){
    H();
    Serial.print("H"); 
    digitalWrite(10,HIGH);
    digitalWrite(2,LOW); 
    digitalWrite(4,HIGH);
    digitalWrite(13,LOW);
    analogWrite(9, 153);
    Serial.print("T=");
    Serial.println(T/1000);
    delay(T);  
    
    a();
    Serial.print("a");
    digitalWrite(10,LOW);
    analogWrite(9, 0);
    Serial.print("T=");
    Serial.println(T/1000);
    delay(T);
    
    L();
    Serial.print("L");
    digitalWrite(10,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(13,HIGH);
    analogWrite(9, 230);
    Serial.print("T=");
    Serial.println(T/1000);
    delay(T);
    
    o();
    Serial.print("0");
    digitalWrite(2,HIGH);
    analogWrite(9, 0);
    Serial.print("T=");
    Serial.println(T/1000);
    delay(T);
    
  }
  else{
    x();
    digitalWrite(10,HIGH);
    digitalWrite(2,LOW);
    analogWrite(9, 0);
  }
}
void H(){
  digitalWrite (5,HIGH);
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (11,HIGH);
  digitalWrite (12,LOW);
  digitalWrite (15,LOW);
  digitalWrite (16,LOW);
}
void a(){
  digitalWrite (5,LOW);
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (11,LOW);
  digitalWrite (12,LOW);
  digitalWrite (15,HIGH);
  digitalWrite (16,LOW);
}
void L(){
  digitalWrite (5,HIGH);
  digitalWrite (7,HIGH);
  digitalWrite (8,HIGH);
  digitalWrite (11,LOW);
  digitalWrite (12,LOW);
  digitalWrite (15,LOW);
  digitalWrite (16,HIGH);
}
void o(){
  digitalWrite (5,HIGH);
  digitalWrite (7,HIGH);
  digitalWrite (8,LOW);
  digitalWrite (11,LOW);
  digitalWrite (12,LOW);
  digitalWrite (15,HIGH);
  digitalWrite (16,LOW);
}
void x(){
  digitalWrite (5,HIGH);
  digitalWrite (7,HIGH);
  digitalWrite (8,HIGH);
  digitalWrite (11,HIGH);
  digitalWrite (12,HIGH);
  digitalWrite (15,HIGH);
  digitalWrite (16,HIGH);
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
