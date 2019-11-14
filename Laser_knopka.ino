int regim=1;
int flag=0;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
}

void loop() {
  if (digitalRead(4)==HIGH && flag==0) {
    regim++;
    flag=1;
    if (regim>2){
      regim=1;
    }
  }
  if (digitalRead(4)==LOW && flag==1) {
    flag=0;
  }
  if (regim==1) {
    digitalWrite(7, HIGH);
  }
  if (regim==2) {
    digitalWrite(7, LOW);
  }
}
