#include "Buzzer_manager.h"
#include "Arduino.h"
#include "Connection/HTTP_manager.h"

namespace buzzer {
    int buzzerPin = 17;
    bool buzz = false;

    void Buzzer_init() {
        pinMode(buzzerPin, OUTPUT);
        digitalWrite(buzzerPin, LOW);
    }

    void BuzzMode(bool b) {
        buzz = b;
        digitalWrite(buzzerPin, buzz ? HIGH : LOW);
    }

    void BuzzUpdate() {
        String val = http::read_data("buzz");
        if (val == "on") {
            BuzzMode(true);
        } else if (val == "off") {
            BuzzMode(false);
        }
    }
}