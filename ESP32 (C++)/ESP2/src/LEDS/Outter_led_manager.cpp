#include "Outter_led_manager.h"

#include <esp32-hal-gpio.h>

namespace OL {
    int OL = 16;

    void OL_initial() {
        pinMode(OL,OUTPUT);
    }
    void OL_write(bool state) {
        digitalWrite(OL,state);
    }
}
