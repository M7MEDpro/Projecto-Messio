#include "Room2_led_manager.h"
#include "Arduino.h"

namespace room2 {
    int led1 = 5;
    int led2 = 17;

    void room2_init() {
        pinMode(led1, OUTPUT);
        pinMode(led2, OUTPUT);

        analogWrite(led1, 0);
        analogWrite(led2, 0);
    }

    void l1_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(led1, pwm);
    }

    void l2_write(int percent) {
        int pwm = map(percent, 0, 100, 0, 255);
        analogWrite(led2, pwm);
    }
}
