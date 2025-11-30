#include "LDR_reading_manager.h"
#include <Arduino.h>

#include "Connection/HTTP_manager.h"


namespace LDR {
    int LDR0 = 33;
    int LDR1 = 25;

    void LDR_init() {
        pinMode(LDR0, INPUT);
        pinMode(LDR1, INPUT);
    }

    void LDR0_read() { http::send_data("LDR0", String(digitalRead(LDR0))); }
    void LDR1_read() { http::send_data("LDR1", String(digitalRead(LDR1))); }

}
