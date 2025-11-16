#include <Arduino.h>

#include "Connection/wifi_Connection.h"
#include "LEDS/Garage_led_manager.h"
#include "LEDS/Reception_led_manager.h"
#include "Others/Buzzer_manager.h"
#include "Others/Servo_manager.h"
#include "Readings/IR_reading_manager.h"
#include "Readings/LDR_reading_manager.h"

void setup() {

    Serial.begin(115200);
    wifi :: connectWiFi();
    buzzer :: Buzzer_init();
    servo :: init();
    LDR :: LDR_init();
    IR ::IR_init();
    gled :: init();
    rled :: init();
}

void loop() {
    LDR :: LDR0_read();
    LDR :: LDR1_read();
    IR :: M0_read();
    IR :: M1_read();
    IR :: M2_read();
    IR :: M3_read();
    IR :: M4_read();
    gled :: g1_write();
    rled :: r1_write();
    buzzer::BuzzUpdate();
    servo::Update();
    delay(100);
}