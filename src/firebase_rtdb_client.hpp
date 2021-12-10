#include <Firebase_ESP_Client.h>
#include "env.h"
#include <WiFi.h>

class FirebaseRTDBClient
{
private:
    FirebaseData fbdo;
    FirebaseAuth auth;

public:
    FirebaseConfig config;
    void setup();
    void updateRTDB(FirebaseJson json);
};