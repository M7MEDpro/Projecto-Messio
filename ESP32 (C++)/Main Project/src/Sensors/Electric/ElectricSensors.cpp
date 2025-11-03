#include "ElectricSensors.h"
#include <Arduino.h>

namespace ElectricSensors {
    int currentSensor;
    int voltageSensor;

    double current = 0;
    double volatge = 0;

    // Set up the sensor pins
    void initialize() {
        pinMode(currentSensor, INPUT);
        pinMode(voltageSensor, INPUT);
    }

    // Read current value from sensor
    double readCurrent() {
        // Take 10 readings and add them up
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            sum += analogRead(currentSensor);
        }

        // Convert ADC value to voltage
        double voltage = ((sum / 5.0) * 3.3) / 4095.0;

        // Convert voltage to current (ACS712 sensor formula)
        double current = (voltage - 1.65) / 0.100;

        // Filter out noise - return 0 if the current is very small
        return (abs(current) < 0.05) ? 0.0 : current;
    }

    // Read voltage value from sensor
    double readVoltage() {
        // Take 10 readings and add them up
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            sum += analogRead(voltageSensor);
        }

        // Convert ADC value to voltage
        double adcVoltage = ((sum / 5.0) * 3.3) / 4095.0;

        // Scale up to actual voltage using voltage divider ratio
        return adcVoltage * 7.576;
    }

     void reading() {
        current = ElectricSensors::readCurrent();
        volatge = ElectricSensors::readVoltage();
     }

}