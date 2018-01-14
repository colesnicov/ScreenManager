#pragma once

/**
 * File: HomeScreen.hpp
 * Created on: 13. 1. 2018
 * Author: Denis Colesnicov <eugustus@gmail.com>
 */

#include <Adafruit_ILI9341.h>
#include <Screen.h>
#include <ui/ToggleButton.h>
#include <Colors.h>

#define LED_1 13
#define LED_2 14

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

private:

    enum e_screens
    {
        home
    };

    e_screens m_current_screen;
    ui::ToggleButton* m_toggle_1;
    ui::ToggleButton* m_toggle_2;
    uint8_t m_activeItem;


};

