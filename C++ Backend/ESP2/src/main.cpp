#include <Arduino.h>
#include "Connections/wifi_Connection.h"
#include "Connections/HTTP_manager.h"
#include "Connections/Sensor_manager.h"
#include "Connections/Actuator_manager.h"
#include "Others/Display_manager.h"

TaskHandle_t SensorTask;
TaskHandle_t ActuatorTask;
TaskHandle_t DisplayTask;

void sensorTaskCode(void * parameter) {
    for(;;) {
        auto sensorData = sensors::readAllSensors();
        http::send_batch(sensorData);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void actuatorTaskCode(void * parameter) {
    for(;;) {
        std::vector<String> keys = {"OL", "l1", "l2", "l3", "l4", "GD"};
        auto actuatorData = http::read_batch(keys);
        actuators::updateAll(actuatorData);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void displayTaskCode(void * parameter) {
    for(;;) {
        display::update();
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);

    wifi::connectWiFi();

    sensors::init();
    actuators::init();
    display::start();

    xTaskCreatePinnedToCore(
        sensorTaskCode,
        "SensorTask",
        10000,
        NULL,
        1,
        &SensorTask,
        0
    );

    xTaskCreatePinnedToCore(
        actuatorTaskCode,
        "ActuatorTask",
        10000,
        NULL,
        1,
        &ActuatorTask,
        0
    );

    xTaskCreatePinnedToCore(
        displayTaskCode,
        "DisplayTask",
        10000,
        NULL,
        1,
        &DisplayTask,
        1
    );
}

void loop() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(10);
}