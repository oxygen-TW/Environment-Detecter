/*
  Firmware for Gsa detector
  Version 1.0
  By oxygen
  2017/05/22
*/

#define MQ3ReadAnalogPin A0
#define MQ3ReadDigitalPin 3

#define MQ7ReadAnalogPin A1
#define MQ7ReadDigitalPin 4

#define buzzer 6
#define AlartLEDA 8
#define AlartLEDC 9
#define Heating_time 300000

void sensor_heat()
{
  static int heat_start = millis();
  while (millis() - heat_start < Heating_time)
  {
    if (_SerialRead() == "GET")
    {
      Serial.print("H," + String((double)millis() / 1000.0));
    }
    delay(1000);
  }
  delay(700);
  Serial.print("OK");
}

String _SerialRead()
{
  String backstr = "";
  while (Serial.available())
  {
    backstr += Serial.read();
  }
  return backstr;
}

void COalart(int CO_value)
{
  const int CO_limit = 700;
  if (CO_value > CO_limit)
  {
    for ( int i = 0; i < 10; i++ )
    {
      tone(buzzer, 1000);
      delay(50);
      tone(buzzer, 500);
      delay(50);
    }
    noTone(buzzer);
  }
  Serial.print("COALART");
  AlartLED(AlartLEDC);
}

void AlcholAlart(int Alcholvalue)
{
  const int Alchol_limit = 400;
  if ( Alcholvalue > Alchol_limit)
  {
    Serial.print("ALCHOLALART");
    AlartLED(AlartLEDA);
  }
}

void AlartLED(const int pin)
{
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
}
void setup() {
  pinMode(MQ3ReadDigitalPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(AlartLEDA, OUTPUT);
  pinMode(AlartLEDC, OUTPUT);
  Serial.begin(9600);
  sensor_heat();  //Pre-heating
}

void loop()
{
  int MQ3valueAIN = analogRead(MQ3ReadAnalogPin);
  bool MQ3valueDIN = digitalRead(MQ3ReadDigitalPin); //不利用
  int MQ7valueAIN = analogRead(MQ7ReadAnalogPin);
  bool MQ7valueDIN = digitalRead(MQ7ReadDigitalPin); //不利用

  if (_SerialRead() == "MQ3")
    Serial.print(MQ3valueAIN);
  else if (_SerialRead() == "MQ7")
    Serial.print(MQ7valueAIN);

  COalart(MQ7valueAIN);
  delay(1000);
}
