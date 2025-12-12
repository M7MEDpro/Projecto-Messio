#include "flameAlarm.h"
#include "httplib.h"
#include "server.h"
#include "alarmManager.h"
#include "bedTimeMode.h"
#include "EmergencyMode.h"
#include "homeAway.h"
#include "garage.h"
#include "outerLed.h"
#include "reception.h"
#include "room1.h"
#include "room2.h"
#include "serverConfig.h"

void mainLoop() {
    while (true) {
        room1::updateLed();
        room2::updateLed();
        reception::updateLed();
        outerLed::updateLed();
        garage::updateLed();
        homeAway::update();
        flameAlarm::update();
        EmergencyMode :: update();
        bedTimeMode::update();
        alarmmanager :: update();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}
int main()
{
    config::loadConfig();

    std::thread mainLoopThread(mainLoop);
    mainLoopThread.detach();

    server::startServer();
    return 0;
}
