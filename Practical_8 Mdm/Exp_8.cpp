char rxBuffer[64];
uint8_t indexRx = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("UNO UART ready. Enter a message:");
}

void loop() {
  while (Serial.available() > 0) {
    char c = (char)Serial.read();

    if (c == '\n' || c == '\r') {
      if (indexRx > 0) {
        rxBuffer[indexRx] = '\0';

        Serial.print("UNO received: ");
        Serial.println(rxBuffer);

        Serial.print("Length: ");
        Serial.println(indexRx);

        Serial.println("UNO TX: Message acknowledged");

        indexRx = 0;
      }
    }
    else if (indexRx < sizeof(rxBuffer) - 1) {
      rxBuffer[indexRx++] = c;
    }
    else {
      indexRx = 0;
      Serial.println("Error: message too long");
    }
  }
}
