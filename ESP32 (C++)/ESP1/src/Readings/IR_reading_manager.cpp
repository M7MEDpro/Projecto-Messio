
#include "IR_reading_manager.h"
#include <Arduino.h>

#include "Connection/HTTP_manager.h"

namespace IR {
    int M0 =36;
    int M1 =39;
    int M2 =34;
    int M3 =35;
    int M4 =32;


    void IR_init(){
        pinMode(M0,INPUT);
        pinMode(M1,INPUT);
        pinMode(M2,INPUT);
        pinMode(M3,INPUT);
        pinMode(M4,INPUT);
    }

    void M0_read() { http::send_data("M0", String(digitalRead(M0))); }
    void M1_read() { http::send_data("M1", String(digitalRead(M1))); }
    void M2_read() { http::send_data("M2", String(digitalRead(M2))); }
    void M3_read() { http::send_data("M3", String(digitalRead(M3))); }
    void M4_read() { http::send_data("M4", String(digitalRead(M4))); }

}