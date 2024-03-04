#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the I2C LCD address and dimensions
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Define the button pin
#define BUTTON_PIN 8

// Initialize the LCD object
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Initialize the LCD
  lcd.begin(LCD_COLUMNS, LCD_ROWS);

  // Set up the button pin as input with internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(BUTTON_PIN);

  // Check if the button is pressed
  if (buttonState == LOW) {
    // Button is pressed, display "Charging"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Charging");
  } else {
    // Button is not pressed, display "Not Charging"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Not Charging");
  }
}
