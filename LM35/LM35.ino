const uint8_t LM35pin = A5;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println(analogRead(LM35pin));
  Serial.println((125*analogRead(LM35pin))>>8);
  delay(1000);
}

