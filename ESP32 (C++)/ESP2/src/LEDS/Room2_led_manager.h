#ifndef ROOM2_LED_MANAGER_H
#define ROOM2_LED_MANAGER_H

namespace room2 {
    void room2_init();


    void l1_write(bool state);
    void l2_write(bool state);

    void l1_write();
    void l2_write();
}

#endif