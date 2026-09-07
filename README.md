# IOTBAESDREMOTEPATIENTVITALMONITORINGSYSTEM
# IoT-Based Remote Patient Vital Monitoring System

## 📌 Project Overview

The IoT-Based Remote Patient Vital Monitoring System is a portable healthcare monitoring solution designed to monitor important patient vital parameters in real time.

The system uses an ESP32 microcontroller with biomedical sensors to measure heart rate, SpO₂, body temperature, blood pressure, and ECG signals. The collected data is processed by the ESP32 and transmitted through Wi-Fi to an IoT cloud platform for remote monitoring.

Healthcare professionals and caregivers can access the patient's health information through an IoT dashboard using an internet-connected device.

## 🎯 Objectives

- Monitor patient vital signs in real time.
- Measure heart rate and SpO₂.
- Monitor body temperature.
- Monitor blood pressure.
- Acquire ECG signals.
- Transmit health data through Wi-Fi.
- Enable remote patient monitoring.
- Support early detection of abnormal readings.
- Provide a portable and cost-effective healthcare solution.

## 🔧 Hardware Components

- ESP32 Development Board
- MAX30102 Pulse Oximeter Sensor
- MLX90614 Temperature Sensor
- AD8232 ECG Sensor
- Blood Pressure Sensor
- Breadboard
- Jumper Wires
- USB/5V Power Supply

## 💻 Software

- Arduino IDE
- Embedded C/C++
- ESP32 Wi-Fi
- IoT Cloud Dashboard

## ⚙️ Working

1. The ESP32 initializes all connected sensors.
2. MAX30102 measures heart rate and SpO₂.
3. The temperature sensor measures body temperature.
4. The blood pressure sensor provides blood pressure readings.
5. AD8232 captures the ECG signal.
6. ESP32 processes the sensor readings.
7. The readings are transmitted through Wi-Fi.
8. The IoT dashboard displays the patient information.
9. The system continuously updates the readings for remote monitoring.

## ✨ Features

- Real-time monitoring
- Multi-parameter monitoring
- IoT connectivity
- Remote healthcare monitoring
- Continuous data monitoring
- Portable design
- Cost-effective solution
- User-friendly dashboard

## 🏥 Applications

- Home healthcare
- Rural healthcare centers
- Elderly care
- Telemedicine
- Ambulance monitoring
- Remote patient monitoring

## 📊 Project Outcome

The prototype demonstrates the integration of biomedical sensors, ESP32, wireless communication, and an IoT dashboard for continuous remote patient monitoring.

## ⚠️ Disclaimer

This project is intended for educational and prototype purposes. It is a health-monitoring and decision-support system and should not be considered a replacement for professional medical diagnosis or emergency treatment.
