# Smart Driving Alert System

An Arduino-based driver-safety assistant that watches for three common risk
factors while driving — **tailgating/obstacles**, **drowsiness**, and
**alcohol presence** — and raises a buzzer/LED alert, shows live status on
an LCD, and streams status updates over Bluetooth to a paired phone.

## Features

- **Collision/obstacle warning** — HC-SR04 ultrasonic sensor measures
  following distance; warns when it drops below a safe threshold and
  escalates to a critical alert at very close range.
- **Drowsiness detection** — IR eye-blink sensor flags prolonged eye closure
  as a drowsiness event.
- **Alcohol detection** — MQ-3 gas sensor flags alcohol presence above a
  calibrated threshold.
- **Local alerts** — buzzer + red/green status LEDs.
- **On-board display** — 16x2 I2C LCD shows live distance and current
  status/alert.
- **Bluetooth status feed** — HC-05 module streams a simple CSV status line
  to any paired app, and accepts a `MUTE` command to silence an active alert.

## Hardware Required

| Module                  | Purpose                     |
|--------------------------|------------------------------|
| Arduino Uno/Nano (or compatible) | Main controller       |
| HC-SR04                 | Ultrasonic distance sensing  |
| IR eye-blink sensor      | Drowsiness detection         |
| MQ-3                     | Alcohol detection            |
| Buzzer                  | Audible alert                |
| 2x LED (+ resistors)     | Visual status                |
| HC-05                    | Bluetooth communication      |
| 16x2 I2C LCD             | On-board status display      |

See [`docs/wiring.md`](docs/wiring.md) for the full pin-out table.

## Project Structure

```
Smart-Driving-Alert-System/
├── src/                     # .cpp implementations
│   ├── Sensors.cpp
│   ├── Alerts.cpp
│   ├── Bluetooth.cpp
│   └── Display.cpp
├── include/                 # headers
│   ├── Config.h             # pins + tunable thresholds
│   ├── Sensors.h
│   ├── Alerts.h
│   ├── Bluetooth.h
│   └── Display.h
├── SmartDrivingAlertSystem.ino   # main sketch (setup/loop)
├── docs/
│   └── wiring.md
├── README.md
└── LICENSE
```

## Required Libraries

Install these via the Arduino Library Manager before building:

- `LiquidCrystal_I2C` (for the 16x2 I2C display)
- `SoftwareSerial` (bundled with the Arduino core)

## Building & Uploading (Arduino IDE)

1. Open `SmartDrivingAlertSystem.ino` in the Arduino IDE.
2. Make sure `src/` and `include/` are in the **same sketch folder** as the
   `.ino` file (the Arduino IDE compiles every `.cpp`/`.h` it finds there —
   it does not need a separate build step for this project layout).
3. Install the libraries listed above.
4. Select your board and COM port, then **Upload**.

> If you're using PlatformIO instead, point `src_dir` at `src/` and
> `include_dir` at `include/` in `platformio.ini`, and PlatformIO will pick
> up this structure automatically.

## Configuration

All pin assignments and alert thresholds live in `include/Config.h` —
adjust them there to match your wiring and to calibrate the alcohol/distance
thresholds for your specific sensors, without touching any other file.

## Bluetooth Protocol

Each status update sent to a paired device looks like:

```
DIST,34.0,OBST,1,DROWSY,0,ALCOHOL,0
```

Send `MUTE` (newline-terminated) from the paired app to silence the current
alert.

## License

See [`LICENSE`](LICENSE).
