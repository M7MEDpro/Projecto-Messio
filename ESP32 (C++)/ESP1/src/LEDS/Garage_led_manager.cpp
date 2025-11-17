#include "Garage_led_manager.h"
#include "Arduino.h"
#include "Connection/HTTP_manager.h"

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

    void g1_write() {
        String val = http::read_data("g1");
        int percent = val.toInt();
        g1_write(percent);
    }
}