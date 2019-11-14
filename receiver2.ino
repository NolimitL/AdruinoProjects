#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
    pinMode(13, OUTPUT);
    mySwitch.enableReceive(2);
}

void loop() {
    if( mySwitch.available() ){
        int value = mySwitch.getReceivedValue();
 
        if( value == B1000 )
            digitalWrite(13, HIGH);
        else if( value == B0100 )
            digitalWrite(13, LOW);
        mySwitch.resetAvailable();
    }
  mySwitch.resetAvailable();
}
