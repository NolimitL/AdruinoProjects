#include <VirtualWire.h>
const int tx_pin = 2; 
const int indicate_pin = 13; 
const int Y_PIN = A2;  
const int X_PIN = A3; 

void setup()
{
vw_set_tx_pin(tx_pin);
pinMode(indicate_pin, OUTPUT);
vw_setup(2000);
delay(500);
digitalWrite(indicate_pin, HIGH); 
delay(500);
digitalWrite(indicate_pin, LOW);
  pinMode(Y_PIN, INPUT);
  pinMode(X_PIN, INPUT);
}


void loop()
{
    if (analogRead(Y_PIN)<=1024 && analogRead(Y_PIN)>=690){
      send("a");
      delay(1000);
    }
    if (analogRead(Y_PIN)<=512 && analogRead(Y_PIN)>=0) {
      send("b");
      delay(1000);
    }
}
void send (char *message)
{
vw_send((uint8_t *)message, strlen(message));
vw_wait_tx(); 
}

