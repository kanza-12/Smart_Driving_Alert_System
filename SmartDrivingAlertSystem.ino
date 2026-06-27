#include "Config.h"
#include "Sensors.h"
#include "Alerts.h"
#include "Bluetooth.h"
#include "Display.h"

Sensors sensors;
Alerts alerts;
BluetoothModule bluetooth;
Display display;

unsigned long lastSensorPoll = 0;
unsigned long lastDisplayUpdate = 0;

void setup() {
  Serial.begin(9600);

  sensors.begin();
  alerts.begin();
  bluetooth.begin();
  display.begin();

  delay(1000); // let modules settle / show boot screen briefly
}

void loop() {
  unsigned long now = millis();

  if (now - lastSensorPoll >= SENSOR_POLL_INTERVAL_MS) {
    lastSensorPoll = now;

    SensorData data = sensors.readAll();

    // Priority order: drowsiness > alcohol > collision > all clear
    if (data.drowsinessDetected) {
      alerts.triggerDrowsinessAlert();
    } else if (data.alcoholDetected) {
      alerts.triggerAlcoholAlert();
    } else if (data.obstacleDetected) {
      bool critical = (data.distanceCm > 0 && data.distanceCm <= CRITICAL_DISTANCE_CM);
      alerts.triggerCollisionAlert(critical);
    } else {
      alerts.clear();
    }

    bluetooth.sendStatus(data.distanceCm, data.obstacleDetected,
                          data.drowsinessDetected, data.alcoholDetected);

    if (now - lastDisplayUpdate >= DISPLAY_REFRESH_MS) {
      lastDisplayUpdate = now;
      display.showStatus(data.distanceCm, data.obstacleDetected,
                          data.drowsinessDetected, data.alcoholDetected);
    }

    // Allow a paired phone app to silence an active alert, e.g. send "MUTE"
    String cmd = bluetooth.checkIncoming();
    if (cmd == "MUTE") {
      alerts.clear();
    }
  }
}
