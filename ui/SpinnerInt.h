#pragma once

/*
 * File: Spinner.h
 * Created on: 3. 1. 2018
 * Author: Denis Colesnicov <eugustus@gmil.com>
 * Version: 1.2.1
 */

#include <TextualElement.hpp>

namespace ui
{

    /*
     * Inkrementlni/Dekrementalni spinner pro cele cislo
     *
     * @todo Implementovat maximalni a minimalni limit pro hodnotu
     */
    class SpinnerInt: public TextualElement
    {
    public:
        SpinnerInt();

        virtual ~SpinnerInt();

        /**
         * Vykresli prvek
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
         *
         * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
         */
        bool Draw(Adafruit_GFX *tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
                uint8_t tpos_div = 0);

        /**
         * Nastavi hodnotu referenci
         *
         * @param *value Ukazatel na hodnotu
         */
        void setValue(int *value)
        {
            m_value = value;
        }

        /**
         * Spocte pocet znaku v cisle. Znamenko "-" je take do poctu!
         *
         * @param x Cislo
         *
         * @return uint8_t Delka cisla
         */
        short intLength(int x)
        {
            if (x >= 1000)
            {
                return 4;
            }
            else if (x >= 100)
            {
                return 3;
            }
            else if (x >= 10)
            {
                return 2;
            }
            else if (x >= 0)
            {
                return 1;
            }
            else if (x <= -1000)
            {
                return 5;
            }
            else if (x <= -100)
            {
                return 4;
            }
            else if (x <= -10)
            {
                return 3;
            }
            else if (x < 0)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }

    private:
        int* m_value;
    };

} /* namespace ui */

