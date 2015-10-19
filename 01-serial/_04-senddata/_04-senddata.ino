int multiply = 5;
 
void setup() {
  Serial.begin(9600);           // initialise serial communication
}
 
void loop() {
  int val = 0;
  Serial.flush();               // clear serial port
  while(!Serial.available()) ;  // wait for a serial event
  if(Serial.available() > 0) {
    val = Serial.parseInt();    // convert serial data to an integer
  }
  Serial.print("The value is: ");
  Serial.println(val);
}
