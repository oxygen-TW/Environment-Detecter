//Oxygen studio designed
//include LCD I2C funtion
//support PC test
//using LED

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define PL 9
#define L 8
#define M1 7
#define M2 5
#define H 3
#define PH 2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();

  pinMode(L, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(PH, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(H, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = 0;
  lcd.clear();

  data = analogRead(A0);//read data
  Serial.println(data);
  lcd.print(data);

  if (data >= 1000)
  {
    digitalWrite(PL, HIGH);
    digitalWrite(L, LOW);
    digitalWrite(M1, LOW);
     digitalWrite(M2, LOW);
    digitalWrite(H, LOW);
    digitalWrite(PH, LOW);
  }
  else if (data < 1000 && data >=850)
  {
    digitalWrite(PL, LOW);
    digitalWrite(L, HIGH);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(H, LOW);
    digitalWrite(PH, LOW);
  }
  else if (data > 700  && data < 850)
  {
    digitalWrite(PL, LOW);
    digitalWrite(L, LOW);
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(H, LOW);
    digitalWrite(PH, LOW);
  } 
  else if (data > 500 && data <= 700)
  {
    digitalWrite(PL, LOW);
    digitalWrite(L, LOW);
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(H, LOW);
    digitalWrite(PH, LOW);
  }
  else if (data > 300 && data <= 500)
  {
    digitalWrite(PL, LOW);
    digitalWrite(L, LOW);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(H, HIGH);
    digitalWrite(PH, LOW);
  }
  else if (data > 0 && data <= 300)
  {
    digitalWrite(PL, LOW);
    digitalWrite(L, LOW);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(H, LOW);
    digitalWrite(PH, HIGH);
  }
 delay(500);
}
