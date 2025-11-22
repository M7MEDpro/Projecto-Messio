#include "Actuator_manager.h"
#include "LEDS/Outter_led_manager.h"
#include "LEDS/Room1_led_manager.h"
#include "LEDS/Room2_led_manager.h"

namespace actuators {
    
    void init() {
        OL::OL_initial();
        room1::room1_init();
        room2::room2_init();
    }
    
    void updateAll(const std::map<String, String>& data) {
        auto it = data.find("OL");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(16, pwm);
        }

        it = data.find("l1");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(19, pwm);
        }

        it = data.find("l2");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(18, pwm);
        }

        it = data.find("l3");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(5, pwm);
        }

        it = data.find("l4");
        if (it != data.end()) {
            int percent = it->second.toInt();
            int pwm = map(percent, 0, 100, 0, 255);
            analogWrite(17, pwm);
        }

        it = data.find("mg");
        if (it != data.end()) {
            String val = it->second;
            val.toLowerCase();

        }
    }
}