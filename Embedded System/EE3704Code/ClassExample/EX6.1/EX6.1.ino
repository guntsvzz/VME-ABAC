int Analog_Input_value;

void setup() {
  // put your setup code here, to run once:  
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(5,51); //20%
  //analogWrite(5,128); //50%
  //analogWrite(5,191); //75%
}
