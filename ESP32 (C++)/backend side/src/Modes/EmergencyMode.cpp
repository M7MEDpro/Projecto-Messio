#include "EmergencyMode.h"

#include "managerMode.h"
#include "../dataModel.h"

namespace EmergencyMode {
    void update () {
        if (mobile_app::EmergencyMode == 1 ) {
            managerMode::emergency = 1;
        }else {
            managerMode::emergency = 0;
        }
    }
}
