#include <Arduino.h>

#include "Connection/wifi_Connection.h"
#include "Connection/HTTP_manager.h"
#include "Connection/Sensor_manager.h"
#include "Connection/Actuator_manager.h"

void setup() {
    Serial.begin(115200);
    wifi::connectWiFi();

    sensors::init();
    actuators::init();
}

void loop() {
    auto sensorData = sensors::readAllSensors();

    http::send_batch(sensorData);

    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};
    auto actuatorData = http::read_batch(keys);

    actuators::updateAll(actuatorData);

    delay(300);
}