#pragma once

/**
 * File: Element.hpp
 * Created on: 12. 9. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
 */

#include "Adafruit_GFX.h"
#include "common.h"

/**
 * Bazova trida pro vsechny ovladaci prvky
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
                m_lastState_active(false),
                m_active(false)
    {
    }

    virtual ~Element()
    {
    }

    /**
     * Vykresli prvek
     * Tato metoda musi se implementovat kazdym prvkem
     *
     * @param Adafruit_GFX* Ukazatel na instanci displeje
     * @param bool Priznak jestli je tento prvek "pod kurzorem"
     * @param Action Aktulni akce tlacitek
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint8_t Delic pro korekci pozice
     *
     * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
     */
    virtual bool Draw(Adafruit_GFX*, bool, Action, uint16_t, uint16_t, uint16_t,
            uint16_t, uint16_t, uint16_t, uint8_t)
    {
        return false;
    }
    ;

    /**
     * Vykresli prvek
     * Tato metoda musi se implementovat kazdym prvkem
     *
     * @param Adafruit_GFX* Ukazatel na instanci displeje
     * @param bool Priznak jestli je tento prvek "pod kurzorem"
     * @param Action Aktulni akce tlacitek
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint8_t Delic pro korekci pozice
     *
     * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
     */
    virtual bool Draw(Adafruit_GFX*, bool, Action, uint16_t, uint16_t, uint16_t,
            uint8_t)
    {
        return false;
    }
    ;

    /**
     * Vykresli prvek
     * Tato metoda musi se implementovat kazdym prvkem
     *
     * @param Adafruit_GFX* Ukazatel na instanci displeje
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint16_t Barva
     * @param uint8_t Delic pro korekci pozice
     *
     * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
     */
    virtual bool Draw(Adafruit_GFX*, uint16_t, uint16_t, uint16_t, uint8_t)
    {
        return false;
    }
    ;

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
     * Nastavi pozici prvku
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

    /**
     * Je prvek aktivni? Pouze jeden prvek by mel byt aktivni!
     *
     * @return bool TRUE pokud je prvek aktivni, jinak false
     */
    inline bool isActive()
    {
        return m_active;
    }

    /**
     * Natavi aktivnost prvku. Pouze jeden prvek na stranci mel byt aktivni!
     *
     * @param active Sav prvku
     */
    inline void setActive(bool active)
    {
        m_active = active;
    }

protected:
    uint16_t m_width, m_height;
    int16_t m_pos_x, m_pos_y;

private:
    bool m_invalid;
    bool m_lastState_active;
    bool m_active;

};

