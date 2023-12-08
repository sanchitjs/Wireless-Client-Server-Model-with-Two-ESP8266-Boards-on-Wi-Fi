# Wireless-Client-Server-Model-with-Two-ESP8266-Boards-on-Wi-Fi
ESP8266-based Environmental Monitoring: AP server with BMP280 sensor &amp; client with OLED display. Seamless Wi-Fi communication using HTTP GET requests for real-time data visualization. Explore the code for an efficient wireless solution.

Overview
This project implements a wireless environmental monitoring system using two ESP8266 boards. One board serves as an Access Point (AP) server with a BMP280 sensor, while the other functions as a client with an OLED display for real-time data visualization.

Features
Real-time Monitoring: Receive precise environmental data, including temperature and pressure.
Seamless Wi-Fi Communication: Utilizes HTTP GET requests and responses for efficient data exchange.
User-Friendly Display: OLED display provides clear and immediate visualization of sensor data.
Setup
Access Point (AP):

Connect BMP280 sensor to ESP8266.
Upload the AP_Server_Code to the AP ESP8266.
Client:

Connect OLED display to ESP8266.
Upload the Client_Code to the client ESP8266.
Configure Wi-Fi:

Update Wi-Fi credentials in the code.
Dependencies
Adafruit_BMP280 Library
Adafruit_SSD1306 Library
Usage
Power up both ESP8266 boards.
Monitor environmental data on the OLED display.
