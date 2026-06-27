#include "Bluetooth.h"
#include "Config.h"

BluetoothModule::BluetoothModule() : _bt(BT_RX_PIN, BT_TX_PIN) {}

void BluetoothModule::begin() {
  _bt.begin(BT_BAUD_RATE);
}

void BluetoothModule::sendStatus(float distanceCm, bool obstacle, bool drowsy, bool alcohol) {
  _bt.print("DIST,");
  _bt.print(distanceCm, 1);
  _bt.print(",OBST,");
  _bt.print(obstacle ? 1 : 0);
  _bt.print(",DROWSY,");
  _bt.print(drowsy ? 1 : 0);
  _bt.print(",ALCOHOL,");
  _bt.println(alcohol ? 1 : 0);
}

String BluetoothModule::checkIncoming() {
  String received = "";
  while (_bt.available()) {
    char c = (char)_bt.read();
    if (c == '\n') break;
    received += c;
  }
  received.trim();
  return received;
}
