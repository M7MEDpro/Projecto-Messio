#include "Sensor_manager.h"
#include "Readings/Flame_reading_manager.h"

namespace sensors {
    
    void init() {
        flame::flame_init();
    }
    
    std::vector<std::pair<String, String>> readAllSensors() {
        flame::flame_read();

        return {};
    }
}