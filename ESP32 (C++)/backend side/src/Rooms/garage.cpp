#include "garage.h"

#include "../dataModel.h"

namespace garage {

    void updateLed() {
        if (mobile_app::garage::mode == 0) {
            esp1::g1 = 0;
            return;
        }
        if (mobile_app::garage::mode == 1) {
            esp1::g1 = mobile_app::garage::brightness;
            return;
        }
        if (mobile_app::garage::mode == 2 && mobile_app::garage::ir == 1) {
            if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
                esp1::g1 =mobile_app::garage::brightness;
            }
        }
        if (mobile_app::garage:: mode == 2 && mobile_app::garage::ldr == 1 && mobile_app::garage::ir == 0) {
            if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
                esp1 :: g1=mobile_app::garage::brightness;
                return;
            }else {
               esp1 :: g1 =0;
                return;
            }

        }
        if (mobile_app::garage:: mode == 2 && mobile_app::garage::ldr == 0 && mobile_app::garage:: ir == 1) {
            if (esp1 :: M0 == 1) {
                esp1 :: g1=mobile_app::garage::brightness;
                return;

            }
            if (esp1 :: M0 == 0) {
                  esp1 :: g1 =0;
                return;
            }
        } if (mobile_app::garage:: mode ==2 && mobile_app::garage::ldr == 1 && mobile_app::garage::ir == 1) {
            if (esp1 :: M0 ==1 && (esp1 :: LDR0 ==1 || esp1 :: LDR1 ==1)) {
                esp1 :: g1=mobile_app::garage::brightness;
                return;
            }

        }else {
            esp1 :: g1 =0;
            return;
        }
    }
}