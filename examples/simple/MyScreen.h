/*
 * MyScreen.h
 *
 *  Created on: 30. 11. 2017
 *      Author: Denis Colesnicov
 */

#ifndef MYSCREEN_H_
#define MYSCREEN_H_

#include <Screen.h>
#include <Adafruit_ST7735.h>

/*
 *
 */
class MyScreen: public Screen {
public:
	MyScreen();

	MyScreen(Adafruit_GFX* tft);

	void begin();

	void update(Action action = Action::NONE);

	void Home(Action action);

private:
	Adafruit_ST7735* m_tft;
};

#endif /* MYSCREEN_H_ */
