#pragma once
#include "Button.h"
#include "Point.h"
#include "floatAnchor.h"
#include <SDL.h>


class PortraitButton : public Button
{
    static int buttonAnimationFrames;
    SDL_Texture* characterPortraits;
    SDL_Rect srcRect;

public:
    PortraitButton();
    ~PortraitButton();
    PortraitButton(SDL_Texture*, Point, Point, Point, int, int, floatAnchor);
    void Render(SDL_Renderer*, bool selected = 0, Point position = Point(-700, -700));
};
