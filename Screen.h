#pragma once

/**
 * File: Screen.h
 * Created on: 12. 9. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "common.h"

/**
 * Bazova trida pro obrazovky
 */
class Screen
{
public:

    Screen()
    {
    }

    /**
     * @param tft Ukazatel na instanci displeje
     */
    Screen(Adafruit_GFX* tft) :
                m_tft(tft),
                m_invalid(true)
    {
    }

    virtual ~Screen()
    {
    }

    /**
     * Pripravna metoda
     */
    virtual void begin()
    {
    }

    /**
     * Vykresli obrazovku
     * Tato metoda musi se implementovat kazdou obrazovkou
     *
     * @param action Akce tlacitek
     */
    virtual void update(Action action = Action::NONE)
    {
    }

    /**
     * Vrati ukazatel na instanci displeje
     *
     * @return Adafruit_GFX*
     */
    Adafruit_GFX* getTft()
    {
        return m_tft;
    }

    /**
     * Je nastaven priznak pro prekresleni obrzovky?
     */
    bool isInvalid()
    {
        return m_invalid;
    }

    /**
     * Nastavi priznak pro prekresleni obrazovky
     */
    void setValid()
    {
        m_invalid = false;
    }

    /**
     * Zrusi priznak pro prekresleni obrazovky
     */
    void setInvalid()
    {
        m_invalid = true;
    }

private:

    bool m_invalid;
    Adafruit_GFX* m_tft;
};

