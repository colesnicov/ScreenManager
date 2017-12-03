/*
 * Handler.hpp
 *
 *  Created on: 8. 10. 2017
 *      Author: denis
 */

#ifndef HANDLER_HPP_
#define HANDLER_HPP_

#include "common.h"

class Handler {
public:

	/**
	 * Resetuje posledni akci
	 */
	virtual void reset();

	/**
	 * Overi zda doslo ke zmene stavu tlacitek
	 */
	virtual void update();

	/**
	 * Vrati ID akce ktera byla provedena
	 * @return Action
	 */
	virtual Action getAction();

	/**
	 * Inicializace
	 */
	virtual void begin();
};

#endif /* HANDLER_HPP_ */
