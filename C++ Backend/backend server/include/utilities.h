#ifndef UTILITIES_H
#define UTILITIES_H
#include <thread>
#include <chrono>
#include <functional>
#include <iostream>
#include "nlohmann/json.hpp"
namespace utilities {

    void runLater(std::function<void()> callback, long delayMs);
    int jsonToNum(const nlohmann::json& val);
}

#endif

