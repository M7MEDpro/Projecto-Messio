#include "Flame_reading_manager.h"
#include <Arduino.h>

#include "Connections/HTTP_manager.h"

namespace flame {
    int F1 =36;
    int F2 =39;
    int F3 =34;
    int F4 =35;
    int F5 =32;
    

    void flame_init(){
        pinMode(F1,INPUT);
        pinMode(F2,INPUT);
        pinMode(F3,INPUT);
        pinMode(F4,INPUT);
        pinMode(F5,INPUT);

    }

    void F1_read() { http::send_data("F1", String(digitalRead(F1))); }
    void F2_read() { http::send_data("F2", String(digitalRead(F2))); }
    void F3_read() { http::send_data("F3", String(digitalRead(F3))); }
    void F4_read() { http::send_data("F4", String(digitalRead(F4))); }
    void F5_read() { http::send_data("F5", String(digitalRead(F5))); }
}
