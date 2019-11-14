#include <Servo.h>
Servo myservo;
int pos;
const int X_PIN = A2;  // x
const int Y_PIN = A3;  // y 
int xPos = 0;
int yPos = 0;

void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  myservo.attach(9);
}

void loop()
{
  yPos = analogRead(Y_PIN);
  if (yPos <= 300){
    digitalWrite(4, HIGH);
      }else{
    digitalWrite(4,LOW);
  }
  xPos = analogRead(X_PIN);
  Serial.print("Y== ");
  Serial.print(yPos);
  Serial.print("  //  ");
  delay(2000);
  Serial.print("X== ");
  Serial.println(xPos);  
  delay(2000);
}

