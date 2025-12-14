#include "garage.h"
#include "dataModel.h"

namespace garage {

    unsigned long openStartTime = 0;
    bool waitingToClose = false;
    int previousM0Read = -1;
    int stableCount = 0;

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
                // We only send '1' if we aren't already in the open wait cycle to avoid spamming
                 if (!waitingToClose) {
                    esp2::mg = 1;      // Send Open
                    waitingToClose = true;
                    openStartTime = millis();
                    Serial.println("Garage: M0 Triggered -> Opening");
                }
            }
        }

        // --- TIMING LOGIC (Wait 4 seconds then Close) ---
        if (waitingToClose) {
            if (millis() - openStartTime >= 4000) {
                esp2::mg = 0; // Send Close
                waitingToClose = false;
                Serial.println("Garage: Auto-Closing after 4s");
            }
        }

        // --- MOBILE APP LOGIC ---
        // If user manually presses Open (1) or Close (0) on App
        // NOTE: The app updates `esp2::mg` directly via dataModel mapping usually,
        // or we need to intercept it. Assuming `esp2::mg` is the shared state.
        // However, `esp2::mg` is an OUTPUT to ESP2. We need to check inputs or just let the M0 logic override.
        // Current requirement: "mobile app send 1 it opens send 0 it close"
        
        // This is tricky because `esp2::mg` is the variable sent TO ESP2. 
        // If the App writes to it, it changes. 
        // We need to ensure we don't overwrite user commands unless logic dictates.
        
        // Refinement based on "M0 READ ALL FILES and make mobiel app send 1 it opens send 0 it close if its already 0 sending 0 again won't do any thingg"
        // This suggests `esp2::mg` holds the desired state.
        
        // Allow App to override "waitingToClose" if they manually close
        if (esp2::mg == 0 && waitingToClose) {
             waitingToClose = false; // User forced close
        }
    }
}