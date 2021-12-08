#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
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
    void begin();
    void updateRTDB(bool status);
};