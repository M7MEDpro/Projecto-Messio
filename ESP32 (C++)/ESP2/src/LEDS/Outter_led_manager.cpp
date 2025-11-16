#include "Outter_led_manager.h"
#include "Arduino.h"
#include "connections/HTTP_manager.h"

namespace OL {
    int OL_pin = 16;

    void OL_initial() {
        pinMode(OL_pin, OUTPUT);
        digitalWrite(OL_pin, LOW);
    }

    void OL_write(bool state) {
        digitalWrite(OL_pin, state);
    }

    void OL_write() {
        if (http::read_data("OL") == "1") OL_write(HIGH);
        else OL_write(LOW);
    }
}