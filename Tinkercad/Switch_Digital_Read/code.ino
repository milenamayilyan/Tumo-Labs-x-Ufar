const int buttonPin = 2;
const int ledPin = 13;

int lastButtonState = HIGH;
int ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int currentButtonState = digitalRead(buttonPin);

  // Detect button press (from HIGH → LOW)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.println(ledState);
    delay(50); // debounce
  }

  lastButtonState = currentButtonState;
}
