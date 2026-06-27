#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Display {
  public:
    Display();

    // Initializes the I2C LCD. Call once from setup().
    void begin();

    // Shows the current driving status on the LCD.
    void showStatus(float distanceCm, bool obstacle, bool drowsy, bool alcohol);

    // Shows a generic two-line message (e.g. boot screen).
    void showMessage(const String& line1, const String& line2);

  private:
    LiquidCrystal_I2C _lcd;
};

#endif // DISPLAY_H
