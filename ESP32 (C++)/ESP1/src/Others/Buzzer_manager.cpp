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

    void BuzzMode(int b) {
        buzz = b;
    }

    void BuzzUpdate() {
        if (http::read_data("buzz") == "1") buzz = true;
        else buzz = false;

        digitalWrite(buzzerPin, buzz ? HIGH : LOW);
    }
}
