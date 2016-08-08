import ddf.minim.*;
import processing.serial.*;

AudioPlayer player;
Minim minim;//audio context

Serial myPort; 

void setup(){
  
  printArray(Serial.list());
  myPort = new Serial(this, "/dev/tty.usbmodem1411", 9600);
  
}

void draw(){
}

void boca(int led, int abre, int fecha, int tempo){
  myPort.write(0x20);
  myPort.write(abre);
  myPort.write(fecha);
  myPort.write(tempo/10);
  //myPort.write(led);
}

void keyPressed() {
  if (key == '1') {
      minim = new Minim(this);
      player = minim.loadFile("griffindor.wav", 2048);
      player.play();
      myPort.write(3);
  } else if (key == '2') {
      minim = new Minim(this);
      player = minim.loadFile("hufflepuff.wav", 2048);
      player.play();
      myPort.write(3);
  } else if (key == '3') {
      minim = new Minim(this);
      player = minim.loadFile("ravenclaw.wav", 2048);
      player.play();
      myPort.write(3);
  } else if (key == '4') {
      minim = new Minim(this);
      player = minim.loadFile("slitheryn.wav", 2048);
      player.play();
      myPort.write(2);
  }
}
