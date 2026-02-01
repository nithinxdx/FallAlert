# FallAlert

Real-time Human Fall Detection, Alert and Rescue System using ESP32 and MPU6050.

## Overview
FallAlert is a wearable embedded safety system that continuously monitors body motion using an IMU sensor.  
When a fall is detected, it automatically sends alerts to caregivers through Wi-Fi/GSM and triggers local alarms.

This system helps reduce response time and improves safety for elderly and vulnerable individuals.

## Features
- Real-time fall detection
- Hybrid threshold + posture algorithm
- Wi-Fi / GSM alerts (SMS/notification)
- Local buzzer alert
- Low power wearable design
- Optional GPS tracking

## Hardware Components
- ESP32 Dev Board
- MPU6050 (Accelerometer + Gyroscope)
- GSM Module (SIM800/SIM900)
- Buzzer / Vibration Motor
- Li-ion Battery
- Optional GPS (NEO-6M)

## Working Principle
1. MPU6050 collects motion data
2. ESP32 calculates acceleration magnitude
3. Detects:
   - Free fall
   - Impact spike
   - Lying posture
4. If confirmed → Alert sent immediately

## Folder Structure

FallAlert/
├── code/
├── docs/
├── README.md
├── requirements.txt
├── .gitignore
└── LICENSE


## How to Run
1. Install Arduino IDE
2. Install ESP32 board package
3. Install MPU6050 library
4. Open code/FallAlert_Code.ino
5. Upload to ESP32

## Applications
- Elderly care
- Hospitals
- Rehabilitation centers
- Personal safety monitoring
- Smart healthcare IoT

## Author
Nithin ,
Electronics & Communication Engineering

## License
MIT License
