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
    unsigned long lastSendTime = 0;
    const unsigned long SEND_INTERVAL = 500;
    void flame_init() {
        pinMode(F1, INPUT);
        pinMode(F2, INPUT);
        pinMode(F3, INPUT);
        pinMode(F4, INPUT);
        pinMode(F5, INPUT);   
    }

    void process_sensor(int pin, const char* key, int& lastState, unsigned long& lowTime,
                       std::vector<std::pair<String, String>>& updates, bool forceSend) {
        unsigned long currentTime = millis();
        int val = digitalRead(pin);

         
        if (val == LOW) {  
            if (lastState != LOW || forceSend) {
                updates.push_back({key, "1"});
                lastState = LOW;
            }
            lowTime = 0;
        } else {  
            if (lowTime == 0) {
                lowTime = currentTime;
            } else if (currentTime - lowTime >= 2000 && lastState != HIGH) {
                updates.push_back({key, "0"});
                lastState = HIGH;
            } else if (forceSend && lastState == HIGH) {
                updates.push_back({key, "0"});
            }
        }
    }

    std::vector<std::pair<String, String>> flame_read() {
        std::vector<std::pair<String, String>> updates;
        unsigned long currentTime = millis();

         
        bool forceSend = (currentTime - lastSendTime >= SEND_INTERVAL);

        process_sensor(F1, "F1", F1_last, F1_lowTime, updates, forceSend);
        process_sensor(F2, "F2", F2_last, F2_lowTime, updates, forceSend);
        process_sensor(F4, "F4", F4_last, F4_lowTime, updates, forceSend);

        if (forceSend) {
            lastSendTime = currentTime;
        }

        return updates;
    }
}
