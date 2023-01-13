void setup() {
  // Quiz set 3
    Serial.begin(9600);
  for (char i=4;i<11;i++)
  {
    pinMode(i,OUTPUT);
  }
  for (char i=11;i<14;i++)
  {
    pinMode(i,INPUT);
  }
  pinMode(2,OUTPUT);
  pinMode(A0,INPUT);
}
int Analog_Input_Value;
int M;
bool DIP1;
bool DIP2;
bool DIP3;
int A[7]={0,1,0,0,1,0,1};
int B[7]={0,0,0,0,0,0,1};
int C[7]={0,0,1,0,0,1,1};
int ON[7]={1,1,1,1,1,1,1};
int OFF[7]={0,0,0,0,0,0,0};
void loop() {
  // put your main code here, to run repeatedly:
  Analog_Input_Value = analogRead(A0);
  switch(Analog_Input_Value){
    case 0 ... 205:
      M=1000;
    break;
    case 206 ... 410:
      M=2000;
    break;
    case 411 ... 615:
      M=3000;
    break;
    case 616 ... 820:
      M=4000;
    break;
    case 821 ... 1023:
      M=5000;
    break;
    default:
    break;
    }
    Serial.print("data = ");
    Serial.print(M/1000);
    Serial.println(" second");
    DIP1= digitalRead(11);
    DIP2= digitalRead(12);
    DIP3= digitalRead(13);
    if (DIP1 == 1 && DIP2 == 0 && DIP3 == 0)
  {
  digitalWrite(2,LOW);
  delay(2000); 
  digitalWrite(2,HIGH);
  delay(2000); 
  }
  else
  {
  if (DIP1 == 0 && DIP2 == 0 && DIP3 == 0)
  {
  digitalWrite(2,HIGH);
  for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,OFF[id]);
    }
  }
  else
  {
  if (DIP1 == 1 && DIP2 == 1 && DIP3 == 1)
  {
  digitalWrite(2,LOW);
  for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,ON[id]);
    }
  }
  else
  {
  digitalWrite(2,HIGH);
  for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,A[id]);
    }
    delay(M);
  for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,OFF[id]);
    }
    delay(500);
   for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,B[id]);
    }
    delay(M);
  for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,OFF[id]);
    }
    delay(500);
   for (char id=0;id<7;id++)
    {
      digitalWrite(id+4,C[id]);
    }
    delay(M);
  }
  }
  }
}
