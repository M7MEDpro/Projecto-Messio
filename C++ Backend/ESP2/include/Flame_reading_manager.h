#ifndef FLAME_READING_MANAGER_H
#define FLAME_READING_MANAGER_H

namespace flame {
    extern int F1, F2, F3, F4, F5;

    void flame_init();
    std::vector<std::pair<String, String>> flame_read();
}
#endif