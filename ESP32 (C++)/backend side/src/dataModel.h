#ifndef DATAMODEL_H
#define DATAMODEL_H


namespace esp1 {
    extern int LDR0;
    extern int LDR1;
    extern int M0;
    extern int M1;
    extern int M2;
    extern int M3;
    extern int M4;
    extern int g1;
    extern int r1;
    extern int r2;
    extern int r3;
    extern int r4;
    extern int buzz;
    extern int servo;


}
namespace esp2 {
    extern int F1;
    extern int F2;
    extern int F3;
    extern int F4;
    extern int F5;
    extern int OL;
    extern int l1;
    extern int l2;
    extern int l3;
    extern int l4;

}
namespace mobile_app {

    // Home modes
    extern bool homeAway;
    extern bool bedTimeMode;
    extern bool powerSavingMode;
    extern bool EmergencyMode;

    // Room1
    namespace room1 {
        extern int brightness;
        extern int mode; // 0 is off 1 is on 2 is auto
        extern bool ldr;
        extern bool ir;
        extern bool alarmMode;

    }

    // Room2
    namespace room2 {
        extern int brightness;
        extern int mode; // 0 is off 1 is on 2 is auto
        extern bool ldr;
        extern bool ir;
        extern bool alarmMode;

    }

    // Reception
    namespace reception {
        extern int brightness;
        extern int mode;
        extern bool ldr;
        extern bool ir;
        extern bool alarmMode;

    }

    // Garage
    namespace garage {
        extern int brightness;
        extern int mode;
        extern bool ldr;
        extern bool alarmMode;
        extern bool ir;

    }

    // Outer LED
    namespace outerLed {
        extern int brightness;
        extern int mode;
        extern bool ldr;
        extern bool ir;
    }

}

#endif
