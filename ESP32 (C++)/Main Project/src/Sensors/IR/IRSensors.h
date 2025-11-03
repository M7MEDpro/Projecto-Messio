//
// Created by sch on 11/2/2025.
//

#ifndef IRSENSORS_H
#define IRSENSORS_H

namespace IRSensors {
    bool readSensorRoom1();
    bool readSensorRoom2();
    bool readSensorGarage();
    bool readSensorReception1();
    bool readSensorReception2();
    void initialize();

} // IRSensors

#endif //IRSENSORS_H
