#ifndef GARAGE_LED_MANAGER_H
#define GARAGE_LED_MANAGER_H

namespace gled {
    void init();
    void g1_write(int percent);
    void g1_write();
}

#endif