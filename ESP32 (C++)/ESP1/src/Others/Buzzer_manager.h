//
// Created by sch on 11/15/2025.
//

#ifndef BUZZER_MANAGER_H
#define BUZZER_MANAGER_H

namespace buzzer {

    void Buzzer_init();
    void BuzzMode(int b);
    void BuzzUpdate();

    extern bool buzz;

} // buzzer

#endif //BUZZER_MANAGER_H
