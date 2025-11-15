#include "Reception_led_manager.h"
#include "Arduino.h"

namespace rled {
    // Assign the pins here
    int r1 = 26;
    int r2 = 27;
    int r3 = 14;
    int r4 = 19;

    void rled_int() {
        pinMode(r1, OUTPUT);
        pinMode(r2, OUTPUT);
        pinMode(r3, OUTPUT);
        pinMode(r4, OUTPUT);
        digitalWrite(r1, LOW);
        digitalWrite(r2, LOW);
        digitalWrite(r3, LOW);
        digitalWrite(r4, LOW);
    }

    void r1_write(bool s) {
        digitalWrite(r1, s);
    }
    void r2_write(bool s) {
        digitalWrite(r2, s);
    }
    void r3_write(bool s) {
        digitalWrite(r3, s);
    }
    void r4_write(bool s) {
        digitalWrite(r4, s);
    }

} // namespace rled
