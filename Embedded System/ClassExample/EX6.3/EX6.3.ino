void setup()

{
  Serial.begin(9600);
  for(int a=8;a<12;a++)
  {
  pinMode(a, INPUT);
  }
  pinMode(3, OUTPUT);
  }

void loop()

{
  bool SW1 = digitalRead(8);
  bool SW2 = digitalRead(9);
  bool SW3 = digitalRead(10);
  bool SW4 = digitalRead(11);
  if(SW1==1 && SW2==0 && SW3==0 && SW4==0){
  analogWrite(3,64); //25%
  Serial.print("SW1:");
  Serial.println(" Blink PWM 25%");
  }
  else if(SW1==0 && SW2==1 && SW3==0 && SW4==0){
  analogWrite(3,128); //50%
  Serial.print("SW2:");
  Serial.println(" Blink PWM 50%");
  }
  else if(SW1==0 && SW2==0 && SW3==1 && SW4==0){
  analogWrite(3,191); //75%
  Serial.print("SW3:");
  Serial.println(" Blink PWM 75%");
  }
  else if(SW1==0 && SW2==0 && SW3==0 && SW4==1)
  
  {
  analogWrite(3,255); //100%
  Serial.print("SW4:");
  Serial.println(" Blink PWM 100%");
  }
  else
  {
  analogWrite(3,0);
  }
  delay(100);
  }
