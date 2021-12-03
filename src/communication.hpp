#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "key.cpp"

class Communication
{
private:
    HTTPClient http;
    char *ssid;
    char *password;
    char *host;

public:
    void setWiFi(char *ssid, char *password);
    void setHost(char *url);
    void connectWiFi();                                                                                                      // WiFiに接続
    StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request); // APIをたたく
};
#endif // COMMUNICATION_HPP