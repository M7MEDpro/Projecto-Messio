#include "sensor20a.h"
#include <Arduino.h>

namespace sensor20a {

    const int SENSOR_PIN = 33;
    const float SENSITIVITY = 0.100;

    // Non-blocking reading state
    static bool isReading = false;
    static unsigned long readStartTime = 0;
    static int maxValue = 0;
    static int minValue = 4095;
    static const unsigned long READ_DURATION = 200; // Reduced from 1000ms to 200ms

    double voltage = 0;
    double vRMS = 0;
    double AmpsRMS = 0;

    void sensor20a_init() {
        pinMode(SENSOR_PIN, INPUT);
    }

    // Non-blocking version - call this repeatedly
    bool updateReading() {
        if (!isReading) {
            // Start new reading
            isReading = true;
            readStartTime = millis();
            maxValue = 0;
            minValue = 4095;
            return false; // Not done yet
        }

        // Continue reading
        int readValue = analogRead(SENSOR_PIN);
        if (readValue > maxValue) {
            maxValue = readValue;
        }
        if (readValue < minValue) {
            minValue = readValue;
        }

        // Check if we're done
        if (millis() - readStartTime >= READ_DURATION) {
            isReading = false;
            return true; // Reading complete
        }

        return false; // Still reading
    }

    float getVPP() {
        float result = ((maxValue - minValue) * 3.3) / 4095.0;
        return result;
    }

    std::vector<std::pair<String, String>> sensor20a_read() {
        std::vector<std::pair<String, String>> updates;

        // Only return data if we have a complete reading
        if (updateReading()) {
            voltage = getVPP();
            vRMS = voltage / 2.828;
            AmpsRMS = vRMS / SENSITIVITY;
            float power = 220.0 * AmpsRMS;

            if (power < 0) power = 0;
            if (AmpsRMS < 0.1) {
                power = 0;
            }

            updates.push_back({"S20A", String((int)power)});
        }

        return updates;
    }
}