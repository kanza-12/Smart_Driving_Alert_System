#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothModule {
  public:
    BluetoothModule();

    // Starts the SoftwareSerial link to the HC-05. Call once from setup().
    void begin();

    // Sends a simple CSV status line a paired phone app can parse:
    // DIST,<cm>,OBST,<0/1>,DROWSY,<0/1>,ALCOHOL,<0/1>
    void sendStatus(float distanceCm, bool obstacle, bool drowsy, bool alcohol);

    // Returns a received command string, or "" if nothing was received.
    String checkIncoming();

  private:
    SoftwareSerial _bt;
};

#endif // BLUETOOTH_H
