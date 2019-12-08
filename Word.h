#pragma once
#include "ACharacter.h"
#include "Point.h"

class Word : public Unit
{
public:
    int length;
    string word;
    ACharacter** charTextures = 0;
    Word();
    Word(string, Point anchor = Point(0,0));
    ~Word();
    void Render(SDL_Renderer*, Point, int, string);
    int GetProjectedWidth(int);
};
