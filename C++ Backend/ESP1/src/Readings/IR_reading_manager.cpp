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

    unsigned long lastSendTime = 0;
    const unsigned long SEND_INTERVAL = 500; // Send all sensors every 500ms

    void IR_init() {
        pinMode(M0, INPUT);
        pinMode(M1, INPUT);
        pinMode(M2, INPUT);
        pinMode(M3, INPUT);
        pinMode(M4, INPUT);
    }

    std::vector<std::pair<String, String>> checkAllSensors() {
        std::vector<std::pair<String, String>> updates;
        unsigned long currentTime = millis();

        // Force send all sensors periodically
        bool forceSend = (currentTime - lastSendTime >= SEND_INTERVAL);

        // Inverted Logic: LOW = Detected ("1"), HIGH = Idle ("0")

        int val0 = digitalRead(M0);
        if (val0 == LOW) { // Detected
            if (M0_last != LOW || forceSend) {
                updates.push_back({"M0", "1"});
                M0_last = LOW;
            }
            M0_lowTime = 0;
        } else { // Idle
            if (M0_lowTime == 0) {
                M0_lowTime = currentTime;
            } else if (currentTime - M0_lowTime >= 2000 && M0_last != HIGH) {
                updates.push_back({"M0", "0"});
                M0_last = HIGH;
            } else if (forceSend && M0_last == HIGH) {
                updates.push_back({"M0", "0"});
            }
        }

        int val1 = digitalRead(M1);
        if (val1 == LOW) {
            if (M1_last != LOW || forceSend) {
                updates.push_back({"M1", "1"});
                M1_last = LOW;
            }
            M1_lowTime = 0;
        } else {
            if (M1_lowTime == 0) {
                M1_lowTime = currentTime;
            } else if (currentTime - M1_lowTime >= 2000 && M1_last != HIGH) {
                updates.push_back({"M1", "0"});
                M1_last = HIGH;
            } else if (forceSend && M1_last == HIGH) {
                updates.push_back({"M1", "0"});
            }
        }

        int val2 = digitalRead(M2);
        if (val2 == LOW) {
            if (M2_last != LOW || forceSend) {
                updates.push_back({"M2", "1"});
                M2_last = LOW;
            }
            M2_lowTime = 0;
        } else {
            if (M2_lowTime == 0) {
                M2_lowTime = currentTime;
            } else if (currentTime - M2_lowTime >= 2000 && M2_last != HIGH) {
                updates.push_back({"M2", "0"});
                M2_last = HIGH;
            } else if (forceSend && M2_last == HIGH) {
                updates.push_back({"M2", "0"});
            }
        }

        int val3 = digitalRead(M3);
        if (val3 == LOW) {
            if (M3_last != LOW || forceSend) {
                updates.push_back({"M3", "1"});
                M3_last = LOW;
            }
            M3_lowTime = 0;
        } else {
            if (M3_lowTime == 0) {
                M3_lowTime = currentTime;
            } else if (currentTime - M3_lowTime >= 2000 && M3_last != HIGH) {
                updates.push_back({"M3", "0"});
                M3_last = HIGH;
            } else if (forceSend && M3_last == HIGH) {
                updates.push_back({"M3", "0"});
            }
        }

        int val4 = digitalRead(M4);
        if (val4 == LOW) {
            if (M4_last != LOW || forceSend) {
                updates.push_back({"M4", "1"});
                M4_last = LOW;
            }
            M4_lowTime = 0;
        } else {
            if (M4_lowTime == 0) {
                M4_lowTime = currentTime;
            } else if (currentTime - M4_lowTime >= 2000 && M4_last != HIGH) {
                updates.push_back({"M4", "0"});
                M4_last = HIGH;
            } else if (forceSend && M4_last == HIGH) {
                updates.push_back({"M4", "0"});
            }
        }

        if (forceSend) {
            lastSendTime = currentTime;
        }

        return updates;
    }
}