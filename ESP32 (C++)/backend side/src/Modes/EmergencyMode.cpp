#include "EmergencyMode.h"

#include "../dataModel.h"

namespace EmergencyMode {
    void update () {
        if (mobile_app::EmergencyMode == 1 ) {
            esp1::buzz = 1;
        }else {
            esp1::buzz = 0;
        }
    }
}
