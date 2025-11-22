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
        httpClient.begin("http://192.168.1.200:5000/esp1");
        httpClient.addHeader("Content-Type", "application/json");

        DynamicJsonDocument doc(2048);
        JsonObject esp1Obj = doc.createNestedObject("esp1");

        for (const auto& pair : data) {
            esp1Obj[pair.first] = pair.second.toInt();
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
        std::vector<std::pair<String, String>> data;
        data.push_back({key, value});
        send_batch(data);
    }

    std::map<String, String> read_batch(const std::vector<String>& keys) {
        std::map<String, String> results;
        if (keys.empty()) return results;

        initClient();
        httpClient.begin("http://192.168.1.200:5000/esp1");

        int code = httpClient.GET();

        if (code == 200) {
            String payload = httpClient.getString();
            DynamicJsonDocument doc(2048);
            DeserializationError err = deserializeJson(doc, payload);

            if (!err) {
                for (const String& key : keys) {
                    if (doc.containsKey(key)) {
                        // Handle all types - int, string, bool
                        if (doc[key].is<int>()) {
                            results[key] = String(doc[key].as<int>());
                        } else if (doc[key].is<bool>()) {
                            results[key] = doc[key].as<bool>() ? "true" : "false";
                        } else if (doc[key].is<const char*>()) {
                            results[key] = doc[key].as<String>();
                        } else {
                            results[key] = doc[key].as<String>();
                        }
                        cache[key] = CacheEntry{results[key], millis(), true};
                    }
                }
            }
        } else {
            Serial.println("HTTP Batch GET failed, code: " + String(code));
        }

        return results;
    }

    String read_data(const String& key) {
        // Check cache first
        auto it = cache.find(key);
        if (it != cache.end() && it->second.valid) {
            if (millis() - it->second.timestamp < CACHE_DURATION) {
                return it->second.value;
            }
        }

        std::vector<String> keys = {key};
        auto results = read_batch(keys);

        if (results.find(key) != results.end()) {
            return results[key];
        }

        return "";
    }

    void clearCache() {
        cache.clear();
    }
}