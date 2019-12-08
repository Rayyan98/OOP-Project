#pragma once
#include "Projectile.h"

class ProjectileFactory
{
public:
    //Factory
    static Projectile* createProjectile(int, Point, bool);
};

