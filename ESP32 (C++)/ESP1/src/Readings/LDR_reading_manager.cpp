//
// Created by sch on 11/15/2025.
//

#include "LDR_reading_manager.h"
#include <Arduino.h>
namespace LDR {
    int L0 = 33;
    int L1 = 25;


    int L0Value = L0_read();
    int L1Value = L1_read();

    void LDR_init() {
        pinMode(L0, INPUT);
        pinMode(L1, INPUT);

    }

    bool L0_read() { return digitalRead(L0); }
    bool L1_read() { return digitalRead(L1); }

} // LDR