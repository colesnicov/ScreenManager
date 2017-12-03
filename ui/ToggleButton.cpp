/*
 * ToggleButton.cpp
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#include "ToggleButton.h"

namespace ui {
void drawToggleButton(Adafruit_GFX* m_tft, int x, int y, int w, int h,
		bool value, uint16_t colorFrame, uint16_t colorBg, uint16_t colorFg,
		uint16_t colorOff, uint16_t colorOn) {

	m_tft->fillRect(x, y, w, h, colorBg);
	m_tft->drawRect(x, y, w, h, colorFrame);

	int y2 = y + 2;

	m_tft->setTextColor(colorFg);
	if (value) {
		m_tft->setCursor(x + (strlen("On") * 12 / 2) + 1, y2);
		m_tft->print("On");
	} else {
		m_tft->setCursor(x + (strlen("Off") * 12 / 2) + 1, y2);
		m_tft->print("Off");
	}
	m_tft->fillRect(w / 2, y + 1, (w / 2) - 1, h - 2,
			value ? colorOn : colorOff);
}
}
