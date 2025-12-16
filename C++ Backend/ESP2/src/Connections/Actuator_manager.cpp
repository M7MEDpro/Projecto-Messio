#include "Actuator_manager.h"
#include "Garage_door_manager.h"
 
#include "Outter_led_manager.h"
#include "Room1_led_manager.h"
#include "Room2_led_manager.h"

namespace actuators {

    void init() {
        gm::garagedoor_init();
         
        OL::OL_initial();
        room1::room1_init();
        room2::room2_init();
    }

    void updateAll(const std::map<String, String>& data) {
        if (data.find("GD") != data.end()) {
            int gdValue = data.at("GD").toInt();
            gm::garagedoor_command(gdValue);
        }

        if (data.find("OL") != data.end()) {
            int olValue = data.at("OL").toInt();
             
            OL::OL_write(olValue);
        }

        if (data.find("l1") != data.end()) {
            int l1Value = data.at("l1").toInt();
             
            room1::l1_write(l1Value);
        }

        if (data.find("l2") != data.end()) {
            int l2Value = data.at("l2").toInt();
             
            room1::l2_write(l2Value);
        }

        if (data.find("l3") != data.end()) {
            int l3Value = data.at("l3").toInt();
             
            room2::l1_write(l3Value);
        }

        if (data.find("l4") != data.end()) {
            int l4Value = data.at("l4").toInt();
             
            room2::l2_write(l4Value);
        }
    }
}
