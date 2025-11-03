//
// Created by sch on 11/2/2025.
//

#ifndef IRSENSORS_H
#define IRSENSORS_H

namespace IRSensors {
    extern bool IRStatusRoom1;
    extern bool IRStatusRoom2;
    extern bool IRStatusGarage;
    extern bool IRStatusRec1;
    extern bool IRStatusRec2;
    bool readSensorRoom1();
    bool readSensorRoom2();
    bool readSensorGarage();
    bool readSensorRec1();
    bool readSensorRec2();
    void initialize();
    void reading ();

} // IRSensors

#endif //IRSENSORS_H
