#include "Buzzer_manager.h"
#include "Arduino.h"
#include "HTTP_manager.h"

namespace buzzer { int buzzerPin = 4;  
    bool buzz = false;

    void Buzzer_init() {
        pinMode(buzzerPin, OUTPUT);
        digitalWrite(buzzerPin, LOW);
    }

    void BuzzMode(bool b) {
        buzz = b;
        digitalWrite(buzzerPin, buzz ? HIGH : LOW);
    }
}
