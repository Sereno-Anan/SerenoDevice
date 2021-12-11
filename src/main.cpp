#include <M5StickC.h>
#include "env.h"

// SheetDB
#include <ArduinoJson.h>
#include "sheet_db.hpp"
#include "json_key.cpp"

// Firebase ESP Client
#include "firebase_rtdb_client.hpp"
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

// Sensor
#include "sensor.hpp"

// Define Firebase variables
#define WIFI_SSID wifi_ssid
#define WIFI_PASSWORD wifi_password

unsigned long sendDataPrevMillis = 0;
unsigned long count = 0;

// Define SheetDB object
const char *url = host_url;
SheetDB sheetDB;
StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request;
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> json_response;

// Define FirebaseRTDBClient object
FirebaseRTDBClient firebaseRTDBClient;

// Define Sensor
Sensor sensor;

void setup()
{
  M5.begin();
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\nConnecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nConnected with IP: ");
  Serial.println(WiFi.localIP());

  // Initialize SheetDB
  sheetDB.setHost(url);

  // Initialize FirebaseRTDBClient
  firebaseRTDBClient.config.token_status_callback = tokenStatusCallback;
  firebaseRTDBClient.setup();

  // Initialize Sensor
  sensor.setPin(36);
}

void loop()
{
  M5.update();
  json_request["weather"] = "rain";
  json_request["time"] = 100;
  json_response = sheetDB.post(json_request);

  if ((millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
    FirebaseJson json;
    json.set("raindrops/timestamp/.sv", "timestamp");
    json.set("raindrops/status/", 1 == sensor.getValue());
    firebaseRTDBClient.updateRTDB(json);
    sendDataPrevMillis = millis();
    count++;
  }
}
