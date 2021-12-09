#include "firebase_rtdb_client.hpp"

FirebaseRTDBClient::FirebaseRTDBClient()
{
    Serial.printf("\nFirebase Client v%s\n", FIREBASE_CLIENT_VERSION);
    config.api_key = firebase_api_key;
    auth.user.email = firebase_user_email;
    auth.user.password = firebase_user_password;
    config.database_url = firebase_rtdb_url;
    Serial.print("1");
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

void FirebaseRTDBClient::updateRTDB(FirebaseJson json)
{
    while(!Firebase.ready()){
        Serial.print(Firebase.ready());
        delay(100);
    }
    Serial.printf("Update node... %s\n", Firebase.RTDB.updateNode(&fbdo, "/", &json) ? "ok" : fbdo.errorReason().c_str());
    Serial.println();
}
