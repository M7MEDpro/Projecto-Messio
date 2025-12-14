#include "garage.h"
#include "dataModel.h"

namespace garage {

    int lastAppliedM0 = -1;
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

        int currentM0 = esp1::M0;

        if (currentM0 == previousM0Read) {
            stableCount++;
        } else {
            stableCount = 0;
            previousM0Read = currentM0;
        }

        if (stableCount >= 2) {

            if (currentM0 != lastAppliedM0) {
                esp2::mg = currentM0;
                lastAppliedM0 = currentM0;
            }
        }
    }
}