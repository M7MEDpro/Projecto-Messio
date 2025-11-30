#include "EmergencyMode.h"

#include "../alarmManager.h"
#include "../dataModel.h"

namespace EmergencyMode {
    void update () {
        if (mobile_app::EmergencyMode == 1 ) {
            alarmmanager::emergency = 1;
        }else {
            alarmmanager::emergency = 0;
        }
    }
}
