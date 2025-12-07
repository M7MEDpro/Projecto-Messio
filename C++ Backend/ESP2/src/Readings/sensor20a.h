#ifndef SENSOR20A_MANAGER_H
#define SENSOR20A_MANAGER_H

namespace sensor20a {
    extern int SENSOR_PIN;
    
    void sensor20a_init();
    void sensor20a_read();
}

#endif