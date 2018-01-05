/*
 * ScrollableText.h
 *
 *  Created on: 27. 12. 2017
 *      Author: denis
 */

#pragma once

#include <TextualElement.hpp>

#include "screen_config.h"

namespace ui
{

    /*
     *
     */
    class ScrollableText: public TextualElement
    {
    public:
        ScrollableText();

        ~ScrollableText();


        bool Draw(Adafruit_GFX* tft, bool current, Action action =
                Action::NONE);

        bool Draw(Adafruit_GFX *tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
                uint8_t tpos_div = 0);


        void drawBox(/*uint16_t textHeight*/);

    private:

        int m_rowsCount;
        int m_rowsLength[];
        uint16_t m_start_row;

        bool m_recalculate = true;
        uint16_t m_visibled_rows;

        uint8_t m_lineHeight;

    };

} /* namespace ui */

























