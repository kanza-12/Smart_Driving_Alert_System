#ifndef ALERTS_H
#define ALERTS_H

#include <Arduino.h>

enum class AlertLevel {
  NONE,
  WARNING,   // approaching the safe-distance limit
  CRITICAL   // collision risk, drowsiness, or alcohol detected
};

class Alerts {
  public:
    Alerts();

    // Configures pin modes and resets to a clear state. Call once from setup().
    void begin();

    void triggerCollisionAlert(bool critical);
    void triggerDrowsinessAlert();
    void triggerAlcoholAlert();
    void clear();

    AlertLevel currentLevel() const;

  private:
    void setBuzzer(bool on);
    void setLeds(bool redOn, bool greenOn);

    AlertLevel _level;
};

#endif // ALERTS_H
