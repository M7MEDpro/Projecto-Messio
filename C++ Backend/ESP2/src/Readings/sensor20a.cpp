#include "Sensor20A_manager.h"
#include <Arduino.h>
#include "Connections/HTTP_manager.h"

namespace sensor20a {
    int SENSOR_PIN = 0;
    int lastState = -1;
    unsigned long lastChangeTime = 0;
    const unsigned long DEBOUNCE_DELAY = 50;
    const float VOLTAGE = 6.1;

    void sensor20a_init() {
        pinMode(SENSOR_PIN, INPUT);
    }

    void sensor20a_read() {
        int val = digitalRead(SENSOR_PIN);

        if (val != lastState) {
            if (millis() - lastChangeTime > DEBOUNCE_DELAY) {
                lastState = val;
                lastChangeTime = millis();
                float power = val * VOLTAGE;
                http::send_batch("S20A", String(power));
            }
        }
    }
}