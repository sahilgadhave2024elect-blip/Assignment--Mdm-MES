#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_DC 9
#define OLED_CS 10
#define OLED_RST 8

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT,
  &SPI, OLED_DC, OLED_RST, OLED_CS
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
