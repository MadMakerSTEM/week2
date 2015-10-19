import processing.serial.*; // import the Serial library
 
String serial;
Serial port;
 
int red,green,blue;
 
void setup() {
  printArray(Serial.list());
  //String comPort = Serial.list()[0];    // should work on linux
  String comPort = Serial.list()[Serial.list().length-1];    // select the last, windows and mac
  try {
    port = new Serial(this, comPort, 9600);
  }
  catch (Exception e) {
    println("Exiting! Serial port error! Make sure you choose the correct one in the list above.");
    exit();
  }
  size(800, 600);
  fill(red,green,blue);
}
 
void draw() {
  while (port.available () > 0) {
    serial = port.readStringUntil('\n');
  }
  if (serial != null) {
    serial = trim(serial);
    String[] a = split(serial.substring(4), ',');    // ignore the RGB: at the beginning, and split the rest where there is a ,
    if (a.length >= 3) {
      red = int(a[0]);
      green = int(a[1]);
      blue = int(a[2]);
      println(a);
      background(red,green,blue);    // set background colour to the Esplora mixer
      // Text caption background
      stroke(0);    
      fill(0);
      rectMode(CENTER);
      rect(width/2,height/2+5,350,70);
      // Text caption to display RGB value of background colour
      textSize(40);
      textAlign(CENTER,CENTER);
      fill(255);
      translate(width/2, height/2);
      text(serial,0,0);
    }
    else {
      println("Problem detected! Did you upload the correct program onto your Esplora?");
      exit();
    }
  }
  else {
    println("Could not connect to Esplora! Make sure it is connected to the computer, and the correct port is selected!");
    exit();
  }
}
