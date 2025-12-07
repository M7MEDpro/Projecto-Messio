#include <Arduino.h>
#include "Connection/wifi_Connection.h"
#include "Connection/HTTP_manager.h"
#include "Connection/Sensor_manager.h"
#include "Connection/Actuator_manager.h"

#define LED_PIN 2

TaskHandle_t sensorTaskHandle = NULL;
TaskHandle_t actuatorTaskHandle = NULL;
TaskHandle_t ledTaskHandle = NULL;

SemaphoreHandle_t httpMutex;

void sensorTask(void *parameter) {
    while (true) {
        auto sensorData = sensors::readAllSensors();

        if (!sensorData.empty()) {
            if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(50)) == pdTRUE) {
                http::send_batch(sensorData);
                xSemaphoreGive(httpMutex);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void actuatorTask(void *parameter) {
    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};

    while (true) {
        if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(50)) == pdTRUE) {
            auto actuatorData = http::read_batch(keys);
            xSemaphoreGive(httpMutex);

            if (!actuatorData.empty()) {
                actuators::updateAll(actuatorData);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void ledTask(void *parameter) {
    bool ledState = false;
    while (true) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    wifi::connectWiFi();

    sensors::init();
    actuators::init();

    httpMutex = xSemaphoreCreateMutex();

    xTaskCreatePinnedToCore(sensorTask, "Sensor", 8192, NULL, 2, &sensorTaskHandle, 0);
    xTaskCreatePinnedToCore(actuatorTask, "Actuator", 8192, NULL, 2, &actuatorTaskHandle, 1);
    xTaskCreatePinnedToCore(ledTask, "LED", 2048, NULL, 1, &ledTaskHandle, 0);

    Serial.println("System started");
}

void loop() {
    vTaskDelay(portMAX_DELAY);
}