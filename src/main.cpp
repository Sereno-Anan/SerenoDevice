#include <M5StickC.h>
#include <WiFi.h>
#include "Wi-Fi.h"
#include "communication.hpp"
#include <communication.hpp>

const char *ssid = wifi_ssid;
const char *password = wifi_password;

int PIN = 36;

void setup()
{
  M5.begin();
  StaticJsonDocument<capacity> request;
  pinMode(PIN, ANALOG);
}

void loop()
{
  Serial.printf("G36: %04d\n", analogRead(PIN));
  delay(500);
}
