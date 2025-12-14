#include "Servo_manager.h"
#include "Arduino.h"
#include "ESP32Servo.h"
#include "HTTP_manager.h"

namespace servo {
    Servo myServo;
    int servoPin = 5;
    int currentState = 0;

    void init() {
        myServo.attach(servoPin);
        myServo.write(0); // Ensure default state is physically applied if needed, or just rely on state var.
        // User said "def value to zero", so writing 0 on init is safe.
    }

    void open() {
        if (currentState == 1) return;
        myServo.write(80);
        currentState = 1;
    }

    void close() {
        if (currentState == 0) return;
        myServo.write(0);
        currentState = 0;
    }


}