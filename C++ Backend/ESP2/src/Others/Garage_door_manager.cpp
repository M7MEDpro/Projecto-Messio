#include "Garage_door_manager.h"
#include <Arduino.h>

namespace gm {
    const int MOTOR_PIN1 = 2;
    const int MOTOR_PIN2 = 4;

    unsigned long motorStartTime = 0;
    bool motorRunning = false;

    int lastProcessedGD = -1;

    void garagedoor_init() {
        pinMode(MOTOR_PIN1, OUTPUT);
        pinMode(MOTOR_PIN2, OUTPUT);
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);

        motorRunning = false;
        lastProcessedGD = -1;

        Serial.println("Garage Door initialized");
    }

    void stopMotor() {
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);
        motorRunning = false;
        Serial.println("Garage Motor STOPPED");
    }

    // direction: 1 = Forward (Open), 0 = Reverse (Close)
    void runMotor(int direction) {
        if (direction == 1) {
            // Forward Direction (Open)
            digitalWrite(MOTOR_PIN1, HIGH);
            digitalWrite(MOTOR_PIN2, LOW);
            Serial.println("Garage Motor: FORWARD (Opening)");
        } else {
            // Reverse Direction (Close)
            digitalWrite(MOTOR_PIN1, LOW);
            digitalWrite(MOTOR_PIN2, HIGH);
            Serial.println("Garage Motor: REVERSE (Closing)");
        }

        motorRunning = true;
        motorStartTime = millis();
    }

    void garagedoor_update() {
        // CRITICAL: Stop motor after exactly 800ms
        if (motorRunning && (millis() - motorStartTime >= 800)) {
            stopMotor();
        }
    }

    void garagedoor_command(int gdValue) {
        // First initialization: just store the state, don't run on boot
        if (lastProcessedGD == -1) {
            lastProcessedGD = gdValue;
            Serial.printf("Garage Door initial state: %d\n", gdValue);
            return;
        }

        // Only act on CHANGE of state (Edge Triggered)
        if (gdValue != lastProcessedGD) {
            Serial.printf("Garage Door command changed: %d -> %d\n", lastProcessedGD, gdValue);

            if (gdValue == 1) {
                runMotor(1); // Run Forward (Open)
            } else if (gdValue == 0) {
                runMotor(0); // Run Reverse (Close)
            }
            lastProcessedGD = gdValue;
        }
    }
}