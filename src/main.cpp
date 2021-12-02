#include <M5StickC.h>
#include <Wi-Fi.h>
#include "Wi-Fi.h"
#include <communication.hpp>
#include <ArduinoJson.h>

const char *ssid = wifi_ssid;
const char *password = wifi_password;
const int capacity = JSON_OBJECT_SIZE(10);

void setup()
{
  M5.begin();
  StaticJsonDocument<capacity> json_request;
  json_request["btn"] = "ABCD";
  json_request["time"] = 2;
  Communication com;
  com.connectWiFi();
  StaticJsonDocument<capacity> json_response = com.post(json_request);
}

void loop()
{
  delay(500);
}
