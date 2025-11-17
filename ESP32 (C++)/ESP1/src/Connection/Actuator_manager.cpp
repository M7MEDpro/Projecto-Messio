#include "Actuator_manager.h"
#include "LEDS/Garage_led_manager.h"
#include "LEDS/Reception_led_manager.h"
#include "Others/Buzzer_manager.h"
#include "Others/Servo_manager.h"

namespace actuators {
    
    void init() {
        gled::init();
        rled::init();
        buzzer::Buzzer_init();
        servo::init();
    }
    
    void updateAll(const std::map<String, String>& data) {
        auto it = data.find("g1");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(18, pwm);
        }

        it = data.find("r1");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(26, pwm);
        }

        it = data.find("r2");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(27, pwm);
        }

        it = data.find("r3");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(14, pwm);
        }

        it = data.find("r4");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(19, pwm);
        }

        it = data.find("buzz");
        if (it != data.end()) {
            if (it->second == "on") {
                buzzer::BuzzMode(true);
            } else if (it->second == "off") {
                buzzer::BuzzMode(false);
            }
        }

        it = data.find("servo");
        if (it != data.end()) {
            if (it->second == "open") {
                servo::open();
            } else if (it->second == "close") {
                servo::close();
            }
        }
    }
}