#include <DHT.h>
#include <pms.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define SensorDelayTime 5000
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address.
PmsAltSerial pmsSerial;
pmsx::Pms pms(&pmsSerial);
DHT dht(DHTPIN, DHTTYPE);

void setup(void)
{
  Serial.begin(9600);
  lcd.init();
  dht.begin();

  pmsSelfCheck();
  Serial.println(pmsx::pmsxApiVersion);
}

void loop(void)
{
  static auto lastRead = millis();

  pmsx::PmsData data;
  auto status = pms.read(data);

  /*float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature = ");
  Serial.println(t);
  Serial.print("Humidity = ");
  Serial.println(h); */
  
  switch (status) {
    case pmsx::PmsStatus::OK: {
        Serial.println("_________________");
        const auto newRead = millis();
        Serial.print("Wait time ");
        Serial.println(newRead - lastRead);
        lastRead = newRead;

        auto view = data.raw;
        for (pmsx::PmsData::pmsIdx_t i = 0; i < view.getSize(); ++i) {
          Serial.print(view.getValue(i));
          Serial.print("\t");
          Serial.print(view.getName(i));
          Serial.print(" [");
          Serial.print(view.getMetric(i));
          Serial.print("] ");
          //            Serial.print(" Level: ");
          //            Serial.print(view.getLevel(i));
          Serial.print(" | diameter: ");
          Serial.print(view.getDiameter(i));
          Serial.println();
        }
        break;
      }
    case pmsx::PmsStatus::NO_DATA:
      break;
    default:
      Serial.print("!!! Pms error: ");
      Serial.println(status.getErrorMsg());
  }

  //delay(SensorDelayTime);
}

