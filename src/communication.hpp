#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP
#include <HTTPClient.h>
#include <ArduinoJson.h>

class Communication
{
private:
    HTTPClient http;
    char *ssid;
    char *password;
    char *host;
public:
    void setWiFi(char *wifi_ssid, char *wifi_password);
    void setHost(char *url);
    void connectWiFi(); //WiFiに接続
    StaticJsonDocument<JSON_OBJECT_SIZE(10)> post(StaticJsonDocument<JSON_OBJECT_SIZE(10)> json_request);  //APIをたたく
};
#endif // COMMUNICATION_HPP