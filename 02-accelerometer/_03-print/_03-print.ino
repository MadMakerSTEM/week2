#include <Esplora.h>
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int xAxis = Esplora.readAccelerometer(X_AXIS);
  Serial.print(xAxis);
  Serial.print(',');
  Serial.println();
  delay(500);
}
