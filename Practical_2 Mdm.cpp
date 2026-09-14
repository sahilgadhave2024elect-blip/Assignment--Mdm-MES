//Part A : LED Toggling Using Software Delay
// Experiment: LED toggling using software delay
// Board: Arduino Uno
// LED: Built-in LED connected to digital pin 13
const int ledPin = 13;
void setup()
{
// Configure LED pin as an output
pinMode(ledPin, OUTPUT);
}
void loop()
{
// Turn LED ON
digitalWrite(ledPin, HIGH);
// Wait for 1 second
delay(1000);
// Turn LED OFF
digitalWrite(ledPin, LOW);
// Wait for 1 second
delay(1000);
}

//Part B : LED Toggling Using Non-Blocking millis()
// Experiment: LED toggling using millis()
// Board: Arduino Uno
// This method does not block the execution of the program.
const int ledPin = 13;
// Stores the time at which the LED was last toggled
unsigned long previousMillis = 0;
// Time interval for LED toggling
const unsigned long interval = 1000;
// Stores the current state of the LED
bool ledState = LOW;
void setup()
{
// Configure LED pin as an output
pinMode(ledPin, OUTPUT);
}
void loop()
{
// Get the current time in milliseconds
unsigned long currentMillis = millis();
// Check whether 1 second has passed
if (currentMillis - previousMillis >= interval)
{
// Save the current time
previousMillis = currentMillis;
// Toggle the LED state
ledState = !ledState;
// Apply the new state to the LED
digitalWrite(ledPin, ledState);
}
// Other tasks can be executed here
// because millis() does not block the program.
}
