#ifndef CONFIG_H
#define CONFIG_H

// =====================================================
//  Smart Driving Alert System - Global Configuration
//  Edit pin numbers / thresholds here to match your
//  actual wiring and calibration without touching the
//  rest of the codebase.
// =====================================================

// ----------------- Pin Definitions ------------------

// Ultrasonic Sensor (HC-SR04) - Obstacle / Collision Detection
#define TRIG_PIN            9
#define ECHO_PIN            10

// IR Eye-Blink Sensor - Drowsiness Detection
#define IR_SENSOR_PIN       2

// MQ-3 Alcohol Sensor (Analog output)
#define ALCOHOL_SENSOR_PIN  A0

// Buzzer
#define BUZZER_PIN          8

// Status LEDs
#define LED_RED_PIN         7
#define LED_GREEN_PIN       6

// Bluetooth Module (HC-05) - via SoftwareSerial
#define BT_RX_PIN           4   // Arduino RX  <- HC-05 TX
#define BT_TX_PIN           5   // Arduino TX  -> HC-05 RX
#define BT_BAUD_RATE        9600

// LCD (I2C 16x2)
#define LCD_I2C_ADDRESS     0x27
#define LCD_COLUMNS         16
#define LCD_ROWS            2

// ----------------- Thresholds -----------------------

// Minimum safe following/obstacle distance (cm)
#define SAFE_DISTANCE_CM         50

// Distance below which an alert becomes "critical" (cm)
#define CRITICAL_DISTANCE_CM     20

// How long eyes can stay "closed" before flagging drowsiness (ms)
#define DROWSY_EYE_CLOSED_MS     1500

// MQ-3 analog reading (0-1023) above which alcohol is flagged.
// Calibrate this for your specific sensor/module.
#define ALCOHOL_THRESHOLD        400

// Main loop timing
#define SENSOR_POLL_INTERVAL_MS  100
#define DISPLAY_REFRESH_MS       500

#endif // CONFIG_H
