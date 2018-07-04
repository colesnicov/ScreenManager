#pragma once

/**
 * File: ImageButton.hpp
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
 */

#include <TextualElement.hpp>

namespace ui
{

    /*
     * Tlacitko
     */
    class ImageButton: public TextualElement
    {
    public:
        ImageButton();

        ~ImageButton();

        /**
         * Vykresli prvek
         *
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

        void setImage(const uint16_t* image, uint8_t width, uint8_t height)
        {
            m_image = image;
            m_image_width = width;
            m_image_height = height;
        }

    private:
        uint8_t m_image_width;
        uint8_t m_image_height;
        const uint16_t* m_image;
    };

} /* namespace ui */

