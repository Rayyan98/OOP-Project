#include "Button.h"

Button::Button()
{

}

void Button::Render(SDL_Renderer* gRenderer, bool selected = false, Point position = Point(-700,-700))
{

}

Button::Button(int defaultHeight, int selectedHeight, Point position, floatAnchor inVariant)
{
    if(selectedHeight == 0)
    {
        this->selectedHeight = defaultHeight;
    }
    else
    {
        this->selectedHeight = selectedHeight;
    }
    this->defaultHeight = defaultHeight;
    this->currentHeight = defaultHeight;
    this->position = position;
    this->inVariant = inVariant;
}

Button::~Button()
{

}
