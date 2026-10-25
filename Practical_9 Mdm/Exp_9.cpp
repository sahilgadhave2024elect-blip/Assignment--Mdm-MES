//Part A: Arduino UNO

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 2);
  display.println("OLED GRAPH");

  display.drawLine(5, 55, 123, 55, SSD1306_WHITE);
  display.drawLine(5, 18, 5, 55, SSD1306_WHITE);

  int x1 = 5;
  int y1 = 35;

  for (int x = 6; x < 124; x++) {
    int y = 35 + 15 * sin(x * 0.15);
    display.drawLine(x1, y1, x, y, SSD1306_WHITE);
    x1 = x;
    y1 = y;
  }

  display.display();
}

void loop() {
 
 
//Part B : Esp32

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

void setup() {
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 2);
  display.println("ESP32 GRAPH");

  display.drawLine(5, 55, 123, 55, SSD1306_WHITE);
  display.drawLine(5, 18, 5, 55, SSD1306_WHITE);

  int x1 = 5;
  int y1 = 35;

  for (int x = 6; x < 124; x++) {
    int y = 35 + 15 * sin(x * 0.15);
    display.drawLine(x1, y1, x, y, SSD1306_WHITE);
    x1 = x;
    y1 = y;
  }

  display.display();
}

void loop() {
}
