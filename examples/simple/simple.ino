#include "Arduino.h"

#include "MyScreen.h"
#include "Adafruit_ST7735.h"

Adafruit_ST7735 tft(10, 8, 9);

MyScreen screen(&tft);

void setup() {
	screen.Begin();
}

// The loop function is called in an endless loop
void loop() {
	screen.update(Action::NONE);
}
