//
// Created by sch on 11/15/2025.
//

#include "Servo_manager.h"
#include <ESP32Servo.h>

namespace servo {
    Servo myServo;
    int servoPin = 5;
    void init() {
        myServo.attach(servoPin);
    }
    void open() {
        myServo.write(180);
    }
    void close () {
        myServo.write(0);

    }
} // servo