
#include "IR_reading_manager.h"
#include <Arduino.h>
namespace IR {
    int M0 =36;
    int M1 =39;
    int M2 =34;
    int M3 =35;
    int M4 =32;
    bool M0Value =M0_read();
    bool M1Value =M1_read();
    bool M2Value =M2_read();
    bool M3Value =M3_read();
    bool M4Value =M4_read();

    void IR_init(){
        pinMode(M0,INPUT);
        pinMode(M1,INPUT);
        pinMode(M2,INPUT);
        pinMode(M3,INPUT);
        pinMode(M4,INPUT);
    }
    bool M0_read() {
     return    digitalRead(M0);
    }
    bool M1_read() {
     return   digitalRead(M1);
    }
    bool M2_read() {
      return  digitalRead(M2);
    }
    bool M3_read() {
     return   digitalRead(M3);
    }
    bool M4_read() {
      return  digitalRead(M4);
    }

} // IR