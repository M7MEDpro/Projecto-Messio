#ifndef BUZZER_MANAGER_H
#define BUZZER_MANAGER_H

namespace buzzer {
    void Buzzer_init();

    // Manual control
    void BuzzMode(int b);

    // Automatic update from server
    void BuzzUpdate();

    extern bool buzz;
}

#endif // BUZZER_MANAGER_H
