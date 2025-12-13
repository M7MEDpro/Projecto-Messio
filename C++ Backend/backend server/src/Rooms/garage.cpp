#include "garage.h"
#include <iostream>
#include "dataModel.h"
#include "utilities.h"

namespace garage {

    void updateLed() {
        static int last_M0 = 0;

        if (mobile_app::garage::mode == 2 && mobile_app::garage::ir == 1) {
            if (esp1::M0 == 1 && last_M0 == 0) {
                esp2::mg = (esp2::mg == 0) ? 1 : 0; 
                std::cout << "Garage Door Toggled to: " << esp2::mg << std::endl;
            }
        }
        last_M0 = esp1::M0; 

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
                utilities::runLater([]() {
                    esp1 :: g1 =0;
                },5000);
                return;
            }
        } if (mobile_app::garage:: mode ==2 && mobile_app::garage::ldr == 1 && mobile_app::garage::ir == 1) {
            if (esp1 :: M0 ==1 && (esp1 :: LDR0 ==1 || esp1 :: LDR1 ==1)) {
                esp1 :: g1=mobile_app::garage::brightness;
                return;
            }

        }else {
            utilities::runLater([]() {
                    esp1 :: g1 =0;
                },10000);
            return;
        }
    }
}
