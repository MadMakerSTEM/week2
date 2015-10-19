#include <Esplora.h>
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int red = 0;
  Serial.flush();
  while(!Serial.available()) ;
  if(Serial.available() > 0) {
    red = Serial.parseInt();
    Esplora.writeRed(red);
    Serial.print("Red: ");
    Serail.println(red);
  }
}
