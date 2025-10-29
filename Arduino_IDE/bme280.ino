#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);
  if (!bme.begin(0x76)) {  // Try 0x77 if 0x76 doesn't work
    Serial.println("Could not find a valid BME280 sensor!");
    while (1);
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F); // hPa
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(1013.25)); // sea level pressure in hPa
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
