#include "Display.h"
#include "Config.h"

Display::Display() : _lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS) {}

void Display::begin() {
  _lcd.init();
  _lcd.backlight();
  showMessage("Smart Driving", "Alert System");
}

void Display::showStatus(float distanceCm, bool obstacle, bool drowsy, bool alcohol) {
  _lcd.clear();

  _lcd.setCursor(0, 0);
  if (drowsy) {
    _lcd.print("DROWSY! WAKE UP!");
  } else if (alcohol) {
    _lcd.print("ALCOHOL DETECTED");
  } else if (obstacle) {
    _lcd.print("OBSTACLE AHEAD!");
  } else {
    _lcd.print("Status: SAFE");
  }

  _lcd.setCursor(0, 1);
  if (distanceCm > 0) {
    _lcd.print("Dist: ");
    _lcd.print(distanceCm, 0);
    _lcd.print("cm");
  } else {
    _lcd.print("Dist: --");
  }
}

void Display::showMessage(const String& line1, const String& line2) {
  _lcd.clear();
  _lcd.setCursor(0, 0);
  _lcd.print(line1);
  _lcd.setCursor(0, 1);
  _lcd.print(line2);
}
