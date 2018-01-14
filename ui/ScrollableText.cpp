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
                m_rowsCount(0),
                m_visibled_rows(0),
                m_lineHeight(0)
    {
        m_rowsLength = new int();
    }

    ScrollableText::~ScrollableText()
    {
        delete m_rowsLength;
    }

    bool ScrollableText::Draw(Adafruit_GFX* tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
            uint8_t tpos_div)
    {
        recalculate(tft, tpos_div);

        if (current && action == Action::ENTER)
        {
            setInvalid();
            setActive(!isActive());
        }
        else if (isActive() && action == Action::DOWN
                && (m_rowsCount - m_start_row) >= m_start_row)
        {
            m_start_row++;
            setInvalid();
        }
        else if (isActive() && action == Action::UP && m_start_row > 0)
        {
            m_start_row--;
            setInvalid();
        }
        else if ((getLastState() || current)
                && (action == Action::UP || action == Action::DOWN))
        {
            setInvalid();
        }

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height,
                    (isActive()) ? colorBg : colorBg_a);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current || isActive()) ? colorFr_a : colorFr);

            uint16_t scrollHeight, scroll_row = 0;

            if (m_height - (tpos_div * 2) > (m_lineHeight * m_rowsCount))
            {
                scrollHeight = m_height;
            }
            else
            {
                scrollHeight = ((float) (m_height - 16)
                        / ((m_lineHeight) * m_rowsCount)) * 100;
                scroll_row = ((float) m_lineHeight / (m_height + 10)) * 100;

            }

            tft->fillRect(m_pos_x + m_width - 8,
                    m_pos_y + (m_start_row * scroll_row) + 1, 6, scrollHeight,
                    (isActive()) ? colorFr_a : colorFr);

            tft->setTextWrap(false);

            uint16_t visibled_rows =
                    ((m_height - (tpos_div * 2)) / m_lineHeight); //-1;

            uint16_t label_x = m_pos_x + tpos_div;
            uint16_t label_y = m_pos_y + tpos_div;

            tft->setTextColor((isActive()) ? colorFg_a : colorFg);

            uint16_t i = m_start_row;
            uint16_t steps;
            if (m_rowsCount - m_start_row > visibled_rows)
            {
                steps = visibled_rows;
            }
            else
            {
                steps = (m_rowsCount - m_start_row); // - visibled_rows;
            }
            uint16_t offset = 0;

            if (m_start_row > 0)
            {
                for (int i = 0; i < m_start_row; i++)
                {
                    offset += m_rowsLength[i];
                }
            }

            for (int factor = 0; factor < steps; i++, factor++)
            {
                tft->setCursor(label_x, label_y + (m_lineHeight * factor));

                char row[m_rowsLength[i] + 1];
                strlcpy(row, m_text + offset, m_rowsLength[i] + 1);
                offset += m_rowsLength[i];
                tft->print(row);
            }
            setValid();
        }
        setLastState(current);
        return isActive();
    }

    void ScrollableText::setText(char* text)
    {
        TextualElement::setText(text);
        m_recalculate = true;
    }

    void ScrollableText::recalculate(Adafruit_GFX *tft, uint8_t tpos_div)
    {
        if (m_recalculate)
        {
            uint16_t text_width;

            {
                int16_t tmp;
                tft->getTextBounds((char*) "W", m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &m_lineHeight);
                m_lineHeight += 2; // Pridame rozestup 2px mezi radkami
            }
            uint32_t text_length;
            uint16_t char_per_row;
            text_length = strlen(m_text);
            char_per_row = ((m_width - 12 - tpos_div) / text_width);
            uint32_t globalI = 0;
            while (text_length > globalI)
            {
                uint16_t i = globalI + char_per_row;
                if (i > text_length)
                {
                    i -= (i - text_length);
                }

                int ii = char_per_row + 1;
                int iii = 0;
                while (m_text[i - iii] != ' ' || iii <= 17)
                {
                    if (m_text[i - iii] == ' ' || i == text_length)
                    {
                        m_rowsLength[m_rowsCount] = ii;
                        break;
                    }
                    ii--;
                    iii++;
                }
                m_rowsCount++;
                globalI += ii;
            }
            m_recalculate = false;
        }
    }

} /* namespace ui */
