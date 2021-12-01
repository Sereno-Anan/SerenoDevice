#include <HTTPClient.h>
#include <ArduinoJson.h>

class Communication{
    private:
    HTTPClient http;
    char *url;
    char *ssid;
    char *password;
    void connectWiFi();
    void post();
};