            }

            String payload;
            serializeJson(doc, payload);

            int code = httpClient.PUT(payload);

            if (code != 200) {
                Serial.println("HTTP PUT failed: " + String(code));
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
            httpClient.begin(SERVER_URL_GET);

            int code = httpClient.GET();

            if (code == 200) {
                String payload = httpClient.getString();
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
                }
            } else {
                Serial.println("HTTP GET failed: " + String(code));
            }

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
    }