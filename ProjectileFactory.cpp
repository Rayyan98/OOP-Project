#include "ProjectileFactory.h"
#include "Hadouken.h"
#include "Fire.h"
#include "Fire1.h"

enum{projectileHadouken, projectileFire, projectileFire1};

Projectile* ProjectileFactory::createProjectile(int type, Point pos, bool ori)
{
    if(type == projectileHadouken)
    {
        return new Hadouken(pos, ori);
    }
    else if(type == projectileFire)
    {
        return new Fire(pos, ori);
    }
    else if(type == projectileFire1)
    {
        return new Fire1(pos, ori);
    }
}
