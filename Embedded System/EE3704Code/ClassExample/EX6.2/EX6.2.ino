int Analog_Input_value;

void setup() {
  // put your setup code here, to run once:  
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(9,51); //20%
  //analogWrite(9,128); //50%
  analogWrite(9,191); //75%
}
