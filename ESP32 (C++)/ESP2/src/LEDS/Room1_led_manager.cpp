#include "Room1_led_manager.h"
#include "Arduino.h"
#include "connections/HTTP_manager.h"

namespace room1 {
    int led1 = 19;
    int led2 = 18;

    void room1_init(){
        pinMode(led1, OUTPUT);
        pinMode(led2, OUTPUT);

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }

    void l1_write(bool state){ digitalWrite(led1, state); }
    void l2_write(bool state){ digitalWrite(led2, state); }

    void l1_write() {
        if (http::read_data("l1") == "1") l1_write(HIGH);
        else l1_write(LOW);
    }

    void l2_write() {
        if (http::read_data("l2") == "1") l2_write(HIGH);
        else l2_write(LOW);
    }
}