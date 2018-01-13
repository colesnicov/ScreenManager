/*
 * File: ScrollableText.h
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
 *
 * @note BETA verion, less tested!
 */

#pragma once

#include <TextualElement.hpp>

#define PADDING 5

namespace ui
{

    /*
     * Prvek ktery umoznuje skrolovat text v nem.
     * @note BETA
     */
    class ScrollableText: public TextualElement
    {
    public:
        ScrollableText();

        ~ScrollableText();
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
         *
         * @todo Buffer overflow - Pri vypisu textu, saha mimo svuj pmetovy zasobnik a
         *       vypisuje hodnoty pameti z 'ciziho' sektoru
         * @todo Pri prvnim aktivovani prvku se text rozhodi!
         */
        bool Draw(Adafruit_GFX *tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
                uint8_t tpos_div = 0);

        /**
         * Nastavi text
         *
         * @param text Text pro prvek
         */
        void setText(char* text);

        /**
         * Prepocita pocet radku a optimalni pocet znaku na radek
         *
         * @param char_width Sirka znaku
         */
        void recalculate(uint16_t char_width);

    private:

        int m_rowsCount;
        int *m_rowsLength;

        bool m_recalculate = true;
        uint16_t m_visibled_rows;

        uint8_t m_lineHeight;
        uint16_t m_start_row = 0;

    };

} /* namespace ui */

