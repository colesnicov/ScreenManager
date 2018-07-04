#pragma once

/**
 * File: ToggleButton3.hpp
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
 */

#include <Element.hpp>
#include <Colors.h>

namespace ui
{

    /*
     * Prepinaci tlacitko "ON|OFF"
     */
    class ToggleButton3: public Element
    {
    public:
        ToggleButton3();

        ~ToggleButton3();

        /**
         * @param tft Ukazatel na instanci displeje
         * @param current Indikator, zda prvek ma zamereni (focus)
         * @param action Akce uzivatele
         * @param colorBg Barva pozadi prvku
         * @param colorFr Barva ohraniceni prvku
         * @param colorFg Barva textu prvku
         * @param colorBg_a Barva pozadi prvku kdyz prvek ma zamereni (focus)
         * @param colorFr_a Barva ohraniceni prvku kdyz prvek ma zamereni (focus)
         * @param colorFg_a Barva textu prvku kdyz prvek ma zamereni (focus)
         * @param tpos_div Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
         *
         * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
         */
        bool Draw(Adafruit_GFX* tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
                uint8_t tpos_div = 0);

        bool Draw(Adafruit_GFX* tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint8_t tpos_div = 0);

        /**
         * Je tlacitko sepnuto do stavu "ON"?
         *
         * @return bool TRUE pokud je, jinak FALSE
         */
        inline bool isState(uint8_t state)
        {
            return m_state == state;
        }

        inline int getState()
        {
            return m_state;
        }

        /**
         * Nastavi tlacitko do stavu "ON" nebo "OFF"
         *
         * @note zpusobi invalidaci prvku?
         *
         * @param on Stav tlacitka. TRUE = "ON", FALSE = "OFF"
         */
        inline void setState(uint8_t state)
        {
            m_state = state;
            //setInvalid();
        }

        /**
         * Nastavi popisek pro stav "ON"
         *
         * @note zpusobi invalidaci prvku?
         *
         * @param text Popisek pro stav "ON"
         */
        inline void setTextOne(const char *text)
        {
            m_text_one = text;
            //setInvalid();
        }

        /**
         * Nastavi popisek pro stav "OFF"
         *
         * @note zpusobi invalidaci prvku?
         *
         * @param text Popisek pro stav "OFF"
         */
        inline void setTextTwo(const char *text)
        {
            m_text_two = text;
            //setInvalid();
        }

        /**
         * Nastavi popisek pro stav "OFF"
         *
         * @note zpusobi invalidaci prvku?
         *
         * @param text Popisek pro stav "OFF"
         */
        inline void setTextThree(const char *text)
        {
            m_text_three = text;
            //setInvalid();
        }

    private:
        uint8_t m_state;
        const char *m_text_one;
        const char *m_text_two;
        const char *m_text_three;
    };

} /* namespace ui */

