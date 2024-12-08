Interfacing I2C LCD with Arduino
True to their name, these LCDs are ideal for displaying only text/characters.
A 16×2 character LCD, for example, has an LED backlight and can display 32 ASCII characters in two rows of 16 characters each.

Step 1: Wiring Diagram


Step 2: Library Installation
To drive an I2C LCD we must first install a library called LiquidCrystal_I2C. This library is an enhanced version of the LiquidCrystal library that comes with the Arduino IDE.

To install the library, let's navigate to Sketch > Include Libraries > Manage Libraries… 
Let's then wait for the Library Manager to download the library index and update the list of installed libraries.

Filter your search by typing ‘liquidcrystal‘. Look for the LiquidCrystal I2C library by Frank de Brabander and then select Install.

Step 3: Determining the I2C Address
The easy way to find out the I2C address of the LCD is using the code of Nick Gammon.
Nick wrote the code that scans your I2C bus and returns the address of each I2C device it finds.

Below is Nick's Code, that was customized to scans I2C devices on the Arduino UNO board and returns the found addresses in HEX.
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

Load this sketch into your Arduino and then open your Serial Monitor. You will see the I2C address of your I2C LCD display.

Step 4: Display a Text

We must pass the I2C address of our LCD and the dimensions of the display to the constructor of the LiquidCrystal_I2C class. If we are using a 16×2 character LCD, let's pass the 16 and 2;
If we’re using a 20×4 LCD, we should pass 20 and 4.
Got the point?

Sample Code
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Please change the address according to 

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");
}

void loop() {
}

