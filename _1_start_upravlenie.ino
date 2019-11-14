#include <RCSwitch.h> //подключил библиотеку радиомодуля
RCSwitch Trans = RCSwitch(); //ввел переменную для передатчика
int Pot_pin = 5; //ввел переменную для потенциометра
char *i; //ввел переменную аналогого пина для потенциометра 
char *a;

void setup() {
  Serial.begin(9600);
  Trans.enableTransmit (2); //включил передатчик на пине 2
}

void loop() {
    i = analogRead(5); //считываю с аналогого пина значение
    a = constrain(i, 1023, 180); //даем потенциометру допустимое значение
    Trans.send(i);
}
