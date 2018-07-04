#include "ImageButton.hpp"

namespace ui
{

    ImageButton::ImageButton() :
                TextualElement()
    {
    }

    ImageButton::~ImageButton()
    {

    }

    bool ImageButton::Draw(Adafruit_GFX* tft, bool current, Action action,
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

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorBg_a : colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height,
                    (current) ? colorFr_a : colorFr);

            tft->drawRGBBitmap(m_pos_x + ((m_width - m_image_width) / 2),
                    m_pos_y + 5, m_image, m_image_width, m_image_height);

            {
                uint16_t text_width, text_height;

                {
                    int16_t tmp;
                    tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp,
                            &tmp, &text_width, &text_height);
                }

                uint8_t box_width_half = m_width / 2;
                uint8_t text_width_half = text_width / 2;
                uint16_t label_x = m_pos_x;
                if (box_width_half > text_width_half)
                {
                    label_x = m_pos_x + (box_width_half - text_width_half);
                }

                uint8_t box_height_half = m_height / 2;
                uint8_t text_height_half = text_height / 2;
                uint16_t label_y = m_image_height;
                if (box_height_half > text_height_half)
                {
                    if (tpos_div > 0)
                    {
                        label_y += m_pos_y + box_height_half
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y += m_pos_y
                                + (box_height_half - text_height_half);
                    }
                }
                else
                {
                    label_y += m_pos_y + m_height - text_height_half;
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor((current) ? colorFg_a : colorFg);
                tft->print(m_text);
            }
            setValid();
        }
        setLastState(current);

        return isActive();
    }

} /* namespace ui */

