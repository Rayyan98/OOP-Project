#pragma once
#include "Unit.h"
#include "Point.h"
#include <SDL.h>
#include "floatAnchor.h"

class Figure : public Unit
{
    SDL_Texture* spriteSheet;
    SDL_Rect srcRect;
    Point nextSprite;
    int totalSprites;
    int currentSprite;
    bool defaultOrientation;
    bool loop;
    floatAnchor fAnchor;

public:
    int height;
    Figure();
    ~Figure();
    Figure(SDL_Texture*, Point, Point, Point, int, bool, bool, floatAnchor);
    void Render(SDL_Renderer*, Point, int, bool, bool);
    int ProjectedWidth(int);
};
