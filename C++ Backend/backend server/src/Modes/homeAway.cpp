#include "homeAway.h"

#include "alarmManager.h"
#include "dataModel.h"

namespace homeAway {
    int alarmStats =0;

    void update() {
        if (mobile_app::homeAway == 1) {
            turnOffLEDS();
            alarmUpdate();
        } else {
            if (alarmStats == 1 ) alarmmanager::homeAway = 0;
        }
    }

    void turnOffLEDS() {

        esp1::g1 = 0;
        esp1::r1 = 0;
        esp1::r2 = 0;
        esp1::r3 = 0;
        esp1::r4 = 0;
        esp2::OL = 0;
        esp2::l1 = 0;
        esp2::l2 = 0;
        esp2::l3 = 0;
        esp2::l4 = 0;
    }
    void alarmUpdate () {
        room1Alarm();
        room2Alarm();
        garageAlarm();
        receptionAlarm();
        if (alarmStats == 1) alarmmanager::homeAway = 1; else  alarmmanager::homeAway = 0;

    }
    void room1Alarm() {
        if (        mobile_app::room1::alarmMode == 1 && esp1::M3 == 1) {
            alarmStats = 1;
        }else alarmStats = 0;
    }


    void room2Alarm() {
        if (mobile_app::room2::alarmMode == 1 && esp1::M4 == 1) {
            alarmStats = 1;
        }else alarmStats = 0;
    }


    void garageAlarm() {
        if (mobile_app::garage::alarmMode == 1 && esp1::M0 == 1) {
            alarmStats = 1;
        }else alarmStats = 0;

    }

    void receptionAlarm() {
        if (mobile_app::reception::alarmMode == 1 && (esp1::M1 == 1||esp1::M2 == 1)) {
            alarmStats = 1;
        }else alarmStats = 0;

    }

}
