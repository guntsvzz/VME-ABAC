int Analog_Input_value;

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  pinMode(A0,INPUT);
  for(int pin=2; pin<6; pin++)
  {
  pinMode(pin,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Analog_Input_value = analogRead(A0);
  Serial.print(Analog_Input_value);
  delay(100);
  
  switch(Analog_Input_value)
    {
    case 0 ... 255 :
      Serial.println("pin1");
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      break;
    case 256 ... 511 :
      Serial.println("pin2");      
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      break;  
    case 512 ... 767 :
      Serial.println("pin3"); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      break;
    case 768 ... 1023 :
      Serial.println("pin4"); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      break;
    default : 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      break;    
    } 
}
