//
// Created by sch on 11/2/2025.
//

#ifndef FLAMESENSORS_H
#define FLAMESENSORS_H

namespace FlameSensors {
    extern bool FlameStatusRoom1;
    extern bool FlameStatusRoom2;
    extern bool FlameStatusGarage;
    extern bool FlameStatusRec1;
    extern bool FlameStatusRec2;

    bool readSensorRoom1();
    bool readSensorRoom2();
    bool readSensorGarage();
    bool readSensorRec1();
    bool readSensorRec2();
    void initialize();
    void reading ();


}

#endif
