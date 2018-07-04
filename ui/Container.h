/*
 * Container.h
 *
 *  Created on: 14. 1. 2018
 *      Author: denis
 */

#ifndef LIBRARIES_SCREENMANAGER_UI_CONTAINER_H_
#define LIBRARIES_SCREENMANAGER_UI_CONTAINER_H_

namespace ui
{
    class Element
    {
    };
}

namespace ui
{

    /*
     *
     */
    class Container
    {
    public:
        Container() :
                    m_invalid(true)
        {
        }

        virtual ~Container();

        void update()
        {
            if (m_invalid)
            {
                // ...
                for (int i = 0; i < 0; i++)
                {
                    //m_items[i]->setSize(0,0);
                    //m_items[i]->setPosition(0,0);
                }
                m_invalid = false;
            }
        }

        bool addItem(ui::Element* item, int size)
        {
            // propocitat sirku vsech elementu a pokud
            // je vetsi nez sirka obrazovky odmitnout prvek!
            m_items[sizeof(m_items) / sizeof(ui::Element)] = item;
            m_invalid = true;
            return true;
        }

    protected:

        bool m_invalid;

        int m_width;
        int m_height;
        int m_pos_x;
        int m_pos_y;

        ui::Element* m_items[];

    };

} /* namespace ui */

#endif /* LIBRARIES_SCREENMANAGER_UI_CONTAINER_H_ */
