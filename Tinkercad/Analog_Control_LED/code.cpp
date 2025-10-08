#define ledPin 9  

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Fade in
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10); // wait a bit
  }

  // Fade out
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
}

