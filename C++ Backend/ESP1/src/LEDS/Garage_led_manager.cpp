#include "Garage_led_manager.h"
#include "Arduino.h"
#include "HTTP_manager.h"

namespace gled {
    int gpin = 18;

    void init() {
        pinMode(gpin, OUTPUT);
        analogWrite(gpin, 0);
    }

    void g1_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(gpin, pwm);
    }


}