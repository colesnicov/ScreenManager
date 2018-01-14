#include "Arduino.h"

#include <Adafruit_ILI9341.h>

#include "ButtonHandler.hpp"
#include "HomeScreen.hpp"


#define TFT_CS 24
#define TFT_DC 26


Adafruit_ILI9341 tft(TFT_CS, TFT_DC);

ButtonHandler handler;

HomeScreen myScreen(&tft);

void setup() {
    Serial.begin(115200);

    tft.begin();

	myScreen.begin();
	handler.begin();
    handler.reset();
}


void loop() {
    handler.update();
    myScreen.update(handler.getAction());
}





























































