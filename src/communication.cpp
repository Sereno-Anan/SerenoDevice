#include "communication.hpp"
#include <M5StickC.h>

void Communication::setWiFi(char *ssid, char *password)
{
    this->ssid = ssid;
    this->password = password;
}

void Communication::setHost(char *url)
{
    host = url;
}

void Communication::connectWiFi()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}
StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> Communication::post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request)
{
    char buffer[255];
    serializeJson(json_request, buffer, sizeof(buffer));
    http.begin(host);
    http.addHeader("Content-Type", "application/json");
    int status_code = http.POST((uint8_t *)buffer, strlen(buffer));
    M5.Lcd.printf("%d", status_code);
    if (status_code == 201)
    {
        Stream *resp = http.getStreamPtr();
        DynamicJsonDocument json_response(255);
        deserializeJson(json_response, *resp);
        serializeJson(json_response, Serial);
        return json_response;
    }
    http.end();
}
