#include "IR_reading_manager.h"
#include <Arduino.h>

namespace IR {
    int M0 = 36;
    int M1 = 39;
    int M2 = 34;
    int M3 = 35;
    int M4 = 32;

    int M0_last = -1;
    int M1_last = -1;
    int M2_last = -1;
    int M3_last = -1;
    int M4_last = -1;

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

    std::vector<std::pair<String, String>> checkAllSensors() {
        std::vector<std::pair<String, String>> updates;

        int val0 = digitalRead(M0);
        if (val0 == HIGH) {
            if (M0_last != HIGH) {
                updates.push_back({"M0", "1"});
                M0_last = HIGH;
            }
            M0_lowTime = 0;
        } else {
            if (M0_lowTime == 0) {
                M0_lowTime = millis();
            } else if (millis() - M0_lowTime >= 2000 && M0_last != LOW) {
                updates.push_back({"M0", "0"});
                M0_last = LOW;
            }
        }

        int val1 = digitalRead(M1);
        if (val1 == HIGH) {
            if (M1_last != HIGH) {
                updates.push_back({"M1", "1"});
                M1_last = HIGH;
            }
            M1_lowTime = 0;
        } else {
            if (M1_lowTime == 0) {
                M1_lowTime = millis();
            } else if (millis() - M1_lowTime >= 2000 && M1_last != LOW) {
                updates.push_back({"M1", "0"});
                M1_last = LOW;
            }
        }

        int val2 = digitalRead(M2);
        if (val2 == HIGH) {
            if (M2_last != HIGH) {
                updates.push_back({"M2", "1"});
                M2_last = HIGH;
            }
            M2_lowTime = 0;
        } else {
            if (M2_lowTime == 0) {
                M2_lowTime = millis();
            } else if (millis() - M2_lowTime >= 2000 && M2_last != LOW) {
                updates.push_back({"M2", "0"});
                M2_last = LOW;
            }
        }

        int val3 = digitalRead(M3);
        if (val3 == HIGH) {
            if (M3_last != HIGH) {
                updates.push_back({"M3", "1"});
                M3_last = HIGH;
            }
            M3_lowTime = 0;
        } else {
            if (M3_lowTime == 0) {
                M3_lowTime = millis();
            } else if (millis() - M3_lowTime >= 2000 && M3_last != LOW) {
                updates.push_back({"M3", "0"});
                M3_last = LOW;
            }
        }

        int val4 = digitalRead(M4);
        if (val4 == HIGH) {
            if (M4_last != HIGH) {
                updates.push_back({"M4", "1"});
                M4_last = HIGH;
            }
            M4_lowTime = 0;
        } else {
            if (M4_lowTime == 0) {
                M4_lowTime = millis();
            } else if (millis() - M4_lowTime >= 2000 && M4_last != LOW) {
                updates.push_back({"M4", "0"});
                M4_last = LOW;
            }
        }

        return updates;
    }

}