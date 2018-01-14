/*
 * MyScreen.hpp
 *
 *  Created on: 13. 12. 2017
 *  Author: Denis Colesnicov <eugustus@gmail.com>
 */

#pragma once

#include <Adafruit_GFX.h>

#include "achafsex14pt7b.h"

#include <Screen.h>

#include "screen_config.h"
#include <ui/Button.hpp>
#include <ui/ToggleButton.h>
#include <ui/Spinner.h>
#include <ui/ScrollableText.h>


/*
 *
 */
class HomeScreen: public Screen
{
public:
    HomeScreen();
    HomeScreen(Adafruit_GFX* tft);
    ~HomeScreen();

    void begin();

    void update(Action action = Action::NONE);

    void showHome(Action action);

    void showTextArea(Action action);

    void showToggler(Action action);

    void showSpinner(Action action);

    void showAbout(Action action);

private:

    enum e_screens
    {
        about,
        home,
        spinner,
        text,
        toggle
    };

    e_screens m_curent_screen;

    uint8_t m_activeItem = 0;

    ui::ScrollableText* scrollableText;

    ui::Button* m_buttonAbout;
    ui::Button* m_buttonSpinner;
    ui::Button* m_buttonText;
    ui::Button* m_buttonToggle;
    ui::Button* m_buttonZpet;

    ui::ToggleButton *m_toggle;

    ui::SpinnerInt *m_spinnerInt;

    bool m_hasActiveItem;
};

