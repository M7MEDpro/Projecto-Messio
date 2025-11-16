#include <Arduino.h>

#include "Connections/wifi_Connection.h"
#include "LEDS/Outter_led_manager.h"
#include "LEDS/Room1_led_manager.h"
#include "LEDS/Room2_led_manager.h"
#include "Others/Display_manager.h"
#include "Readings/Flame_reading_manager.h"

void setup() {
    Serial.begin(115200);
    wifi::connectWiFi();
    flame::flame_init();
    OL :: OL_initial();
    room1 :: room1_init();
    room2 :: room2_init();
    display::start();

}

void loop() {
    flame :: F1_read();
    flame :: F2_read();
    flame :: F3_read();
    flame :: F4_read();
    flame :: F5_read();
    OL :: OL_write();
    room1 :: l1_write();
    room1 :: l2_write();
    room2 :: l1_write();
    room2 :: l2_write();
    display::update();
    delay(100);

}