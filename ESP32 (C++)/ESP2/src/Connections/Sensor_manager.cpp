#include "Sensor_manager.h"
#include "Readings/Flame_reading_manager.h"

namespace sensors {
    
    void init() {
        flame::flame_init();
    }
    
    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> data;
        data.reserve(5);
        
        // Update flame sensor states
        flame::flame_read();

        // Read current states (with 2s delay for LOW)
        int val1 = digitalRead(36);
        if (val1 == HIGH) {
            data.push_back({"F1", "1"});
        } else if (flame::F1_lowTime > 0 && (millis() - flame::F1_lowTime >= 2000)) {
            data.push_back({"F1", "0"});
        }

        int val2 = digitalRead(39);
        if (val2 == HIGH) {
            data.push_back({"F2", "1"});
        } else if (flame::F2_lowTime > 0 && (millis() - flame::F2_lowTime >= 2000)) {
            data.push_back({"F2", "0"});
        }

        int val3 = digitalRead(34);
        if (val3 == HIGH) {
            data.push_back({"F3", "1"});
        } else if (flame::F3_lowTime > 0 && (millis() - flame::F3_lowTime >= 2000)) {
            data.push_back({"F3", "0"});
        }

        int val4 = digitalRead(35);
        if (val4 == HIGH) {
            data.push_back({"F4", "1"});
        } else if (flame::F4_lowTime > 0 && (millis() - flame::F4_lowTime >= 2000)) {
            data.push_back({"F4", "0"});
        }

        int val5 = digitalRead(32);
        if (val5 == HIGH) {
            data.push_back({"F5", "1"});
        } else if (flame::F5_lowTime > 0 && (millis() - flame::F5_lowTime >= 2000)) {
            data.push_back({"F5", "0"});
        }
        
        return data;
    }
}