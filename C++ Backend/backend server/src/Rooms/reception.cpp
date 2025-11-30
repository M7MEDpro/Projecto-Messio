#include "reception.h"

#include "../dataModel.h"
#include "../utilities.h"

namespace reception {
    void updateLed() {
       if (mobile_app::reception::mode == 0) {
         esp1::r1 = 0;
         esp1::r2 = 0;
         esp1::r3 = 0;
         esp1::r4 = 0;
         return;
       }
      if (mobile_app::reception::mode == 1) {
        esp1::r1 =mobile_app::reception::brightness;
        esp1::r2 =mobile_app::reception::brightness;
        esp1::r3 =mobile_app::reception::brightness;
        esp1::r4 =mobile_app::reception::brightness;
        return;
      }
      if (mobile_app::reception::mode == 2 && mobile_app::reception::ldr == 1 && mobile_app::reception::ir == 0) {
        if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
          esp1::r1 =mobile_app::reception::brightness;
          esp1::r2 =mobile_app::reception::brightness;
          esp1::r3 =mobile_app::reception::brightness;
          esp1::r4 =mobile_app::reception::brightness;
          return;
        }else {
          esp1::r1 =0;
          esp1::r2 =0;
          esp1::r3 =0;
          esp1::r4 =0;
          return;
      }
      }
      if (mobile_app::reception::mode == 2 && mobile_app::reception::ldr == 0 && mobile_app::reception::ir == 1)
         if (esp1 :: M2 == 1 || esp1 :: M1 == 1) {
           esp1::r1 =mobile_app::reception::brightness;
           esp1::r2 =mobile_app::reception::brightness;
           esp1::r3 =mobile_app::reception::brightness;
           esp1::r4 =mobile_app::reception::brightness;
           return;
         }
      if (esp1 :: M2 == 0 && esp1 :: M1 == 0) {
           utilities::runLater([]() {
             esp1::r1 =0;
             esp1::r2 =0;
             esp1::r3 =0;
             esp1::r4 =0;
           },5000);
           return;
         }
      if (mobile_app::reception:: mode ==2 && mobile_app::reception::ldr == 1 && mobile_app::reception::ir == 1) {
        if ((esp1 :: M2 == 1 || esp1 :: M1 == 1) && (  esp1 :: LDR0 ==1 || esp1 :: LDR1 ==1)) {
          esp1::r1 =mobile_app::reception::brightness;
          esp1::r2 =mobile_app::reception::brightness;
          esp1::r3 =mobile_app::reception::brightness;
          esp1::r4 =mobile_app::reception::brightness;
          return;
        }else {
          utilities::runLater([]() {
            esp1::r1 =0;
            esp1::r2 =0;
            esp1::r3 =0;
            esp1::r4 =0;
          }, 5000);
          return;
        }
      }





}

}
