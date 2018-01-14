/*
 * MyScreen.cpp
 *
 *  Created on: 13. 12. 2017
 *      Author: denis
 */

#include <Adafruit_ILI9341.h>
#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_curent_screen(e_screens::home),
            scrollableText(nullptr),
            m_buttonAbout(nullptr),
            m_buttonSpinner(nullptr),
            m_buttonText(nullptr),
            m_buttonToggle(nullptr),
            m_buttonZpet(nullptr),
            m_toggle(nullptr),
            m_spinnerInt(nullptr),
            m_hasActiveItem(false)
{
}

void HomeScreen::begin()
{
    ((Adafruit_ILI9341*) getTft())->begin();

    getTft()->fillScreen(ILI9341_BLACK);
    getTft()->setTextWrap(false);

    getTft()->setRotation(2);

    pinMode(13, OUTPUT);
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::update(Action action)
{

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

        case e_screens::spinner:
        {
            this->showSpinner(action);
            break;
        }

        case e_screens::text:
        {
            this->showTextArea(action);
            break;
        }

        case e_screens::toggle:
        {
            this->showToggler(action);
            break;
        }

    };
}

void HomeScreen::showHome(Action action)
{

    if (action != Action::NONE)
    {
        switch (action)
        {
            case Action::DOWN:
            {
                if (m_activeItem < 3)
                {
                    m_activeItem++;
                }
            }
            break;

            case Action::UP:
            {
                if (m_activeItem > 0)
                {
                    m_activeItem--;
                }
            }
            break;

            case Action::ENTER:
            {
                switch (m_activeItem)
                {
                    case 0:
                        m_curent_screen = e_screens::text;
                        delete m_buttonAbout;
                        m_buttonAbout = nullptr;
                        delete m_buttonSpinner;
                        m_buttonSpinner = nullptr;
                        delete m_buttonText;
                        m_buttonText = nullptr;
                        delete m_buttonToggle;
                        m_buttonToggle = nullptr;
                    break;

                    case 1:
                        m_curent_screen = e_screens::toggle;
                        delete m_buttonAbout;
                        m_buttonAbout = nullptr;
                        delete m_buttonSpinner;
                        m_buttonSpinner = nullptr;
                        delete m_buttonText;
                        m_buttonText = nullptr;
                        delete m_buttonToggle;
                        m_buttonToggle = nullptr;
                    break;

                    case 2:
                        m_curent_screen = e_screens::spinner;
                        delete m_buttonAbout;
                        m_buttonAbout = nullptr;
                        delete m_buttonSpinner;
                        m_buttonSpinner = nullptr;
                        delete m_buttonText;
                        m_buttonText = nullptr;
                        delete m_buttonToggle;
                        m_buttonToggle = nullptr;
                    break;

                    case 3:
                        m_curent_screen = e_screens::about;
                        delete m_buttonAbout;
                        m_buttonAbout = nullptr;
                        delete m_buttonSpinner;
                        m_buttonSpinner = nullptr;
                        delete m_buttonText;
                        m_buttonText = nullptr;
                        delete m_buttonToggle;
                        m_buttonToggle = nullptr;
                    break;

                    default:
                        m_curent_screen = e_screens::home;
                }
                m_activeItem = 0;
                setInvalid();
                update();
                return;
            }
        }
    }

    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setFont(&Achafsex14pt7b);
        getTft()->setTextSize(1);

        getTft()->setCursor(90, 25);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->print("Menu");
        getTft()->drawFastHLine(0, 35, 240, COLOR_CYAN);

        getTft()->setFont();
        getTft()->setTextSize(1);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->setCursor(45, 130);
        getTft()->print("(Zvolte jednu z moznosti)");

        getTft()->setTextColor(COLOR_BLACK);
        getTft()->setCursor(75, 310);
        getTft()->print("Powered on ScreenManager(C)");

        getTft()->setFont(&Achafsex14pt7b);
        setValid();
    }

    if (m_buttonText == nullptr)
    {
        m_buttonText = new ui::Button();
        m_buttonText->setPosition(5, 145);
        m_buttonText->setSize(230, 35);
        m_buttonText->setText((char*) "Text");
    }
    m_buttonText->Draw(getTft(), m_activeItem == 0, action, COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3);

    if (m_buttonToggle == nullptr)
    {
        m_buttonToggle = new ui::Button();
        m_buttonToggle->setPosition(5, 185);
        m_buttonToggle->setSize(230, 35);
        m_buttonToggle->setText((char*) "Toggle button");
    }
    m_buttonToggle->Draw(getTft(), m_activeItem == 1, action,
    COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 6);

    if (m_buttonSpinner == nullptr)
    {
        m_buttonSpinner = new ui::Button();
        m_buttonSpinner->setPosition(5, 225);
        m_buttonSpinner->setSize(230, 35);
        m_buttonSpinner->setText((char*) "Spinner");
    }
    m_buttonSpinner->Draw(getTft(), m_activeItem == 2, action,
    COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3);

    if (m_buttonAbout == nullptr)
    {
        m_buttonAbout = new ui::Button();
        m_buttonAbout->setPosition(5, 265);
        m_buttonAbout->setSize(230, 35);
        m_buttonAbout->setText((char*) "O Aplikaci");
    }
    m_buttonAbout->Draw(getTft(), m_activeItem == 3, action,
    COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3);

}

void HomeScreen::showTextArea(Action action)
{

    if (!m_hasActiveItem && action == Action::DOWN)
    {
        if (m_activeItem < 1)
        {
            m_activeItem++;
        }
    }
    else if (!m_hasActiveItem && action == Action::UP)
    {
        if (m_activeItem > 0)
        {
            m_activeItem--;
        }
    }

    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setFont(&Achafsex14pt7b);

        getTft()->setCursor(42, 25);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->print("ScrollableText");
        getTft()->drawFastHLine(0, 35, 240, COLOR_CYAN);

        getTft()->setFont();
        getTft()->setTextSize(2);
        getTft()->setCursor(5, 55);
        getTft()->print("Ukazka skrolovatelneho.");
        getTft()->setCursor(5, 75);
        getTft()->print("textu.");
        setValid();
    }

    if (scrollableText == nullptr)
    {
        scrollableText = new ui::ScrollableText();
        scrollableText->setPosition(5, 95);
        scrollableText->setSize(230, 180);
        scrollableText->setText(
                (char*) "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
                        " Integer sit amet est vel mauris placerat pulvinar vitae ut sapien."
                        " Praesent mollis eget urna et fringilla. Nullam interdum nibh a posuere sollicitudin."
                        " Aenean tincidunt mi ut sapien pretium, eu maximus turpis sollicitudin.");
    }

    getTft()->setFont();
    getTft()->setTextSize(2);
    m_hasActiveItem = scrollableText->Draw(getTft(), m_activeItem == 0, action,
    COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE, COLOR_BUTTON_FG_ACTIVE, 3);

    if (m_buttonZpet == nullptr)
    {
        m_buttonZpet = new ui::Button();
        m_buttonZpet->setPosition(5, 280);
        m_buttonZpet->setSize(230, 35);
        m_buttonZpet->setText((char*) "Zpet");
    }

    getTft()->setFont(&Achafsex14pt7b);
    getTft()->setTextSize(1);
    if (m_buttonZpet->Draw(getTft(), m_activeItem == 1, action, COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3))
    {
        m_curent_screen = e_screens::home;
        m_activeItem = 0;
        setInvalid();
        delete scrollableText;
        delete m_buttonZpet;
        scrollableText = nullptr;
        m_buttonZpet = nullptr;
        update();
        return;
    }
}

void HomeScreen::showToggler(Action action)
{
    if (action == Action::DOWN && !m_hasActiveItem)
    {
        if (m_activeItem < 1)
        {
            m_activeItem++;
        }
    }
    else if (action == Action::UP && !m_hasActiveItem)
    {
        if (m_activeItem > 0)
        {
            m_activeItem--;
        }
    }

    if (isInvalid())
    {

        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setFont(&Achafsex14pt7b);

        getTft()->setCursor(42, 25);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->print("ToggleButton");
        getTft()->drawFastHLine(0, 35, 240, COLOR_CYAN);

        getTft()->setFont();
        getTft()->setTextSize(2);
        getTft()->setCursor(5, 55);
        getTft()->print("Ukazka prepinaciho");
        getTft()->setCursor(5, 75);
        getTft()->print("tlacitka.");
        getTft()->setCursor(5, 130);
        getTft()->print("Led 1");
        setValid();
    }

    if (m_toggle == nullptr)
    {

        m_toggle = new ui::ToggleButton();
        m_toggle->setPosition(75, 120);
        m_toggle->setSize(150, 35);
        m_toggle->setTextOff("Vypnuto");
        m_toggle->setTextOn("Zapnuto");
    }
    getTft()->setFont();
    getTft()->setTextSize(2);

    m_toggle->Draw(getTft(), m_activeItem == 0, action, COLOR_TOGGLE_BG,
    COLOR_TOGGLE_FR, COLOR_TOGGLE_FG, COLOR_TOGGLE_BG_ACTIVE,
    COLOR_TOGGLE_FR_ACTIVE,
    COLOR_TOGGLE_FG_ACTIVE);

    if (m_toggle->isOn())
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        digitalWrite(13, LOW);
    }

    if (m_buttonZpet == nullptr)
    {
        m_buttonZpet = new ui::Button();
        m_buttonZpet->setPosition(5, 280);
        m_buttonZpet->setSize(230, 35);
        m_buttonZpet->setText((char*) "Zpet");
    }

    getTft()->setFont(&Achafsex14pt7b);
    getTft()->setTextSize(1);
    if (m_buttonZpet->Draw(getTft(), m_activeItem == 1, action, COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3))
    {
        m_curent_screen = e_screens::home;
        m_activeItem = 0;
        setInvalid();
        delete m_toggle;
        delete m_buttonZpet;
        m_toggle = nullptr;
        m_buttonZpet = nullptr;
        update();
        return;
    }
}

void HomeScreen::showSpinner(Action action)
{
    if (action == Action::DOWN && !m_hasActiveItem)
    {
        if (m_activeItem < 1)
        {
            m_activeItem++;
        }
    }
    else if (action == Action::UP && !m_hasActiveItem)
    {
        if (m_activeItem > 0)
        {
            m_activeItem--;
        }
    }

    static int value = 10;
    static int oldValue = 0;

    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setFont(&Achafsex14pt7b);

        getTft()->setCursor(80, 25);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->print("Spinner");
        getTft()->drawFastHLine(0, 35, 240, COLOR_CYAN);

        getTft()->setFont();
        getTft()->setTextSize(2);
        getTft()->setCursor(5, 55);
        getTft()->print("Ukazka spinneru.");

        getTft()->setCursor(5, 80);
        getTft()->print("Value is: ");
        setValid();
    }


    getTft()->setFont();
    getTft()->setTextSize(2);
    if (oldValue != value)
    {
        // Clear previous value
        getTft()->setCursor(120, 80);
        getTft()->setTextColor(COLOR_BROWN);
        getTft()->println(oldValue);
        // Print new value
        getTft()->setCursor(120, 80);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->println(value);
        oldValue = value;
    }

    if (m_spinnerInt == nullptr)
    {
        m_spinnerInt = new ui::SpinnerInt();
        m_spinnerInt->setPosition(5, 120);
        m_spinnerInt->setSize(230, 35);
        m_spinnerInt->setValue(&value);
        m_spinnerInt->setText((char*) "%d%%");
    }

    m_hasActiveItem = m_spinnerInt->Draw(getTft(), m_activeItem == 0, action,
    COLOR_TOGGLE_BG, COLOR_TOGGLE_FR, COLOR_TOGGLE_FG, COLOR_TOGGLE_BG_ACTIVE,
    COLOR_TOGGLE_FR_ACTIVE, COLOR_TOGGLE_FG_ACTIVE, 0);

    if (m_buttonZpet == nullptr)
    {
        m_buttonZpet = new ui::Button();
        m_buttonZpet->setPosition(5, 280);
        m_buttonZpet->setSize(230, 35);
        m_buttonZpet->setText((char*) "Zpet");
    }

    getTft()->setFont(&Achafsex14pt7b);
    getTft()->setTextSize(1);
    if (m_buttonZpet->Draw(getTft(), m_activeItem == 1, action, COLOR_BUTTON_BG,
    COLOR_BUTTON_FR, COLOR_BUTTON_FG, COLOR_BUTTON_BG_ACTIVE,
    COLOR_BUTTON_FR_ACTIVE,
    COLOR_BUTTON_FG_ACTIVE, 3))
    {
        m_curent_screen = e_screens::home;
        m_activeItem = 0;
        setInvalid();
        delete m_spinnerInt;
        delete m_buttonZpet;
        m_spinnerInt = nullptr;
        m_buttonZpet = nullptr;
        update();
        return;
    }
}

void HomeScreen::showAbout(Action action)
{
    if (action != Action::NONE)
    {
        m_curent_screen = e_screens::home;
        m_activeItem = 0;
        setInvalid();
        return;
    }
    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setFont(&Achafsex14pt7b);

        getTft()->setCursor(50, 25);
        getTft()->setTextColor(COLOR_CYAN);
        getTft()->print("O Aplikaci");
        getTft()->drawFastHLine(0, 35, 240, COLOR_CYAN);

        getTft()->setFont();
        getTft()->setTextSize(2);
        getTft()->setCursor(5, 55);
        getTft()->print("Kompletni ukazka");
        getTft()->setCursor(5, 75);
        getTft()->print("knihovny");
        getTft()->setCursor(5, 95);
        getTft()->print("ScreenManager od.");
        getTft()->setCursor(5, 115);
        getTft()->print("Denis Colesnicov.");

        getTft()->setCursor(5, 135);
        getTft()->setTextSize(1);
        getTft()->setTextWrap(true);
        getTft()->setTextColor(COLOR_BLUE);
        getTft()->print("https://github.com/colesnicov/ScreenManager");
        setValid();
    }
}




