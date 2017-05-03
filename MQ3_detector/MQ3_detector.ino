/*
  Firmware for MQ3 alcohol detector
  Version 1.0
  By oxygen
  2017/03/18
*/
#include <LiquidCrystal_I2C.h>

#define ReadAnalogPin A0
#define ReadDigitalPin 3
#define Heating_time 300000
LiquidCrystal_I2C lcd(0x27, 16, 2);

void sensor_heat()
{
  static int heat_start = millis();
  while (millis() - heat_start < Heating_time)
  {
    lcd.print("Pre-Heating...");
    lcd.setCursor(0, 1);
    lcd.print(String((double)millis() / 1000.0) + "/200");
    delay(1000);
    lcd.clear();
  }
  lcd.print("Finished");
  delay(700);
  lcd.clear();
}

void setup() {
  pinMode(ReadDigitalPin, INPUT);
  Serial.begin(9600);
  lcd.begin();

  lcd.backlight();
  sensor_heat();  //Pre-heating
}

void loop()
{
  int valueAIN = analogRead(ReadAnalogPin);
  bool valueDIN = digitalRead(ReadDigitalPin); //不利用

  //lcd.setCursor(0, 0);
  lcd.print("Current Alcohol");
  lcd.setCursor(0, 1);
  lcd.print(valueAIN);

  delay(1000);
  lcd.clear();
}
