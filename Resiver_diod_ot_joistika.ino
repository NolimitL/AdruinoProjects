#include <Servo.h>
#include <AFMotor.h>
#include <VirtualWire.h>

  byte message[VW_MAX_MESSAGE_LEN]; //буфер для хранения данных
  byte messageLength = VW_MAX_MESSAGE_LEN; //размер сообщения
  const int receive_pin = 3; //пин ресивера
  const int pin3 = 13; //пины светодиода (не нужно =--)
  const int pin2 = 12;
  const int pin1 = 11;
  const int pin0 = 10;
  AF_DCMotor my_motor4(4);
  AF_DCMotor my_motor3(3);
  
void set_speed(int speed){ // функция СКОРОСТЬ
  my_motor3.setSpeed(speed);
  my_motor4.setSpeed(speed);
}
void motor_forward(){ // функция ПЕРЕДНИЙ ХОД
  my_motor3.run(FORWARD);
  my_motor4.run(FORWARD);
}
 
void motor_backward(){ // функция ЗАДНИЙ ХОД
  my_motor3.run(BACKWARD);
  my_motor4.run(BACKWARD);
}
 
void motor_release(){ // функция ОСТАНОВКА ДВИГАТЕЛЕЙ
  my_motor3.run(RELEASE);
  my_motor4.run(RELEASE);
}
  
void setup() {
  set_speed(250);
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
             motor_forward();
          } 
          if(c == 'b') {
             motor_backward();
          }
          if(c == 'c') { 
            
          } 
          if(c == 'd') { 
            
          }
          if(c == 'n'){
            motor_release();
          }
       } 
    Serial.println(); 
  } 
}

