#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte LED_PIN = 13;
const byte BUTTON_PIN = 7;

volatile bool ledState = false;

// Change 0x27 to 0x3F if required for your LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Timer LED Blink");

  lcd.setCursor(0, 1);
  lcd.print("Button: RELEASED");

  // Stop interrupts while configuring Timer1
  noInterrupts();

  TCCR1A = 0;                   // Clear Timer1 control register A
  TCCR1B = 0;                   // Clear Timer1 control register B
  TCNT1  = 0;                   // Start counting from zero

  // CTC mode: TOP value is stored in OCR1A
  TCCR1B |= (1 << WGM12);

  // Prescaler = 1024
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);

  // Approximately 1.5-second interrupt interval
  OCR1A = 23437;

  // Enable Timer1 Compare Match A interrupt
  TIMSK1 |= (1 << OCIE1A);

  interrupts();
}

void loop()
{
  static int previousButtonState = HIGH;

  int currentButtonState = digitalRead(BUTTON_PIN);

  // Update LCD only when the button state changes
  if (currentButtonState != previousButtonState)
  {
    delay(20);  // Simple switch debounce

    currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState != previousButtonState)
    {
      lcd.setCursor(0, 1);

      if (currentButtonState == LOW)
      {
        lcd.print("Button: PRESSED ");
      }
      else
      {
        lcd.print("Button: RELEASED");
      }

      previousButtonState = currentButtonState;
    }
  }

  // Other controller tasks can also be performed here
}

// Timer1 Compare Match A Interrupt Service Routine
ISR(TIMER1_COMPA_vect)
{
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
}
