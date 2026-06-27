#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// Snapshot of all sensor readings for a single loop iteration.
struct SensorData {
  float distanceCm;          // -1 if out of range / no echo
  bool  obstacleDetected;    // true if distanceCm <= SAFE_DISTANCE_CM
  bool  drowsinessDetected;  // true if eyes have been closed too long
  int   alcoholRaw;          // raw analog reading 0-1023
  bool  alcoholDetected;     // true if alcoholRaw >= ALCOHOL_THRESHOLD
};

class Sensors {
  public:
    Sensors();

    // Configures pin modes. Call once from setup().
    void begin();

    // Reads every sensor and returns a populated snapshot.
    SensorData readAll();

  private:
    float readDistanceCm();
    bool  updateDrowsiness();

    unsigned long _eyeClosedSince;
    bool          _eyeCurrentlyClosed;
};

#endif // SENSORS_H
