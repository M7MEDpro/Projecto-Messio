#ifndef SENSOR20A_MANAGER_H
#define SENSOR20A_MANAGER_H

#include <vector>
#include <utility>
#include <Arduino.h>

namespace sensor20a {
    extern const int SENSOR_PIN;

    void sensor20a_init();
    std::vector<std::pair<String, String>> sensor20a_read();
}

#endif
