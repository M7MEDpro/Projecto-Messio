#include "Sensor_manager.h"
#include "Readings/IR_reading_manager.h"
#include "Readings/LDR_reading_manager.h"
#include "Connection/HTTP_manager.h"

namespace sensors {

    unsigned long lastSendTime = 0;
    const unsigned long SEND_INTERVAL = 500;

    void init() {
        LDR::LDR_init();
        IR::IR_init();
    }

    std::vector<std::pair<String, String>> readAllSensors() {
        std::vector<std::pair<String, String>> batchData;

        auto irUpdates = IR::checkAllSensors();
        batchData.insert(batchData.end(), irUpdates.begin(), irUpdates.end());

        unsigned long currentTime = millis();
        if (currentTime - lastSendTime >= SEND_INTERVAL) {
            batchData.push_back({"LDR0", String(LDR::LDR0_read())});
            batchData.push_back({"LDR1", String(LDR::LDR1_read())});
            lastSendTime = currentTime;
        }

        return batchData;
    }
}