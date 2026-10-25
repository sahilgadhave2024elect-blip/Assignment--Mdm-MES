const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int total = 0;

  for (int i = 0; i < 10; i++) {
    total += analogRead(sensorPin);
    delay(10);
  }

  float average = total / 10.0;

  float voltage = average * 5.0 / 1023.0;

  // TMP36 temperature conversion
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Filtered ADC: ");
  Serial.println(average);

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.println("----------------");

  delay(1000);
}
