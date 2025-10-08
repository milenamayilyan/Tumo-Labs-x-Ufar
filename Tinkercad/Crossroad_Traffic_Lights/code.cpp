#define red_green 2
#define green_red 3
#define orange 4

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(red_green, LOW);  // red_green off
  digitalWrite(green_red, HIGH); // green_red on
  digitalWrite(orange, LOW);     // orange off
  delay(25000);                  // green_red on for 25s

  digitalWrite(orange, HIGH);    // orange on
  delay(5000);                   // orange and green_red on tgthr for 5s
  digitalWrite(orange, LOW);     // orange off
  digitalWrite(green_red, LOW);  // green_red off

  digitalWrite(red_green, HIGH); // red_green on
  delay(25000);                  // red_green on for 25s
  
  digitalWrite(orange, HIGH);    // orange on
  delay(5000);                   // orange and red_green on tghtr for street 2
  digitalWrite(orange, LOW);     // orange off
}

