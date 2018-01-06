#pragma once

/**
 * File: Handler.hpp
 * Created on: 8. 10. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include "common.h"

/**
 * Bazova trida pro zpracovani udlosti. Musi se dedit!
 */
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

