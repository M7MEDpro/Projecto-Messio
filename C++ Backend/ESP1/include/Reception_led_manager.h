#ifndef RECEPTION_LED_MANAGER_H
#define RECEPTION_LED_MANAGER_H

namespace rled {
    void init();
    void r1_write(int percent);
    void r2_write(int percent);
    void r3_write(int percent);
    void r4_write(int percent);
}

#endif
