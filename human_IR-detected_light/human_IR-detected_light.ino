
int sensor = 4;
int sw = 7;
int relay = 2; //繼電器
bool led = false;
int Value = 0;

bool sw_chk()
{
  if (digitalRead(sw) == HIGH)
    return true;
  else
    return false;
}

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT); 
  pinMode(sw, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  Value = digitalRead(sensor);
  Serial.println(Value);

  if (Value == HIGH || sw_chk())
  {
    if (led == false)
    {
      digitalWrite(relay, HIGH);
      led = true;
      delay(10000);
    }
  }
  else if (Value == LOW)
  {
    if (led == true)
    {
      digitalWrite(relay, LOW);
      led = false;
    }
  }
}
