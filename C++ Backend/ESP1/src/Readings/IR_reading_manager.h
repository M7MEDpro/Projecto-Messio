#ifndef IR_READING_MANAGER_H
#define IR_READING_MANAGER_H

#include <vector>
#include <Arduino.h>

namespace IR {
    extern bool M0Value;
    extern bool M1Value;
    extern bool M2Value;
    extern bool M3Value;
    extern bool M4Value;

    void IR_init();
    std::vector<std::pair<String, String>> checkAllSensors();
}

#endif