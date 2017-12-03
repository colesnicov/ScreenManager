/*
 * SliderI.h
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#ifndef SCREENMANAGER_SLIDERI_H_
#define SCREENMANAGER_SLIDERI_H_

#include <Adafruit_GFX.h>

namespace ui {
void drawSliderI(Adafruit_GFX* m_tft, int x, int y, int w, int h, int value,
		uint16_t colorFrame, uint16_t colorBg, uint16_t colorFg,
		uint16_t colorButton, uint16_t colorRect, int sizeOfVal = 3);
}
#endif /* SCREENMANAGER_SLIDERI_H_ */
