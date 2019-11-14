#include <Servo.h>
Servo myservo;

int Lup = 0; // шаг приращение или убывание угла
int Lup2 = 90;
int Red_pin1 = 3;
int Red_pin2 = 4;
int Red_pin3 = 5;
int Red_pin4 = 6;
int regim=1;
int stateB=0;

void setup() {
  pinMode(2, INPUT);
  pinMode(Red_pin1, OUTPUT);
  pinMode(Red_pin2, OUTPUT);
  pinMode(Red_pin3, OUTPUT);
  pinMode(Red_pin4, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  myservo.write(0);
  //digitalWrite(3, LOW);
  //digitalWrite(3, LOW);
  //digitalWrite(3, LOW);
  //digitalWrite(3, LOW);
  
  if (digitalRead(2)==HIGH && stateB == 0){
    regim++;
    stateB=1;
    if (regim>8){
      regim = 1;
    }
  }
  if (digitalRead(2)==LOW && stateB == 1){
    stateB = 0;
  }
  if (regim==1){
    delay(10);
    digitalWrite(Red_pin1, HIGH);
    Serial.print("sv 1");
  }
  if (regim==2){
    delay(10);
    digitalWrite(Red_pin1, LOW);
    digitalWrite(Red_pin2, HIGH);
    Serial.print("sv 2");
  } 
  if (regim==3){
    delay(10);
    digitalWrite(Red_pin2, LOW);
    digitalWrite(Red_pin3, HIGH);
    Serial.print("sv 3");
  }
  if (regim==4){
    delay(100);
    for (Lup == 0; Lup<=90; Lup + 1){
      myservo.write(Lup);
      Serial.println(Lup);
      delay(10);
    }
  }
  if (regim==5){
    delay(100);
    digitalWrite(Red_pin3, LOW);
    digitalWrite(Red_pin4, HIGH);
    for (Lup2 == 90; Lup2>0; Lup2 - 1){
      myservo.write(Lup2);
      Serial.println(Lup2);
      delay(10);
    }
  }
  if (regim==6){
    delay(10);
    digitalWrite(Red_pin4, LOW);
     Serial.print("sv 4"); 
  }
  if (regim==7){
    delay(10);
    digitalWrite(Red_pin1, HIGH);
    digitalWrite(Red_pin2, HIGH);
    digitalWrite(Red_pin3, HIGH);
    digitalWrite(Red_pin4, HIGH); 
    Serial.print("alles");
  }
  if (regim==8){
    delay(10);
    digitalWrite(Red_pin1, LOW);
    digitalWrite(Red_pin2, LOW);
    digitalWrite(Red_pin3, LOW);
    digitalWrite(Red_pin4, LOW); 
    Serial.print("aggg");
  }
}
