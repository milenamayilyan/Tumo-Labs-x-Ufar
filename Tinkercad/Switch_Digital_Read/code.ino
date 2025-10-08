const int buttonPin = 2;
const int ledPin = 13;

int buttonState = HIGH;
int lastButtonState = HIGH;
int ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);
  }

  lastButtonState = buttonState;

  Serial.print("Button: ");
  Serial.print(buttonState == LOW ? 1 : 0); // 1 = pressed, 0 = not pressed
  Serial.print(" | LED: ");
  Serial.println(ledState == HIGH ? 1 : 0); // 1 = ON, 0 = OFF

  delay(100);
}
