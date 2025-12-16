#include "outerLed.h"

#include "dataModel.h"

namespace outerLed {

    void updateLed() {
        if (mobile_app::outerLed::mode == 0) {
            esp2::OL = 0;
            return;
        }
        if (mobile_app::outerLed::mode == 1) {
            esp2::OL = mobile_app::outerLed::brightness;
            return;
        }
        if (mobile_app ::outerLed::mode == 2 ) {
            if (esp1::LDR0 ==1 || esp1::LDR1 ==1) {
                esp2::OL = 1;
                return;
            }else {
                esp2::OL = 0;
                return;
            }
        }

    }

}
