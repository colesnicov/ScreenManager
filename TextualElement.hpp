#pragma once

/**
 * File: TextualElement.hpp
 * Created on: 3. 1. 2018
 * Author: denis
 * Author: Denis Colesnicov <eugustus@gmail.com>
 * Version: 1.2.1
 */

#include "Element.hpp"

/**
 * Bazova trida pro ovladaci prvky s textem
 */

class TextualElement: public Element
{
public:

    /**
     * Nastavi text
     *
     * @param text Text pro prvek
     */
    inline void setText(char* text)
    {
        m_text = text;
    }

protected:
    char *m_text;
};
