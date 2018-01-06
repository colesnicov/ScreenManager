#pragma once

/*
 * File: HomeScreen.hpp
 * Created on: 13. 12. 2017
 * Author: Denis Colesnicov <eugustus@gmail.com>
 */

#include <Screen.h>
#include <Adafruit_ILI9341.h>

#define COLOR_BLACK 0X0000
#define COLOR_BLUE  0X001F
#define COLOR_WHITE 0XFFFF

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

    void showAbout(Action action);

private:

    enum e_screens
    {
        about,
        home
    };

    e_screens m_curent_screen;


};

