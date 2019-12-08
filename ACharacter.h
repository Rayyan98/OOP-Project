#pragma once
#include "SDL.h"
#include <string>
#include "Point.h"
#include "Unit.h"

class ACharacter : public Unit
{
public:
    int origWidth;
    int origHeight;
    int lastWidth;
    int lastHeight;
    string chr;
    string color;
    char* path;
    SDL_Rect dstRect;
    SDL_Surface* temp = 0;
    SDL_Texture* img = 0;

public:
    ACharacter();
    ACharacter(SDL_Renderer*, string, string, Point anchor = Point(0,0));
    ~ACharacter();
    void Render(SDL_Renderer*, Point&, int);
    int GetProjectedWidth(int);
};
