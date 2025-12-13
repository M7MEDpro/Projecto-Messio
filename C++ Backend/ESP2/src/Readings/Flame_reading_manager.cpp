#include "Flame_reading_manager.h"
#include <Arduino.h>

namespace flame {
    int F1 = 36;
    int F2 = 39;
    int F3 = 34;
    int F4 = 35;
    int F5 = 32;

    int F1_last = -1;
    int F2_last = -1;
    int F3_last = -1;
    int F4_last = -1;
    int F5_last = -1;

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

    void process_sensor(int pin, const char* key, int& lastState, unsigned long& lowTime, std::vector<std::pair<String, String>>& updates) {
        int val = digitalRead(pin);
        // Inverted Logic: LOW = Detected ("1"), HIGH = Idle ("0")
        if (val == LOW) { // Detected
            if (lastState != LOW) {
                updates.push_back({key, "1"});
                lastState = LOW;
            }
            lowTime = 0;
        } else { // Idle
            if (lowTime == 0) {
                lowTime = millis();
            } else if (millis() - lowTime >= 2000 && lastState != HIGH) {
                updates.push_back({key, "0"});
                lastState = HIGH;
            }
        }
    }

    std::vector<std::pair<String, String>> flame_read() {
        std::vector<std::pair<String, String>> updates;
        process_sensor(F1, "F1", F1_last, F1_lowTime, updates);
        process_sensor(F2, "F2", F2_last, F2_lowTime, updates);
        process_sensor(F3, "F3", F3_last, F3_lowTime, updates);
        process_sensor(F4, "F4", F4_last, F4_lowTime, updates);
        process_sensor(F5, "F5", F5_last, F5_lowTime, updates);
        return updates;
    }
}