#ifndef RECEPTION_LED_MANAGER_H
#define RECEPTION_LED_MANAGER_H

namespace rled {
    void init();
    void r1_write(bool s);
    void r1_write(); // automatic read from server
    void r2_write(bool s);
    void r2_write(); // automatic read from server
    void r3_write(bool s);
    void r3_write(); // automatic read from server
    void r4_write(bool s);
    void r4_write(); // automatic read from server
} // namespace rled

#endif // RECEPTION_LED_MANAGER_H
