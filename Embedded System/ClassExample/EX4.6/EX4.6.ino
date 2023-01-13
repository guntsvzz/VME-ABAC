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
    int number = random(0,100);
    Serial.print("The number is : ");
    Serial.println(number);
   
    switch(number)
    {
    case 0 ... 70 :
      Serial.println("pin1");
      digitalWrite(10, HIGH);
      digitalWrite(2, LOW);
      delay(1000);
      digitalWrite(2, HIGH);   
      delay(2000);
      digitalWrite(10, LOW);
      break;
    case 71 ... 85 :
      Serial.println("pin2");      
      digitalWrite(3, LOW);
      delay(1000);
      digitalWrite(3, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      break;  
    case 86 ... 98 :
      Serial.println("pin3"); 
      digitalWrite(10, HIGH);
      digitalWrite(4, LOW);
      delay(1000);
      digitalWrite(4, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      break;
    case 99 ... 100 :
      Serial.println("pin4"); 
      digitalWrite(10, HIGH);
      digitalWrite(5, LOW);
      delay(1000);
      digitalWrite(5, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      break;  
    } 
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
  
