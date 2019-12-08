#ifndef COMBOBAR_H
#define COMBOBAR_H
#include<SDL.h>
#include<SDL_image.h>
#include "Point.h"
#include "Bars.h"
#include "Global.h"
#include "BarFactory.h"
#include "Characters.h"

class ComboBar : public Bars
{
private:
    SDL_Rect comboRect;
    Point* srcArray;
    int state;
    //SDL_Texture** allComboBars;
    ComboBar(bool P2 = false,int state = 0);
    ~ComboBar();
//    void loadBarSprite(SDL_Renderer*);
    void renderBar(SDL_Renderer*);
    void decreaseBy(int decrement);
    void increaseBy(int increment);
    void increase(int);
    void emptyBar();

    friend Character;
    friend BarFactory;
public:
    void giveValue(int);
};

#endif // COMBOBAR_H
