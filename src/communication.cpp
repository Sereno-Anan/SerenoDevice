#include "communication.hpp"
const int capacity = 10; //JsonKeyの数
void Communication::connectWiFi()
{
    WiFi.begin(wifi_ssid, wifi_password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}
StaticJsonDocument<JSON_OBJECT_SIZE(capacity)> Communication::post(StaticJsonDocument<JSON_OBJECT_SIZE(capacity)> json_request)
{
    char buffer[255];
    serializeJson(json_request, Serial);
    serializeJson(json_request, buffer, sizeof(buffer));
    http.begin(url);
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
