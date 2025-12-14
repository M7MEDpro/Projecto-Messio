    #include "flameAlarm.h"

#include "dataModel.h"
#include "utilities.h"
#include "alarmManager.h"

namespace flameAlarm {
    void update() {
        if (esp2::F1 == 1 || esp2::F2 == 1 || esp2::F3 == 1|| esp2::F4 == 1|| esp2::F5 == 1) {
           alarmmanager::flame = 1;
        }else
            utilities::runLater([]() {
                alarmmanager::flame = 0;
            }, 1000);
    }
}
