#include <Arduino.h>

#include "Connections/wifi_Connection.h"
#include "Connections/HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"
#include "Others/Display_manager.h"

void setup() {
    Serial.begin(115200);
    wifi::connectWiFi();

    sensors::init();
    actuators::init();
    display::start();
}

void loop() {
    auto sensorData = sensors::readAllSensors();

    http::send_batch(sensorData);

    std::vector<String> keys = {"OL", "l1", "l2", "l3", "l4"};
    auto actuatorData = http::read_batch(keys);

    actuators::updateAll(actuatorData);

    display::update();

    delay(300);
}