#include "flameAlarm.h"

#include "dataModel.h"
#include "utilities.h"

namespace flameAlarm {
    void update() {
        if (esp2::F1 == 1 || esp2::F2 == 1 || esp2::F3 == 1|| esp2::F4 == 1|| esp2::F5 == 1) {
            esp1::buzz = 1;
        }else
            utilities::runLater([]() {
                esp1::buzz = 0;
            }, 5000);
    }
}
