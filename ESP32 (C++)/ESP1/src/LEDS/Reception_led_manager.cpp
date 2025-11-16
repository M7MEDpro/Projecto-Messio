#include "Reception_led_manager.h"
#include "Arduino.h"
#include "Connection/HTTP_manager.h"

namespace rled {

    // Assign the pins
    int r1 = 26;
    int r2 = 27;
    int r3 = 14;
    int r4 = 19;

    void init() {
        pinMode(r1, OUTPUT);
        pinMode(r2, OUTPUT);
        pinMode(r3, OUTPUT);
        pinMode(r4, OUTPUT);

        // Start with LEDs OFF
        digitalWrite(r1, LOW);
        digitalWrite(r2, LOW);
        digitalWrite(r3, LOW);
        digitalWrite(r4, LOW);
    }

    // Manual write
    void r1_write(bool s) { digitalWrite(r1, s); }
    void r2_write(bool s) { digitalWrite(r2, s); }
    void r3_write(bool s) { digitalWrite(r3, s); }
    void r4_write(bool s) { digitalWrite(r4, s); }

    // Automatic write based on server value
    void r1_write() {
        if (http::read_data("r1") == "1") r1_write(HIGH);
        else r1_write(LOW);
    }

    void r2_write() {
        if (http::read_data("r2") == "1") r2_write(HIGH);
        else r2_write(LOW);
    }

    void r3_write() {
        if (http::read_data("r3") == "1") r3_write(HIGH);
        else r3_write(LOW);
    }

    void r4_write() {
        if (http::read_data("r4") == "1") r4_write(HIGH);
        else r4_write(LOW);
    }

} // namespace rled
