#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

namespace wifi {

    void connectWiFi(unsigned long timeout = 10000);
    void checkAndReconnect();

}

#endif