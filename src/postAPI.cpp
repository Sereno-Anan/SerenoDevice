#include "postAPI.hpp"

void PostAPI::setHost(char *url)
{
    host = url;
}

StaticJsonDocument<JSON_OBJECT_SIZE(response_key)> PostAPI::post(StaticJsonDocument<JSON_OBJECT_SIZE(request_key)> json_request)
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
