//
// Created by sch on 11/15/2025.
//

#ifndef LDR_READING_MANAGER_H
#define LDR_READING_MANAGER_H

namespace LDR {

    extern int L0Value;
    extern int L1Value;


    void LDR_init();
    void LDR0_read();
    void LDR1_read();

} // LDR

#endif //LDR_READING_MANAGER_H
