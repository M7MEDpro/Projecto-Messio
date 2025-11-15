#include "Buzzer_manager.h"
#include <Arduino.h>

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
        if (buzz == 1) {
            digitalWrite(buzzerPin, HIGH);
        }else digitalWrite(buzzerPin, LOW);
    }


}
