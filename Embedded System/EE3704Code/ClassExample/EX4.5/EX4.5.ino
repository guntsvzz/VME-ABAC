void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  for(int pin=2; pin<6; pin++)
  {
  pinMode(pin,OUTPUT);
  }
  pinMode(11,INPUT);
  pinMode(10,OUTPUT);
  Serial.println("Welcome to Game Show");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool SW;
  SW = digitalRead(11);
  if(SW)
  {
    int number = random(2,6);
    Serial.print("Number is :");
    Serial.println(number);
    digitalWrite(number, LOW);
    digitalWrite(10, HIGH);
    dely(1000);
    digitalWrite(10, LOW);
    delay(2000);

  }
  else
  {
    for(int pin=2; pin<6; pin++)
    {
    digitalWrite(pin, LOW);  
    delay(10);
    digitalWrite(pin, HIGH);  
    delay(10);
    } 
  }   
}
  
