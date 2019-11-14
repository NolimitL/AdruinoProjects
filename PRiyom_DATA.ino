#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
    Serial.begin(9600);
    mySwitch.enableReceive(0);
    pinMode(13, OUTPUT);
}

void loop() {
    if( mySwitch.available() ){
        int value = mySwitch.getReceivedValue();
 
        if( value == B1000 ){
            Serial.print("Y-High  ");
            digitalWrite(13, HIGH);
        }else{
          digitalWrite(13, LOW);
          }
        if( value == B0100 ){
            Serial.println("Y-Low  ");
            digitalWrite(13, HIGH);
        }else{
          digitalWrite(13, LOW);
          }
        
        if( value == B0010 ){
            Serial.print("X-High  ");
            digitalWrite(13, HIGH);
        }else{
          digitalWrite(13, LOW);
          }
        if( value == B0001 ){
            Serial.println("X-Low  ");
            digitalWrite(13, HIGH);
        }else{
          digitalWrite(13, LOW);
          }
        mySwitch.resetAvailable();
    }
}

/*
servo1.write(126);
servo1.write(95);
 servo1.write(110);
 */
