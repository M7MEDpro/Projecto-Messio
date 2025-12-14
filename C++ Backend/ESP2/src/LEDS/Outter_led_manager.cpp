#include "Outter_led_manager.h"
#include "Arduino.h"

namespace OL {
    int OL_pin = 17;

    void OL_initial() {
        pinMode(OL_pin, OUTPUT);
        analogWrite(OL_pin, 0);
    }

    void OL_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(OL_pin, pwm);
    }
}