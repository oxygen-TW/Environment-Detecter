/*
  Firmware for Gsa detector
  Version 1.1
  By oxygen
  2017/05/22
*/

//接角與參數定義
#define MQ3ReadAnalogPin A0
#define MQ3ReadDigitalPin 3

#define MQ7ReadAnalogPin A1
#define MQ7ReadDigitalPin 4

#define buzzer 6
#define AlartLEDA 8
#define AlartLEDC 9
#define Heating_time 300000

//函式宣告
void sensor_heat(void); //開始預熱
String _SerialRead(void); //接收序列埠資料
void COalart(const int);  //一氧化碳警報
void AlcholAlart(const int);  //酒精過量警報

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
  //bool MQ3valueDIN = digitalRead(MQ3ReadDigitalPin); //不利用
  int MQ7valueAIN = analogRead(MQ7ReadAnalogPin);
  //bool MQ7valueDIN = digitalRead(MQ7ReadDigitalPin); //不利用

  //接收並處理主機請求
  if (_SerialRead() == "MQ3")
    Serial.print(MQ3valueAIN);
  else if (_SerialRead() == "MQ7")
    Serial.print(MQ7valueAIN);

  //檢查氣體狀態
  COalart(MQ7valueAIN);
  AlcholAlart(MQ3valueAIN);
  delay(1000);
}
