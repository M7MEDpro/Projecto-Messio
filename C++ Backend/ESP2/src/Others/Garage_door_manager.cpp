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

     
    void runMotor(int direction) {
        if (direction == 1) {
             
            digitalWrite(MOTOR_PIN1, HIGH);
            digitalWrite(MOTOR_PIN2, LOW);
            Serial.println("Garage Motor: FORWARD (Opening)");
        } else {
             
            digitalWrite(MOTOR_PIN1, LOW);
            digitalWrite(MOTOR_PIN2, HIGH);
            Serial.println("Garage Motor: REVERSE (Closing)");
        }

        motorRunning = true;
        motorStartTime = millis();
    }

    void garagedoor_update() {
         
        if (motorRunning && (millis() - motorStartTime >= 800)) {
            stopMotor();
        }
    }

    void garagedoor_command(int gdValue) {
         
        if (lastProcessedGD == -1) {
            lastProcessedGD = gdValue;
            Serial.printf("Garage Door initial state: %d\n", gdValue);
            return;
        }

         
        if (gdValue != lastProcessedGD) {
            Serial.printf("Garage Door command changed: %d -> %d\n", lastProcessedGD, gdValue);

            if (gdValue == 1) {
                runMotor(1);  
            } else if (gdValue == 0) {
                runMotor(0);  
            }
            lastProcessedGD = gdValue;
        }
    }
}
