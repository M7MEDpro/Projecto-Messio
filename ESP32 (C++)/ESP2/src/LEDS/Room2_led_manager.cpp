#include "Room2_led_manager.h"
#include <Arduino.h>
namespace room2 {
    int led1 =5;
    int led2 =17;

    void room2_init(){
        pinMode(led1,OUTPUT);
        pinMode(led2,OUTPUT);
    }
    void l1_write(bool state){
        digitalWrite(led1,state);
    }
    void l2_write(bool state){
        digitalWrite(led2,state);
    }
}