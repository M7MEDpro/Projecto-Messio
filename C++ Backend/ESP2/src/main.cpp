#include <Arduino.h>
#include "wifi_Connection.h"
#include "HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"
#include "Display_manager.h"

SemaphoreHandle_t httpMutex;
TaskHandle_t SensorTask;
TaskHandle_t ActuatorTask;
TaskHandle_t DisplayTask;
TaskHandle_t WifiTask;

void sensorTaskCode(void * parameter) {
    for(;;) {
        auto sensorData = sensors::readAllSensors();
        if(!sensorData.empty()){
             if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(500)) == pdTRUE) {
                http::send_batch(sensorData);
                xSemaphoreGive(httpMutex);
             }
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void actuatorTaskCode(void * parameter) {
    for(;;) {
        std::vector<String> keys = {"OL", "l1", "l2", "l3", "l4", "GD"};
        if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(500)) == pdTRUE) {
            auto actuatorData = http::read_batch(keys);
            xSemaphoreGive(httpMutex);
            actuators::updateAll(actuatorData);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void displayTaskCode(void * parameter) {
    for(;;) {
        display::update();
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void wifiTaskCode(void * parameter) {
    for(;;) {
        if (WiFi.status() != WL_CONNECTED) {
             wifi::connectWiFi();
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);

    // Create mutex before starting tasks
    httpMutex = xSemaphoreCreateMutex();

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
        4096, // Reduced stack size for display if possible
        NULL,
        1,
        &DisplayTask,
        1
    );

    xTaskCreatePinnedToCore(
        wifiTaskCode,
        "WifiTask",
        4096,
        NULL,
        1,
        &WifiTask,
        1
    );
}

void loop() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(10);
}