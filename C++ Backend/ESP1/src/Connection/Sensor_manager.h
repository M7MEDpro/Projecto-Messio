#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <vector>
#include <Arduino.h>

namespace sensors {
    std::vector<std::pair<String, String>> readAllSensors();
    
    void init();
}

#endif