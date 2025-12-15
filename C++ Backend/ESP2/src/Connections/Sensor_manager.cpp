#include "Sensor_manager.h"
#include "Flame_reading_manager.h"
#include "sensor20a.h"

namespace sensors {

    void init() {
        flame::flame_init();
        sensor20a::sensor20a_init();
    }

    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> allUpdates;

        // Flame sensors are fast
        auto flameUpdates = flame::flame_read();
        allUpdates.insert(allUpdates.end(), flameUpdates.begin(), flameUpdates.end());

        // Power sensor now non-blocking - may return empty if still reading
        auto powerUpdates = sensor20a::sensor20a_read();
        allUpdates.insert(allUpdates.end(), powerUpdates.begin(), powerUpdates.end());

        return allUpdates;
    }
}