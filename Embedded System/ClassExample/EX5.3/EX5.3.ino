int Analog_Input_value;

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  pinMode(A0,INPUT);
  for(int pin=2; pin<5; pin++)
  {
  pinMode(pin,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Analog_Input_value = analogRead(A0);
  Serial.println(Analog_Input_value);
  delay(100);
  
  switch(Analog_Input_value)
    {
    case 601 ... 1000 :
      Serial.println("pin1");
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      break;
    case 401 ... 600 :
      Serial.println("pin2");      
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      break;  
    case 0  ... 400 :
      Serial.println("pin3"); 
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
    default : 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      break;    
    } 
}
