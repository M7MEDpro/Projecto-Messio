#include <Arduino.h>

#include "Connection/wifi_Connection.h"
#include "Connection/HTTP_manager.h"
#include "Connection/Sensor_manager.h"
#include "Connection/Actuator_manager.h"

#define LED_PIN 2

bool ledState = false;

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    wifi::connectWiFi();

    sensors::init();
    actuators::init();
}

void loop() {
    Serial.println("Ready");

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    auto sensorData = sensors::readAllSensors();
    http::send_batch(sensorData);
    delay(100);

    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};
    auto actuatorData = http::read_batch(keys);

    delay(200);
}
