#include "Hadouken.h"
#include "Global.h"

enum{stance, crouch, guard, crouchGuard, jump, crouchJab, shortKick,
     strongJab, walkForward, walkBackward, crouchKick, crouchTurn, combo1,jumpJab,jumpKick,crouchKick1,combo2,
     getHitCrouch, getHitStandingHigh,
     getHitStandingLow, hCreation, hDestruction,numElements};

Hadouken::Hadouken(Point position, bool orientation) : Projectile(position, orientation)
{
    int a[] = {1,-1};
    allSprites = new Sprite*[8];
    Point s1[] = {Point(22,2),Point(52,28),Point(-700,-700)};
    Point s2[] = {Point(78,3),Point(102,28),Point(-700,-700)};

    allSprites[0] = new Sprite(Global::TrivediBabuAnimations[hCreation], Point(0,0), Point(60,32),
                               Point(44,15), 0,0,s1,0);
    allSprites[1] = new Sprite(Global::TrivediBabuAnimations[hCreation], Point(60,0), Point(107,32),
                               Point(94,15), 0,0,s2,0);
    allSprites[2] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(0,0), Point(47,63),
                               Point(31,30), 0,0,0,0);
    allSprites[3] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(47,0), Point(94,63),
                               Point(77,30), 0,0,0,0);
    allSprites[4] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(94,0), Point(152,63),
                               Point(129,30), 0,0,0,0);
    allSprites[5] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(152,0), Point(216,63),
                               Point(195,30), 0,0,0,0);
    allSprites[6] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(216,0), Point(284,63),
                               Point(264,30), 0,0,0,0);
    allSprites[7] = new Sprite(Global::TrivediBabuAnimations[hDestruction], Point(284,0), Point(316,63),
                               Point(331,30), 0,0,0,0);

    velocity = Point(30*a[orientation],0);
    damage = 45;
}

void Hadouken::UpdateSprite()
{
    if(nextSprite == 0)
    {
        Creation();
    }

    current ++;
    if(current / spread >= cap)
    {
        if(current/spread == 2)
        {
            current--;
        }
        else
        {
            status = false;
        }
    }

    if(status)
    {
        position.x += velocity.x;
        nextSprite = allSprites[current / spread];
        nextSprite->UpdateSprite(position, defaultOrientation);
    }
}

void Hadouken::Creation()
{
    cap = 2;
    current = -1;
    spread = 16 * Global::dF;
}

void Hadouken::HandleHit(bool hit)
{
//    cout << " jasdadf--------------------------------------" << endl;
    hasDamaged = true;
    velocity = Point(0,0);
    cap = 8;
    spread = 8 * Global::dF;
}

Hadouken::~Hadouken()
{
    delete allSprites;

}

void Hadouken::Render(SDL_Renderer* gRenderer)
{
//    cout << cap << " " << current << " " << spread << endl;
    nextSprite->Render(gRenderer);
}
