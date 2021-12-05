#ifndef SHEET_DB_HPP
#define SHEET_DB_HPP
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "json_key.cpp"

class SheetDB
{
private:
    HTTPClient http;
    char *host;

public:
    void setHost(char *url);
    StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request); // APIをたたく
};
#endif