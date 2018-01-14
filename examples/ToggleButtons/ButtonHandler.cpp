#include "ButtonHandler.hpp"

ButtonHandler::ButtonHandler() :
            m_action(Action::NONE),
            m_backButton(A6),
            m_downButton(A3),
            m_leftButton(A0),
            m_okButton(A4),
            m_rightButton(A2),
            m_upButton(A1)
{
}

void ButtonHandler::reset()
{
    m_action = Action::NONE;
}

void ButtonHandler::update()
{
    if (m_upButton.pressed())
    {
        m_action = Action::UP;
    }
    else if (m_downButton.pressed())
    {
        m_action = Action::DOWN;
    }
    else if (m_leftButton.pressed())
    {
        m_action = Action::LEFT;
    }
    else if (m_rightButton.pressed())
    {
        m_action = Action::RIGHT;
    }
    else if (m_backButton.pressed())
    {
        m_action = Action::BACK;
    }
    else if (m_okButton.pressed())
    {
        m_action = Action::ENTER;
    }
    else
    {
        m_action = Action::NONE;
    }
}

Action ButtonHandler::getAction()
{
    return m_action;
}

void ButtonHandler::begin()
{
    m_upButton.begin();
    m_downButton.begin();
    m_okButton.begin();
    m_leftButton.begin();
    m_rightButton.begin();
    m_backButton.begin();
}
