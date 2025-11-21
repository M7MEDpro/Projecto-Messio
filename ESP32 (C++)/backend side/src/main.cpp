#include "flameAlarm.h"
#include "httplib.h"
#include "server.h"
#include "Modes/bedTimeMode.h"
#include "Modes/EmergencyMode.h"
#include "Modes/homeAway.h"
#include "Rooms/garage.h"
#include "Rooms/outerLed.h"
#include "Rooms/reception.h"
#include "Rooms/room1.h"
#include "Rooms/room2.h"

void mainLoop() {
    while (true) {
    // LEDS
        room1::updateLed();
        room2::updateLed();
        reception::updateLed();
        outerLed::updateLed();
        garage::updateLed();
        homeAway::update();
        flameAlarm::update();
        EmergencyMode :: update();
        bedTimeMode::update();





        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}
int main()
{

    std::thread mainLoopThread(mainLoop);
    mainLoopThread.detach();

    server::startServer();
    return 0;
}
