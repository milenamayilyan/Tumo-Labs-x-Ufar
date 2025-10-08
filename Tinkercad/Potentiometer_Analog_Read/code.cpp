void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
  int sensorValue = analogRead(A0); // Read the value from potentiometer (0-1023)
  Serial.println(sensorValue);      // Print the value to Serial Monitor
  delay(200);                       // Wait a little bit before reading again
}

