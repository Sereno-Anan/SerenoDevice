#include <M5StickC.h>
#include <ArduinoJson.h>
#include "Wi-Fi.h"
#include "communication.hpp"
#include "key.cpp"

char *ssid = wifi_ssid;
char *password = wifi_password;
char *url = host_url;
Communication com;
StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request;
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> json_response;

void setup()
{
  M5.begin();
  com.setWiFi(ssid, password);
  com.connectWiFi();
  com.setHost(url);
}

void loop()
{
  /*
  json_request["weather"] = "rain";
  json_request["time"] = 100;
  */
  json_response = com.post(json_request);
  delay(500);
}
