#pragma once

/**
 * File: HomeScreen.hpp
 * Created on: 13. 1. 2018
 * Author: Denis Colesnicov <eugustus@gmail.com>
 */

#include <Adafruit_ILI9341.h>
#include <Screen.h>
#include <ui/ScrollableText.h>
#include <Colors.h>

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
    ui::ScrollableText* m_scrollableText;
    uint8_t m_activeItem;


};

