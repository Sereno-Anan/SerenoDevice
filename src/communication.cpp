#include "communication.hpp"

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
StaticJsonDocument<JSON_OBJECT_SIZE(10)> Communication::post(StaticJsonDocument<JSON_OBJECT_SIZE(10)> json_request)
{
    char buffer[255];
    serializeJson(json_request, buffer, sizeof(buffer));
    http.begin(host);
    http.addHeader("Content-Type", "application/json");
    int status_code = http.POST((uint8_t *)buffer, strlen(buffer));
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
