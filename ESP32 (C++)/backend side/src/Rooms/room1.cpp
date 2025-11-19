#include "room1.h"

#include "../dataModel.h"

namespace room1 {
    void updateLed() {
        if (mobile_app::room1::mode == 0) {
            esp2::l1 =0;
            esp2::l2 =0;
            return;
        }
        if (mobile_app::room1::mode == 1) {
            esp2 :: l1 =mobile_app::room1::brightness;;
            esp2 :: l2 =mobile_app::room1::brightness;
            return;
        } if ( mobile_app::room1::mode == 2 && mobile_app::room1::ldr == 1 && mobile_app::room1::ir == 0) {
            if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
                esp2 :: l1 =mobile_app::room1::brightness;
                esp2 :: l2 =mobile_app::room1::brightness;
                return;
            }else {
                esp2:: l1 =0;
                esp2:: l2 =0;
                return;
            }
        }
         if (mobile_app::room1::mode == 2 && mobile_app::room1::ldr == 0 && mobile_app::room1::ir == 1) {
            if (esp1 :: M3 == 1) {
                esp2:: l1 =mobile_app::room1::brightness;
                esp2:: l2 =mobile_app::room1::brightness;
                return;
            }
             if (esp1 :: M3 == 0) {
                 esp2 :: l1 =mobile_app::room1::brightness;
                 esp2 :: l2 =mobile_app::room1::brightness;
                 return;
             }
        } if (mobile_app::room1:: mode ==2 && mobile_app::room1::ldr == 1 && mobile_app::room1::ir == 1) {
            if (esp1 :: M3 ==1 && (esp1 :: LDR0 ==1 || esp1 :: LDR1 ==1)) {
                esp2 :: l1 =mobile_app::room1::brightness;
                esp2 :: l2 =mobile_app::room1::brightness;
                return;
            }else {
                esp2 :: l1 =0;
                esp2 :: l2 =0;
                return;
            }
        }



    }
}
