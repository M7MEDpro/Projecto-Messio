#include "Sensor_manager.h"
#include "Readings/Flame_reading_manager.h"

namespace sensors {
    
    void init() {
        flame::flame_init();
    }
    
    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> data;
        data.reserve(5);
        
        data.push_back({"F1", String(digitalRead(36))});
        data.push_back({"F2", String(digitalRead(39))});
        data.push_back({"F3", String(digitalRead(34))});
        data.push_back({"F4", String(digitalRead(35))});
        data.push_back({"F5", String(digitalRead(32))});
        
        return data;
    }
}