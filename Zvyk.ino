int z = 5;
int raz=0;
void setup() {
  pinMode(z, OUTPUT);
}

void loop() {
  for (raz=0; raz<=2; raz++){ 
    tone(z, 20);
    delay(100);
    tone(z, 60);
    delay(100);
    tone(z, 100);
    delay(100);
  }
  tone(z, 0);
}
