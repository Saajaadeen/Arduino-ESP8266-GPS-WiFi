#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

void ledStartup(int times);
void createWebServer();
void displayGPSData();

const int ledPin = 2;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(4, 5);

// Connect to a wifi network
const char* ssid     = "Wifi Network";   
const char* password = "Wifi Password";  
WiFiServer webServer(80);                

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(9600);
    // Startup Delay of 5 seconds
    delay(5000);
    Serial.println();
    
    ledStartup(5);
    createWebServer();
}
void loop() {
    displayGPSData();
}
void createWebServer() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.print(".");
    }
    webServer.begin();
    Serial.println();
    Serial.print("[+] Connected to network, Webserver IP: http://");
    Serial.print(WiFi.localIP());
    delay(10000);
    Serial.println();
    Serial.print("[+] Requesting new GPS data streams");
    delay(1500);
    Serial.println();
}
void displayGPSData() {
    // Check if gps signal is availble
    while (gpsSerial.available() > 0) {
        char c = gpsSerial.read();
        gps.encode(c);
    }
    if (gps.location.isValid()) {       
        // Lat-Long & Time-Date float/int declaration
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();
        int satellites = gps.satellites.value();
        int year = gps.date.year();
        int month = gps.date.month();
        int day = gps.date.day();
        int hourUTC = gps.time.hour();
        int minute = gps.time.minute();
        int second = gps.time.second();
        int hourPST = (hourUTC - 8 + 24) % 24;

        // Prepare the HTML response
        String htmlResponse = "<html><body>";
        htmlResponse += "<center><h1>GPS Data</h1></center>";
        htmlResponse += "<center><p>Satellites: " + String(satellites) + "</p></center>";
        htmlResponse += "<center><p>Latitude: " + String(latitude, 6) + "</p></center>";
        htmlResponse += "<center><p>Longitude: " + String(longitude, 6) + "</p></center>";
        htmlResponse += "<center><p>Date: " + String(year) + "/" + String(month) + "/" + String(day) + "</p></center>";
        htmlResponse += "<center><p>Time: " + String(hourPST) + ":" + String(minute) + ":" + String(second) + "</p></center>";
        htmlResponse += "</body></html>";

        WiFiClient client = webServer.accept();
        if (client) {
            // Send the HTML response to the client
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();
            client.println(htmlResponse);
            client.flush();
            client.stop();
        }
        // Serial monitor data    
        Serial.println("Satellites: " + String(satellites));
        Serial.println("Latitude: " + String(latitude, 6));
        Serial.println("Longitude: " + String(longitude, 6));
        Serial.println("Date: " + String(year) + "/" + String(month) + "/" + String(day));
        Serial.println("Time: " + String(hourPST) + ":" + String(minute) + ":" + String(second));
        // Serial monitor data
    } else {
        Serial.println("[x] Bad GPS data stream, wait 60 seconds");
    }   
}
void ledStartup(int times) {
    // Flash the LED 5 times
    for (int i = 0; i < times; i++) {
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
        delay(300);
    }
    // Turn off GPIO2 (LED)
    pinMode(ledPin, INPUT); 
    // Startup message
    Serial.println("[+] Board startup Complete");
}