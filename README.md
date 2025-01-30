# IoT-Based Multifunctional Safety Device

## Overview
The **IoT-Based Multifunctional Safety Device** is a smart security system that integrates multiple sensors to detect fire, unauthorized access, environmental hazards, and other safety threats. The device is powered by an **ESP32** microcontroller and uses **ThingSpeak** for real-time data monitoring and analytics.

## Features
- **Intruder Detection**: Detects unauthorized entry using a motion sensor and triggers an alarm.
- **Fire Detection**: Monitors temperature and smoke levels to detect fire hazards.
- **Environmental Monitoring**: Tracks air quality, temperature, and humidity in real time.
- **ThingSpeak Integration**: Sends real-time sensor data to **ThingSpeak** for remote monitoring.
- **Automated Alerts**: Sends SMS, email, or push notifications in case of an emergency.
- **Low-Power Consumption**: Optimized for continuous operation with minimal energy usage.

## Components Used
- **ESP32** (Microcontroller)
- **DS18B20** (Temperature Sensor)
- **Analog TDS Sensor** (Water Quality Measurement)
- **PIR Motion Sensor** (Intruder Detection)
- **Smoke & Gas Sensor (MQ Series)**
- **Buzzer & LED Indicators**
- **OLED Display** (For on-device status monitoring)
- **ThingSpeak Cloud API**

## Installation & Setup
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/deepesh-dhanwani/IOT-BASED-MULTIFUCTIONAL-SAFETY-DEVICE.git
   cd IOT-BASED-MULTIFUCTIONAL-SAFETY-DEVICE
   ```

2. **Install Dependencies**:
   - Arduino IDE with ESP32 board support
   - Required libraries: `WiFi.h`, `HTTPClient.h`, `DallasTemperature.h`, `OneWire.h`, `ThingSpeak.h`

3. **Configure WiFi & ThingSpeak**:
   - Update `WiFi SSID` and `password` in the code.
   - Set up a ThingSpeak channel and obtain an API key.
   - Insert the API key in the code to enable cloud data transmission.

4. **Upload Code to ESP32**:
   - Connect ESP32 to your PC.
   - Compile and upload the code using Arduino IDE.

## Usage
- Once powered on, the device starts monitoring in real-time.
- Data is uploaded to **ThingSpeak** and can be accessed remotely via the dashboard.
- Alerts are triggered when a critical event is detected (fire, intrusion, hazardous air quality, etc.).

## Future Enhancements
- **Mobile App Integration** for real-time notifications.
- **AI-based Anomaly Detection** for predictive safety alerts.
- **Battery Backup & Solar Power Support** for enhanced reliability.

## Contributing
Contributions are welcome! Feel free to fork the repository and submit pull requests.

---
Developed by **Deepesh Dhanwani** 🚀

