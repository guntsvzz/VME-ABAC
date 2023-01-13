void setup()
{
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(2),blink,FALLING);
}
void loop()
{
  pinMode(A0,INPUT);
  pinMode(2,INPUT);
  pinMode(4, OUTPUT);
  pinMode(12,OUTPUT);
  int X;
  for (char i=5; i<12; i++)
  {
    pinMode(i,OUTPUT); //CA
  }
   int number_09[10][7] ={{0,0,0,0,0,0,1},  //row0
                         {1,0,0,1,1,1,1},  //row1 
                         {0,0,1,0,0,1,0},  //row2 
                         {0,0,0,0,1,1,0},  //row3
                         {1,0,0,1,1,0,0},  //row4
                         {0,1,0,0,1,0,0},  //row5
                         {0,1,0,0,0,0,0},  //row6
                         {0,0,0,1,1,1,1},  //row7
                         {0,0,0,0,0,0,0},  //row8
                         {0,0,0,0,1,0,0},};//row9 //a,b,c,d,e,f,g
                         
  for (char row=0; row<10; row++)
  {
  for (char pin=5; pin<12; pin++)
  {
    digitalWrite(pin,number_09[row][pin-5]);
  }
  
  X=analogRead(A0);
  Serial.println(X);  
    if(X>400)
    {
    digitalWrite(12,HIGH);
    }
    else
    {
    digitalWrite(12,LOW);
    digitalWrite(12,HIGH);
    }
  delay(1000);
  }  
  
}

void blink()
{
  digitalWrite(4,HIGH);
  delay(200);
  digitalWrite(4,LOW);
}
