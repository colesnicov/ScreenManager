/*
 * Screen.cpp
 *
 *  Created on: 30. 11. 2017
 *      Author: denis
 */

#include "Screen.h"

Screen::Screen() :
		m_tft(nullptr), m_invalid(true) {
}

Screen::Screen(Adafruit_GFX* tft) :
		m_tft(tft), m_invalid(true) {
}

Screen::~Screen() {
}

void Screen::begin() {
}

<<<<<<< HEAD
void Screen::update(Action action) {
=======
void Screen::update(Action action = Action::NONE) {
>>>>>>> d6f1c54e5bed26b66678e168b3471d72d9412558
}

bool Screen::isInvalid() {
	return m_invalid;
}

void Screen::setValid() {
	m_invalid = false;
}

void Screen::setInvalid() {
	m_invalid = true;
}

Adafruit_GFX* Screen::getTft() {
	return m_tft;
}
