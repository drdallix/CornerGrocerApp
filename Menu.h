/*
 * Student: Dallas Roberts
 * Class: CS204 c++
 * CornerGrocer.cpp
 *
 */
#ifndef MENU_H
#define MENU_H

#include "ItemCounter.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>

class Menu {
private:
    //private method takes user input, handles erros and returns the users choice
    static int GetInput();
    //static constant for what the highest menu option is, used to verify user input against.
    static const int MAXCHOICE = 4;
public:
    // Static method to display the menu
    static void display(ItemCounter& item);
    };

#endif
