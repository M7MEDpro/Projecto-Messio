#include "Actuator_manager.h"
#include "LEDS/Outter_led_manager.h"
#include "LEDS/Room1_led_manager.h"
#include "LEDS/Room2_led_manager.h"
#include "Others/Garage_door_manager.h"

namespace actuators {

    void init() {
        OL::OL_initial();
        room1::room1_init();
        room2::room2_init();
        gm::garagedoor_init();
    }

    void updateAll(const std::map<String, String>& data) {
        if (data.count("OL")) OL::OL_write(data.at("OL").toInt());

        if (data.count("l1")) room1::l1_write(data.at("l1").toInt());
        if (data.count("l2")) room1::l2_write(data.at("l2").toInt());

        if (data.count("l3")) room2::l1_write(data.at("l3").toInt());
        if (data.count("l4")) room2::l2_write(data.at("l4").toInt());

        if (data.count("GD")) gm::garagedoor_command(data.at("GD"));

        gm::garagedoor_update();
    }
}