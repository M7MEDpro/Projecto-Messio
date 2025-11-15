

#ifndef IR_READING_MANAGER_H
#define IR_READING_MANAGER_H

namespace IR {
    extern bool M0Value;
    extern bool M1Value;
    extern bool M2Value;
    extern bool M3Value;
    extern bool M4Value;

    void IR_init();
    bool M0_read();
    bool M1_read();
    bool M2_read();
    bool M3_read();
    bool M4_read();
} // IR

#endif //IR_READING_MANAGER_H
