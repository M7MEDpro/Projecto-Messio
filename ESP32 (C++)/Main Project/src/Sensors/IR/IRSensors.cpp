#include "IRSensors.h"
#include <Arduino.h>

namespace IRSensors {

    // Pin variables for the IR sensors
    int sensorRoom1;
    int sensorRoom2;
    int sensorGarage;
    int sensorReception1;
    int sensorReception2;

    // Initializes the IR sensor pins as input
    void initialize() {
        pinMode(sensorRoom1, INPUT);
        pinMode(sensorRoom2, INPUT);
        pinMode(sensorGarage, INPUT);
        pinMode(sensorReception1, INPUT);
        pinMode(sensorReception2, INPUT);
    }

    // Reads the IR sensor for the first room
    bool readSensorRoom1() {
        return digitalRead(sensorRoom1);
    }

    // Reads the IR sensor for the second room
    bool readSensorRoom2() {
        return digitalRead(sensorRoom2);
    }

    // Reads the IR sensor for the garage
    bool readSensorGarage() {
        return digitalRead(sensorGarage);
    }

    // Reads the IR sensor for the first reception area
    bool readSensorReception1() {
        return digitalRead(sensorReception1);
    }

    // Reads the IR sensor for the second reception area
    bool readSensorReception2() {
        return digitalRead(sensorReception2);
    }
}
