#include <VirtualWire.h>
const int tx_pin = 2; 
const int indicate_pin = 13;
const int X_PIN = 5; 
const int Y_PIN = 6;
const int BUTTON_PIN = 4;

void setup() {
  vw_set_tx_pin(tx_pin);
  pinMode(indicate_pin, OUTPUT);
  vw_setup(4000);
  delay(100);
  digitalWrite(indicate_pin, HIGH); 
  delay(100);
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

 
  if (yVal > 550) {
    send("a");
    Serial.println("frontgo");
  }
  if (yVal < 450) {
    send("b");
    Serial.println("back");
  }
  if (xVal > 550) {
    send("c");
    Serial.println("right");
  }
  if (xVal < 450) {
    send("d");
    Serial.println("left");
  }
  if (xVal > 450 && xVal < 550 && yVal < 550 && yVal > 450){
    send("n");
    Serial.println("null");
  }
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); 
}
