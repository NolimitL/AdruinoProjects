#include <VirtualWire.h>
const int tx_pin = 2; 
const int indicate_pin = 13;
const int X_PIN = 5; 
const int Y_PIN = 6; 

void setup() {
  vw_set_tx_pin(tx_pin);
  pinMode(indicate_pin, OUTPUT);
  vw_setup(2000);
  delay(500);
  digitalWrite(indicate_pin, HIGH); 
  delay(500);
  digitalWrite(indicate_pin, LOW);
  Serial.begin(9600);
}


void loop() {
  int yVal = analogRead(Y_PIN);
  int xVal = analogRead(X_PIN);

  Serial.print("y = ");
  Serial.print(yVal);
  Serial.print("   ");
  Serial.print("x = ");
  Serial.println(xVal);
  delay(400);
  
  if (yVal > 500) {
    send("a");
    Serial.println("a");
  }
  if (yVal < 490) {
    send("b");
    Serial.println("b");
  }
  if (xVal > 500) {
    send("c");
    Serial.println("c");
  }
  if (xVal < 490) {
    send("d");
    Serial.println("d");
  }
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); 
}
