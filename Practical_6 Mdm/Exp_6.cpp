// Experiment: PWM Control
// Board: Arduino Uno
// LED -> Pin 9
// Buzzer -> Pin 10
// DC Motor -> Pin 11 through L293D motor driver
const int ledPin = 9;
const int buzzerPin = 10;
const int motorPin = 11;
void setup()
{
// Set PWM pins as outputs
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(motorPin, OUTPUT);
}
void loop()
{
// Generate PWM values from 0 to 255
for (int pwmValue = 0; pwmValue <= 255; pwmValue++)
{
// Control LED brightness
analogWrite(ledPin, pwmValue);
// Control buzzer drive level
analogWrite(buzzerPin, pwmValue);
// Control DC motor speed
analogWrite(motorPin, pwmValue);
/ Small delay to observe the change
delay(20);
}
// Decrease PWM value from 255 to 0
for (int pwmValue = 255; pwmValue >= 0; pwmValue--)
{
// Control LED brightness
analogWrite(ledPin, pwmValue);
// Control buzzer drive level
analogWrite(buzzerPin, pwmValue);
// Control DC motor speed
analogWrite(motorPin, pwmValue);
delay(20);
}
}
