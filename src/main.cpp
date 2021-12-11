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

RTC_DATA_ATTR static int lastValue = -1; // remember number in RTC Memory

#define DEBUG_MODE true
#define INTERVAL_TIME 1

// Define Firebase variables
#define WIFI_SSID wifi_ssid
#define WIFI_PASSWORD wifi_password

// Define SheetDB object
const char *url = host_url;
SheetDB sheetDB;
StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request;
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> json_response;
// Define FirebaseRTDBClient object
FirebaseRTDBClient firebaseRTDBClient;
FirebaseJson json;
// Define Sensor
Sensor sensor;

int value;

void setup()
{
  setCpuFrequencyMhz(80);
  M5.begin(false, true, true);
  M5.Axp.ScreenBreath(0);
  // Initialize Sensor
  sensor.setPin(36);
  value = sensor.getValue();
  if (value == lastValue && DEBUG_MODE == false) //  センサの値が前回更新した値と等しいとき
  {
    setCpuFrequencyMhz(20);
    esp_deep_sleep(1000000LL * 60 * INTERVAL_TIME);
  }
  lastValue = value;

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

  json.set("raindrops/timestamp/.sv", "timestamp");
  json.set("raindrops/status/", 1 == value);
  firebaseRTDBClient.updateRTDB(json);

  setCpuFrequencyMhz(20);
  esp_deep_sleep(1000000LL * 60 * INTERVAL_TIME);
}

void loop()
{
}
