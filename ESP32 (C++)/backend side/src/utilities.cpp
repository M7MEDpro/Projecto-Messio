#include "utilities.h"

#include <thread>
#include <chrono>
#include <functional>
#include <iostream>
namespace utilities {

    void runLater(std::function<void()> callback, long delayMs) {
        std::thread([callback, delayMs]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            callback();
        }).detach();
    }
}