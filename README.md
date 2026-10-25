# Smart Home IoT Automation

An ESP32-based smart home monitoring system that measures temperature and humidity, detects motion, controls an LED, and publishes live sensor data to a web dashboard using MQTT.

## Features

- Real-time temperature and humidity monitoring
- Motion detection using a PIR sensor
- Automatic LED control when motion is detected
- MQTT communication using the HiveMQ public broker
- Browser-based dashboard displaying live sensor data

## Hardware Components

- ESP32 microcontroller
- DHT22 temperature and humidity sensor
- PIR motion sensor
- LED and current-limiting resistor

## Software and Technologies

- Embedded C/C++ with Arduino framework
- Wokwi ESP32 simulator
- MQTT and HiveMQ public broker
- HTML, CSS and JavaScript
- MQTT.js library

## System Architecture

DHT22 and PIR Sensor → ESP32 → Wi-Fi → MQTT Broker → Web Dashboard

The ESP32 reads sensor values, publishes them as JSON messages over MQTT, and the browser dashboard subscribes to the same topic to display the readings.

## MQTT Configuration

- **Broker:** `broker.hivemq.com`
- **Port:** `1883` for ESP32 MQTT
- **Dashboard connection:** MQTT over WebSocket
- **Topic:** `ishant-smart-home-demo-48271`

## Project Files

- `esp32-code/sketch.ino` — ESP32 firmware
- `dashboard/live-dashboard.html` — Web dashboard
- `wokwi-circuit.png` — Circuit diagram

## How to Run

1. Open the ESP32 project in Wokwi.
2. Install the required DHT and PubSubClient libraries.
3. Start the simulation and verify the Wi-Fi and MQTT connection in the Serial Monitor.
4. Open `live-dashboard.html` in a browser with an internet connection.
5. Confirm that the dashboard displays sensor readings and motion/light status.

## Future Improvements

- Add remote light control from the dashboard.
- Add historical sensor readings and charts.
- Improve dashboard design for mobile devices.

## Author

Created as an IoT mini-project.
