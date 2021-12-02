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
    StaticJsonDocument<capacity> post(StaticJsonDocument<capacity> json_request);  //APIをたたく
};