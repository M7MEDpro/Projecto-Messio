#include "LDRSensors.h"
#include <Arduino.h>



namespace LDRSensors {
    int sensor1;
    int sensor2;

    bool readSensor1(){
        return digitalRead(sensor1);
    }


    bool readSensor2(){
        return digitalRead(sensor2);
    }
}