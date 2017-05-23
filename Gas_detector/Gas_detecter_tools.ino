//等候感測器預熱300秒
void sensor_heat()
{
  static int heat_start = millis();
  while (millis() - heat_start < Heating_time)
  {
    if (_SerialRead() == "GET") //預熱中如收到請求，回傳預熱剩餘時間
    {
      Serial.print("H," + String((double)millis() / 1000.0));
    }
    delay(1000);
  }
  delay(700);
  Serial.print("OK"); //主動傳送準備完成訊號
}

//接收序列埠資料
String _SerialRead()
{
  String backstr = "";
  while (Serial.available())
  {
    backstr += Serial.read();
  }
  return backstr;
}

//一氧化碳警報
void COalart(const int CO_value)
{
  const int CO_limit = 700;

  //如一氧化碳過量，啟動蜂鳴器並傳送高電位給警示燈
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
    digitalWrite(AlartLEDC, HIGH);
    Serial.print("COALART");
  }
  else
  {
    digitalWrite(AlartLEDC, LOW);
  }
}

//酒精過量警報
void AlcholAlart(int Alcholvalue)
{
  const int Alchol_limit = 400;
  if ( Alcholvalue > Alchol_limit)
  {
    Serial.print("ALCHOLALART");
    digitalWrite(AlartLEDA, HIGH);
  }
  else
  {
    digitalWrite(AlartLEDA, LOW);
  }
}
