#pragma once

/**
 * File: Button.hpp
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include <Element.hpp>

namespace ui
{

    /*
     * Tlacitko
     */
    class Button: public Element
    {
    public:
        Button();

        ~Button();

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
        bool Draw(Adafruit_GFX* tft, bool current, Action action, uint16_t colorBg, uint16_t colorFr,
                uint16_t colorFg, uint16_t colorBg_a, uint16_t colorFr_a,
                uint16_t colorFg_a,
                uint8_t tpos_div = 0);

        /**
         * Nastavi text
         */
        inline void setText(char* text)
        {
            m_text = text;
            setInvalid();
        }

    private:
        char* m_text;
    };

} /* namespace ui */

