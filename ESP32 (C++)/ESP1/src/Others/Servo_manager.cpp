#include "Servo_manager.h"
#include "Arduino.h"
#include "ESP32Servo.h"
#include "Connection/HTTP_manager.h"

namespace servo {
    Servo myServo;
    int servoPin = 5;

    void init() {
        myServo.attach(servoPin);
    }

    void open() {
        myServo.write(180);
    }

    void close() {
        myServo.write(0);
    }

    void Update() {
        String val = http::read_data("servo");
        if (val == "open") {
            open();
        } else if (val == "close") {
            close();
        }
    }
}