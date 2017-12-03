/*
 * SliderI.cpp
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#include "SliderI.h"

namespace ui {
void drawSliderI(Adafruit_GFX* m_tft, int x, int y, int w, int h, int value,
		uint16_t colorFrame, uint16_t colorBg, uint16_t colorFg,
		uint16_t colorButton, uint16_t colorRect, int sizeOfVal) {

	m_tft->setTextColor(colorFg);

	m_tft->fillRect(x, y, w, h, colorBg);
	m_tft->fillRect(x + 1, y + 1, 23, h - 2, colorButton);
	m_tft->fillRect(w - 23 - 1, y + 1, 23, h - 2, colorButton);
	m_tft->fillRect(x + 24, y + 1, w - 48, h - 2, colorRect);

	m_tft->drawRect(x, y, w, h, colorFrame);

	int y2 = y + 2;
	m_tft->setCursor((x + (23 / 2)) - (12 / 2) + 1, y2);
	m_tft->print("-");
	char val[sizeOfVal + 1];
	snprintf(val, sizeOfVal + 1, "%d", value);
	m_tft->setCursor((x + (w / 2)) - (strlen(val) * 12 / 2), y2);
	m_tft->print(val);

	m_tft->setCursor(((x + w - 23)) + (12 / 2) + 2, y2);
	m_tft->print("+");

}
}
