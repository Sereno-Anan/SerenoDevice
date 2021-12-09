#include <Firebase_ESP_Client.h>
#include "env.h"
#include <WiFi.h>

class FirebaseRTDBClient
{
private:
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
public:
    FirebaseRTDBClient();
    void updateRTDB(FirebaseJson json);
};