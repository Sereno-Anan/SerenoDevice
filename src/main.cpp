#include <M5StickC.h>
#include "env.h"

// SheetDB
#include <ArduinoJson.h>
#include "sheet_db.hpp"
#include "json_key.cpp"

// Firebase ESP Client
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

// define Firebase
#define WIFI_SSID wifi_ssid
#define WIFI_PASSWORD wifi_password
#define API_KEY firebase_api_key
#define DATABASE_URL firebase_rtdb_url
#define USER_EMAIL firebase_user_email
#define USER_PASSWORD firebase_user_password

unsigned long sendDataPrevMillis = 0;
unsigned long count = 0;

// Define Firebase object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

const char *ssid = wifi_ssid;
const char *password = wifi_password;
const char *url = host_url;
SheetDB sheetDB;
StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request;
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> json_response;

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

  Serial.printf("\nFirebase Client v%s\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Initialize SheetDB
  sheetDB.setHost(url);
}

void loop()
{
  M5.update();
  /*
  json_request["weather"] = "rain";
  json_request["time"] = 100;
  */
  json_response = sheetDB.post(json_request);
  delay(500);
}
