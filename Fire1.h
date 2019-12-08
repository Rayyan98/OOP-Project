#pragma once
#include "ProjectileFactory.h"

class Fire1 : public Projectile
{
    Fire1();
    void Creation();
    Fire1(Point, bool);
public:
    ~Fire1();
    void UpdateSprite();
    void HandleHit(bool);
    void Render(SDL_Renderer*);

    friend ProjectileFactory;
};
