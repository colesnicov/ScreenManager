/*
 * ToggleButton.cpp
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#include "Button.h"

namespace ui{

void drawButton(Adafruit_GFX* m_tft, int x, int y, int w, int h,
		const char* label, uint16_t colorFrame, uint16_t colorBg,
		uint16_t colorFg) {

	m_tft->fillRect(x, y, w, h, colorBg);
	m_tft->drawRect(x, y, w, h, colorFrame);

	int y2 = y + 2;
	m_tft->setCursor((w / 2) - (strlen(label) * 12 / 2) + 1, y2);
	m_tft->setTextColor(colorFg);
	m_tft->print(label);
}

}
