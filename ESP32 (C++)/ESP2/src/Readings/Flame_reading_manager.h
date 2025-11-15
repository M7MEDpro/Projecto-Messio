#ifndef FLAME_READING_MANAGER_H
#define FLAME_READING_MANAGER_H

namespace flame {
    extern bool F1Value;
    extern bool F2Value;
    extern bool F3Value;
    extern bool F4Value;
    extern bool F5Value;

    void flame_init();
    bool F1_read();
    bool F2_read();
    bool F3_read();
    bool F4_read();
    bool F5_read();

}

#endif
