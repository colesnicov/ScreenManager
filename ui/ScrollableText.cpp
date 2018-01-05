/*
 * ScrollableText.cpp
 *
 *  Created on: 27. 12. 2017
 *      Author: denis
 */

#include "ScrollableText.h"

namespace ui
{

    ScrollableText::ScrollableText() :
                TextualElement(),
                //m_padding(5),
                m_rowsCount(0),
                m_start_row(0),
                m_visibled_rows(0),
                m_lineHeight(0)
    {
    }

    ScrollableText::~ScrollableText()
    {
        // TODO Auto-generated destructor stub
    }

    bool ScrollableText::Draw(Adafruit_GFX* tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
            uint8_t tpos_div)
    {

        int8_t padding = 5;
        uint16_t text_width, text_height;
        {
            int16_t tmp;
            tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                    &text_width, &text_height);
        }
        uint32_t text_length = strlen(m_text);
        uint16_t char_per_row = ((m_width - 12 - (padding * 3))
                / (text_width / text_length)) - 2;

        int rows = 1;
        if (text_length > char_per_row)
        {
            rows = text_length / char_per_row;
        }

        static uint16_t start_row = 0;
        if (current && action == Action::ENTER)
        {
            setInvalid();
            setActive(!isActive());
        }
        else if (isActive() && action == Action::DOWN
                && (rows - start_row) >= start_row)
        {
            start_row++;
            setInvalid();
        }
        else if (isActive() && action == Action::UP && start_row > 0)
        {
            start_row--;
            setInvalid();
        }
        else if ((getLastState() || current)
                && (action == Action::UP || action == Action::DOWN))
        {
            Serial.println("reload");
            setInvalid();
        }

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height,
                    (isActive()) ? colorBg : colorBg_a);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current || isActive()) ? colorFr_a : colorFr);

            uint16_t scrollHeight, scroll_row = 0;

            if (m_height - (padding * 2) > (text_height * rows))
            {
                scrollHeight = m_height;
            }
            else
            {
                scrollHeight = ((float) (m_height-16) / ((text_height + 2) * rows)) * 100;
                scroll_row = ((float) text_height / (m_height+10)) * 100;

            }

            tft->fillRect(m_pos_x + m_width - 8,
                    m_pos_y + (start_row * scroll_row) + 1, 6, scrollHeight,
                    (isActive()) ? colorFr_a : colorFr);

            tft->setTextWrap(false);

            text_height += 2;
            uint16_t visibled_rows = ((m_height - (padding * 2)) / text_height); //-1;

            int zustatek = text_length - (rows * char_per_row);

            unsigned int index = 0, tmp_index;
            if (zustatek > 0)
            {
                rows++;
                m_rowsLength[m_rowsCount] = zustatek;
            }
            char text_[rows][char_per_row + 1];
            uint16_t keys[rows];

            for (int i = 0; rows > i; i++)
            {
                tmp_index =
                        (i == rows) ? index + zustatek : index + char_per_row;
                while ((rows > i) && (m_text[tmp_index] != ' ' || tmp_index > 0))
                {

                    if (m_text[tmp_index] == ' ')
                    {
                        break;
                    }
                    tmp_index--;
                }

                int ii = 0;

                for (; index < tmp_index; index++)
                {
                    if (ii == 0 && m_text[index] == ' ')
                    {
                        continue;
                    }
                    text_[i][ii] = m_text[index];
                    ii++;
                }
                keys[i] = ii;
            }

            uint16_t label_x;
            uint16_t label_y;

            label_y = m_pos_y + text_height;
            label_x = m_pos_x + padding;

            tft->setTextColor(colorFg);

            uint16_t i = start_row;
            uint16_t steps;
            if (rows - start_row > visibled_rows)
            {
                steps = visibled_rows;
            }
            else
            {
                steps = (rows - start_row); // - visibled_rows;
            }

            for (int factor = 0; factor < steps; i++, factor++)
            {
                Serial.print("i: ");
                Serial.println(i);
                tft->setCursor(label_x, label_y + (text_height * factor));
                for (int k = 0; k < keys[i]; k++)
                {
                    tft->print(text_[i][k]);
                }
            }
            setValid();
        }
        setLastState(current);
        return isActive();
    }

} /* namespace ui */
