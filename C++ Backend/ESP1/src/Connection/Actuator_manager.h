#ifndef ACTUATOR_MANAGER_H
#define ACTUATOR_MANAGER_H

#include <map>
#include <Arduino.h>

namespace actuators {
    void updateAll(const std::map<String, String>& data);
    
    void init();
}

#endif