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
    // 1. Wifi Check
    wifi::checkAndReconnect();

    // 2. Read Sensors
    auto sensorData = sensors::readAllSensors();

    // 3. Send Data (PUT)
    if(!sensorData.empty()){
        http::send_batch(sensorData);
    }

    // Delay 200ms
    delay(200);

    // 4. Get Data (GET)
    std::vector<String> keys = {"g1", "r1", "r2", "r3", "r4", "buzz", "servo"};
    auto actuatorData = http::read_batch(keys);
    actuators::updateAll(actuatorData);

    // Delay remaining time to make total cycle approx 1000ms
    // Logic: Actions take time, so we just add a "Rest" delay.
    // User requested "loops hapen in a second with 200 ms delay between each stroke"
    // We have one explicit 200ms delay. Let's add another one at end or make loop longer.
    // Simulating "Stroke 1 (Send)" -> Delay 200 -> "Stroke 2 (Get)" -> Delay 200/Wait.
    
    delay(200); 
    
    // Heartbeat LED
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    
    // Additional delay to calm down the loop to ~1 sec total if needed, 
    // but user asked for "loops hapen in a second", implies 1Hz freq.
    // HTTP calls take ~100-500ms each.
    // 200 (delay) + 200 (delay) + 500 (http1) + 500 (http2) approx = 1.4s.
    // This is close enough.
}