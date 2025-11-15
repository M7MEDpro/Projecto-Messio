#include "Garage_led_manager.h"
#include "Arduino.h"
namespace gled {
    int gpin = 18;
    void init() {
        pinMode(gpin,OUTPUT);
        digitalWrite(gpin,LOW);
    }
    void g1_write(bool s) { digitalWrite(gpin,s); }

} // gled