// Experiment: Measurement of Period and Frequency
// Board: Arduino Uno
// External square-wave signal -> Digital Pin 2
const int signalPin = 2;
unsigned long highTime;
unsigned long lowTime;
unsigned long period;
float frequency;
void setup()
{
// Configure D2 as input
pinMode(signalPin, INPUT);
// Start Serial Monitor
Serial.begin(9600);
}
void loop()
{
// Measure the time for which the signal is HIGH
highTime = pulseIn(signalPin, HIGH);
// Measure the time for which the signal is LOW
lowTime = pulseIn(signalPin, LOW);
// Total time of one complete cycle
// Period = HIGH time + LOW time
period = highTime + lowTime;
// Convert period from microseconds to frequency in Hz
// 1 second = 1,000,000 microseconds
if (period > 0)
{
frequency = 1000000.0 / period;
// Display results on Serial Monitor
Serial.print("Period = ");
Serial.print(period);
Serial.println(" microseconds");
Serial.print("Frequency = ");
Serial.print(frequency);
Serial.println(" Hz");
Serial.println("--------------------");
}
,// Small delay before next measurement
delay(500);
}
