#include "IR_reading_manager.h"
#include <Arduino.h>

#include "Connection/HTTP_manager.h"

namespace IR {
    int M0 = 36;
    int M1 = 39;
    int M2 = 34;
    int M3 = 35;
    int M4 = 32;

    // Track last sent state
    int M0_last = -1;
    int M1_last = -1;
    int M2_last = -1;
    int M3_last = -1;
    int M4_last = -1;

    // Track when LOW started
    unsigned long M0_lowTime = 0;
    unsigned long M1_lowTime = 0;
    unsigned long M2_lowTime = 0;
    unsigned long M3_lowTime = 0;
    unsigned long M4_lowTime = 0;

    void IR_init() {
        pinMode(M0, INPUT);
        pinMode(M1, INPUT);
        pinMode(M2, INPUT);
        pinMode(M3, INPUT);
        pinMode(M4, INPUT);
    }

    void M0_read() {
        int val = digitalRead(M0);
        if (val == HIGH) {
            if (M0_last != HIGH) {
                http::send_data("M0", "1");
                M0_last = HIGH;
            }
            M0_lowTime = 0;
        } else {
            if (M0_lowTime == 0) {
                M0_lowTime = millis();
            } else if (millis() - M0_lowTime >= 2000 && M0_last != LOW) {
                http::send_data("M0", "0");
                M0_last = LOW;
            }
        }
    }

    void M1_read() {
        int val = digitalRead(M1);
        if (val == HIGH) {
            if (M1_last != HIGH) {
                http::send_data("M1", "1");
                M1_last = HIGH;
            }
            M1_lowTime = 0;
        } else {
            if (M1_lowTime == 0) {
                M1_lowTime = millis();
            } else if (millis() - M1_lowTime >= 2000 && M1_last != LOW) {
                http::send_data("M1", "0");
                M1_last = LOW;
            }
        }
    }

    void M2_read() {
        int val = digitalRead(M2);
        if (val == HIGH) {
            if (M2_last != HIGH) {
                http::send_data("M2", "1");
                M2_last = HIGH;
            }
            M2_lowTime = 0;
        } else {
            if (M2_lowTime == 0) {
                M2_lowTime = millis();
            } else if (millis() - M2_lowTime >= 2000 && M2_last != LOW) {
                http::send_data("M2", "0");
                M2_last = LOW;
            }
        }
    }

    void M3_read() {
        int val = digitalRead(M3);
        if (val == HIGH) {
            if (M3_last != HIGH) {
                http::send_data("M3", "1");
                M3_last = HIGH;
            }
            M3_lowTime = 0;
        } else {
            if (M3_lowTime == 0) {
                M3_lowTime = millis();
            } else if (millis() - M3_lowTime >= 2000 && M3_last != LOW) {
                http::send_data("M3", "0");
                M3_last = LOW;
            }
        }
    }

    void M4_read() {
        int val = digitalRead(M4);
        if (val == HIGH) {
            if (M4_last != HIGH) {
                http::send_data("M4", "1");
                M4_last = HIGH;
            }
            M4_lowTime = 0;
        } else {
            if (M4_lowTime == 0) {
                M4_lowTime = millis();
            } else if (millis() - M4_lowTime >= 2000 && M4_last != LOW) {
                http::send_data("M4", "0");
                M4_last = LOW;
            }
        }
    }

}