#pragma once

/**
 * File: Label.hpp
 * Created on: 27. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.2
 */

#include <TextualElement.hpp>

namespace ui
{

    namespace Properties
    {

        enum TextAlignment
        {
            CENTER,
            LEFT,
            RIGHT
        };
    }

    /*
     * Tlacitko
     */
    class Label
    {
        public:
            Label() :
                        m_invalid(true),
                        m_text('\0'),
                        m_last_text('\0')
            {
            }

            ~Label();

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
             * Nastavi text
             *
             * @param char* Text pro prvek
             */
            void setText(char* text)
            {
                m_text = text;
            }

            /**
             * Vykresli prvek s textem zarovnanym doleva
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawLeft(Adafruit_GFX*, uint16_t, uint8_t = 0);

            /**
             * Vykresli prvek s textem zarovnanym doleva
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva pozadi prvku
             * @param uint16_t Barva ohraniceni prvku
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawLeft(Adafruit_GFX*, uint16_t, uint16_t, uint16_t, uint8_t =
                    0);

            /**
             * Vykresli prvek s textem zarovnanym doprava
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawRight(Adafruit_GFX*, uint16_t, uint8_t = 0);

            /**
             * Vykresli prvek s textem zarovnanym doprava
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva pozadi prvku
             * @param uint16_t Barva ohraniceni prvku
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawRight(Adafruit_GFX*, uint16_t, uint16_t, uint16_t,
                    uint8_t = 0);

            /**
             * Vykresli prvek s textem zarovnanym uprostred
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawCenter(Adafruit_GFX*, uint16_t, uint8_t);

            /**
             * Vykresli prvek s textem zarovnanym uprostred
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva pozadi prvku
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawCenter(Adafruit_GFX*, uint16_t, uint16_t, uint8_t);

            /**
             * Vykresli prvek s textem zarovnanym uprostred
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva pozadi prvku
             * @param uint16_t Barva ohraniceni prvku
             * @param uint16_t Barva textu prvku
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool DrawCenter(Adafruit_GFX*, uint16_t, uint16_t, uint16_t,
                    uint8_t);

            /**
             * Vykresli prvek
             *
             * @param Adafruit_GFX* Ukazatel na instanci displeje
             * @param uint16_t Barva pozadi prvku
             * @param uint16_t Barva ohraniceni prvku
             * @param uint16_t Barva textu prvku
             * @param Properties::TextAlignment Horizontalni zarovnni textu
             * @param uint8_t Delic pro vertikalni pozicovani textu. Cim vetsi cislo, tim vic nahore.
             *
             * @return bool TRUE pokud je prvek aktivni nebo zpracoval udalost, jinak False
             */
            bool Draw(Adafruit_GFX*, uint16_t, uint16_t, uint16_t,
                    Properties::TextAlignment, uint8_t);

        private:

            uint16_t m_width, m_height;
            int16_t m_pos_x, m_pos_y;

            bool m_invalid;
            char *m_text;
            char *m_last_text;
    };

} /* namespace ui */

