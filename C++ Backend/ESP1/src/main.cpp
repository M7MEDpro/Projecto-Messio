#include <Arduino.h>
#include "wifi_Connection.h"
#include "HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"

void setup() {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);

    wifi::connectWiFi(10000);

    sensors::init();
    actuators::init();

    Serial.println("System started - ESP1 (Big Body Loop)");
}

void loop() {
     
    wifi::checkAndReconnect();

     
    auto sensorData = sensors::readAllSensors();

     
    if(!sensorData.empty()){
        http::send_batch(sensorData);
    }

     
    delay(80);

     
    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};
    auto actuatorData = http::read_batch(keys);
    actuators::updateAll(actuatorData);


    delay(80);

     
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

     
     
     
     
     
}
