#include "Bars.h"

Bars::Bars()
{
    maxValue = 100;
    //barWidth = SCREEN_WIDTH/8;
    //barHeight = SCREEN_HEIGHT/8;
}

Bars::~Bars()
{
    SDL_DestroyTexture(barTexture);
    barTexture = NULL;
    //destroy surface?
}

void Bars::decreaseBy(int decrement)
{
    currentValue-=decrement;
    if(currentValue < 0)
    {
        currentValue = 0;
    }
//    void renderBar(SDL_Renderer* grenderer,bool P2);
}

void Bars::increaseBy(int increment)
{
    currentValue+=increment;
    if(currentValue > maxValue)
    {
        currentValue = maxValue;
    }
//    void renderBar(SDL_Renderer* grenderer,bool P2 = false);
}

void Bars::increase(int value)
{

}

void Bars::emptyBar()
{

}
