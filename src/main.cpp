#include <M5StickC.h>
#include <ArduinoJson.h>
#include "Wi-Fi.h"
#include "sheet_db.hpp"
#include "json_key.cpp"

char *ssid = wifi_ssid;
char *password = wifi_password;
char *url = host_url;
SheetDB sheetDB;
StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request;
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> json_response;

void setup()
{
  M5.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
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
