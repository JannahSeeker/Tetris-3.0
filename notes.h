/*To do add button interface
//fix rotation
//fix weird glitches and bugs

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // Send the command to the Slave Arduino
  Wire.beginTransmission(0x09); // Slave address is 0x09
  Wire.write("PrintHello");    // Send the command as a string
  Wire.endTransmission();
  delay(2000); // Wait for 2 seconds before sending the command again
}
*/