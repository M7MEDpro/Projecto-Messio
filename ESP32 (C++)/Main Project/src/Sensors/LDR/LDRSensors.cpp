#include "LDRSensors.h"
#include <Arduino.h>


// Namespace for managing LDR (Light Dependent Resistor) sensors
namespace LDRSensors {

    // Pin variables for the LDR sensors
    int sensor1;
    int sensor2;

    bool LDR1Status = false;
    bool LDR2Status = false;

    // Initializes the LDR sensors by setting their pin modes
    void initialize() {
        pinMode(sensor1, INPUT);
        pinMode(sensor2, INPUT);
    }

    // Reads the digital value from the first LDR sensor
    bool readSensor1(){
        return digitalRead(sensor1);
    }

    // Reads the digital value from the second LDR sensor
    bool readSensor2(){
        return digitalRead(sensor2);
    }

    void reading () {
         LDR1Status = LDRSensors::readSensor1();
         LDR2Status = LDRSensors::readSensor2();
    }


}