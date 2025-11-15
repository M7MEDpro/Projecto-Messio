#include "Flame_reading_manager.h"
#include <Arduino.h>
namespace flame {
    int F1 =36;
    int F2 =39;
    int F3 =34;
    int F4 =35;
    int F5 =32;
    bool F1Value=F1_read();
    bool F2Value=F2_read();
    bool F3Value=F3_read();
    bool F4Value=F4_read();
    bool F5Value=F5_read();

    void flame_init(){
        pinMode(F1,INPUT);
        pinMode(F2,INPUT);
        pinMode(F3,INPUT);
        pinMode(F4,INPUT);
        pinMode(F5,INPUT);

    }
    bool F1_read() {
        return    digitalRead(F1);
    }
    bool F2_read() {
        return   digitalRead(F2);
    }
    bool F3_read() {
        return  digitalRead(F3);
    }
    bool F4_read() {
        return   digitalRead(F4);
    }
    bool F5_read() {
        return  digitalRead(F5);
    }
}