

void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  delay(300);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(3, LOW);
  delay(300);
  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
}
