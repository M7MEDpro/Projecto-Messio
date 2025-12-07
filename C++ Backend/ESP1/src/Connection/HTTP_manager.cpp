#include <Arduino.h>

#include "Connection/wifi_Connection.h"
#include "Connection/HTTP_manager.h"
#include "Connection/Sensor_manager.h"
#include "Connection/Actuator_manager.h"

#define LED_PIN 2

bool ledState = false;

TaskHandle_t sensorTaskHandle = NULL;
TaskHandle_t actuatorTaskHandle = NULL;

SemaphoreHandle_t httpMutex;

void sensorTask(void *parameter) {
    while (true) {
        auto sensorData = sensors::readAllSensors();

        if (!sensorData.empty()) {
            if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(100)) == pdTRUE) {
                http::send_batch(sensorData);
                xSemaphoreGive(httpMutex);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void actuatorTask(void *parameter) {
    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};

    while (true) {
        if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(100)) == pdTRUE) {
            auto actuatorData = http::read_batch(keys);
            xSemaphoreGive(httpMutex);

            if (!actuatorData.empty()) {
                actuators::updateAll(actuatorData);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    wifi::connectWiFi();

    sensors::init();
    actuators::init();

    httpMutex = xSemaphoreCreateMutex();

    xTaskCreatePinnedToCore(
        sensorTask,
        "SensorTask",
        4096,
        NULL,
        1,
        &sensorTaskHandle,
        0
    );

    xTaskCreatePinnedToCore(
        actuatorTask,
        "ActuatorTask",
        4096,
        NULL,
        1,
        &actuatorTaskHandle,
        1
    );

    Serial.println("Multi-threaded system started!");
}

void loop() {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    Serial.println("System Running - Free Heap: " + String(ESP.getFreeHeap()));

    delay(1000);
}