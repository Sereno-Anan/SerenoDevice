#ifndef SHEET_DB_HPP
#define SHEET_DB_HPP
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "json_key.cpp"

class SheetDB
{
private:
    HTTPClient http;
    const char *host;

public:
    void setHost(const char *url);
    StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request); // APIをたたく
};
#endif