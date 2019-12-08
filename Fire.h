#pragma once
#include "ProjectileFactory.h"

class Fire : public Projectile
{
    Fire();
    void Creation();
    Fire(Point, bool);
public:
    ~Fire();
    void UpdateSprite();
    void HandleHit(bool);
    void Render(SDL_Renderer*);

    friend ProjectileFactory;
};
