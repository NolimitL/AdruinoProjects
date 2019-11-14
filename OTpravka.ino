#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
const int Y_PIN = A2;  
const int X_PIN = A3; 

void setup() {
  mySwitch.enableTransmit(1);
  Serial.begin(9600);
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
}

void loop() {
  if (analogRead(Y_PIN)<=1024 && analogRead(Y_PIN)>=690) {
    mySwitch.send(B1000, 4);
  }
  if (analogRead(Y_PIN)<=512 && analogRead(Y_PIN)>=0) {
    mySwitch.send(B0100, 4);
  }
  
  if (analogRead(X_PIN)<=1024 && analogRead(X_PIN)>=690) {
    mySwitch.send(B0010, 4);
  }
  if (analogRead(X_PIN)<=512 && analogRead(X_PIN)>=0) {
    mySwitch.send(B0001, 4);
  }
}
