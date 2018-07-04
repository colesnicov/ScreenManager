#include <ui/Label.hpp>

namespace ui
{

    Label::~Label()
    {

    }

    bool Label::DrawLeft(Adafruit_GFX* tft, uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
            }

            uint16_t label_y;
            if (m_height > text_height)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
                }
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            tft->setCursor(m_pos_x, label_y);
            tft->setTextColor(colorFg);
            tft->print(m_text);
            setValid();
        }

        return false;
    }

    bool Label::DrawLeft(Adafruit_GFX* tft, uint16_t colorBg, uint16_t colorFr,
            uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height, colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height, colorFr);

            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
            }

            uint16_t label_y;
            if (m_height > text_height)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
                }
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            tft->setCursor(m_pos_x, label_y);
            tft->setTextColor(colorFg);
            tft->print(m_text);
            setValid();
        }

        return false;
    }

    bool Label::DrawRight(Adafruit_GFX* tft, uint16_t colorBg, uint16_t colorFr,
            uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height, colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height, colorFr);

            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
            }

            uint16_t label_y;
            if (m_height > text_height)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
                }
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            if (tpos_div > 0)
            {
                label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
            }
            else if (m_height > text_height)
            {
                label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            tft->setCursor((m_pos_x + m_width) - text_width, label_y);
            tft->setTextColor(colorFg);
            tft->print(m_text);
            setValid();
        }

        return false;
    }

    bool Label::DrawRight(Adafruit_GFX* tft, uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
            }

            uint16_t label_y;
            if (m_height > text_height)
            {
                if (tpos_div > 0)
                {
                    label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
                }
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            if (tpos_div > 0)
            {
                label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
            }
            else if (m_height > text_height)
            {
                label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            tft->setCursor((m_pos_x + m_width) - text_width, label_y);
            tft->setTextColor(colorFg);
            tft->print(m_text);
            setValid();
        }

        return false;
    }

    bool Label::DrawCenter(Adafruit_GFX* tft, uint16_t colorBg,
            uint16_t colorFr, uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height, colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height, colorFr);

        }

        if (m_last_text != m_text)
        {

            {
                uint16_t label_x;
                uint16_t text_width, text_height;
                {

                    {
                        int16_t tmp;
                        tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y,
                                &tmp, &tmp, &text_width, &text_height);
                    }

                    label_x = m_pos_x + ((m_width / 2) - (text_width / 2));
                }

                uint16_t label_y;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorBg);
                tft->print(m_text);
            }
            {

                uint16_t text_width, text_height;

                {
                    int16_t tmp;
                    tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp,
                            &tmp, &text_width, &text_height);
                }

                uint16_t label_x = m_pos_x + ((m_width / 2) - (text_width / 2));

                uint16_t label_y;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorFg);
                tft->print(m_text);
            }
            m_last_text = m_text;
        }

        return false;
    }

    bool Label::DrawCenter(Adafruit_GFX* tft, uint16_t colorBg,
            uint16_t colorFg, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height, colorBg);
            setValid();
        }

        size_t _tl = sizeof(m_text);
        size_t _ltl = sizeof(m_last_text);

        if (strncasecmp(m_last_text, m_text, (_tl > _ltl) ? _ltl : _tl))
        {

            {
                uint16_t label_x;
                uint16_t text_width, text_height;
                {

                    {
                        int16_t tmp;
                        tft->getTextBounds((char*) m_last_text, m_pos_x,
                                m_pos_y, &tmp, &tmp, &text_width, &text_height);
                    }

                    label_x = m_pos_x + ((m_width / 2) - (text_width / 2));
                }

                uint16_t label_y;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorBg);
                tft->print(m_last_text);
            }
            {

                uint16_t text_width, text_height;

                {
                    int16_t tmp;
                    tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp,
                            &tmp, &text_width, &text_height);
                }

                uint16_t label_x = m_pos_x + ((m_width / 2) - (text_width / 2));

                uint16_t label_y;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorFg);
                tft->print(m_text);
            }

            //m_last_text = m_text;

            strlcpy(m_last_text, m_text, (_tl > _ltl) ? _ltl : _tl);
        }

        return false;
    }

    bool Label::DrawCenter(Adafruit_GFX* tft, uint16_t colorFg,
            uint8_t tpos_div)
    {

        if (isInvalid())
        {

            uint16_t text_width, text_height;

            {
                int16_t tmp;
                tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp, &tmp,
                        &text_width, &text_height);
            }

            uint16_t label_y;
            if (tpos_div > 0)
            {
                label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
            }
            else if (m_height > text_height)
            {
                if (tpos_div > 0)
                {
                    //label_y = m_pos_y + (m_height / 2) + text_height / tpos_div;
                }
                else
                {
                    label_y = m_pos_y + ((m_height / 2) - (text_height / 2));
                }
            }
            else
            {
                label_y = m_pos_y + m_height - (text_height / 2);
            }

            tft->setCursor(m_pos_x + ((m_width / 2) - (text_width / 2)),
                    label_y);
            tft->setTextColor(colorFg);
            tft->print(m_text);
            setValid();
        }

        return false;
    }

    bool Label::Draw(Adafruit_GFX* tft, uint16_t colorBg, uint16_t colorFr,
            uint16_t colorFg, Properties::TextAlignment align, uint8_t tpos_div)
    {

        if (isInvalid())
        {
            tft->fillRect(m_pos_x, m_pos_y, m_width, m_height, colorBg);
            tft->drawRect(m_pos_x, m_pos_y, m_width, m_height, colorFr);

            setValid();
        }

        if (m_last_text != m_text)
        {
            {

                uint16_t text_width, text_height;

                {
                    int16_t tmp;
                    tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp,
                            &tmp, &text_width, &text_height);
                }

                uint16_t label_x = 0;
                switch (align)
                {
                    case Properties::TextAlignment::CENTER:
                        label_x = m_pos_x + ((m_width / 2) - (text_width / 2));
                    break;

                    case Properties::TextAlignment::RIGHT:
                        label_x = (m_pos_x + m_width) - text_width;
                    break;

                    case Properties::TextAlignment::LEFT:
                        label_x = m_pos_x;
                    break;
                }

                uint16_t label_y = 0;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorBg);
                tft->print(m_text);
            }
            {

                uint16_t text_width, text_height;

                {
                    int16_t tmp;
                    tft->getTextBounds((char*) m_text, m_pos_x, m_pos_y, &tmp,
                            &tmp, &text_width, &text_height);
                }

                uint16_t label_x = 0;
                switch (align)
                {
                    case Properties::TextAlignment::CENTER:
                        label_x = m_pos_x + ((m_width / 2) - (text_width / 2));
                    break;

                    case Properties::TextAlignment::RIGHT:
                        label_x = (m_pos_x + m_width) - text_width;
                    break;

                    case Properties::TextAlignment::LEFT:
                        label_x = m_pos_x;
                    break;
                }

                uint16_t label_y = 0;
                if (m_height > text_height)
                {
                    if (tpos_div > 0)
                    {
                        label_y = m_pos_y + (m_height / 2)
                                + text_height / tpos_div;
                    }
                    else
                    {
                        label_y = m_pos_y
                                + ((m_height / 2) - (text_height / 2));
                    }
                }
                else
                {
                    label_y = m_pos_y + m_height - (text_height / 2);
                }

                tft->setCursor(label_x, label_y);
                tft->setTextColor(colorFg);
                tft->print(m_text);
            }
            m_last_text = m_text;
        }

        return false;
    }

} /* namespace ui */
