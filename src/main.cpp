#include <M5StickC.h>
#include "env.h"

// Firebase ESP Client
#include "firestore_client.hpp"
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

// Sensor
#include "sensor.hpp"

// Define parameters
#define WIFI_SSID wifi_ssid
#define WIFI_PASSWORD wifi_password
#define DEBUG_MODE true
#define INTERVAL_TIME 5
int sensorAnalogValue;
bool sensorStatus;

// Define FirestoreClient object
FirestoreClient firestoreClient;
FirebaseJson json;

// Define Sensor object
Sensor sensor;

void setup()
{
    setCpuFrequencyMhz(80);
    M5.begin(false, true, true);
    // スクリーンを真っ暗にする
    M5.Axp.ScreenBreath(0);

    // Initialize Sensor
    sensor.setPin(36);
    sensorAnalogValue = sensor.getStatus();
    sensorStatus = sensorAnalogValue > 1000;

    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("\nConnecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.print("\nConnected with IP: ");
    Serial.println(WiFi.localIP());

    configTime(9 * 3600, 0, "ntp.nict.jp");

    firestoreClient.config.token_status_callback = tokenStatusCallback;
    firestoreClient.setup();

    String documentPath = "test1";

    struct tm timeInfo;
    getLocalTime(&timeInfo);
    char now[24];
    sprintf(now, "%04d-%02d-%02dT%02d:%02d:%02dZ",
            timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday,
            timeInfo.tm_hour - 9, timeInfo.tm_min, timeInfo.tm_sec);
    json.set("fields/createdAt/timestampValue", now);
    json.set("fields/status/booleanValue", sensorStatus);
    json.set("fields/analogValue/integerValue", sensorAnalogValue);

    firestoreClient.addDocument(firebase_project_id, documentPath, json);

    setCpuFrequencyMhz(20);
    esp_deep_sleep(1000000LL * 60 * INTERVAL_TIME);
}

void loop()
{
}
