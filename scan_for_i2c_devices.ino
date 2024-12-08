#include <Wire.h>

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bps
  Serial.println("Scanning I2C Devices...\n");

  byte count = 0; // Counter for the number of devices found
  Wire.begin();   // Initialize the I2C bus

  for (byte i = 8; i < 120; i++) { // Scan valid I2C addresses
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) { // Check if a device responds
      Serial.print("Found: 0x");
      Serial.println(i, HEX); // Print the device address in HEX
      count++; // Increment the device counter
    }
    delay(10); // Optional delay to prevent bus errors
  }

  Serial.println("\nDone.");
  if (count == 0) {
    Serial.println("No devices found.");
  } else {
    Serial.print(count);
    Serial.print(" device");
    if (count > 1) Serial.print("s");
    Serial.println(" found.");
  }
}

void loop() {
  // No repeated tasks in the loop
}

