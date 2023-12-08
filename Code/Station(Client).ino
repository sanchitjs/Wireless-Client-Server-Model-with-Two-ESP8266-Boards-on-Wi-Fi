#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

//Required credentials for connecting to the AP
const char* ssid = "Sanchit's NodeMCU AP";
const char* password = "123456789";

//Different domain name with URL path for respective requests
const char* serverNameTemp = "http://192.168.4.1/temperature";
const char* serverNamePres = "http://192.168.4.1/pressure";
const char* serverNameAlti = "http://192.168.4.1/altitude";

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String temperature;
String pressure;
String altitude;


unsigned long previousMillis = 0;
const long interval = 5000; 

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if ((WiFi.status() == WL_CONNECTED)) {
      temperature = httpGETRequest(serverNameTemp);
      pressure = httpGETRequest(serverNamePres);
      altitude = httpGETRequest(serverNameAlti);
      
      Serial.println("Temperature: " + temperature + " *C - Pressure: " + pressure + " hPa - Approx. Altitude: " + altitude + " m");
      
      display.clearDisplay();
      
      // display temperature
      display.setTextSize(2);
      display.setCursor(0,0);
      display.print("T:");
      display.print(temperature);
      display.print(" ");
      display.setTextSize(1);
      display.cp437(true);
      display.write(248);
      display.setTextSize(2);
      display.print("C");

      // display pressure
      display.setTextSize(2);
      display.setCursor(0, 25);
      display.print("P:");
      display.print(pressure);
      display.setTextSize(1);
      display.setCursor(110, 33);
      display.print("hPa");
      
      // display altitude
      display.setTextSize(2);
      display.setCursor(0, 50);
      display.print("A:");
      display.print(altitude);
      display.print(" m"); 
                 
      display.display();
      
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
