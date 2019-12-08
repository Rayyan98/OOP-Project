#pragma once
#include "Sprite.h"

class Projectile
{
protected:
    Point velocity;
    Sprite* nextSprite;
    Sprite** allSprites;

    int damage;
    int cap;
    int spread;
    int current;
    Point position;
    bool status;
    bool defaultOrientation;
    bool hasDamaged;

    Projectile();
    Projectile(Point,bool);

public:
    Point GetPosition();
    bool GetStatus();
    virtual void UpdateSprite() = 0;
    virtual void HandleHit(bool) = 0;
    virtual void Render(SDL_Renderer*) = 0;
    virtual ~Projectile() = 0;
    Sprite* GetSprite();
    int GetDamage();
    bool HasDamaged();
};
