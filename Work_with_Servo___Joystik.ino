#include <Servo.h>
const int Y_PIN = A3;  
const int X_PIN = A2;
//const int tap = 4;
Servo turnservo;
int value;

void setup() {
  //delay(100);
  turnservo.attach(9);
  Serial.begin(9600);
  //pinMode(tap, OUTPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
}

void loop() {
  //digitalWrite(tap, HIGH);
  value = analogRead(Y_PIN);
  Serial.write(value);
  delay(100);
  if (analogRead(Y_PIN)<=1024 && analogRead(Y_PIN)>=690) { 
    turnservo.write(126);
  }else{
    turnservo.write(110);
  }
  if (analogRead(Y_PIN)<=512 && analogRead(Y_PIN)>=0) {
    turnservo.write(950);
  }else{
    turnservo.write(110);
  }
  /*
  if (analogRead(X_PIN)<=1024 && analogRead(X_PIN)>=690) {
    mySwitch.send(B0010, 4);
  }
  if (analogRead(X_PIN)<=512 && analogRead(X_PIN)>=0) {
    mySwitch.send(B0001, 4);
  }
  */
}
