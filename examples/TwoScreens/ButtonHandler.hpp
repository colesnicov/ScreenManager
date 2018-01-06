#pragma once

/*
 * File: ButtonHandler.h
 * Created on: 8. 10. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 */

#include <Handler.hpp>
#include <Button.h>

class ButtonHandler: public Handler {
public:
	ButtonHandler();

	/**
	 * Resetuje posledni akci
	 */
	void reset();

	/**
	 * Overi zda doslo ke zmene stavu tlacitek
	 */
	void update();

	/**
	 * Vrati ktera akce byla provedena
	 * @return Action
	 */
	Action getAction();

	void begin();

private:
	Action m_action;
	Button m_backButton;
	Button m_downButton;
	Button m_leftButton;
	Button m_okButton;
	Button m_rightButton;
	Button m_upButton;
};

#endif /* BUTTONHANDLER_H_ */
