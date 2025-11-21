#ifndef UTILITIES_H
#define UTILITIES_H
#include <thread>
#include <chrono>
#include <functional>
#include <iostream>
namespace utilities {

    void runLater(std::function<void()> callback, long delayMs);

}

#endif
