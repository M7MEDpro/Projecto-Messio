

#ifndef IR_READING_MANAGER_H
#define IR_READING_MANAGER_H

namespace IR {
    extern bool M0Value;
    extern bool M1Value;
    extern bool M2Value;
    extern bool M3Value;
    extern bool M4Value;

    void IR_init();
    void M0_read();
    void M1_read();
    void M2_read();
    void M3_read();
    void M4_read();
}

#endif
