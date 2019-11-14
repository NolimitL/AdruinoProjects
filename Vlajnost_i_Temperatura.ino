#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHT_Pin 3
DHT dht(DHT_Pin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    if(isnan(h) || isnan(t)){
    Serial.println("Не удается считать данные");
    return;
  }else{
   Serial.print("Humidity= ");
   Serial.print(h);
   Serial.println("%");
   Serial.print("Temperature= ");
   Serial.print(t);
   Serial.println(" C");
   }
}
