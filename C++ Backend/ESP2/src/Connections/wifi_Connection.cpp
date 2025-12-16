#include "wifi_Connection.h"
#include <WiFi.h>
#include "NetworkConfig.h"

namespace wifi {
    IPAddress local_IP(LOCAL_IP[0], LOCAL_IP[1], LOCAL_IP[2], LOCAL_IP[3]);
    IPAddress gateway(GATEWAY_IP[0], GATEWAY_IP[1], GATEWAY_IP[2], GATEWAY_IP[3]);
    IPAddress subnet(SUBNET_MASK[0], SUBNET_MASK[1], SUBNET_MASK[2], SUBNET_MASK[3]);

    unsigned long lastReconnectAttempt = 0;
    const unsigned long RECONNECT_INTERVAL = 5000;
    int consecutiveFailures = 0;
    const int MAX_FAILURES_BEFORE_RESTART = 5;

    void connectWiFi(unsigned long timeout) {
         
        WiFi.disconnect(true);
        WiFi.mode(WIFI_OFF);
        delay(500);

        WiFi.mode(WIFI_STA);

        if(!WiFi.config(local_IP, gateway, subnet)) {
            Serial.println("WiFi config failed");
        }

        WiFi.setAutoReconnect(true);
        WiFi.persistent(false);


        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        unsigned long startAttemptTime = millis();
        int dots = 0;

        while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < timeout) {
            delay(500);
            Serial.print(".");
            dots++;
            if (dots % 10 == 0) Serial.println();
        }

        if(WiFi.status() == WL_CONNECTED) {
            Serial.println("\n✓ WiFi Connected");
            Serial.printf("  IP: %s\n", WiFi.localIP().toString().c_str());
            Serial.printf("  RSSI: %d dBm\n", WiFi.RSSI());
            Serial.printf("  Channel: %d\n", WiFi.channel());
            consecutiveFailures = 0;
        } else {
            Serial.println("\n✗ WiFi Connection Failed");
            consecutiveFailures++;

             
            if (consecutiveFailures >= MAX_FAILURES_BEFORE_RESTART) {
                Serial.println("Too many failures, restarting ESP32...");
                delay(1000);
                ESP.restart();
            }
        }
    }

    void checkAndReconnect() {
        if (WiFi.status() == WL_CONNECTED) {
            consecutiveFailures = 0;
            return;
        }

        unsigned long currentTime = millis();

         
        if (currentTime - lastReconnectAttempt >= RECONNECT_INTERVAL) {
            lastReconnectAttempt = currentTime;

            Serial.println("\n!!! WiFi Disconnected !!!");
            Serial.printf("Reconnection attempt #%d\n", consecutiveFailures + 1);

             
            WiFi.disconnect(true);
            delay(100);
            WiFi.mode(WIFI_OFF);
            delay(100);
            WiFi.mode(WIFI_STA);

            if(!WiFi.config(local_IP, gateway, subnet)) {
                Serial.println("WiFi config failed on reconnect");
            }

            WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

             
            unsigned long start = millis();
            while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
                delay(500);
                Serial.print(".");
            }

            if (WiFi.status() == WL_CONNECTED) {
                Serial.println("\n✓ Reconnected!");
                Serial.printf("  RSSI: %d dBm\n", WiFi.RSSI());
                consecutiveFailures = 0;
            } else {
                Serial.println("\n✗ Reconnection failed");
                consecutiveFailures++;

                 
                if (consecutiveFailures >= MAX_FAILURES_BEFORE_RESTART) {
                    Serial.println("Max failures reached, restarting...");
                    delay(1000);
                    ESP.restart();
                }
            }
        }
    }

     
    bool isWiFiHealthy() {
        if (WiFi.status() != WL_CONNECTED) {
            return false;
        }

        int rssi = WiFi.RSSI();
         
        return rssi > -75;   
    }

    int getSignalQuality() {
        if (WiFi.status() != WL_CONNECTED) return 0;

        int rssi = WiFi.RSSI();
        if (rssi >= -50) return 100;
        if (rssi <= -100) return 0;
        return 2 * (rssi + 100);
    }
}
