#include <AFMotor.h>
#include <Servo.h>
Servo servo1;
 
int y = 0;

void setup()
{
  servo1.attach(9);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0){
    y = Serial.read();
  }
    servo1.write(y);
}

