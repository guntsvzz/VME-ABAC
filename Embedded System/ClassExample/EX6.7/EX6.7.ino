
void setup()
{ 
pinMode(9, OUTPUT);  //R
pinMode(10, OUTPUT); //G
pinMode(11, OUTPUT); //B
}

void loop()
{
  //analogWrite(9,  255-228); //PINK
  //analogWrite(10, 255-67); 
  //analogWrite(11, 255-183); 
  analogWrite(9,  255-0);     //BLUE
  analogWrite(10, 255-108); 
  analogWrite(11, 255-255); 
}
