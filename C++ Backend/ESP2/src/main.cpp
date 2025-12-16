#include <Arduino.h>
#include "wifi_Connection.h"
#include "HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"
#include "Display_manager.h"
#include "Garage_door_manager.h"

void setup() {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);

    wifi::connectWiFi(10000);

    sensors::init();
    actuators::init();
    display::start();
    gm::garagedoor_init();

    Serial.println("System started - ESP2 (Big Body Loop)");
}

void loop() {
     
    wifi::checkAndReconnect();


    gm::garagedoor_update();

     
    delay(80);
    gm::garagedoor_update();
     
    std::vector<String> keys = {"OL", "l1", "l2", "l3", "l4", "GD"};
    auto actuatorData = http::read_batch(keys);
    actuators::updateAll(actuatorData);


    delay(80);
    gm::garagedoor_update();
     
    auto sensorData = sensors::readAllSensors();

     
    if(!sensorData.empty()){
        http::send_batch(sensorData);
    }

    delay(80);
    gm::garagedoor_update();

     
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    display::update();
     
     
     
}
