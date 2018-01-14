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
#include <string.h>

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
         * @param tft       Ukazatel na instanci displeje
         * @param current   Indikator, zda prvek ma zamereni (focus)
         * @param action    Akce uzivatele
         * @param colorBg   Barva pozadi prvku
         * @param colorFr   Barva ohraniceni prvku
         * @param colorFg   Barva textu prvku
         * @param colorBg_a Barva pozadi prvku kdyz prvek ma zamereni (focus)
         * @param colorFr_a Barva ohraniceni prvku kdyz prvek ma zamereni (focus)
         * @param colorFg_a Barva textu prvku kdyz prvek ma zamereni (focus)
         * @param tpos_div  Odsazeni textu od okraju v pixelech
         *
         * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
         *
         * @todo Buffer overflow - Pri vypisu textu, saha mimo svuj pmetovy zasobnik a
         *       vypisuje hodnoty pameti z 'ciziho' sektoru
         * @todo Pri prvnim aktivovani prvku se text rozhodi!
         * @todo Scroller ma bud spatne rozmery nebo ma spatnou velikost kroku pri posuvu!
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
         * @note Vypocty provadi na zaklade rozmeru velkeho pismena 'W'!
         *
         * @param *tft      Ukazatel na objekt obrazovky
         * @param tpos_div  Odsazeni textu od okraju v px
         */
        void recalculate(Adafruit_GFX *tft, uint8_t tpos_div);

    private:

        int m_rowsCount;
        int *m_rowsLength;

        bool m_recalculate = true;
        uint16_t m_visibled_rows;

        uint16_t m_lineHeight;
        uint16_t m_start_row = 0;

    };

} /* namespace ui */

