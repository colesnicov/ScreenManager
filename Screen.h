/*
 * Screen.h
 *
 *  Created on: 12. 9. 2017
 *  Author: denis
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "common.h"

#ifdef OPERATOR_DELETE
#ifndef OPERATOR_DELETE_DEFINED
#define OPERATOR_DELETE_DEFINED

void operator delete(void * p) {
	free(p);
}

#endif
#endif

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

	bool m_invalid;
	Adafruit_GFX* m_tft;
};

#endif /* SCREEN_H_ */
