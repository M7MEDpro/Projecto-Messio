#include "bedTimeMode.h"

#include "dataModel.h"

namespace bedTimeMode {
    void update() {
      if (mobile_app::bedTimeMode==1) {
          turnOffLEDS();
      }

    }


    void turnOffLEDS(){

        esp1::g1 = 0;
        esp1::r1 = 0;
        esp1::r2 = 0;
        esp1::r3 = 0;
        esp1::r4 = 0;
        esp2::OL = 0;
        esp2::l1 = 0;
        esp2::l2 = 0;
        esp2::l3 = 0;
        esp2::l4 = 0;
    }
}

