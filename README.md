# 🚗 Smart Driving Alert System using ESP32

<p align="center">

![ESP32](https://img.shields.io/badge/ESP32-DevKit%20V1-red?style=for-the-badge)
![Arduino IDE](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge\&logo=arduino\&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-Arduino-00599C?style=for-the-badge\&logo=cplusplus\&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

</p>

<p align="center">
An <strong>ESP32-based Smart Driving Alert System</strong> that enhances driver safety by detecting <strong>alcohol consumption</strong> and <strong>driver drowsiness</strong> in real time. The system automatically activates visual and audible alerts while simulating vehicle immobilization using a relay and servo motor.
</p>

---

## 📑 Table of Contents

* Overview
* Features
* Hardware Components
* Hardware Connections
* Project Structure
* Software Architecture
* System Workflow
* Installation
* Configuration
* Libraries Used
* Serial Monitor Output
* Future Improvements
* Contributing
* Repository Links
* License

---

# 📖 Overview

The **Smart Driving Alert System** is an embedded systems project developed using the **ESP32 DevKit V1**.

The project continuously monitors the driver's condition using:

* 🍺 MQ-3 Alcohol Sensor
* 😴 IR Eye Blink Sensor

When an unsafe condition is detected, the ESP32 immediately performs multiple safety actions:

* 🔴 Activates an audible buzzer
* 🔴 Turns on a relay
* 🔴 Rotates a servo motor
* 🔴 Changes NeoPixel color
* 🔴 Displays warnings through the Serial Monitor

The project is completely offline and **does not require**:

* Bluetooth
* WiFi
* GPS
* GSM
* Cloud Services
* LCD/OLED Display

---

# ✨ Features

## 🍺 Alcohol Detection

When the MQ-3 sensor detects alcohol above the configured threshold:

* Continuous buzzer alarm
* Relay turns ON
* Servo rotates to **90°**
* NeoPixel changes to **Red**
* Warning printed on Serial Monitor

---

## 😴 Driver Drowsiness Detection

If the IR Eye Blink Sensor detects that the driver's eyes remain closed for more than **2.5 seconds**:

* Buzzer beeps repeatedly
* Relay turns ON
* Servo rotates to **90°**
* NeoPixel changes to **Orange**
* Warning printed on Serial Monitor

---

## ✅ Safe Driving State

When no danger is detected:

* Servo returns to **0°**
* Relay OFF
* Buzzer OFF
* NeoPixel Green
* Serial Monitor displays:

```text
Driver Safe
```

---

# 🛠 Hardware Components

| Component           | Quantity |
| ------------------- | -------: |
| ESP32 DevKit V1     |        1 |
| MQ-3 Alcohol Sensor |        1 |
| IR Eye Blink Sensor |        1 |
| SG90 Servo Motor    |        1 |
| 5V Relay Module     |        1 |
| Active Buzzer       |        1 |
| WS2812B NeoPixel    |        1 |

---

# 🔌 Hardware Connections

| Component           | ESP32 GPIO |
| ------------------- | ---------- |
| MQ-3 Alcohol Sensor | GPIO 34    |
| IR Eye Blink Sensor | GPIO 35    |
| Active Buzzer       | GPIO 25    |
| Relay Module        | GPIO 26    |
| Servo Motor         | GPIO 27    |
| NeoPixel            | GPIO 4     |

---

# 📂 Project Structure

```text
SmartDrivingAlertSystem/

├── SmartDrivingAlertSystem.ino
├── Config.h
├── Sensors.h
├── Sensors.cpp
├── Alerts.h
├── Alerts.cpp
├── README.md
└── LICENSE
```

---

# 🧩 Software Architecture

### Config.h

Stores:

* GPIO Pins
* Threshold Values
* Servo Angles
* NeoPixel Colors
* Timing Constants
* SystemState Enum

---

### Sensors Class

Responsibilities:

* Initialize sensors
* Read MQ-3 values
* Read Eye Blink Sensor
* Detect alcohol
* Detect drowsiness
* Print sensor values
* Return current system state

---

### Alerts Class

Responsibilities:

* Control Servo
* Control Relay
* Control Buzzer
* Control NeoPixel
* Execute alert modes

---

### SmartDrivingAlertSystem.ino

Responsible for:

* System initialization
* Reading sensor data
* State management
* Alert execution

---

# ⚙ System Workflow

```text
             Power ON
                 │
                 ▼
      Initialize Hardware
                 │
                 ▼
       Read Sensor Values
                 │
       ┌─────────┴──────────┐
       │                    │
Alcohol Detected?     Eyes Closed?
       │                    │
      YES                  YES
       │                    │
 Alcohol Alert     Drowsiness Alert
       │                    │
       └─────────┬──────────┘
                 │
                NO
                 │
                 ▼
            Safe State
                 │
                 ▼
             Repeat Loop
```

---

# 🚀 Installation

## Clone the Repository

```bash
git clone https://github.com/kanza-12/SmartDrivingAlertSystem.git
```

## Open the Project

Open the following file in the Arduino IDE:

```text
SmartDrivingAlertSystem.ino
```

## Install Required Libraries

Using the Arduino Library Manager, install:

* ESP32Servo
* Adafruit NeoPixel

## Select the Board

```text
Board:
ESP32 Dev Module
```

Select the correct COM port and click **Upload**.

---

# ⚙ Configuration

All configurable values are stored inside:

```text
Config.h
```

You can easily modify:

* GPIO Pins
* Alcohol Threshold
* Drowsiness Timeout
* Servo Angles
* NeoPixel Colors

without changing any other source file.

---

# 📚 Libraries Used

```cpp
#include <Arduino.h>
#include <ESP32Servo.h>
#include <Adafruit_NeoPixel.h>
```

---

# 🖥 Example Serial Output

## Safe State

```text
MQ3 Value: 180
Eye Status: OPEN

Driver Safe
```

---

## Alcohol Detected

```text
MQ3 Value: 735

WARNING!
Alcohol Detected

Vehicle Disabled
```

---

## Driver Drowsy

```text
Eye Status: CLOSED

Driver Sleeping

Stopping Vehicle
```

---

# 🎓 Concepts Demonstrated

* Embedded Systems Programming
* ESP32 Development
* Object-Oriented Programming (OOP)
* Sensor Interfacing
* State Machine Design
* Non-blocking Programming using `millis()`
* Real-Time Monitoring
* Hardware Integration
* Safety-Critical Embedded Systems

---

# 🚀 Future Improvements

Potential enhancements include:

* AI-based Eye Tracking
* Face Recognition
* GPS Navigation
* GSM Emergency Alerts
* Mobile Application
* Cloud Dashboard
* SD Card Data Logging
* Voice Assistant
* CAN Bus Integration
* Camera-Based Drowsiness Detection

---

# 🤝 Contributing

Contributions are always welcome.

1. Fork the repository.
2. Create a new feature branch.

```bash
git checkout -b feature/NewFeature
```

3. Commit your changes.

```bash
git commit -m "Add new feature"
```

4. Push your branch.

```bash
git push origin feature/NewFeature
```

5. Open a Pull Request.

---

# 🔗 Repository Links

### 📂 GitHub Repository

https://github.com/kanza-12/Smart_Driving_Alert_System

### 🍴 Fork Repository

https://github.com/kanza-12/Smart_Driving_Alert_System/fork

### 🐞 Report an Issue

https://github.com/kanza-12/Smart_Driving_Alert_System/issues

### ✨ Request a Feature

https://github.com/kanza-12/Smart_Driving_Alert_System/issues/new

### 📥 Clone Repository

```bash
git clone https://github.com/kanza-12/Smart_Driving_Alert_System.git
```

---

# 📜 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for more details.

---

# 👩‍💻 Author

**Kanza**

Electronics & Computing Engineering Student

GitHub: https://github.com/kanza-12

---

<p align="center">

⭐ If you found this project useful, consider giving it a <strong>Star</strong> on GitHub!

Made with ❤️ using <strong>ESP32</strong>, <strong>Arduino IDE</strong>, and <strong>C++</strong>.

</p>
