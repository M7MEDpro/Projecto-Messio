#include "HTTP_manager.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

namespace http {

    void send_data(const String& key, const String& value) {
        HTTPClient http;
        http.begin("http://192.168.1.200:5000/data");
        http.addHeader("Content-Type", "application/json");

        DynamicJsonDocument doc(1024);
        doc["key"] = key;
        doc["value"] = value;

        String payload;
        serializeJson(doc, payload);

        int code = http.POST(payload);
        Serial.println("HTTP Response code: " + String(code));

        http.end();
    }


    String read_data(const String& key) {

        HTTPClient http;
        String url = "http://192.168.1.200:5000/data?key=" + key;
        http.begin(url);

        int code = http.GET();
        String value = "";

        if (code == 200) {
            String payload = http.getString();

            // Parse JSON and get the value
            StaticJsonDocument<200> doc;
            DeserializationError err = deserializeJson(doc, payload);
            if (!err && doc.containsKey(key)) {
                value = doc[key].as<String>();
            }
        } else {
            Serial.println("HTTP GET failed, code: " + String(code));
        }

        http.end();
        return value;
    }


}