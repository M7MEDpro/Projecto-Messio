#ifndef HTTP_MANAGER_H
#define HTTP_MANAGER_H
#include <Arduino.h>
#include <vector>
#include <map>

namespace http {

    void send_data(const String& key, const String& value);
    String read_data(const String& key);

    bool send_batch(const std::vector<std::pair<String, String>>& data);
    std::map<String, String> read_batch(const std::vector<String>& keys);

    void clearCache();

}

#endif
