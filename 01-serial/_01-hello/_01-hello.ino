void setup() {
  Serial.begin(9600);              // Start serial communication to the computer at 9600 bits per second
}
 
void loop() {
  Serial.println("Hello world!");  // Print hello world, ending with a new line
  delay(1000);
}
