#include "thingProperties.h"

const int ledPin = 2;
const int pwmPin = 23;   // Analog (PWM) LED
const int ldrPin = 34;

void setup() {
  Serial.begin(9600);
  delay(1500); 
  pinMode(ledPin, OUTPUT);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  int lightValue = analogRead(ldrPin);  // 0–4095
  lightSensor = lightValue;

  Serial.print("LDR value: ");
  Serial.println(lightValue);

  delay(200); 
}

void onLEDChange()  {
  if (lED) {
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    Serial.println("LED turned ON from Arduino Cloud");
  } else {
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    Serial.println("LED turned OFF from Arduino Cloud");
  }
}

void onLED2Change()  {
  lED2 = constrain(lED2, 0, 255);
  analogWrite(pwmPin, lED2);
  Serial.print("Analog LED2 brightness set to: ");
  Serial.println(lED2);
}
void onLightSensorChange()  {
  // Add your code here to act upon LightSensor change
}
