#include "dataModel.h"



namespace esp1 {

    //LDR
    int LDR0 = 0;
    int LDR1 = 0;

    //IR
    int M0 = 0;
    int M1 = 0;
    int M2 = 0;
    int M3 = 0;
    int M4 = 0;


    int g1 = 0; //garage led

    //rleds
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;

    //others
    int buzz = 0;
    int servo = 0;
}
namespace esp2 {
    //flame
    int F1 = 0;
    int F2 = 0;
    int F3 = 0;
    int F4 = 0;
    int F5 = 0;

    int OL = 0; // outer led

    //room leds
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int l4 = 0;
    //motors
    int mg = 0;

}
namespace mobile_app {
    //Home modes
    int homeAway = 0; // post
    int bedTimeMode = 0; // post
    int powerSavingMode = 0;// post
    int EmergencyMode = 0; //post
    //Room1
    namespace  room1 {
        int brightness = 0; //post
        int mode = 0; // 0 is off 1 is on 2 is auto //post
        int ldr = 0;//post
        int ir =  0; //post
        int alarmMode = 0; //post

    }

// room2
    namespace room2 {
        int brightness = 0; //post
        int mode = 0; // 0 is off 1 is on 2 is auto //post
        int ldr = 0; //post
        int ir =  0; //post
        int alarmMode = 0; //post


    }
    namespace reception {
        int brightness = 0; //post
        int mode = 0; // 0 is off 1 is on 2 is auto //post
        int ldr = 0; //post
        int ir =  0; //post
        int alarmMode = 0; //post
    }
    namespace garage {
        int brightness = 0; //post
        int mode = 0; // 0 is off 1 is on 2 is auto //post
        int ldr = 0; //post
        int ir  = 0; //post
        int alarmMode = 0; //post
    }
    namespace outerLed {
        int brightness = 0; //post
        int mode = 0; // 0 is off 1 is on 2 is auto //post
        int ldr = 0; //post
        int ir =  0; //post
    }


}