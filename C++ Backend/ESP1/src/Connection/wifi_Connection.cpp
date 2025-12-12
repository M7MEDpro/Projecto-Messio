#include "wifi_Connection.h"
#include <WiFi.h>
#include "NetworkConfig.h"

namespace wifi {
    IPAddress local_IP(LOCAL_IP[0], LOCAL_IP[1], LOCAL_IP[2], LOCAL_IP[3]);
    IPAddress gateway(GATEWAY_IP[0], GATEWAY_IP[1], GATEWAY_IP[2], GATEWAY_IP[3]);
    IPAddress subnet(SUBNET_MASK[0], SUBNET_MASK[1], SUBNET_MASK[2], SUBNET_MASK[3]);

    unsigned long lastReconnectAttempt = 0;
    const unsigned long RECONNECT_INTERVAL = 5000; // Try reconnect every 5 seconds

    void connectWiFi() {
        WiFi.config(local_IP, gateway, subnet);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

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
        if (WiFi.status() == WL_CONNECTED) {
            return;
        }

        unsigned long currentTime = millis();

        if (currentTime - lastReconnectAttempt >= RECONNECT_INTERVAL) {
            lastReconnectAttempt = currentTime;

            Serial.println("WiFi disconnected. Attempting to reconnect...");
            
 

            WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
            

        }
    }

}