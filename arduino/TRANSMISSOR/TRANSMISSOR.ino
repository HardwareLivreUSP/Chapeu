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
       int x = Serial.read();
       mySwitch.send(x, 24);
       Serial.println(x);
  }
}


