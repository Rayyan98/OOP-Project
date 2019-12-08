#include "Fire.h"

enum{stance, crouch, guard, crouchGuard, jump, crouchJab, shortKick,
     strongJab, walkForward, walkBackward, crouchKick, crouchTurn,jumpJab,
     jumpKick,crouchKick1,combo1,combo2, getHitCrouch, getHitStandingHigh,
     getHitStandingLow, Fire1, Fire2, numElements};


Fire::Fire()
{

}

Fire::~Fire()
{

}

Fire::Fire(Point position, bool defaultOrientation) : Projectile(position, defaultOrientation)
{
    this->velocity = Point(0,0);
    this->damage = 25;

    allSprites = new Sprite*[10];
    Point hurtBox1[] = {Point(11,61), Point(44,88), Point(-700,-700)};
    Point hurtBox2[] = {Point(76,50), Point(123,89), Point(-700,-700)};
    Point hurtBox3[] = {Point(151,48), Point(217,93), Point(-700,-700)};
    Point hurtBox4[] = {Point(251,41), Point(321,90), Point(-700,-700)};
    Point hurtBox5[] = {Point(358,38), Point(421,90), Point(-700,-700)};
    Point hurtBox6[] = {Point(460,38), Point(520,93), Point(-700,-700)};
    Point hurtBox7[] = {Point(566,39), Point(618,93), Point(-700,-700)};

    allSprites[0] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(0,0), Point(51,99),
                               Point(0,79),0,0,hurtBox1,0);
    allSprites[1] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(51,0), Point(131,99),
                               Point(56,79),0,0,hurtBox2,0);
    allSprites[2] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(131,0), Point(231,99),
                               Point(133,79),0,0,hurtBox3,0);
    allSprites[3] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(231,0), Point(332,99),
                               Point(235,79),0,0,hurtBox4,0);
    allSprites[4] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(332,0), Point(434,99),
                               Point(337,79),0,0,hurtBox5,0);
    allSprites[5] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(434,0), Point(538,99),
                               Point(441,79),0,0,hurtBox6,0);
    allSprites[6] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(538,0), Point(635,99),
                               Point(543,79),0,0,hurtBox7,0);
    allSprites[7] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(635,0), Point(720,99),
                               Point(629,79),0,0,0,0);
    allSprites[8] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(720,0), Point(816,99),
                               Point(715,79),0,0,0,0);
    allSprites[9] = new Sprite(Global::GaneshGaitondeAnimations[Fire1], Point(816,0), Point(883,99),
                               Point(799,79),0,0,0,0);
}

void Fire::UpdateSprite()
{
    if(nextSprite == 0)
    {
        Creation();
    }

    current++;
    if(current/spread >= cap)
    {
        status = false;
    }
    else
    {
        nextSprite = allSprites[current/spread];
        nextSprite->UpdateSprite(position, defaultOrientation);
    }
}

void Fire::Creation()
{
    spread = 10;
    cap = 10;
    current = -1;
}

void Fire::HandleHit(bool hit)
{
    if(hit)
    {
        this->hasDamaged = true;
    }
}

void Fire::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
}

