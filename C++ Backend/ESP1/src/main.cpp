#include <Arduino.h>
#include "wifi_Connection.h"
#include "HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"

#define LED_PIN 2

TaskHandle_t sensorTaskHandle = NULL;
TaskHandle_t actuatorTaskHandle = NULL;
TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t wifiTaskHandle = NULL;

SemaphoreHandle_t httpMutex;
QueueHandle_t sensorDataQueue;
QueueHandle_t actuatorDataQueue;

struct SensorData {
    std::vector<std::pair<String, String>> data;
};

struct ActuatorData {
    std::map<String, String> data;
};

void sensorTask(void *parameter) {
    SensorData sensorData;

    while (true) {
        sensorData.data = sensors::readAllSensors();

        if (!sensorData.data.empty()) {
            if (xQueueSend(sensorDataQueue, &sensorData, 0) != pdTRUE) {
                
            }
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void httpSendTask(void *parameter) {
    SensorData sensorData;

    while (true) {
        if (xQueueReceive(sensorDataQueue, &sensorData, portMAX_DELAY) == pdTRUE) {
            if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(500)) == pdTRUE) {
                http::send_batch(sensorData.data);
                xSemaphoreGive(httpMutex);
            }
        }
    }
}

void httpReceiveTask(void *parameter) {
    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};
    ActuatorData actuatorData;

    while (true) {
        if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(500)) == pdTRUE) {
            actuatorData.data = http::read_batch(keys);
            xSemaphoreGive(httpMutex);

            if (!actuatorData.data.empty()) {
               xQueueSend(actuatorDataQueue, &actuatorData, 0);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void actuatorTask(void *parameter) {
    ActuatorData actuatorData;

    while (true) {
        if (xQueueReceive(actuatorDataQueue, &actuatorData, portMAX_DELAY) == pdTRUE) {
            actuators::updateAll(actuatorData.data);
        }
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

void wifiTask(void *parameter) {
    while (true) {
        wifi::checkAndReconnect();
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    wifi::connectWiFi();

    sensors::init();
    actuators::init();

    httpMutex = xSemaphoreCreateMutex();
    sensorDataQueue = xQueueCreate(10, sizeof(SensorData));
    actuatorDataQueue = xQueueCreate(10, sizeof(ActuatorData));

    xTaskCreatePinnedToCore(sensorTask, "Sensor", 8192, NULL, 2, &sensorTaskHandle, 0);
    xTaskCreatePinnedToCore(httpSendTask, "HTTPSend", 8192, NULL, 2, NULL, 0);
    xTaskCreatePinnedToCore(httpReceiveTask, "HTTPReceive", 8192, NULL, 2, NULL, 1);
    xTaskCreatePinnedToCore(actuatorTask, "Actuator", 8192, NULL, 2, &actuatorTaskHandle, 1);
    xTaskCreatePinnedToCore(ledTask, "LED", 2048, NULL, 1, &ledTaskHandle, 0);
    xTaskCreatePinnedToCore(wifiTask, "WiFi", 4096, NULL, 1, &wifiTaskHandle, 1);

    Serial.println("System started");
}

void loop() {
    vTaskDelay(portMAX_DELAY);
}