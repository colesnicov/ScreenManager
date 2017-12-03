/*
 * Screen.h
 *
 *  Created on: 12. 9. 2017
 *      Author: denis
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <Arduino.h>
#include "Adafruit_GFX.h"
//#include <SPI.h>
#include "common.h"

class Screen {
public:
	Screen();
	Screen(Adafruit_GFX* tft);
	virtual ~Screen();

	virtual void begin();

	virtual void update(Action action = Action::NONE);

	Adafruit_GFX* getTft();

	bool isInvalid();

	void setValid();

	void setInvalid();

private:

	Adafruit_GFX* m_tft;
	bool m_invalid;
};

#endif /* SCREEN_H_ */
