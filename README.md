# Wireless-Client-Server-Model-with-Two-ESP8266-Boards-on-Wi-Fi
## Overview

This project implements a wireless environmental monitoring system using two ESP8266 boards. One board serves as an Access Point (AP) server with a BMP280 sensor, while the other functions as a client with an OLED display for real-time data visualization.

## Features

- **Real-time Monitoring:** Receive precise environmental data, including temperature and pressure.
- **Seamless Wi-Fi Communication:** Utilizes HTTP GET requests and responses for efficient data exchange.
- **User-Friendly Display:** OLED display provides clear and immediate visualization of sensor data.

## Setup

### Access Point (AP)

1. Connect BMP280 sensor to ESP8266.
2. Upload the `AP_Server_Code` to the AP ESP8266.

### Client

1. Connect OLED display to ESP8266.
2. Upload the `Client_Code` to the client ESP8266.

### Configure Wi-Fi

- Update Wi-Fi credentials in the code.

## Dependencies

- [Adafruit_BMP280 Library](https://github.com/adafruit/Adafruit_BMP280)
- [Adafruit_SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)

## Usage

1. Power up both ESP8266 boards.
2. Monitor environmental data on the OLED display.
