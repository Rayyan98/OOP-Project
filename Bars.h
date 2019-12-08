#ifndef BARS_H
#define BARS_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <string>
#include <iostream>
#include "Global.h"
#include "Point.h"

class Bars
{
protected:
    int maxValue;
    int currentValue;
    //SDL_Rect srcRect;
    //SDL_Surface* temp;
    SDL_Texture* barTexture;
    int barWidth;
    int barHeight;
    Point topLeft;
    Point destTopLeft;
    bool P2;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    //Point bottomRight;
    Bars();
public:
    ~Bars();
    //Bars(int,int,int,int);
//    virtual void loadBarSprite(SDL_Renderer*) = 0;
    virtual void decreaseBy(int);
    virtual void increaseBy(int);
    virtual void increase(int);
    virtual void emptyBar();
    virtual void renderBar(SDL_Renderer*) = 0;
    virtual void giveValue(int) = 0;

};

#endif // BARS_H
