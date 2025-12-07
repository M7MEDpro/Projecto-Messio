#include "Sensor_manager.h"
#include "Readings/Flame_reading_manager.h"
#include "Readings/Sensor20A_manager.h"

namespace sensors {

    void init() {
        flame::flame_init();
        sensor20a::sensor20a_init();
    }

    std::vector<std::pair<String, String>> readAllSensors() {
        flame::flame_read();
        sensor20a::sensor20a_read();

        return {};
    }
}