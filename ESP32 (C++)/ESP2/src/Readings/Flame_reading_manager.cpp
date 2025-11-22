#include "Flame_reading_manager.h"
#include <Arduino.h>

namespace flame {
    int F1 = 36;
    int F2 = 39;
    int F3 = 34;
    int F4 = 35;
    int F5 = 32;

    // Track last sent state
    int F1_last = -1;
    int F2_last = -1;
    int F3_last = -1;
    int F4_last = -1;
    int F5_last = -1;

    // Track when LOW started
    unsigned long F1_lowTime = 0;
    unsigned long F2_lowTime = 0;
    unsigned long F3_lowTime = 0;
    unsigned long F4_lowTime = 0;
    unsigned long F5_lowTime = 0;

    void flame_init() {
        pinMode(F1, INPUT);
        pinMode(F2, INPUT);
        pinMode(F3, INPUT);
        pinMode(F4, INPUT);
        pinMode(F5, INPUT);
    }

    void flame_read() {
        // Read all sensors and update states
        // This should be called regularly from your main loop

        // F1
        int val1 = digitalRead(F1);
        if (val1 == HIGH) {
            F1_last = HIGH;
            F1_lowTime = 0;
        } else {
            if (F1_lowTime == 0) {
                F1_lowTime = millis();
            } else if (millis() - F1_lowTime >= 2000) {
                F1_last = LOW;
            }
        }

        // F2
        int val2 = digitalRead(F2);
        if (val2 == HIGH) {
            F2_last = HIGH;
            F2_lowTime = 0;
        } else {
            if (F2_lowTime == 0) {
                F2_lowTime = millis();
            } else if (millis() - F2_lowTime >= 2000) {
                F2_last = LOW;
            }
        }

        // F3
        int val3 = digitalRead(F3);
        if (val3 == HIGH) {
            F3_last = HIGH;
            F3_lowTime = 0;
        } else {
            if (F3_lowTime == 0) {
                F3_lowTime = millis();
            } else if (millis() - F3_lowTime >= 2000) {
                F3_last = LOW;
            }
        }

        // F4
        int val4 = digitalRead(F4);
        if (val4 == HIGH) {
            F4_last = HIGH;
            F4_lowTime = 0;
        } else {
            if (F4_lowTime == 0) {
                F4_lowTime = millis();
            } else if (millis() - F4_lowTime >= 2000) {
                F4_last = LOW;
            }
        }

        // F5
        int val5 = digitalRead(F5);
        if (val5 == HIGH) {
            F5_last = HIGH;
            F5_lowTime = 0;
        } else {
            if (F5_lowTime == 0) {
                F5_lowTime = millis();
            } else if (millis() - F5_lowTime >= 2000) {
                F5_last = LOW;
            }
        }
    }
}
