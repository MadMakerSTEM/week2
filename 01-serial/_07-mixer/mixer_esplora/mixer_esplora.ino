#include <Esplora.h>
 
// start off with no value
int red = 0;
int green = 0;
int blue = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() { //Main loop
  showColour();
  printColour(); //Output these values to USB serial for other programs to interpret
}
 
void printColour(){ //prints the colour stored to the Serial Monitor
  Serial.print("RGB:");
  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.println(blue);
}
 
void showColour(){
    int sliderPosition = Esplora.readSlider();
    byte brightness = map(sliderPosition, 0, 1024, 0, 256); //rescale the slider's value to the range of the LEDs.
      if (Esplora.readButton(SWITCH_DOWN) == LOW) {
        red = brightness;
      }
      else if(Esplora.readButton(SWITCH_LEFT) == LOW){
        green = brightness;
      }
      else if(Esplora.readButton(SWITCH_UP) == LOW){
        blue = brightness;
      }
    Esplora.writeRGB(red,green,blue);
}
