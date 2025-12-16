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

    int jsonToNum(const nlohmann::json& val) {
        if (val.is_number()) return val.get<int>();
        if (val.is_string()) {
            try {
                return std::stoi(val.get<std::string>());
            } catch (...) {
                return 0;
            }
        }
        if (val.is_boolean()) return val.get<bool>() ? 1 : 0;
        return 0;
    }
}
