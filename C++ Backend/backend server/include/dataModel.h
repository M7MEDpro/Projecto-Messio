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
    extern int mg;
    extern double power;
}
namespace mobile_app {

     
    extern int homeAway;
    extern int bedTimeMode;
    extern int powerSavingMode;
    extern int EmergencyMode;

     
    namespace room1 {
        extern int brightness;
        extern int mode;  
        extern int ldr;
        extern int ir;
        extern int alarmMode;

    }

     
    namespace room2 {
        extern int brightness;
        extern int mode;  
        extern int ldr;
        extern int ir;
        extern int alarmMode;

    }

     
    namespace reception {
        extern int brightness;
        extern int mode;
        extern int ldr;
        extern int ir;
        extern int alarmMode;

    }

     
    namespace garage {
        extern int brightness;
        extern int mode;
        extern int ldr;
        extern int alarmMode;
        extern int ir;


    }

     
    namespace outerLed {
        extern int brightness;
        extern int mode;
        extern int ldr;
        extern int ir;
    }

}

#endif

