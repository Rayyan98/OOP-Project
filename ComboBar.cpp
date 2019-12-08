#include "ComboBar.h"

ComboBar::ComboBar(bool P2,int state)
{
    state = 0;
    maxValue = 99;
    this->P2 = P2;
    barWidth = (Global::SCREEN_WIDTH * 2.5 )/ 6;
    srcArray = new Point[8];
    srcArray[0] = Point(0,267);
    srcArray[1] = Point(0,211);
    srcArray[2] = Point(0,157);
    srcArray[3] = Point(0,102);
    srcArray[4] = Point(904,269);
    srcArray[5] = Point(904,213);
    srcArray[6] = Point(904,162);
    srcArray[7] = Point(904,107);
    //srcArray = {Point(0,267),Point(0,211),Point(0,157),Point(0,102),Point(904,269),Point(904,213),Point(904,162),Point(904,107)};
    //state = 0;
    this->state = state;
    if (!P2)
    {

        barHeight = Global::CorrectHeight(440,46,barWidth);
        topLeft = srcArray[state];
        destTopLeft = Point(0,(Global::SCREEN_HEIGHT / 6)*5.5);
    }
    else
    {
        barHeight = Global::CorrectHeight(426,42,barWidth);
        topLeft = srcArray[state+4];
        destTopLeft = Point(Global::SCREEN_WIDTH * 3.5 / 6,(Global::SCREEN_HEIGHT / 6)*5.5);
    }
    barTexture = Global::manaBarTexture;
    destRect = {destTopLeft.x,destTopLeft.y,barWidth,barHeight};
    currentValue = 0;
}

ComboBar::~ComboBar()
{
    //dtor
}

//void ComboBar::loadBarSprite(SDL_Renderer* grenderer)
//{
//    std::cout<<"Bar texture loaded"<<std::endl;
//}

void ComboBar::decreaseBy(int decrement)
{
    if (state-decrement < 0)
    {
        std::cout<<"Current state cannot be negative"<<std::endl;
    }
    else if ((state-decrement >= 0) && (!P2))
    {
        state-=decrement;
        topLeft = srcArray[state];
    }
    else if ((P2) && (state-decrement >=0))
    {
        state-=decrement;
        topLeft = srcArray[state+4];
    }
}

void ComboBar::increaseBy(int increment)
{
    if (state+increment > 3)
    {
        std::cout<<"Current state cannot be greater than 3"<<std::endl;
    }
    else if ((state+increment <= 3) && (!P2))
    {
        state+=increment;
        topLeft = srcArray[state];
    }
    else if ((state+increment <= 3) && (P2))
    {
        state+=increment;
        topLeft = srcArray[state+4];
    }
}

void ComboBar::increase(int value)
{
    currentValue += value;
    if(currentValue > maxValue)
    {
        currentValue = maxValue;
    }
//    cout << currentValue << " " << state << endl;
    if(currentValue >= ((state + 1) * 33))
    {
        increaseBy(1);
    }
}

void ComboBar::emptyBar()
{
    currentValue = 0;
    state = -1;
    increaseBy(1);
}

void ComboBar::renderBar(SDL_Renderer* grenderer)
{
    if (!P2)
    {
        comboRect = {topLeft.x,topLeft.y,440,46};
    }
    else
    {
        comboRect = {topLeft.x,topLeft.y,426,42};
    }
    SDL_RenderCopy(grenderer,barTexture,&comboRect,&destRect);
//    std::cout<<"Combo render called "<<std::endl;
}


void ComboBar::giveValue(int val)
{
    int i = val / 33;
    for(int j = 0; j < i; j++)
    {
        increaseBy(1);
    }
}
