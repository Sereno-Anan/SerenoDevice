#include <M5StickC.h>
#include <WiFi.h>
#include "Wi-Fi.h"

const char *ssid = wifi_ssid;
const char *password = wifi_password;

int PIN = 36;

void ota();

void setup()
{
  M5.begin();
  ota();

  pinMode(PIN, ANALOG);
}

void loop()
{
  Serial.printf("G36: %04d\n", analogRead(PIN));
  delay(500);
}
