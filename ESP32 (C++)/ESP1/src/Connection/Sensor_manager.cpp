#include "Sensor_manager.h"
#include "Readings/IR_reading_manager.h"
#include "Readings/LDR_reading_manager.h"

namespace sensors {
    
    void init() {
        LDR::LDR_init();
        IR::IR_init();
    }
    
    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> data;
        data.reserve(7);
        
        data.push_back({"LDR0", String(digitalRead(33))});
        data.push_back({"LDR1", String(digitalRead(25))});
        data.push_back({"M0", String(digitalRead(36))});
        data.push_back({"M1", String(digitalRead(39))});
        data.push_back({"M2", String(digitalRead(34))});
        data.push_back({"M3", String(digitalRead(35))});
        data.push_back({"M4", String(digitalRead(32))});
        
        return data;
    }
}