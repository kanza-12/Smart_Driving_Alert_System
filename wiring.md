# Wiring Reference

Pin numbers below match the defaults in `include/Config.h`. Update both
if your wiring differs.

| Component                  | Arduino Pin | Notes                          |
|-----------------------------|-------------|---------------------------------|
| HC-SR04 Ultrasonic - TRIG   | D9          | Output                          |
| HC-SR04 Ultrasonic - ECHO   | D10         | Input                           |
| IR Eye-Blink Sensor - OUT   | D2          | Digital input, LOW = eye closed |
| MQ-3 Alcohol Sensor - AOUT  | A0          | Analog input                    |
| Buzzer - (+)                | D8          | Output                          |
| Red LED (alert)             | D7          | Output, through ~220Ω resistor  |
| Green LED (status OK)       | D6          | Output, through ~220Ω resistor  |
| HC-05 Bluetooth - TXD       | D4          | Arduino RX (SoftwareSerial)     |
| HC-05 Bluetooth - RXD       | D5          | Arduino TX (use voltage divider)|
| 16x2 I2C LCD - SDA          | A4          | I2C data (Uno/Nano)             |
| 16x2 I2C LCD - SCL          | A5          | I2C clock (Uno/Nano)            |

**Power notes**
- HC-05 RXD is 3.3V logic — use a voltage divider or logic-level shifter
  between the Arduino TX pin and HC-05 RXD to avoid damaging the module.
- The HC-SR04, IR sensor, buzzer, and LEDs can run directly off 5V.
- Common ground (GND) must be shared across all modules.
