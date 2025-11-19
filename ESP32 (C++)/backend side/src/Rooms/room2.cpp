#include "room2.h"

#include "../dataModel.h"

namespace room2 {
    void updateLed() {
      if (mobile_app::room2:: mode == 0) {
         esp2:: l3 = 0;
          esp2:: l4 = 0;
          return;
      }if (mobile_app::room2:: mode == 1) {
          esp2:: l3 = mobile_app::room2::brightness;
          esp2:: l4 = mobile_app::room2::brightness;
          return;

       }
         if (mobile_app::room2:: mode == 2 && mobile_app::room2::ldr == 1 && mobile_app::room2::ir == 0) {
                 if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
                     esp2 :: l3 =mobile_app::room2::brightness;
                     esp2 :: l4 =mobile_app::room2::brightness;
                     return;
              }else {
                     esp2:: l3 =0;
                     esp2:: l4 =0;
                  return;
              }

        }
        if (mobile_app::room2:: mode == 2 && mobile_app::room2::ldr == 0 && mobile_app::room2::ir == 1) {
            if (esp1 :: M4 == 1) {
               esp2:: l3 =mobile_app::room2::brightness;
                esp2:: l4 =mobile_app::room2::brightness;
                return;

            }
            if (esp1 :: M4 == 0) {
                esp2 :: l3 =0;
                esp2 :: l4 =0;
                return;
            }
        } if (mobile_app::room2:: mode ==2 && mobile_app::room2::ldr == 1 && mobile_app::room2::ir == 1) {
            if (esp1 :: M4 ==1 && (esp1 :: LDR0 ==1 || esp1 :: LDR1 ==1)) {
                esp2 :: l3 =mobile_app::room2::brightness;
                esp2 :: l4 =mobile_app::room2::brightness;
                return;
            }

        }else {
            esp2:: l3 =0;
            esp2:: l4 =0;
            return;
        }
    }
}
