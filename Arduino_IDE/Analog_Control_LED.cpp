#define ledPin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("start again");
  for(int i=0; i<4096; i+=10){
    analogWrite(ledPin, i);
    Serial.println(i);
    delay(100);
  }
  Serial.println("done");
}
