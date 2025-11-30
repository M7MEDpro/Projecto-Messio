#include "Display_manager.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace display {

  // Use the I2C version
  LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, 16x2 LCD

  const uint8_t ENTRY_COUNT = 15;

  const char* names[ENTRY_COUNT] = {
    "Khaled Karam",
    "Mohamed Badawy",
    "Omar Moustafa",
    "Abdelrhman Waled",
    "Mahmoud Gamal",
    "Mohammed Sayed",
    "Mariam Mohamed",
    "Yasmin Hassan",
    "Omar Ahmed",
    "Shahad Magdy",
    "Basmala",
    "Shahd Mohamed",
    "Salma Ahmed",
    "Zahra Mohammed",
    "Moaz bellah"
  };

  const char* ids[ENTRY_COUNT] = {
    "192400688",
    "192400676",
    "192400779",
    "192400701",
    "192400755",
    "192400665",
    "192400445",
    "192400160",
    "192400754",
    "192400722",
    "192400154",
    "192400464",
    "192500183",
    "192400847",
    "192400538"
  };

  uint8_t currentIndex = 0;
  unsigned long lastMillis = 0;
  const unsigned long intervalMs = 2000UL; // 2 sec per entry

  // Declare showCurrent first
  void showCurrent();

  void start() {
    Wire.begin(21, 22); // SDA=21, SCL=22 for ESP32
    lcd.init();
    lcd.backlight();
    lastMillis = millis();
    showCurrent();
  }

  // Define showCurrent
  void showCurrent() {
    lcd.clear(); // Clear before showing new content

    lcd.setCursor(0, 0);
    lcd.print(names[currentIndex]);

    lcd.setCursor(0, 1);
    lcd.print(ids[currentIndex]);
  }

  void update() {
    unsigned long now = millis();
    if (now - lastMillis >= intervalMs) {
      lastMillis = now;
      currentIndex = (currentIndex + 1) % ENTRY_COUNT;
      showCurrent();
    }
  }

} // namespace display