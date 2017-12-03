/*
 * ToggleButton.h
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#ifndef SCREENMANAGER_TOGGLEBUTTON_H_
#define SCREENMANAGER_TOGGLEBUTTON_H_

#include <Adafruit_GFX.h>

namespace ui {
void drawToggleButton(Adafruit_GFX* m_tft, int x, int y, int w, int h,
		bool value, uint16_t colorFrame, uint16_t colorBg, uint16_t colorFg,
		uint16_t colorOff, uint16_t colorOn);
}

#endif /* SCREENMANAGER_TOGGLEBUTTON_H_ */
