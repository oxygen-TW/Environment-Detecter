#define readpin 7

void setup()
{
  pinMode(readpin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(readpin) == HIGH){
    Serial.println("Low magnetic");
  }
  else{
    Serial.println("High magnetic");
  }
  delay(1000);
}

