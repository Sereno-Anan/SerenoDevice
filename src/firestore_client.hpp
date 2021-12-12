#include <Firebase_ESP_Client.h>
#include "env.h"
#include <WiFi.h>

class FirestoreClient
{
private:
    FirebaseData fbdo;
    FirebaseAuth auth;

public:
    FirebaseConfig config;
    void setup();
    void addDocument(String firebaseProjectId, String documentPath, FirebaseJson json);
};