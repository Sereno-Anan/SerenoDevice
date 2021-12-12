#include "firestore_client.hpp"

void FirestoreClient::setup()
{
    Serial.printf("\nFirebase Client v%s\n", FIREBASE_CLIENT_VERSION);
    config.api_key = firebase_api_key;
    auth.user.email = firebase_user_email;
    auth.user.password = firebase_user_password;

    // Assign the callback function for the long running token generation task
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

void FirestoreClient::addDocument(String firebaseProjectId, String documentPath, FirebaseJson json)
{
    while (!Firebase.ready())
        ;
    if (Firebase.Firestore.createDocument(&fbdo, firebaseProjectId, "" /* databaseId can be (default) or empty */, documentPath.c_str(), json.raw()))
        Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
    else
        Serial.println(fbdo.errorReason());
}
