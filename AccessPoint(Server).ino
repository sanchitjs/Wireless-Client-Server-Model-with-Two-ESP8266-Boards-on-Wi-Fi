#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>

// Set access point network credentials
const char* ssid = "Sanchit's NodeMCU AP";
const char* password = "123456789";

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP280 bmp; // I2C

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readTemp() {
  return String(bmp.readTemperature());
  //return String(1.8 * bmp.readTemperature() + 32);
}

String readPres() {
  return String(bmp.readPressure() / 100.0F);
}

String readAlti() {
  return String(bmp.readAltitude(SEALEVELPRESSURE_HPA));
}



void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readTemp().c_str());
  });

  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readPres().c_str());
  });
  
  server.on("/altitude", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readAlti().c_str());
  });
  
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a 
    valid BMP280 sensor, check wiring!");
    while (1);
  }
  
  // Start server
  server.begin();
}
 
void loop(){
  
}
