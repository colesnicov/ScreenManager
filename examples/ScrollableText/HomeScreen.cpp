#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
{
}

HomeScreen::HomeScreen(Adafruit_GFX* tft) :
            Screen(tft),
            m_current_screen(e_screens::home),
            m_scrollableText(nullptr),
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

    if (isInvalid())
    {

        getTft()->fillScreen(COLOR_BROWN);
        getTft()->setCursor(10, 10);
        getTft()->setTextSize(2);
        getTft()->setTextColor(COLOR_WHITE);
        getTft()->print("Text example");
        setValid();
    }

    if (m_scrollableText == nullptr)
    {
        m_scrollableText = new ui::ScrollableText();
        m_scrollableText->setPosition(5, 40);
        m_scrollableText->setSize(230, 200);
        m_scrollableText->setText(
                (char*) "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                        "Ut ullamcorper vel libero vel suscipit. "
                        "Curabitur vulputate augue at mauris accumsan, sed mattis nisl auctor. "
                        "Aenean tincidunt ex placerat elementum sagittis. "
                        "Proin tincidunt nibh et ante amet.");
    }

    getTft()->setFont();
    getTft()->setTextSize(2);
    m_scrollableText->Draw(getTft(), m_activeItem == 0, action, COLOR_WHITE,
    COLOR_BLACK, COLOR_BROWN, COLOR_IVORY,
    COLOR_BLUE,
    COLOR_BLACK, 5);
}

