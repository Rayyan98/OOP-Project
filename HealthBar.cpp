#include "HealthBar.h"

HealthBar::HealthBar(bool P2)
{
    this->P2 = P2;
    currentValue = 100;
    barWidth = Global::SCREEN_WIDTH * 2.5 / 8;
    barHeight = Global::CorrectHeight(576,70,barWidth);
    if (!P2)
    {
        topLeft = Point(0,69);
        destTopLeft = Point(((Global::SCREEN_WIDTH)/8)*1,(Global::SCREEN_HEIGHT / 8)*0.5);
    }
    else
    {
        topLeft = Point(802,69);
        destTopLeft = Point (((Global::SCREEN_WIDTH)/8)*4.5,(Global::SCREEN_HEIGHT / 8)*0.5);
    }

    barTexture = Global::healthBarTexture;
    this->srcRect = {topLeft.x,topLeft.y,576,70};
    this->destRect = {destTopLeft.x,destTopLeft.y,barWidth,barHeight};
}

HealthBar::~HealthBar()
{
    //dtor
}

//void HealthBar::loadBarSprite(SDL_Renderer* grenderer)
//{
//}

void HealthBar::renderBar(SDL_Renderer* grenderer)
{
    if (!P2)
    {
        //healthRect = {(33/8)*1+destTopLeft.x+destTopLeft.y+(Global::CorrectHeight(576,23,barWidth))*((maxValue-currentValue)/maxValue),destTopLeft.y+Global::CorrectHeight(576,23,barWidth),(533*2.5/8)*currentValue/maxValue,Global::CorrectHeight(576,27,barWidth)};
        healthRect = {Global::CorrectWidth(35,576,barWidth)+destTopLeft.x,destTopLeft.y+Global::CorrectHeight(70,26,barHeight),Global::CorrectWidth(530,576,barWidth)*float(currentValue)/maxValue,Global::CorrectHeight(70,26,barHeight)};
        //std::cout<<"Width of P1 health bar is: ";
        //std::cout<<Global::CorrectWidth(576,530,barWidth)*(currentValue/maxValue)<<std::endl; //217
    }
    else
    {
        //healthRect = {(33/8)*2.5+destTopLeft.x,destTopLeft.y+Global::CorrectHeight(576,23,barWidth),(533*2.5/8)*currentValue/maxValue,Global::CorrectHeight(576,27,barWidth)};
        healthRect = {Global::CorrectWidth(12,576,barWidth)+destTopLeft.x+(Global::CorrectWidth(530,576,barWidth)*(1-(float(currentValue)/maxValue))),destTopLeft.y+Global::CorrectHeight(70,23,barHeight),Global::CorrectWidth(530,576,barWidth)*float(currentValue)/maxValue,Global::CorrectHeight(70,27,barHeight)};
        //std::cout<<Global::CorrectWidth(576,35,barHeight)+destTopLeft.x+(Global::CorrectWidth(576,530,barWidth)*((maxValue-currentValue)/maxValue))<<std::endl;
        //std::cout<<destTopLeft.x<<std::endl;
    }
    SDL_RenderCopy(grenderer, barTexture, &srcRect, &destRect);
    SDL_SetRenderDrawColor( grenderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect(grenderer,&healthRect);
}

void HealthBar::giveValue(int val)
{
    decreaseBy(maxValue - val);
}
