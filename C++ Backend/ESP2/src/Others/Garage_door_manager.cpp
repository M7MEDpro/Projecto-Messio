#include "Garage_door_manager.h"
#include <Arduino.h>

namespace gm {
    int MOTOR_PIN1 = 16;
    int MOTOR_PIN2 =4;

    unsigned long motorStartTime = 0;
    bool motorRunning = false;
    bool motorDirection = false;
    String lastCommand = "";

    void garagedoor_init() {
        pinMode(MOTOR_PIN1, OUTPUT);
        pinMode(MOTOR_PIN2, OUTPUT);
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);
    }

    void stopMotor() {
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);
        motorRunning = false;
    }

    void runMotor(bool forward) {
        if (forward) {
            digitalWrite(MOTOR_PIN1, HIGH);
            digitalWrite(MOTOR_PIN2, LOW);
        } else {
            digitalWrite(MOTOR_PIN1, LOW);
            digitalWrite(MOTOR_PIN2, HIGH);
        }
        motorRunning = true;
        motorStartTime = millis();
    }

    void garagedoor_update() {
        if (motorRunning && (millis() - motorStartTime >= 2000)) {
            stopMotor();
        }
    }

    void garagedoor_command(const String& command) {
        if (command == lastCommand) {
            return;
        }

        lastCommand = command;

        if (command == "1") {
            runMotor(true);
        } else if (command == "0") {
            runMotor(false);
        }
    }
}