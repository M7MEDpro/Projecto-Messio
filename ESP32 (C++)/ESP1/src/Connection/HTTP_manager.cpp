#include "HTTP_manager.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

namespace http {

    static HTTPClient httpClient;
    static bool clientInitialized = false;


    struct CacheEntry {
        String value;
        unsigned long timestamp{};
        bool valid{};

        // Add constructors to fix compilation errors
        CacheEntry() = default;
        CacheEntry(String v, unsigned long t, bool val)
            : value(std::move(v)), timestamp(t), valid(val) {}
    };

    static std::map<String, CacheEntry> cache;
    static const unsigned long CACHE_DURATION = 500;

    void initClient() {
        if (!clientInitialized) {
            httpClient.setReuse(true);
            httpClient.setTimeout(2000);
            clientInitialized = true;
        }
    }

    bool send_batch(const std::vector<std::pair<String, String>>& data) {
        if (data.empty()) return false;

        initClient();
        httpClient.begin("http://192.168.1.200:5000/data?batch=true");
        httpClient.addHeader("Content-Type", "application/json");

        DynamicJsonDocument doc(2048);
        JsonArray arr = doc.createNestedArray("data");

        for (const auto& pair : data) {
            JsonObject obj = arr.createNestedObject();
            obj["key"] = pair.first;
            obj["value"] = pair.second;
        }

        String payload;
        serializeJson(doc, payload);

        int code = httpClient.POST(payload);

        if (code != 200) {
            Serial.println("HTTP Batch POST failed, code: " + String(code));
            return false;
        }

        return true;
    }

    void send_data(const String& key, const String& value) {
        initClient();
        httpClient.begin("http://192.168.1.200:5000/data");
        httpClient.addHeader("Content-Type", "application/json");

        StaticJsonDocument<256> doc;
        doc["key"] = key;
        doc["value"] = value;

        String payload;
        serializeJson(doc, payload);

        int code = httpClient.POST(payload);

        if (code != 200) {
            Serial.println("HTTP POST failed, code: " + String(code));
        }
    }

    std::map<String, String> read_batch(const std::vector<String>& keys) {
        std::map<String, String> results;
        if (keys.empty()) return results;

        initClient();

        String url = "http://192.168.1.200:5000/data?batch=true&keys=";
        for (size_t i = 0; i < keys.size(); i++) {
            if (i > 0) url += ",";
            url += keys[i];
        }

        httpClient.begin(url);
        int code = httpClient.GET();

        if (code == 200) {
            String payload = httpClient.getString();
            DynamicJsonDocument doc(2048);
            DeserializationError err = deserializeJson(doc, payload);

            if (!err) {
                for (const String& key : keys) {
                    if (doc.containsKey(key)) {
                        results[key] = doc[key].as<String>();

                        cache[key] = CacheEntry{doc[key].as<String>(), millis(), true};
                    }
                }
            }
        } else {
            Serial.println("HTTP Batch GET failed, code: " + String(code));
        }

        return results;
    }

    String read_data(const String& key) {
        auto it = cache.find(key);
        if (it != cache.end() && it->second.valid) {
            if (millis() - it->second.timestamp < CACHE_DURATION) {
                return it->second.value;
            }
        }

        initClient();
        String url = "http://192.168.1.200:5000/data?key=" + key;
        httpClient.begin(url);

        int code = httpClient.GET();
        String value = "";

        if (code == 200) {
            String payload = httpClient.getString();
            StaticJsonDocument<256> doc;
            DeserializationError err = deserializeJson(doc, payload);

            if (!err && doc.containsKey(key)) {
                value = doc[key].as<String>();
                cache[key] = CacheEntry{value, millis(), true};
            }
        } else {
            Serial.println("HTTP GET failed, code: " + String(code));
        }

        return value;
    }

    void clearCache() {
        cache.clear();
    }
}