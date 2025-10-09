const int analogPin = A0;   // Analog input pin
const int ledPin = 13;       // PWM-capable digital pin for LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int analogValue = analogRead(analogPin);  // Read analog input (0–1023)

  // Map analog value (0–1023) to PWM value (0–255)
  int ledBrightness = map(analogValue, 0, 1023, 0, 255);

  // Set LED brightness
  analogWrite(ledPin, ledBrightness);

  delay(100);  // Small delay for stability
}
