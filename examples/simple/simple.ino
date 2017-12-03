#include "Arduino.h"

#include "ScreenManager.hpp"
#include "MyScreen.h"
#include "Adafruit_ST7735.h"

Adafruit_ST7735 tft(10, 8, 9);

MyScreen screen(&tft);
ScreenManager screenManager(&screen);

void setup() {
	screenManager.Begin();
}

// The loop function is called in an endless loop
void loop() {
	screenManager.Update();
}
