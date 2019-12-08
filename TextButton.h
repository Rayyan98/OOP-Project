#pragma once
#include "Button.h"
#include "Word.h"
#include "floatAnchor.h"

class TextButton : public Button
{
    static int buttonAnimationFrames;
    Word* word;
    string defaultColor;
    string selectedColor;
public:
    TextButton();
    ~TextButton();
    TextButton(string, Point, int, int, string, string, floatAnchor inVariant = floatAnchor(0,0));
    void Render(SDL_Renderer*, bool selected = 0, Point position = Point(-700,-700));
    void ChangeWord(string);
};
