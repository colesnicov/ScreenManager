/*
 * MyScreen.cpp
 *
 *  Created on: 30. 11. 2017
 *      Author: denis
 */

#include "Arduino.h"
#include "MyScreen.h"

MyScreen::MyScreen(Adafruit_GFX* tft) :
		Screen(tft), m_tft((Adafruit_ST7735*) tft){
}

void MyScreen::begin() {
	m_tft->initR(INITR_144GREENTAB);
	m_tft->fillScreen(ST7735_BLACK);
}

void MyScreen::update(Action action) {
	this->Home(action);
}

void MyScreen::Home(Action action) {

	if (isInvalid()) {
		m_tft->println("ScreenManager say:");
		m_tft->println("Hello world :-)");
		setValid();
	}

}

