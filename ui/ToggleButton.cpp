#include "ToggleButton.h"

namespace ui
{

    ToggleButton::ToggleButton() :
                Element(),
                m_isOn(false),
                m_text_on('\0'),
                m_text_off('\0')
    {
    }

    ToggleButton::~ToggleButton()
    {
    }

    bool ToggleButton::Draw(Adafruit_GFX* tft, bool current, Action action,
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
            m_isOn = !m_isOn;
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
                        (m_isOn) ? (char*) m_text_on : (char*) m_text_off,
                        m_pos_x, m_pos_y, &tmp, &tmp, &text_width,
                        &text_height);
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
            tft->fillRect(m_pos_x, m_pos_y + 1, tri_width, m_height - 2,
                    (current) ? colorBg_a : colorBg);

            // Indicator
            tft->fillRect(m_pos_x + tri_width + 2, m_pos_y + 1, m_width / 4,
                    m_height - 2, (m_isOn) ? 0x0400 : 0xF800);
            // Border
            tft->fillRect(m_pos_x + tri_width, m_pos_y + 1, 2, m_height - 2,
                    (current) ? colorFr_a : colorFr);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorFr_a : colorFr);

            // Text
            tft->setTextColor((current) ? colorFg_a : colorFg);
            tft->setCursor(m_pos_x + ((tri_width / 2) - (text_width / 2)),
                    label_y);
            if (m_isOn)
            {
                tft->print(m_text_on);
            }
            else
            {
                tft->print(m_text_off);
            }

            setValid();
        }
        setLastState(current);

        return handled;
        //return isActive();
    }

}
/* namespace ui */

