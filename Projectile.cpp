#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::~Projectile()
{
    delete allSprites;
//    cout << " lafanga " << endl;
}

Projectile::Projectile(Point position, bool orientation)
{
    this->defaultOrientation = orientation;
    this->position = position;
    nextSprite = 0;
    status = true;
    this->hasDamaged = false;
}

Point Projectile::GetPosition()
{
    return this->position;
}

bool Projectile::GetStatus()
{
    return this->status;
}

Sprite* Projectile::GetSprite()
{
    return this->nextSprite;
}

int Projectile::GetDamage()
{
    if(hasDamaged)
    {
        return 0;
    }
    else
    {
        return damage;
    }
}

bool Projectile::HasDamaged()
{
    return this->hasDamaged;
}
