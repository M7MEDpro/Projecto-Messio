#include "dataModel.h"



namespace esp1 {

     
    int LDR0 = 0;
    int LDR1 = 0;

     
    int M0 = 0;
    int M1 = 0;
    int M2 = 0;
    int M3 = 0;
    int M4 = 0;


    int g1 = 0;
     
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;

     
    int buzz = 0;
    int servo = 0;
}
namespace esp2 {
     
    int F1 = 0;
    int F2 = 0;
    int F3 = 0;
    int F4 = 0;
    int F5 = 0;

    int OL = 0;
     
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int l4 = 0;
     
    int mg = 0;
    double power = 1.2;

}
namespace mobile_app {
     
    int homeAway = 0;  
    int bedTimeMode = 0;  
    int powerSavingMode = 0; 
    int EmergencyMode = 0;  
     
    namespace  room1 {
        int brightness = 0;  
        int mode = 0;  
        int ldr = 0; 
        int ir =  0;  
        int alarmMode = 0;
    }

 
    namespace room2 {
        int brightness = 0;  
        int mode = 0;  
        int ldr = 0;  
        int ir =  0;  
        int alarmMode = 0;

    }
    namespace reception {
        int brightness = 0;  
        int mode = 0;  
        int ldr = 0;  
        int ir =  0;  
        int alarmMode = 0;  
    }
    namespace garage {
        int brightness = 0;  
        int mode = 0;  
        int ldr = 0;  
        int ir  = 0;  
        int alarmMode = 0;  
    }
    namespace outerLed {
        int brightness = 0;  
        int mode = 0;  
        int ldr = 0;  
        int ir =  0;  
    }


}
