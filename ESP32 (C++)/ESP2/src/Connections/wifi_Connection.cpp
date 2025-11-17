#include "wifi_Connection.h"

#include <WiFi.h>

namespace wifi {
    const  char* ssid = "oppo reno 14 5G";
    const  char*  password = "1234567890";
    IPAddress local_IP(192, 168, 1 101);
    IPAddress gateway(192, 168,1 , 1);
    IPAddress subnet(255, 255, 255, 0);
    void connectWiFi() {
        WiFi.config(local_IP, gateway, subnet);
        WiFi.begin(ssid,password);
        while (WiFiClass::status() != WL_CONNECTED) {
            delay(500);
        }
    }

}