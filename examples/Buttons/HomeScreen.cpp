#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_curent_screen(e_screens::home),
            m_buttonOn(nullptr),
            m_activeItem(0)
{
}

void HomeScreen::begin()
{
    ((Adafruit_ILI9341*) getTft())->begin();
    getTft()->fillScreen(COLOR_WHITE);

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::update(Action action)
{
    this->showHome(action);
}

void HomeScreen::showHome(Action action)
{

    static bool led_on = false;

    if (action == Action::UP && m_activeItem > 0)
    {
        m_activeItem--;
    }
    else if (action == Action::DOWN && m_activeItem < 1)
    {
        m_activeItem++;
    }

    if (isInvalid())
    {
        getTft()->fillScreen(COLOR_BROWN);

        getTft()->setCursor(10, 10);
        getTft()->setTextSize(2);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->print("Buttons example");
        getTft()->setCursor(10, 40);
        getTft()->print("Led 1 is: ");
        getTft()->println((led_on) ? "ON" : "OFF");

        setValid();
    }

    if (m_buttonOn == nullptr)
    {
        m_buttonOn = new ui::Button();
        m_buttonOn->setPosition(5, 80);
        m_buttonOn->setSize(230, 35);
        m_buttonOn->setText((char*) "Led ON");
    }

    if (m_buttonOff == nullptr)
    {
        m_buttonOff = new ui::Button();
        m_buttonOff->setPosition(5, 180);
        m_buttonOff->setSize(230, 35);
        m_buttonOff->setText((char*) "Led OFF");
    }

    if (m_buttonOn->Draw(getTft(), m_activeItem == 0, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_WHITE,
    COLOR_BLUE,
    COLOR_BLACK))
    {
        digitalWrite(LED, HIGH);
        led_on = true;
        m_buttonOn->setActive(false); // to prevent repeatedly click
        m_buttonOn->setInvalid(); // to redraw element after fillscreen!
        m_buttonOff->setInvalid(); // to redraw element after fillscreen!
        setInvalid();
        return; // Allways must be call for correct render!
    }

    if (m_buttonOff->Draw(getTft(), m_activeItem == 1, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_WHITE,
    COLOR_BLUE,
    COLOR_BLACK, 0))
    {
        digitalWrite(LED, LOW);
        led_on = false;
        m_buttonOff->setActive(false); // to prevent repeatedly click
        m_buttonOn->setInvalid(); // to redraw element after fillscreen!
        m_buttonOff->setInvalid(); // to redraw element after fillscreen!
        setInvalid();
        return; // Allways must be call for correct render!
    }
}

