#pragma once
#include <SDL.h>
#include "Screen.h"

class ScreenFactory
{
public:
    //Factory Method
    static Screen*  createScreen(int, int, Screen*, int, int , bool);
};
