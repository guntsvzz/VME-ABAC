void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD &=~(0x0c);  //Declare as Input
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int Data = (PIND)>>2 ; //as Pin 0 and Pin 1 doing communication
  Serial.print(" DIP SW data is : ");
  Serial.println(Data);
  delay(1000);
 
}
