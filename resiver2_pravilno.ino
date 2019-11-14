#include <VirtualWire.h>

  byte message[VW_MAX_MESSAGE_LEN]; //буфер для хранения данных
  byte messageLength = VW_MAX_MESSAGE_LEN; //размер сообщения
  const int receive_pin = 3; //пин ресивера
  const int pin3 = 13; //пины светодиода (не нужно =--)
  const int pin2 = 12;
  const int pin1 = 11;
  const int pin0 = 10;
  
void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  vw_set_rx_pin(receive_pin); //индификация пина ресивера
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_setup(2000); //скорость передачи данных
  vw_rx_start(); //активация приемника
}
void loop() {
  if (vw_get_message(message, &messageLength)){ //узнаем есть ли данные
    Serial.print("Received: "); //=--
      for (int i = 0; i < messageLength; i++) { 
        char c = message[i]; 
        Serial.print(c); 
          if(c == 'a') { 
            digitalWrite(pin0, HIGH);
            delay(50); 
          } 
          if(c == 'b') {
            digitalWrite(pin1, HIGH);
            delay(50);
          }
          if(c == 'c') { 
            digitalWrite(pin2, HIGH); 
            delay(50);
          } 
          if(c == 'd') { 
            digitalWrite(pin3, HIGH);
            delay(50);
          }
          if(c == 'n'){
            digitalWrite(pin0, LOW);
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, LOW);
          }
       } 
    Serial.println(); 
  } 
}

