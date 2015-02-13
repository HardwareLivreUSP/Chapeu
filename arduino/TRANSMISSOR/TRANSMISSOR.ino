#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  // Selecio o pino 10
  mySwitch.enableTransmit(10);
  Serial.begin(9600);
}

void loop(){
  // Aguardo o serial
  while(Serial.available()){
       mySwitch.send(Serial.read(), 24);
  }
}


