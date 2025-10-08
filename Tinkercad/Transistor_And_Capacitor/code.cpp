// Pin definitions
const int switchPin = 2;      // Switch input
const int ledPin = 9;         // LED via transistor (PWM)

// Variables
int ledBrightness = 0;        // LED brightness (0-255)
const int fadeStep = 1;       // Amount to decrease per loop
const int fadeDelay = 10;     // Delay for smooth fading

void setup() {
  pinMode(switchPin, INPUT_PULLUP);  // Switch with internal pull-up
  pinMode(ledPin, OUTPUT);           // Transistor base control
}

void loop() {
  // Read switch state (LOW when pressed)
  bool switchPressed = (digitalRead(switchPin) == LOW);

  if (switchPressed) {
    // Switch pressed → LED fully on
    ledBrightness = 255;
    analogWrite(ledPin, ledBrightness);
  } 
  else {
    // Switch released → LED fades gradually
    if (ledBrightness > 0) {
      ledBrightness -= fadeStep;
      if (ledBrightness < 0) ledBrightness = 0; // prevent negative
      analogWrite(ledPin, ledBrightness);
      delay(fadeDelay);
    }
  }
}
