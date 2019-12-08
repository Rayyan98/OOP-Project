#pragma once
#include "Bars.h"

class BarFactory
{
public:
    //Factory Method
    static Bars* createBar(int, bool);
};
