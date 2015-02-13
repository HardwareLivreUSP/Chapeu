#include <Servo.h> 
#include <RCSwitch.h>

#define ENABLE_Sniffer true


RCSwitch mySwitch = RCSwitch();  // Create an instance of RCSwitch

Servo panServo;  // create servo objects to control our servos

int tilt = 180;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); 
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  panServo.attach(9);  // attaches the servo on pin 9 to the servo object 
  panServo.write(178); 
}

void loop() {

  if (mySwitch.available()) {

    long value = mySwitch.getReceivedValue();

    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    else {

      if (ENABLE_Sniffer) {
        Serial.print("Received ");
        Serial.print( value );
        Serial.print(" / ");
        Serial.print( mySwitch.getReceivedBitlength() );
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println( mySwitch.getReceivedProtocol() );

      }

      tilt = value;

      for(int i=0; i < tilt; i++){
        panServo.write(160);
        delay(200);
        panServo.write(176); 
        delay(200);
      }


    }
    mySwitch.resetAvailable();
  }


}

