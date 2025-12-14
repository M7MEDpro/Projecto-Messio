#include "Garage_door_manager.h"
#include <Arduino.h>

namespace gm {
    const int MOTOR_PIN1 = 16;
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
    }

    void stopMotor() {
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);
        motorRunning = false;
    }

    // direction: 1 = Forward (Open), 0 = Reverse (Close/Reverse)
    void runMotor(int direction) {
        if (direction == 1) {
            // Forward Direction (1)
            digitalWrite(MOTOR_PIN1, HIGH);
            digitalWrite(MOTOR_PIN2, LOW);
        } else {
            // Reverse Direction (0)
            digitalWrite(MOTOR_PIN1, LOW);
            digitalWrite(MOTOR_PIN2, HIGH);
        }

        motorRunning = true;
        motorStartTime = millis();
    }

    void garagedoor_update() {
        // Stop the motor after 800ms (Instant one-time work)
        if (motorRunning && (millis() - motorStartTime >= 800)) {
            stopMotor();
        }
    }

    void garagedoor_command(int gdValue) {
        // First initialization: just store the state, don't run immediately on boot
        if (lastProcessedGD == -1) {
            lastProcessedGD = gdValue;
            return;
        }

        // Only act on CHANGE of state (Edge Triggered)
        if (gdValue != lastProcessedGD) {
            Serial.print("Garage Command: ");
            Serial.println(gdValue);
            
            if (gdValue == 1) {
                runMotor(1); // Run Forward (Open)
            } else if (gdValue == 0) {
                runMotor(0); // Run Reverse (Close/Reverse)
            }
            lastProcessedGD = gdValue;
        }
    }
}