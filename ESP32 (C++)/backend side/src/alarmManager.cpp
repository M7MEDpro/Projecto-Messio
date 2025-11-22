#include "alarmManager.h"

#include "dataModel.h"

namespace alarmmanager {

      int emergency = 0;
      int flame = 0;
      int homeAway = 0;

    void update () {

        if (emergency ==1 || flame  ==1|| homeAway ==1) {
              esp1::buzz = 1;
        }else {
            esp1::buzz = 0;
        }


    }
}
