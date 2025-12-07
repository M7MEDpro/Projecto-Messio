#include "LDR_reading_manager.h"
#include <Arduino.h>

namespace LDR {
    int LDR0 = 33;
    int LDR1 = 25;

    void LDR_init() {
        pinMode(LDR0, INPUT);
        pinMode(LDR1, INPUT);
    }

    int LDR0_read() {
        return digitalRead(LDR0);
    }

    int LDR1_read() {
        return digitalRead(LDR1);
    }

}