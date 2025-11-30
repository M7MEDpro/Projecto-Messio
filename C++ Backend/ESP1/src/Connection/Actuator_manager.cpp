#include "Actuator_manager.h"
#include "LEDS/Garage_led_manager.h"
#include "LEDS/Reception_led_manager.h"
#include "LEDS/Outter_led_manager.h"
#include "Others/Buzzer_manager.h"
#include "Others/Servo_manager.h"

namespace actuators {

    void init() {
        gled::init();
        rled::init();
        OL::OL_initial();
        buzzer::Buzzer_init();
        servo::init();
    }

    void updateAll(const std::map<String, String>& data) {
        if (data.count("g1")) gled::g1_write(data.at("g1").toInt());

        if (data.count("r1")) rled::r1_write(data.at("r1").toInt());
        if (data.count("r2")) rled::r2_write(data.at("r2").toInt());
        if (data.count("r3")) rled::r3_write(data.at("r3").toInt());
        if (data.count("r4")) rled::r4_write(data.at("r4").toInt());

        if (data.count("o1")) OL::OL_write(data.at("o1").toInt());

        if (data.count("buzz")) buzzer::BuzzMode(data.at("buzz").toInt() == 1);

        if (data.count("servo")) {
            int val = data.at("servo").toInt();
            (val == 1) ? servo::open() : servo::close();
        }
    }
}