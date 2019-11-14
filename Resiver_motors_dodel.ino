#include <ServoTimer2.h>
#include <AFMotor.h>
#include <VirtualWire.h>

  byte message[VW_MAX_MESSAGE_LEN]; //буфер для хранения данных
  byte messageLength = VW_MAX_MESSAGE_LEN; //размер сообщения
  const int receive_pin = 2; //пин ресивера
  AF_DCMotor my_motorB1(3);
  AF_DCMotor my_motorB2(4);
  ServoTimer2 myservo;
  
void setup() {
  my_motorB1.setSpeed(250);
  my_motorB2.setSpeed(250);
  vw_set_rx_pin(receive_pin); //индификация пина ресивера
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_setup(4000); //скорость передачи данных
  vw_rx_start(); //активация приемника
  myservo.attach(9);
}
void loop() {
  if (vw_get_message(message, &messageLength)){ //узнаем есть ли данные
    Serial.print("Received: "); //=--
      for (int i = 0; i < messageLength; i++) { 
        char c = message[i]; 
          if(c == 'a') {
            Serial.print("frontgo"); 
            my_motorB1.run(FORWARD);
            my_motorB2.run(FORWARD);
          } 
          if(c == 'b') {
            Serial.print("back");
            my_motorB1.run(BACKWARD);
            my_motorB2.run(BACKWARD);
          }
          if(c == 'c') {
            Serial.print("right"); 
            myservo.write(1400);
          } 
          if(c == 'd') {
            Serial.print("left"); 
            myservo.write(1600);
          }
          if(c == 'n'){
            Serial.print(" stop and middle");
            my_motorB1.run(RELEASE);
            my_motorB2.run(RELEASE);
            myservo.write(1500);
          }
       } 
    Serial.println(); 
  }/*else{
    my_motorB1.run(RELEASE);
    my_motorB2.run(RELEASE);
    myservo.write(1500);
    }*/
}

