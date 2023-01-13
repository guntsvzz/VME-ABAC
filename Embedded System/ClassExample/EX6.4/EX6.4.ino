
void setup()
{
Serial.begin(9600);
pinMode(9, OUTPUT);
}

void loop()

{
int Analog_Input_value1,Analog_Input_value2,percent;
Analog_Input_value1 = analogRead(A0);
Analog_Input_value2 = Analog_Input_value1/4; // From 1023 >> 255
percent = (Analog_Input_value2*100)/255;
analogWrite(9,Analog_Input_value2);//0-255
Serial.print("Blink PWM ");
Serial.print(percent);
Serial.println(" %");
}
