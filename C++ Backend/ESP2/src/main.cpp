#include <Arduino.h>
#include "wifi_Connection.h"
#include "HTTP_manager.h"
#include "Sensor_manager.h"
#include "Actuator_manager.h"
#include "Display_manager.h"
#include "Garage_door_manager.h"

SemaphoreHandle_t httpMutex;
TaskHandle_t SensorTask;
TaskHandle_t ActuatorTask;
TaskHandle_t DisplayTask;
TaskHandle_t WifiTask;
TaskHandle_t LedTask;
TaskHandle_t GarageTask;

void sensorTaskCode(void * parameter) {
    for(;;) {
        auto sensorData = sensors::readAllSensors();
        if(!sensorData.empty()){
             if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(2000)) == pdTRUE) {
                http::send_batch(sensorData);
                xSemaphoreGive(httpMutex);
             }
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void actuatorTaskCode(void * parameter) {
    for(;;) {
        std::vector<String> keys = {"OL", "l1", "l2", "l3", "l4", "GD"};
        if (xSemaphoreTake(httpMutex, pdMS_TO_TICKS(2000)) == pdTRUE) {
            auto actuatorData = http::read_batch(keys);
            xSemaphoreGive(httpMutex);
            actuators::updateAll(actuatorData);
        }
        vTaskDelay(800 / portTICK_PERIOD_MS);
    }
}

void displayTaskCode(void * parameter) {
    for(;;) {
        display::update();
        vTaskDelay(1200 / portTICK_PERIOD_MS);
    }
}

void wifiTaskCode(void * parameter) {
    for(;;) {
        wifi::checkAndReconnect();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void ledTaskCode(void * parameter) {
    for(;;) {
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        vTaskDelay(350 / portTICK_PERIOD_MS);
    }
}

void garageTaskCode(void * parameter) {
    for(;;) {
        gm::garagedoor_update();
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);

    httpMutex = xSemaphoreCreateMutex();

    pinMode(LED_BUILTIN, OUTPUT);

    wifi::connectWiFi(10000);

    sensors::init();
    actuators::init();
    display::start();

    xTaskCreatePinnedToCore(
        sensorTaskCode,
        "SensorTask",
        10000,
        NULL,
        2,
        &SensorTask,
        0
    );

    xTaskCreatePinnedToCore(
        actuatorTaskCode,
        "ActuatorTask",
        10000,
        NULL,
        2,
        &ActuatorTask,
        0
    );

    xTaskCreatePinnedToCore(
        displayTaskCode,
        "DisplayTask",
        4096,
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
        3,
        &WifiTask,
        1
    );

    xTaskCreatePinnedToCore(
        ledTaskCode,
        "LedTask",
        2048,
        NULL,
        1,
        &LedTask,
        1
    );

    xTaskCreatePinnedToCore(
        garageTaskCode,
        "GarageTask",
        4096,
        NULL,
        2,
        &GarageTask,
        0
    );
}

void loop() {
}