#include "Sensor_manager.h"
#include "IR_reading_manager.h"
#include "LDR_reading_manager.h"

namespace sensors {

    void init() {
        LDR::LDR_init();
        IR::IR_init();
    }

    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> batchData;

        // IR sensors (M0-M4) - now includes periodic updates
        auto irUpdates = IR::checkAllSensors();
        batchData.insert(batchData.end(), irUpdates.begin(), irUpdates.end());

        // LDR sensors - always send (removed throttling)
        batchData.push_back({"LDR0", String(LDR::LDR0_read())});
        batchData.push_back({"LDR1", String(LDR::LDR1_read())});

        return batchData;
    }
}