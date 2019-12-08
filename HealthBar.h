#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include<SDL.h>
#include<SDL_image.h>
#include"Point.h"
#include "Bars.h"
#include "Global.h"
#include "BarFactory.h"
#include "Characters.h"

class HealthBar : public Bars
{
private:
    SDL_Rect healthRect;
    HealthBar(bool P2 = false);
    ~HealthBar();
//    void loadBarSprite(SDL_Renderer*);
    void renderBar(SDL_Renderer* grenderer);

    friend Character;
    friend BarFactory;
public:
    void giveValue(int);
};

#endif // HEALTHBAR_H
