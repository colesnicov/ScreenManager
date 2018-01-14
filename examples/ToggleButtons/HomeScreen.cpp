#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_current_screen(e_screens::home),
            m_toggle_1(nullptr),
            m_activeItem(0)
{
}

void HomeScreen::begin()
{
    ((Adafruit_ILI9341*) getTft())->begin();
    getTft()->fillScreen(COLOR_WHITE);

    pinMode(LED_1, OUTPUT);
    digitalWrite(LED_1, LOW);

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

    static bool led_1_on = false;
    static bool led_2_on = false;

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
        getTft()->print("ToggleButtons example");
        getTft()->setCursor(10, 40);
        getTft()->print("Led 1 is: ");
        getTft()->println((led_1_on) ? "ON" : "OFF");
        getTft()->setCursor(10, 70);
        getTft()->print("Led 2 is: ");
        getTft()->println((led_2_on) ? "ON" : "OFF");

        setValid();
    }

    if (m_toggle_1 == nullptr)
    {
        m_toggle_1 = new ui::ToggleButton();
        m_toggle_1->setPosition(5, 140);
        m_toggle_1->setSize(230, 35);
        m_toggle_1->setTextOff((char*) "Led 1 OFF");
        m_toggle_1->setTextOn((char*) "Led 1 ON");
    }

    if (m_toggle_2 == nullptr)
    {
        m_toggle_2 = new ui::ToggleButton();
        m_toggle_2->setPosition(5, 180);
        m_toggle_2->setSize(230, 35);
        m_toggle_2->setTextOff((char*) "Led 2 OFF");
        m_toggle_2->setTextOn((char*) "Led 2 ON");
    }

    if (m_toggle_1->Draw(getTft(), m_activeItem == 0, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_WHITE,
    COLOR_BLUE,
    COLOR_BLACK))
    {
        digitalWrite(LED_1, HIGH);
        led_1_on = m_toggle_1->isOn();
        m_toggle_1->setActive(false); // to prevent repeatedly click
        m_toggle_1->setInvalid(); // to redraw element after fillscreen!
        m_toggle_2->setInvalid(); // to redraw element after fillscreen!
        setInvalid();
        return; // Allways must be call for correct render!
    }

    if (m_toggle_2->Draw(getTft(), m_activeItem == 1, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_WHITE,
    COLOR_BLUE,
    COLOR_BLACK, 0))
    {
        digitalWrite(LED_1, LOW);
        led_2_on = m_toggle_2->isOn();
        m_toggle_2->setActive(false); // to prevent repeatedly click
        m_toggle_1->setInvalid(); // to redraw element after fillscreen!
        m_toggle_2->setInvalid(); // to redraw element after fillscreen!
        setInvalid();
        return; // Allways must be call for correct render!
    }
}

