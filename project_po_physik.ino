int startlight = 0; // начальная яркость
int lightup = 10; // шаг приращения или убывания яркости
int Red_pin1 = 5;
int Red_pin2 = 6;
int Red_pin3 = 9;
int Red_pin4 = 10;
int Relay_pin = 3;
int stateB = 0;
int regim = 1;

void setup() {
  pinMode(Red_pin1, OUTPUT);
  pinMode(Red_pin2, OUTPUT);
  pinMode(Red_pin3, OUTPUT);
  pinMode(Red_pin4, OUTPUT);
  pinMode(Relay_pin, OUTPUT);
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
  if (regim==1){
    analogWrite(9, startlight);
    startlight = lightup + startlight;
    if (startlight == 250 || startlight == 0) {
      delay(100);
      lightup = -lightup;
    }
    delay(70);
    analogWrite(10, startlight);
    startlight = lightup + startlight;
    if (startlight == 250 || startlight == 0) {
      delay(100);
      lightup = -lightup;
    }
    delay(200);
    analogWrite(5, startlight);
    startlight = lightup + startlight;
    if (startlight == 250 || startlight == 0) {
      delay(100);
      lightup = -lightup;
    }
    delay(100);
    analogWrite(6, startlight);
    startlight = lightup + startlight;
    if (startlight == 250 || startlight == 0) {
      delay(100);
      lightup = -lightup;
    }
    digitalWrite(3, HIGH);
  }
  if (regim==2){
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(3, LOW);
  }
}
