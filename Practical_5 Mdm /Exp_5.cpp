
//Timer1-Based Periodic LED Task with Pushbutton and I²C LCD

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int ledPin = 13;
const int buttonPin = 7;

LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile bool ledState = false;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Timer1 + Button");

  lcd.setCursor(0, 1);
  lcd.print("Button: RELEASED");

  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // CTC mode, prescaler = 1024
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Approximately 1.5 second interrupt interval
  OCR1A = 23437;

  // Enable Timer1 Compare Match A interrupt
  TIMSK1 |= (1 << OCIE1A);

  interrupts();
}

ISR(TIMER1_COMPA_vect)
{
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
}

void loop()
{
  static int previousButtonState = HIGH;
  int buttonState = digitalRead(buttonPin);

  if (buttonState != previousButtonState)
  {
    delay(50);  // Debounce

    buttonState = digitalRead(buttonPin);

    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);

    if (buttonState == LOW)
    {
      lcd.print("Button: PRESSED");
    }
    else
    {
      lcd.print("Button: RELEASED");
    }

    previousButtonState = buttonState;
  }
}
