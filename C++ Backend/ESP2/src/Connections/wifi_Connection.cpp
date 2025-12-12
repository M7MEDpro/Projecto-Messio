#include "wifi_Connection.h"
#include <WiFi.h>
#include "NetworkConfig.h"

namespace wifi {
    IPAddress local_IP(LOCAL_IP[0], LOCAL_IP[1], LOCAL_IP[2], LOCAL_IP[3]);
    IPAddress gateway(GATEWAY_IP[0], GATEWAY_IP[1], GATEWAY_IP[2], GATEWAY_IP[3]);
    IPAddress subnet(SUBNET_MASK[0], SUBNET_MASK[1], SUBNET_MASK[2], SUBNET_MASK[3]);

    void connectWiFi() {
        WiFi.config(local_IP, gateway, subnet);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        while (WiFiClass::status() != WL_CONNECTED) {
            delay(500);
        }
    }

}