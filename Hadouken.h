#pragma once
#include "ProjectileFactory.h"

class Hadouken : public Projectile
{
    Hadouken();
    ~Hadouken();
    Hadouken(Point, bool);
    void Creation();
public:
    void UpdateSprite();
    void Render(SDL_Renderer*);
    void HandleHit(bool);

    friend ProjectileFactory;
};
