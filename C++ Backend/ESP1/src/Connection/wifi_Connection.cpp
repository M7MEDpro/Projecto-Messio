#include "wifi_Connection.h"

#include <WiFi.h>

namespace wifi {
    const char* ssid = "oppo reno 14 5G";
    const char* password = "1234567890";
    IPAddress local_IP(10, 205, 248, 101);
    IPAddress gateway(10, 205, 248, 70);
    IPAddress subnet(255, 255, 255, 0);

    unsigned long lastReconnectAttempt = 0;
    const unsigned long RECONNECT_INTERVAL = 5000; // Try reconnect every 5 seconds

    void connectWiFi() {
        WiFi.config(local_IP, gateway, subnet);
        WiFi.begin(ssid, password);

        Serial.print("Connecting to WiFi");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.println("\nWiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }

    void checkAndReconnect() {
        if (WiFi.status() != WL_CONNECTED) {
            unsigned long currentTime = millis();

            // Avoid trying to reconnect too frequently
            if (currentTime - lastReconnectAttempt >= RECONNECT_INTERVAL) {
                lastReconnectAttempt = currentTime;

                Serial.println("WiFi disconnected. Attempting to reconnect...");
                WiFi.disconnect();
                delay(100);

                WiFi.config(local_IP, gateway, subnet);
                WiFi.begin(ssid, password);

                // Wait up to 10 seconds for connection
                int attempts = 0;
                while (WiFi.status() != WL_CONNECTED && attempts < 20) {
                    delay(500);
                    Serial.print(".");
                    attempts++;
                }

                if (WiFi.status() == WL_CONNECTED) {
                    Serial.println("\nReconnected to WiFi!");
                    Serial.print("IP Address: ");
                    Serial.println(WiFi.localIP());
                } else {
                    Serial.println("\nReconnection failed. Will retry later.");
                }
            }
        }
    }

}