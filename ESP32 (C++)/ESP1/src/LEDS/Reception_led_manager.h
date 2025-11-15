#ifndef RECEPTION_LED_MANAGER_H
#define RECEPTION_LED_MANAGER_H

namespace rled {
    void rled_int();
    void r1_write(bool s);
    void r2_write(bool s);
    void r3_write(bool s);
    void r4_write(bool s);
} // namespace rled

#endif
