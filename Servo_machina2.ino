#include <AFMotor.h>
#include <Servo.h>
Servo myservo;
int regim=1;
int stateB=0;

void setup() {  
  myservo.attach(9);
  pinMode(2, INPUT);
}

void loop() {
   if (digitalRead(2)==HIGH && stateB == 0){
    regim++;
    stateB=1;
    if (regim>3){
      regim = 1;
    }
  }
  if (digitalRead(2)==LOW && stateB == 1){
    stateB = 0;
  }
  if (regim==1) {
    myservo.write(95);
  }
  if (regim==2) {
    myservo.write(110);
  }
  if (regim==3) {
    myservo.write(126);
  }
}

