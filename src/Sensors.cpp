#include "Sensors.h"
#include "Config.h"

Sensors::Sensors() : _eyeClosedSince(0), _eyeCurrentlyClosed(false) {}

void Sensors::begin() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(ALCOHOL_SENSOR_PIN, INPUT);
}

float Sensors::readDistanceCm() {
  // Send a 10us trigger pulse to the ultrasonic sensor.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 30ms timeout (~5m max range) so we never block forever if there's no echo.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) {
    return -1.0f; // no echo received -> treat as "out of range"
  }

  // distance = (time * speed of sound) / 2  [0.0343 cm/us]
  return (duration * 0.0343f) / 2.0f;
}

bool Sensors::updateDrowsiness() {
  // Assumes the IR module outputs LOW while the eye is detected as closed.
  bool eyeClosedNow = (digitalRead(IR_SENSOR_PIN) == LOW);
  unsigned long now = millis();

  if (eyeClosedNow && !_eyeCurrentlyClosed) {
    _eyeCurrentlyClosed = true;
    _eyeClosedSince = now;
  } else if (!eyeClosedNow) {
    _eyeCurrentlyClosed = false;
  }

  if (_eyeCurrentlyClosed && (now - _eyeClosedSince >= DROWSY_EYE_CLOSED_MS)) {
    return true;
  }
  return false;
}

SensorData Sensors::readAll() {
  SensorData data;

  data.distanceCm = readDistanceCm();
  data.obstacleDetected = (data.distanceCm > 0 && data.distanceCm <= SAFE_DISTANCE_CM);

  data.drowsinessDetected = updateDrowsiness();

  data.alcoholRaw = analogRead(ALCOHOL_SENSOR_PIN);
  data.alcoholDetected = (data.alcoholRaw >= ALCOHOL_THRESHOLD);

  return data;
}
