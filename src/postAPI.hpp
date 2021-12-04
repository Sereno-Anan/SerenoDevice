#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "key.cpp"

class PostAPI
{
private:
    HTTPClient http;
    char *host;

public:
    void setHost(char *url);
    StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request); // APIをたたく
};
#endif // COMMUNICATION_HPP