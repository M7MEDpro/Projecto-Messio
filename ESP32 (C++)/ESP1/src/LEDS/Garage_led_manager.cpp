#include "Garage_led_manager.h"
#include "Arduino.h"
#include "Connection/HTTP_manager.h"
namespace gled {
    int gpin = 18;
    void init() {
        pinMode(gpin,OUTPUT);
        digitalWrite(gpin,LOW);
    }

    void g1_write(bool s) {
        digitalWrite(gpin,s);
    }

    void g1_write() {
        if (http ::read_data("g1") == "1") {
            g1_write(HIGH);
        }
        else {
            g1_write(LOW);
        }

    }



}