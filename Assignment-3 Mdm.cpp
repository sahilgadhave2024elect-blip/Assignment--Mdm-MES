// Experiment: Pushbutton and LED with Debouncing
// Board: Arduino Uno
// Button: Digital Pin 2
// LED: Digital Pin 13
const int buttonPin = 2; // Pushbutton connected to D2
const int ledPin = 13; // LED connected to D13
void setup()
{
// Configure the button pin as INPUT with internal pull-up resistor
pinMode(buttonPin, INPUT_PULLUP);
// Configure the LED pin as OUTPUT
pinMode(ledPin, OUTPUT);
// Initially turn OFF the LED
digitalWrite(ledPin, LOW);
}
void loop()
{
// Read the current state of the pushbutton
int buttonState = digitalRead(buttonPin);
// With INPUT_PULLUP, LOW means the button is pressed
if (buttonState == LOW)
{
// Wait for 50 ms to allow switch bouncing to settle
delay(50);
// Read the button again after the debounce delay
buttonState = digitalRead(buttonPin);
// Check whether the button is still pressed
if (buttonState == LOW)
{
// Turn ON the LED
digitalWrite(ledPin, HIGH);
 }
}
else
{
// Button is released, so turn OFF the LED
digitalWrite(ledPin, LOW);
 }
}
