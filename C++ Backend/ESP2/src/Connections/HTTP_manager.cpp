#include "HTTP_manager.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "NetworkConfig.h"

namespace http {

    // Separate clients for GET and PUT to avoid conflicts
    static HTTPClient putClient;
    static HTTPClient getClient;
    static bool putClientReady = false;
    static bool getClientReady = false;

    static std::map<String, String> cache;
    static const unsigned long CACHE_DURATION = 500;
    static std::map<String, unsigned long> cacheTime;

    // Configuration
    static const int MAX_RETRIES = 2;  // Reduced retries, faster failure
    static const int TIMEOUT_MS = 500;  // Longer timeout
    static const int CONNECT_TIMEOUT_MS = 500;

    // Statistics for monitoring
    static unsigned long successCount = 0;
    static unsigned long failCount = 0;
    static unsigned long totalRequests = 0;

    void initPutClient() {
        if (!putClientReady) {
            putClient.setReuse(false);  // ✅ Disable reuse - create fresh connection
            putClient.setTimeout(TIMEOUT_MS);
            putClient.setConnectTimeout(CONNECT_TIMEOUT_MS);
            putClientReady = true;
        }
    }

    void initGetClient() {
        if (!getClientReady) {
            getClient.setReuse(false);  // ✅ Disable reuse
            getClient.setTimeout(TIMEOUT_MS);
            getClient.setConnectTimeout(CONNECT_TIMEOUT_MS);
            getClientReady = true;
        }
    }

    void printStats() {
        if (totalRequests % 20 == 0 && totalRequests > 0) {
            float successRate = (float)successCount / totalRequests * 100.0;
            Serial.printf("HTTP Stats: %lu/%lu success (%.1f%%)\n",
                         successCount, totalRequests, successRate);
        }
    }

    bool send_batch(const std::vector<std::pair<String, String>>& data) {
        if (data.empty()) return false;

        totalRequests++;
        initPutClient();

        // Check WiFi before attempting
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("WiFi not connected, skipping PUT");
            failCount++;
            return false;
        }

        for (int attempt = 0; attempt < MAX_RETRIES; attempt++) {
            // ✅ Fresh connection each time
            putClient.end();

            if (!putClient.begin(SERVER_URL_PUT)) {
                Serial.printf("PUT begin() failed (attempt %d)\n", attempt + 1);
                delay(50 * (attempt + 1));
                continue;
            }

            putClient.addHeader("Content-Type", "application/json");
            putClient.addHeader("Connection", "close");  // ✅ Force close after request

            DynamicJsonDocument doc(2048);
            for (const auto& pair : data) {
                doc[pair.first] = pair.second.toInt();
            }

            String payload;
            serializeJson(doc, payload);

            int code = putClient.PUT(payload);
            putClient.end();  // ✅ Immediately close

            if (code == 200) {
                successCount++;
                printStats();
                return true;
            }

            if (code > 0) {
                Serial.printf("PUT HTTP error %d (attempt %d)\n", code, attempt + 1);
            } else {
                // Negative codes are HTTPClient errors
                const char* errorMsg = "";
                switch(code) {
                    case -1: errorMsg = "Connection refused"; break;
                    case -2: errorMsg = "Send header failed"; break;
                    case -3: errorMsg = "Send payload failed"; break;
                    case -4: errorMsg = "Not connected"; break;
                    case -5: errorMsg = "Connection lost"; break;
                    case -6: errorMsg = "No stream"; break;
                    case -7: errorMsg = "No HTTP server"; break;
                    case -8: errorMsg = "Too less RAM"; break;
                    case -9: errorMsg = "Encoding error"; break;
                    case -10: errorMsg = "Stream write error"; break;
                    case -11: errorMsg = "Read timeout"; break;
                    default: errorMsg = "Unknown error"; break;
                }
                Serial.printf("PUT error %d: %s (attempt %d)\n", code, errorMsg, attempt + 1);
            }

            // Don't retry on client errors (400-499)
            if (code >= 400 && code < 500) {
                break;
            }

            // Small delay before retry
            if (attempt < MAX_RETRIES - 1) {
                delay(100 * (attempt + 1));
            }
        }

        failCount++;
        printStats();
        return false;
    }

    void send_data(const String& key, const String& value) {
        std::vector<std::pair<String, String>> data;
        data.push_back({key, value});
        send_batch(data);
    }

    std::map<String, String> read_batch(const std::vector<String>& keys) {
        std::map<String, String> results;
        if (keys.empty()) return results;

        totalRequests++;
        initGetClient();

        // Check WiFi before attempting
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("WiFi not connected, skipping GET");
            failCount++;
            return results;
        }

        for (int attempt = 0; attempt < MAX_RETRIES; attempt++) {
            // ✅ Fresh connection each time
            getClient.end();

            if (!getClient.begin(SERVER_URL_GET)) {
                Serial.printf("GET begin() failed (attempt %d)\n", attempt + 1);
                delay(50 * (attempt + 1));
                continue;
            }

            getClient.addHeader("Connection", "close");  // ✅ Force close

            int code = getClient.GET();

            if (code == 200) {
                String payload = getClient.getString();
                getClient.end();  // ✅ Immediately close

                DynamicJsonDocument doc(2048);
                DeserializationError err = deserializeJson(doc, payload);

                if (!err) {
                    for (const String& key : keys) {
                        if (doc.containsKey(key)) {
                            results[key] = String(doc[key].as<int>());
                            cache[key] = results[key];
                            cacheTime[key] = millis();
                        }
                    }
                    successCount++;
                    printStats();
                    return results;
                }
                Serial.println("GET JSON parse error");
            } else {
                getClient.end();

                if (code > 0) {
                    Serial.printf("GET HTTP error %d (attempt %d)\n", code, attempt + 1);
                } else {
                    const char* errorMsg = "";
                    switch(code) {
                        case -1: errorMsg = "Connection refused"; break;
                        case -11: errorMsg = "Read timeout"; break;
                        default: errorMsg = "Connection error"; break;
                    }
                    Serial.printf("GET error %d: %s (attempt %d)\n", code, errorMsg, attempt + 1);
                }

                // Don't retry on client errors
                if (code >= 400 && code < 500) {
                    break;
                }
            }

            // Small delay before retry
            if (attempt < MAX_RETRIES - 1) {
                delay(100 * (attempt + 1));
            }
        }

        failCount++;
        printStats();
        return results;
    }

    String read_data(const String& key) {
        if (cache.find(key) != cache.end()) {
            if (millis() - cacheTime[key] < CACHE_DURATION) {
                return cache[key];
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
        cacheTime.clear();
    }

    void resetStats() {
        successCount = 0;
        failCount = 0;
        totalRequests = 0;
    }
}