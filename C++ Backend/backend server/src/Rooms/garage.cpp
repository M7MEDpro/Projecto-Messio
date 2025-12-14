#include "garage.h"
#include "dataModel.h"
#include <chrono>
#include <iostream>

namespace garage {

    std::chrono::steady_clock::time_point openStartTime;
    bool waitingToClose = false;
    int previousM0Read = -1;
    int stableCount = 0;
    bool commandSent = false;

    void updateLed() {
        if (mobile_app::garage::mode == 0) {
            esp1::g1 = 0;
        } else if (mobile_app::garage::mode == 1) {
            esp1::g1 = mobile_app::garage::brightness;
        } else if (mobile_app::garage::mode == 2) {
            if (mobile_app::garage::ldr == 1) {
                if (esp1::LDR1 < 500) {
                    esp1::g1 = mobile_app::garage::brightness;
                } else {
                    esp1::g1 = 0;
                }
            }
            if (mobile_app::garage::ir == 1) {
                if (esp1::M4 == 1) {
                    esp1::g1 = mobile_app::garage::brightness;
                } else {
                    esp1::g1 = 0;
                }
            }
        }
    }

    void update() {
        updateLed();

        int currentM0 = esp1::M0; // 0=High/Idle, 1=Low/Detected (based on IR_reading_manager logic)

        if (currentM0 == previousM0Read) {
            stableCount++;
        } else {
            stableCount = 0;
            previousM0Read = currentM0;
        }

        // Only act if reading is stable
        if (stableCount >= 2) {
            // Logic: M0 Detected (1) -> Open Door
            if (currentM0 == 1) {
                // If not already opening/open, send Open command (1)
                if (!waitingToClose) {
                    esp2::mg = 1;      // Send Open
                    waitingToClose = true;
                    commandSent = false;
                    openStartTime = std::chrono::steady_clock::now();
                    std::cout << "Garage: M0 Triggered -> Opening" << std::endl;
                }
            }
        }

        // --- TIMING LOGIC (Wait 4 seconds then Close) ---
        if (waitingToClose) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - openStartTime).count();

            // Send close command at 4 seconds
            if (elapsed >= 4000 && !commandSent) {
                esp2::mg = 0; // Send Close
                commandSent = true;
                std::cout << "Garage: Auto-Closing after 4s" << std::endl;
            }

            // Reset cycle at 5 seconds to allow next trigger
            if (elapsed >= 5000) {
                waitingToClose = false;
                commandSent = false;
                std::cout << "Garage: Cycle Complete, Ready for Next Trigger" << std::endl;
            }
        }

        // --- MOBILE APP LOGIC ---
        // Allow App to override "waitingToClose" if they manually close
        if (esp2::mg == 0 && waitingToClose && !commandSent) {
            waitingToClose = false; // User forced close before auto-close
            commandSent = false;
        }
    }
}