#include "Alerts.h"
#include "Config.h"

Alerts::Alerts() : _level(AlertLevel::NONE) {}

void Alerts::begin() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  clear();
}

void Alerts::setBuzzer(bool on) {
  digitalWrite(BUZZER_PIN, on ? HIGH : LOW);
}

void Alerts::setLeds(bool redOn, bool greenOn) {
  digitalWrite(LED_RED_PIN, redOn ? HIGH : LOW);
  digitalWrite(LED_GREEN_PIN, greenOn ? HIGH : LOW);
}

void Alerts::triggerCollisionAlert(bool critical) {
  _level = critical ? AlertLevel::CRITICAL : AlertLevel::WARNING;
  setLeds(true, false);
  setBuzzer(critical); // steady tone only once it's critical
}

void Alerts::triggerDrowsinessAlert() {
  _level = AlertLevel::CRITICAL;
  setLeds(true, false);
  setBuzzer(true);
}

void Alerts::triggerAlcoholAlert() {
  _level = AlertLevel::CRITICAL;
  setLeds(true, false);
  setBuzzer(true);
}

void Alerts::clear() {
  _level = AlertLevel::NONE;
  setLeds(false, true);
  setBuzzer(false);
}

AlertLevel Alerts::currentLevel() const {
  return _level;
}
