#include <Esplora.h>
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int slider = Esplora.readSlider();    // read the slider and store it in slider
  Serial.print("The slider is: ");
  Serial.println(slider);               // print the value with a new line after it
  delay(500);
}
