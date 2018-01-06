#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_curent_screen(e_screens::home)
{
}

void HomeScreen::begin()
{
    ((Adafruit_ILI9341*) getTft())->begin();
    getTft()->fillScreen(COLOR_WHITE);

}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::update(Action action)
{

    if (action == Action::ENTER)
    {
        if (m_curent_screen == e_screens::about)
        {
            m_curent_screen = e_screens::home;
            setInvalid();
        }
        else
        {
            m_curent_screen = e_screens::about;
            setInvalid();
        }
    }

    switch (m_curent_screen)
    {

        case e_screens::about:
        {
            this->showAbout(action);
            break;
        }

        case e_screens::home:
        {
            this->showHome(action);
            break;
        }

    };
}

void HomeScreen::showHome(Action action)
{

    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BLUE);

        getTft()->setCursor(10, 10);
        getTft()->setTextSize(2);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->print("Primary screen");
        setValid();
    }
}

void HomeScreen::showAbout(Action action)
{
    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BLACK);

        getTft()->setCursor(10, 10);
        getTft()->setTextSize(2);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->print("Secondary screen");
        setValid();
    }
}
