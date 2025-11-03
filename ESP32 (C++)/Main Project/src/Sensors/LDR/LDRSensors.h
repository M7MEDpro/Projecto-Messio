

#ifndef LDRSENSORS_H
#define LDRSENSORS_H

namespace LDRSensors {
    extern bool LDR1Status;
    extern bool LDR2Status;
    bool readSensor1();
    bool readSensor2();
    void initialize();

    void reading ();
}

#endif
