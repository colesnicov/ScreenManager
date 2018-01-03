#pragma once

/**
 * File: ToggleButton.hpp
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include <Element.hpp>
#include <Colors.h>

namespace ui
{

    /*
     * Prepinaci tlacitko
     */
    class ToggleButton: public Element
    {
    public:
        ToggleButton();

        ~ToggleButton();

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
         */
        bool Draw(Adafruit_GFX* tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
                uint8_t tpos_div = 0);

        /**
         * Je tlacitko sepnuto do stavu "ON"?
         *
         * @return bool TRUE pokud je, jinak FALSE
         */
        inline bool isOn()
        {
            return m_isOn;
        }

        /**
         * Nastavi tlacitko do stavu "ON" nebo "OFF"
         *
         * @param on Stav tlacitka. TRUE = "ON", FALSE = "OFF"
         */
        inline void setOn(bool on)
        {
            m_isOn = on;
        }

        /**
         * Nastavi popisek pro stav "ON"
         *
         * @param text Popisek pro stav "ON"
         */
        inline void setTextOn(const char *text)
        {
            m_text_on = text;
        }

        /**
         * Nastavi popisek pro stav "OFF"
         *
         * @param text Popisek pro stav "OFF"
         */
        inline void setTextOff(const char *text)
        {
            m_text_off = text;
        }

    private:
        bool m_isOn;
        const char *m_text_on;
        const char *m_text_off;
    };

} /* namespace ui */

