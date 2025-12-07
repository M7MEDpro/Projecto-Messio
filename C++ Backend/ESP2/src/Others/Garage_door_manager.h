#ifndef GARAGE_DOOR_MANAGER_H
#define GARAGE_DOOR_MANAGER_H

#include <Arduino.h>

namespace gm {
    extern int MOTOR_PIN1;
    extern int MOTOR_PIN2;

    void garagedoor_init();
    void garagedoor_update();
    void garagedoor_command(const String& command);
}

#endif