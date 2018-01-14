#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_current_screen(e_screens::home),
            m_spinner(nullptr),
            m_activeItem(0)
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
    this->showHome(action);
}

void HomeScreen::showHome(Action action)
{

    static int value = 10;
    static int oldValue = 0;

    if (isInvalid())
    {

        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setCursor(10, 10);
        getTft()->setTextSize(2);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->print("Spinner example");
        getTft()->setCursor(10, 40);
        getTft()->print("Value is: ");
        setValid();
    }

    if (oldValue != value)
    {
        // Clear previous value
        getTft()->setCursor(120, 40);
        getTft()->setTextColor(COLOR_BROWN);
        getTft()->println(oldValue);
        // Print new value
        getTft()->setCursor(120, 40);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->println(value);
        oldValue = value;
    }

    if (m_spinner == nullptr)
    {
        m_spinner = new ui::SpinnerInt();
        m_spinner->setPosition(5, 140);
        m_spinner->setSize(230, 35);
        m_spinner->setValue(&value);
        m_spinner->setText((char*) "%d%%");
    }

    getTft()->setFont();
    getTft()->setTextSize(2);
    m_spinner->Draw(getTft(), m_activeItem == 0, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_WHITE,
    COLOR_BLUE,
    COLOR_BLACK);
}

