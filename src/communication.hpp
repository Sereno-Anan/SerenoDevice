#include <WiFi.cpp>
#include <HTTPClient.h>
#include <ArduinoJson.h>

extern const int capacity;
extern char *url;
extern char *wifi_ssid;
extern char *wifi_password;

class Communication
{
private:
    HTTPClient http;
public:
    void connectWiFi(); //WiFiに接続
    StaticJsonDocument<JSON_OBJECT_SIZE(capacity)> post(StaticJsonDocument<JSON_OBJECT_SIZE(capacity)> json_request);  //APIをたたく
};