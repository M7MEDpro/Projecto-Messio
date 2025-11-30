#include "Sensor_manager.h"
#include "Readings/IR_reading_manager.h"
#include "Readings/LDR_reading_manager.h"

namespace sensors {
    
    void init() {
        LDR::LDR_init();
        IR::IR_init();
    }
    
    std::vector<std::pair<String, String>> readAllSensors() {
        LDR::LDR0_read();
        LDR::LDR1_read();

        IR::M0_read();
        IR::M1_read();
        IR::M2_read();
        IR::M3_read();
        IR::M4_read();

        return {};
    }
}