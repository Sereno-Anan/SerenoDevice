#include <M5StickC.h>

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.print("Hello World!");
}

void loop() {
  M5.update();
}