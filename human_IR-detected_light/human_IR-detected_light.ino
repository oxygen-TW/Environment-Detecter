/*
   接腳定義
   繼電器 數位2
   人體紅外線感測器 數位4
   Vcc = 5V
   Gnd = 0V
*/
const int BaulRate = 9600;
const int sensor = 4;
const int relay = 2; //繼電器
bool led = false;
int Value = 0;


void setup() {
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  Value = digitalRead(sensor);

  if (Value == HIGH)
  {
     Serial.println("true");
     
    if (led == false)
    {
      digitalWrite(relay, HIGH);
      led = true;
    }
   delay(10000);
  }
  else if (Value == LOW)
  {
    Serial.println("false");
    if (led == true)
    {
      digitalWrite(relay, LOW);
      led = false;
    }
    delay(10);
  }
}
