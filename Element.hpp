#pragma once

/**
 * File: Element.hpp
 * Created on: 12. 9. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "common.h"

/**
 * Bazova trida pro ovladaci prvky
 */
class Element
{
public:
    Element() :
                m_width(0),
                m_height(0),
                m_pos_x(0),
                m_pos_y(0),
                m_invalid(true),
                m_lastState_active(false)
    {
    }

    virtual ~Element()
    {
    }

    /**
     * Vykresli prvek
     * Tato metoda musi se implementovat kazdym prvkem
     *
     * @param *tft Ukazatel na instanci displeje
     * @param current Priznak jestli je tento prvek "pod kurzorem"
     * @param action Aktulni akce tlacitek
     * @param colorBg Barva pozadi prvku
     * @param colorFr Barva ohraniceni prvku
     * @param colorFg Barva textu prvku
     * @param colorBg_a Barva pozadi prvku kdyz prvek ma zamereni (focus)
     * @param colorFr_a Barva ohraniceni prvku kdyz prvek ma zamereni (focus)
     * @param colorFg_a Barva textu prvku kdyz prvek ma zamereni (focus)
     * @param tpos_div Delic pro korekci vertikalni pozice textu, cim vetsi cislo tim vic nahore
     */
    virtual bool Draw(Adafruit_GFX *tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
            uint8_t tpos_div = 0)
    {
        return false;
    }

    /**
     * Nastavi velikost prvku
     *
     * @param w Sirka
     * @param h Vyska
     */
    inline void setSize(uint16_t w, uint16_t h)
    {
        m_width = w;
        m_height = h;
        setInvalid();
    }

    /**
     * Nastavi posici prvku
     *
     * @param x Horizontalni
     * @param y Vertikalni
     */
    inline void setPosition(int16_t x, int16_t y)
    {
        m_pos_x = x;
        m_pos_y = y;
        setInvalid();
    }

    /**
     * Je nastaven priznak na prekresleni prvku?
     */
    inline bool isInvalid()
    {
        return m_invalid;
    }

    /**
     * Nastavi priznak pro prekresleni prvku
     */
    inline void setValid()
    {
        m_invalid = false;
    }

    /**
     * Zrusi priznak pro prekresleni prvku
     */
    inline void setInvalid()
    {
        m_invalid = true;
    }

    /**
     * Nastavi priznak posledniho stavu
     */
    inline void setLastState(bool state)
    {
        m_lastState_active = state;
    }

    /**
     * Vrati TRUE pokud prvek naposledy byl "pod kurzorem", jinak FALSE
     */
    inline bool getLastState()
    {
        return m_lastState_active;
    }

protected:
    uint16_t m_width, m_height;
    int16_t m_pos_x, m_pos_y;

private:
    bool m_invalid;
    bool m_lastState_active;

};

