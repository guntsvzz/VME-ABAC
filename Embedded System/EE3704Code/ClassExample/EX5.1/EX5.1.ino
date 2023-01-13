int Analog_Input_value;

void setup() {
  // put your setup code here, to run once:  
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Analog_Input_value = analogRead(A0);
  Serial.println(Analog_Input_value);
  delay(100);
}
  
