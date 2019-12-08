#pragma once
#include "Point.h"
#include "floatAnchor.h"
#include "Unit.h"
#include <SDL.h>

class Button : public Unit
{
public:
    int defaultHeight;
    int selectedHeight;
    int currentHeight;
    Point position;
    floatAnchor inVariant;

    Button();
    Button(int, int, Point, floatAnchor);

public:
    virtual void Render(SDL_Renderer*, bool, Point) = 0;
    virtual ~Button() = 0;
};
