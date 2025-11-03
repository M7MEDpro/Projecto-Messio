#include <Arduino.h>

#include "Sensors/Electric/ElectricSensors.h"
#include "Sensors/Flame/FlameSensors.h"
#include "Sensors/IR/IRSensors.h"
#include "Sensors/LDR/LDRSensors.h"

void setup() {
    LDRSensors::initialize();
    IRSensors::initialize();
    FlameSensors::initialize();
    ElectricSensors::initialize();
}

void loop() {
// write your code here
    LDRSensors::reading();
    FlameSensors::reading();
    IRSensors::reading();
    ElectricSensors::reading();
}