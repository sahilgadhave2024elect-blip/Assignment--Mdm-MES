// Experiment: 16x2 I2C LCD
// Board: Arduino Uno
// Display: Hello World
#include <Wire.h> // I2C communication library
#include <LiquidCrystal_I2C.h> // I2C LCD library
// Create LCD object
// 0x27 = common I2C address
// 16 = number of columns
// 2 = number of rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
// Initialize the LCD
lcd.init();
// Turn ON the LCD backlight
lcd.backlight();
// Display "Hello World"
lcd.setCursor(0, 0); // Column 0, Row 0
lcd.print("Hello World");
}
void loop()
{
// Nothing required here
}
