#include <M5StickC.h>
#include <ArduinoJson.h>
#include "Wi-Fi.h"
#include "communication.hpp"
#include "info.h"
char *ssid = wifi_ssid;
char *password = wifi_password;
char *url = host_url;
const int capacity = JSON_OBJECT_SIZE(10);  //keyの数を定義
Communication com;

void setup()
{
  M5.begin();
  com.setWiFi(ssid, password);
  com.connectWiFi();
  com.setHost(url);
  StaticJsonDocument<capacity> json_request;
  json_request["btn"] = "ABCD";
  json_request["time"] = 2;
  StaticJsonDocument<capacity> json_response = com.post(json_request);
}

void loop()
{
  delay(500);
}
