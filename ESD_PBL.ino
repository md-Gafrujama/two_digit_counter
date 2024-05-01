
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "Galaxy S10";
const char* password = "aisha1234";

// ThingSpeak channel settings
unsigned long channelID =  2524820;             // Your ThingSpeak Channel ID
const char* writeAPIKey = "Y8H5YOW41ECKZB2Y";  // Your ThingSpeak Write API Key

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(1000);
    return;
  }

  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(3.3/1024);
  Serial.print("Voltage = ");
  Serial.println(voltage);
  
  // Sending Data to ThingSpeak
  ThingSpeak.setField(1, voltage);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully.\n");
  } else {
    Serial.print("Error sending data to ThingSpeak. HTTP error code ");
    Serial.println(response);
  }
  delay(15000);
}