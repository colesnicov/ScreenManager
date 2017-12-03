/*
 * ScreenManager.hpp
 *
 *  Created on: 9. 9. 2017
 *      Author: Denis Colesnicov
 */

#ifndef SCREENMANAGER_HPP_
#define SCREENMANAGER_HPP_

#include <Adafruit_GFX.h>

#include "Handler.hpp"
#include "common.h"
#include "Screen.h"

class ScreenManager {
public:

	ScreenManager(Screen* t);

	void Begin();

	void Update();

	void setHandler(Handler*);

	Adafruit_GFX* getTft();

	Action getAction();

private:
	Adafruit_GFX* m_tft;
	Handler* m_handler;
	Screen* m_screen;
};

#endif /* SCREENMANAGER_HPP_ */
