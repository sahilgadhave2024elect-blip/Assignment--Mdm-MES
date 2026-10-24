//Part A: Arduino UNO

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define WIDTH 128
#define HEIGHT 64
#define OLED_DC 9
#define OLED_RST 8
#define OLED_CS 10

Adafruit_SSD1306 display(
  WIDTH, HEIGHT, &SPI,
  OLED_DC, OLED_RST, OLED_CS
);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 2);
  display.println("SPI OLED GRAPH");

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

//Part B : Esp32

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define WIDTH 128
#define HEIGHT 64
#define OLED_DC 16
#define OLED_RST 17
#define OLED_CS 5

Adafruit_SSD1306 display(
  WIDTH, HEIGHT, &SPI,
  OLED_DC, OLED_RST, OLED_CS
);

void setup() {
  SPI.begin(18, -1, 23, 5);

  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 2);
  display.println("ESP32 SPI GRAPH");

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
