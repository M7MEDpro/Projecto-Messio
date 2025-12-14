#include "Reception_led_manager.h"
#include "Arduino.h"
#include "HTTP_manager.h"

namespace rled {
    int r1 = 26;
    int r2 = 27;
    int r3 = 14;
    int r4 = 19;

    void init() {
        pinMode(r1, OUTPUT);
        pinMode(r2, OUTPUT);
        pinMode(r3, OUTPUT);
        pinMode(r4, OUTPUT);

        analogWrite(r1, 0);
        analogWrite(r2, 0);
        analogWrite(r3, 0);
        analogWrite(r4, 0);
    }

    void r1_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(r1, pwm);
    }

    void r2_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(r2, pwm);
    }

    void r3_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(r3, pwm);
    }

    void r4_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(r4, pwm);
    }
}