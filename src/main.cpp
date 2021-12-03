#include <M5StickC.h>
#include <ArduinoJson.h>
#include "Wi-Fi.h"
#include "communication.hpp"
#include "key.cpp"

char *ssid = wifi_ssid;
char *password = wifi_password;
char *url = host_url;
Communication com;
StaticJsonDocument<request_key> json_request;
StaticJsonDocument<response_key> json_response;

void setup()
{
  M5.begin();
  com.setWiFi(ssid, password);
  com.connectWiFi();
  com.setHost(url);
  
  json_request["btn"] = "AAAA";
  json_request["time"] = 5;
  json_response = com.post(json_request);
}

void loop()
{
  delay(500);
}
