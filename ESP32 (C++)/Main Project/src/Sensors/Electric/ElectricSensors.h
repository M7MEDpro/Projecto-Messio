#ifndef ELECTRICSENSORS_H
#define ELECTRICSENSORS_H

namespace ElectricSensors {

    double readCurrent();
    double readVoltage();
    void initialize();
    extern  double current;
    extern  double voltage;
    void reading ();

}

#endif
