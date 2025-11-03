#include "FlameSensors.h"
#include <Arduino.h>


// Namespace for managing FlameSensors
namespace FlameSensors {

    // Pin variables for the Flame sensors
    int sensorRoom1;
    int sensorRoom2;
    int sensorGarage;
    int sensorRec1;
    int sensorRec2;


    // Initializes the Flame sensors by setting their pin modes
    void initialize() {
        pinMode(sensorRoom1 , INPUT);
        pinMode(sensorRoom2 , INPUT);
        pinMode(sensorGarage, INPUT);
        pinMode(sensorRec1  , INPUT);
        pinMode(sensorRec2  , INPUT);

    }
    // Reads the digital value from the first Flame sensor
    bool readSensorRoom1(){
        return digitalRead(sensorRoom1);
    }
    // Reads the digital value from the second Flame sensor
    bool readSensorRoom2(){
        return digitalRead(sensorRoom2);
    }
    // Reads the digital value from the Garage Flame sensor
    bool readSensorGarage(){
        return digitalRead(sensorGarage);
    }
    // Reads the digital value from the Rec1 Flame sensor
    bool readSensorRec1(){
        return digitalRead(sensorRec1);
    }
    // Reads the digital value from the Rec2 Flame sensor
    bool readSensorRec2(){
        return digitalRead(sensorRec2);
    }
}