#ifndef LDR_READING_MANAGER_H
#define LDR_READING_MANAGER_H

namespace LDR {

    extern int L0Value;
    extern int L1Value;

    void LDR_init();
    int LDR0_read();
    int LDR1_read();

}

#endif
