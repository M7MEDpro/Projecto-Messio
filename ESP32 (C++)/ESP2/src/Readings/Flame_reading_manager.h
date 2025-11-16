#ifndef FLAME_READING_MANAGER_H
#define FLAME_READING_MANAGER_H

namespace flame {
    extern bool F1Value;
    extern bool F2Value;
    extern bool F3Value;
    extern bool F4Value;
    extern bool F5Value;

    void flame_init();
    void F1_read();
    void F2_read();
    void F3_read();
    void F4_read();
    void F5_read();

}

#endif
