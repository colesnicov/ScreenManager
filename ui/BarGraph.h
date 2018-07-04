// Henry's Bench
//  Basic Bargraph Tutorial

#include <SPI.h>
#include <Adafruit_GFX.h>

#include <Element.hpp>

// Color Pallette

#define BACKCOLOR 0x18E3
#define BARCOLOR 0x0620
#define SCALECOLOR 0xFFFF

namespace ui
{

    class BarGraph: public Element
    {
    public:

        int getValue()
        {
            return m_value;
        }

        void setValue(int value)
        {
            m_value = value;
        }

        void draw(Adafruit_GFX* tft, bool current, Action action,
                uint16_t colorBg, uint16_t colorFr, uint16_t colorFg,
                uint8_t tpos_div = 0)
        {
            drawScale(colorFr);

            if (m_value != m_valueLast)
            {
                if (m_value < m_valueLast)
                {
                    tft->fillRect(61, 20 + (100 - m_valueLast), 30,
                            m_valueLast - m_value, colorBg);
                }
                else
                {
                    tft->fillRect(61, 20 + (100 - m_value), 30,
                            m_value - m_valueLast, colorFg);
                }
                m_valueLast = m_value;
            }
        }

    private:

        int m_valueLast = 0;
        int m_value;

        void drawScale(uint16_t color)
        {
            if (isInvalid())
            {
                tft.drawFastVLine(55, 20, 100, color); // Vertical Scale Line
                tft.drawFastHLine(47, 20, 8, color); // Major Division
                tft.drawFastHLine(50, 44, 5, color); // Minor Division
                tft.drawFastHLine(47, 69, 8, color); // Major Division
                tft.drawFastHLine(50, 94, 5, color); // Minor Division
                tft.drawFastHLine(47, 119, 8, color); // Major Division
                setValid();
            }
        }

    };

}
