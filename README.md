**Interfacing I2C LCD with Arduino**
True to their name, these LCDs are ideal for displaying only text/characters.
A 16×2 character LCD, for example, has an LED backlight and can display 32 ASCII characters in two rows of 16 characters each.

**Step 1: Wiring Diagram**
Check for it.

**Step 2: Library Installation**
**Wire.h:** The Wire.h library is part of the Arduino ecosystem and is used for I2C (Inter-Integrated Circuit) communication. It comes pre-installed with the Arduino IDE.

**LiquidCrystal_I2C:** To drive an I2C LCD we must first install a library called LiquidCrystal_I2C. This library is an enhanced version of the LiquidCrystal library that comes with the Arduino IDE.

To install the library, let's navigate to Sketch > Include Libraries > Manage Libraries… 
Let's then wait for the Library Manager to download the library index and update the list of installed libraries.

Filter your search by typing ‘liquidcrystal‘. Look for the LiquidCrystal I2C library by Frank de Brabander and then select Install.

**Step 3: Determining the I2C Address**
The easy way to find out the I2C address of the LCD is using the code of Nick Gammon.
Nick wrote the code that scans your I2C bus and returns the address of each I2C device it finds.

We customized NIck's code to scans I2C devices on the Arduino UNO board and returns the found addresses in HEX.

**Step 4: Display a Text**

We must pass the I2C address of our LCD and the dimensions of the display to the constructor of the LiquidCrystal_I2C class. If we are using a 16×2 character LCD, let's pass the 16 and 2;
If we’re using a 20×4 LCD, we should pass 20 and 4.
Got the point?
