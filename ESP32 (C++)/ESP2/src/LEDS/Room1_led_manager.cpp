#include "Room1_led_manager.h"
#include <Arduino.h>
namespace room1 {
        int led1 =19;
        int led2 =18;
       
        void room1_init(){
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
