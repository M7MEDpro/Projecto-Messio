#include "Servo_manager.h"
#include "Arduino.h"
#include "ESP32Servo.h"

namespace servo {
    Servo myServo; int servoPin = 5; int currentState = 0;

    void init() {
        myServo.attach(servoPin);
        myServo.write(90); // Default to Closed (90) on set

    }

    void open() {
        if (currentState == 1) return;
        myServo.write(0); // Open set to 0
        currentState = 1;
    }

    void close() {
        if (currentState == 0) return;
        myServo.write(90); // Close set to 90
        currentState = 0;
    }
}