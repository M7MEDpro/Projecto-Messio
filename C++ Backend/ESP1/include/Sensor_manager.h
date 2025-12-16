 
#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>
#include <vector>
#include <utility>

namespace sensors {
    void init();
    std::vector<std::pair<String, String>> readAllSensors();
}

#endif
