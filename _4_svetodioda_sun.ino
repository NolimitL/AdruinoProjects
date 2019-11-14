int startlight = 0; // начальная яркость
int lightup = 5; // шаг приращения или убывания яркости
int Red_pin1 = 5;
int Red_pin2 = 6;
int Red_pin3 = 9;
int Red_pin4 = 10;
int stateB = 0;
int regim = 1;

void setup() {
  pinMode(Red_pin1, OUTPUT);
  pinMode(Red_pin2, OUTPUT);
  pinMode(Red_pin3, OUTPUT);
  pinMode(Red_pin4, OUTPUT);
  pinMode(4, INPUT);
}

void loop() {
  if (digitalRead(4)==HIGH && stateB == 0){
    regim++;
    stateB=1;
    if (regim>2){
      regim = 1;
    }
  }
  if (digitalRead(4)==LOW && stateB == 1){
    stateB = 0;
  }
  if (regim==1) {
    analogWrite(9, startlight);
    delay(50);
    analogWrite(10, startlight);
    delay(10);
    analogWrite(5, startlight);
    delay(20);
    analogWrite(6, startlight);
    startlight = lightup + startlight;
    for (, startlight < 255, startlight++) {
      analogWrite(9, startlight);
      delay(10);
    } 
  }
  if (regim==2) {
   digitalWrite(10, LOW); 
   digitalWrite(9, LOW);
   digitalWrite(6, LOW);
   digitalWrite(5, LOW);
  }
}
