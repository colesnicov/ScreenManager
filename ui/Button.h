/*
 * ToggleButton.h
 *
 *  Created on: 19. 10. 2017
 *      Author: denis
 */

#ifndef SCREENMANAGER_BUTTON_H_
#define SCREENMANAGER_BUTTON_H_

#include <Adafruit_GFX.h>

namespace ui {

void drawButton(Adafruit_GFX* m_tft, int x, int y, int w, int h,
		const char* label, uint16_t colorFrame, uint16_t colorBg,
		uint16_t colorFg);

}
#endif /* SCREENMANAGER_BUTTON_H_ */
