#include "ToggleButton3.h"

namespace ui
{

    ToggleButton3::ToggleButton3() :
                Element(),
                m_state(0),
                m_text_one('\0'),
                m_text_two('\0'),
                m_text_three('\0')
    {
    }

    ToggleButton3::~ToggleButton3()
    {
    }

    bool ToggleButton3::Draw(Adafruit_GFX* tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
            uint8_t tpos_div)
    {

        bool handled = false;
        if (current && action == Action::ENTER)
        {
            setInvalid();
            setActive(true);
            handled = true;
            if (m_state == 2)
            {
                m_state = 0;
            }
            else
            {
                m_state++;
            }
        }
        else if ((getLastState() || current)
                && (action == Action::UP || action == Action::DOWN))
        {
            setInvalid();
        }

        if (isInvalid())
        {
            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds(
                        (m_state == 0) ?
                                (char*) m_text_one :
                                ((m_state == 1) ?
                                        (char*) m_text_two :
                                        (char*) m_text_three), m_pos_x, m_pos_y,
                        &tmp, &tmp, &text_width, &text_height);
            }

            uint8_t box_height_half = m_height / 2;
            uint8_t text_height_half = text_height / 2;
            uint16_t label_y;
            if (box_height_half > text_height_half)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + box_height_half
                            + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + (box_height_half - text_height_half);
                }
            }
            else
            {
                label_y = m_pos_y + m_height - text_height_half;
            }

            uint16_t tri_width = (m_width / 4) * 3;

            // Label
            tft->fillRect(m_pos_x, m_pos_y + 1, m_width, m_height - 2,
                    (current) ? colorBg_a : colorBg);

            // Indicator
            //tft->fillRect(m_pos_x + tri_width + 2, m_pos_y + 1, (m_width / 4) - 2, m_height - 2, (m_state) ? 0x0400 : 0xF800);
//            tft->drawFastVLine(m_pos_x+tri_width+2, m_pos_y+1, m_height-2, (m_state) ? colorFr_a:colorFr);
            tft->fillTriangle(m_pos_x + m_width - 12,
                    m_pos_y + (m_height / 2) - 4, m_pos_x + m_width - 8,
                    m_pos_y + (m_height / 2) + 4, m_pos_x + m_width - 4,
                    m_pos_y + (m_height / 2) - 4,
                    (current) ? colorFr_a : colorFr);

            // Border
            tft->fillRect(m_pos_x + m_width - 16, m_pos_y + 1, 2, m_height - 2,
                    (current) ? colorFr_a : colorFr);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorFr_a : colorFr);

            // Text
            tft->setTextColor((current) ? colorFg_a : colorFg);
            tft->setCursor(m_pos_x + (((m_width - 16) / 2) - (text_width / 2)),
                    label_y);
            if (m_state == 0)
            {
                tft->print(m_text_one);
            }
            else if (m_state == 1)
            {
                tft->print(m_text_two);
            }
            else
            {
                tft->print(m_text_three);
            }

            setValid();
        }
        setLastState(current);

        return handled;
        //return isActive();
    }

    bool ToggleButton3::Draw(Adafruit_GFX* tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint8_t tpos_div)
    {

        bool handled = false;
        if (current && action == Action::ENTER)
        {
            if (m_state == 2)
            {
                m_state = 0;
            }
            else
            {
                m_state++;
            }
            setInvalid();
            setActive(true);
            handled = true;
        }

        if (isInvalid())
        {
            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds(
                        (m_state == 0) ?
                                (char*) m_text_one :
                                ((m_state == 1) ?
                                        (char*) m_text_two :
                                        (char*) m_text_three), m_pos_x, m_pos_y,
                        &tmp, &tmp, &text_width, &text_height);
            }

            uint8_t box_height_half = m_height / 2;
            uint8_t text_height_half = text_height / 2;
            uint16_t label_y;
            if (box_height_half > text_height_half)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + box_height_half
                            + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + (box_height_half - text_height_half);
                }
            }
            else
            {
                label_y = m_pos_y + m_height - text_height_half;
            }

            uint16_t tri_width = (m_width / 4) * 3;

            // Label
            tft->fillRect(m_pos_x, m_pos_y + 1, m_width, m_height - 2, colorBg);

            // Indicator
            tft->fillTriangle(m_pos_x + m_width - 12,
                    m_pos_y + (m_height / 2) - 4, m_pos_x + m_width - 8,
                    m_pos_y + (m_height / 2) + 4, m_pos_x + m_width - 4,
                    m_pos_y + (m_height / 2) - 4, colorFr);

            // Border
            tft->fillRect(m_pos_x + m_width - 16, m_pos_y + 1, 2, m_height - 2,
                    colorFr);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height, colorFr);

            // Text
            tft->setTextColor(colorFg);
            tft->setCursor(m_pos_x + (((m_width - 16) / 2) - (text_width / 2)),
                    label_y);
            if (m_state == 0)
            {
                tft->print(m_text_one);
            }
            else if (m_state == 1)
            {
                tft->print(m_text_two);
            }
            else
            {
                tft->print(m_text_three);
            }

            setValid();
        }
        setLastState(current);

        return handled;
        //return isActive();
    }

}
/* namespace ui */

