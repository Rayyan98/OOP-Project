#include <iostream>
#include "Color.h"

Color:: Color()
{
    red = 0;
    blue = 0;
    green = 0;
}
Color::Color(int red, int blue, int green)
{
    this->red = red;
    this->blue = blue;
    this->green = green;
}

Color::~Color()
{
    std::cout << "Color Destroyed";
}
