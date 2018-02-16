#include <ui/SpinnerInt.h>

namespace ui
{

    SpinnerInt::SpinnerInt() :
                m_value(0),
                m_changed(false)
    {

    }

    SpinnerInt::~SpinnerInt()
    {
    }

    bool SpinnerInt::Draw(Adafruit_GFX* tft, bool current, Action action,
            uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
            uint16_t colorBg_a, uint16_t colorFr_a, uint16_t colorFg_a,
            uint8_t tpos_div)
    {

        if (current && action == Action::ENTER)
        {
            setInvalid();
            setActive(!isActive());
        }
        else if ((getLastState() != current)
                && (action == Action::UP || action == Action::DOWN))
        {
            setInvalid();
        }

        if (current && isActive())
        {
            if (action == Action::RIGHT)
            {
                *m_value += 1;
                m_changed = true;
                setInvalid();
            }
            else if (action == Action::LEFT)
            {
                *m_value -= 1;
                m_changed = true;
                setInvalid();
            }
        }

        if (isInvalid())
        {

            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorBg_a : colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorFr_a : colorFr);
            tft->drawFastVLine(m_pos_x + m_height, m_pos_y + 1, m_height - 2,
                    (current) ? colorFr_a : colorFr);
            tft->drawFastVLine(m_pos_x + m_width - m_height, m_pos_y + 1,
                    m_height - 2, (current) ? colorFr_a : colorFr);

            tft->fillRect(m_pos_x + 3, (m_pos_y + (m_height / 2) - 1),
                    m_height - 6, 3, (isActive()) ? colorFr_a : colorFr);

            // +
            tft->fillRect(m_pos_x + m_width + 3 - m_height,
                    (m_pos_y + (m_height / 2) - 1), m_height - 6, 3,
                    (isActive()) ? colorFr_a : colorFr);
            tft->fillRect(m_pos_x + m_width - (m_height / 2) - 2, m_pos_y + 3,
                    3, m_height - 6, (isActive()) ? colorFr_a : colorFr);

            uint8_t val_len = intLength(*m_value) + 1;
            char val[val_len];
            snprintf(val, strlen(m_text) + val_len, m_text, *m_value);

            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds(val, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
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

            tft->setTextColor((isActive()) ? colorFg_a : colorFg);
            tft->setCursor((m_pos_x + (m_width / 2)) - (text_width / 2),
                    label_y);
            tft->print(val);

            setValid();
        }

        setLastState(current);
        return isActive();
    }

} /* namespace ui */

