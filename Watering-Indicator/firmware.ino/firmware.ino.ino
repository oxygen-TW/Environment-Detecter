/*
 * PLEASE Change this selection to
 * your situation.
 */
#define LED_PIN 2
#define SENSOR_PIN A0
#define WATER_HIGH_VALUE 200
#define WATER_LOW_VALUE 1000

/*
 * DO NOT EDIT BELOW!
 */
bool Status = false;
   
void changeLEDStatus(bool Status){
  digitalWrite(LED_PIN,Status);
}

void LEDBlink(bool Status){
  digitalWrite(LED_PIN,~Status);
  delay(500);
  digitalWrite(LED_PIN,Status);
  delay(500);
}

int CheckMoisture(int moisture){
  if(moisture >= WATER_LOW_VALUE){ //Too low; code = -1
    digitalWrite(LED_PIN,HIGH);
    return -1;
  }
  else if(moisture <= WATER_HIGH_VALUE){ //Too high; code = -1
    LEDBlink(Status);
    return 1;
  }
  else{ //Normal; code = 0
    digitalWrite(LED_PIN,LOW);
    return 0; 
  }
}

void setup() {
  //Initialize
  Status = false;

  //Self-check LED
  digitalWrite(LED_PIN,HIGH);
  delay(250);
  digitalWrite(LED_PIN,LOW);

  //Self-check Value
  CheckMoisture(WATER_LOW_VALUE + 1);
  delay(250);
  CheckMoisture(WATER_HIGH_VALUE - 1);

  //Finished singal
  digitalWrite(LED_PIN,HIGH);
  delay(100);
  digitalWrite(LED_PIN,LOW);
  delay(100);
  digitalWrite(LED_PIN,HIGH);
  delay(100);
  digitalWrite(LED_PIN,LOW);
  delay(100);
}

void loop() {
  CheckMoisture(analogRead(SENSOR_PIN));
}
