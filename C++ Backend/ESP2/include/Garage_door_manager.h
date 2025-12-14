#ifndef GARAGE_DOOR_MANAGER_H
#define GARAGE_DOOR_MANAGER_H

#include <Arduino.h>

namespace gm {
    void garagedoor_init();
    void garagedoor_update();
    void garagedoor_command(int gdValue);
}

#endif