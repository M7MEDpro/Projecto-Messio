#ifndef SERVO_MANAGER_H
#define SERVO_MANAGER_H

namespace servo {
    void init();
    void open();
    void close();

    // Automatic update from server
    void Update();
}

#endif // SERVO_MANAGER_H
