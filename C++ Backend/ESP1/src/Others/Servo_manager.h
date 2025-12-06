#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <vector>
#include <Arduino.h>

namespace sensors {
    void readAllSensors();
    void init();
}

#endif