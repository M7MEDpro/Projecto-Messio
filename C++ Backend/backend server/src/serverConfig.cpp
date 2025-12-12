#include "serverConfig.h"
#include <yaml-cpp/yaml.h>

namespace config {
    std::string ip;
    int port;
    std::string passkey;

    void loadConfig() {
        YAML::Node config = YAML::LoadFile("config.yml");
        ip = config["server"]["ip"].as<std::string>();
        port = config["server"]["port"].as<int>();
        passkey = config["server"]["passkey"].as<std::string>();
    }
}
