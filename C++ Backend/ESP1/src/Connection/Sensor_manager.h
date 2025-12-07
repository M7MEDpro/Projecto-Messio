#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>
#include <vector>

namespace sensors {
    void init();
    std::vector<std::pair<String, String>> readAllSensors();
}

#endif