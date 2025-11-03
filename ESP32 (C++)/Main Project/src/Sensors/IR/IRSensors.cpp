#include "IRSensors.h"
#include <Arduino.h>

namespace IRSensors {

    // Pin variables for the IR sensors
    int sensorRoom1;
    int sensorRoom2;
    int sensorGarage;
    int sensorRec1;
    int sensorRec2;

    bool IRStatusRoom1 = false;
    bool IRStatusRoom2 = false;
    bool IRStatusGarage = false;
    bool IRStatusRec1 = false;
    bool IRStatusRec2 = false;

    // Initializes the IR sensor pins as input
    void initialize() {
        pinMode(sensorRoom1, INPUT);
        pinMode(sensorRoom2, INPUT);
        pinMode(sensorGarage, INPUT);
        pinMode(sensorRec1, INPUT);
        pinMode(sensorRec2, INPUT);
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
    bool readSensorRec1() {
        return digitalRead(sensorRec1);
    }

    // Reads the IR sensor for the second reception area
    bool readSensorRec() {
        return digitalRead(sensorRec2);
    }
    void reading () {
         IRStatusRoom1 = IRSensors::readSensorRoom1();
         IRStatusRoom2 = IRSensors::readSensorRoom2();
         IRStatusGarage = IRSensors::readSensorGarage();
         IRStatusRec1 = IRSensors::readSensorRec1();
         IRStatusRec2 = IRSensors:: readSensorRec1();
    }
}
