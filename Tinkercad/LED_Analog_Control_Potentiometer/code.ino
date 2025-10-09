const int potPin = A0;   // Analog input from potentiometer
const int ledPin = 9;    // LED output (PWM)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);    // Start serial communication
}

void loop() {
  int potValue = analogRead(potPin);                    // Read 0–1023
  int ledBrightness = map(potValue, 0, 1023, 0, 255);  // Map to PWM 0–255

  analogWrite(ledPin, ledBrightness);                  // Set LED brightness
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print("  |  LED brightness: ");
  Serial.println(ledBrightness);

  delay(100);  // Small delay for stability
}
