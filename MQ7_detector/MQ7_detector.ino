/*
Firmware for MQ7 detector
version 1.0
by oxygen
2017/03/18 
*/

#include <LiquidCrystal_I2C.h>

#define ReadAnalogPin A0
#define ReadDigitalPin 3
#define warning_pin 4
#define warningLED 5
#define Heating_time 200000
LiquidCrystal_I2C lcd(0x27, 16, 2);

void sensor_preheat()
{
    static int heat_start = millis();
    while(millis()-heat_start<Heating_time) 
    {
      lcd.print("Pre-Heating...");
      lcd.setCursor(0, 1);
      lcd.print(String((double)millis()/1000.0)+"/200");
      delay(1000);
      lcd.clear();
    }
    lcd.print("Finished");
    delay(700);
    lcd.clear();
} 

void setup() {
    pinMode(ReadDigitalPin,INPUT);
    pinMode(warning_pin,OUTPUT);
    pinMode(warningLED,OUTPUT);
    
    digitalWrite(warningLED,LOW);
    
    Serial.begin(9600);
    lcd.begin();
    
    lcd.backlight();
    sensor_heat();  //Pre-heating
}

void loop() 
{
    int valueAIN = analogRead(ReadAnalogPin);
    bool valueDIN = digitalRead(ReadDigitalPin);
    
    lcd.print("Current CO");
    lcd.setCursor(0, 1);
    lcd.print(valueAIN);
    
    while(valueDIN)
    {
        digitalWrite(warningLED,HIGH);
        tone(warning_pin, 1000, 1000);
        delay(2000); 
    }
    digitalWrite(warningLED,LOW);

    lcd.clear();
}

