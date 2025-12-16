#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

#include <string>

namespace config {
    extern std::string ip;
    extern int port;
    extern std::string passkey;

    void loadConfig();
}

#endif
