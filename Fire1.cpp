#include "Fire1.h"

enum{stance, crouch, guard, crouchGuard, jump, crouchJab, shortKick,
     strongJab, walkForward, walkBackward, crouchKick, crouchTurn,jumpJab,
     jumpKick,crouchKick1,combo1,combo2, getHitCrouch, getHitStandingHigh,
     getHitStandingLow, Fire1, Fire2, numElements};


Fire1::Fire1()
{

}

Fire1::~Fire1()
{

}

Fire1::Fire1(Point position, bool defaultOrientation) : Projectile(position, defaultOrientation)
{
    this->velocity = Point(0,0);
    this->damage = 45;

    allSprites = new Sprite*[10];
    Point hurtBox0[] = {Point(0,13), Point(15,29), Point(-700,-700)};
    Point hurtBox1[] = {Point(177,12), Point(205,29), Point(-700,-700)};
    Point hurtBox2[] = {Point(353,0), Point(430,29), Point(-700,-700)};
    Point hurtBox3[] = {Point(529,0), Point(624,29), Point(-700,-700)};
    Point hurtBox4[] = {Point(0,72), Point(129,106), Point(-700,-700)};
    Point hurtBox5[] = {Point(160,72), Point(311,106), Point(-700,-700)};
    Point hurtBox6[] = {Point(341,66), Point(498,106), Point(-700,-700)};
    Point hurtBox7[] = {Point(516,67), Point(681,106), Point(-700,-700)};
    Point hurtBox8[] = {Point(707,66), Point(874,106), Point(-700,-700)};
    Point hurtBox9[] = {Point(884,64), Point(1052,106), Point(-700,-700)};
    Point hurtBox10[] = {Point(0,164), Point(126,181), Point(-700,-700)};
    Point hurtBox11[] = {Point(187,166), Point(304,181), Point(-700,-700)};
    Point hurtBox12[] = {Point(376,159), Point(488,181), Point(-700,-700)};
    Point hurtBox13[] = {Point(556,160), Point(670,181), Point(-700,-700)};
    Point hurtBox14[] = {Point(755,158), Point(847,181), Point(-700,-700)};
    Point hurtBox15[] = {Point(977,156), Point(1019,181), Point(-700,-700)};


    allSprites[0] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(0,13), Point(15,29),
                               Point(0,29),0,0,hurtBox0,0);
    allSprites[1] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(177,12), Point(205,29),
                               Point(176,29),0,0,hurtBox1,0);
    allSprites[2] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(353,0), Point(430,29),
                               Point(353,29),0,0,hurtBox2,0);
    allSprites[3] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(529,0), Point(624,29),
                               Point(529,29),0,0,hurtBox3,0);
    allSprites[4] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(0,72), Point(129,106),
                               Point(0,106),0,0,hurtBox4,0);
    allSprites[5] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(160,72), Point(311,106),
                               Point(160,106),0,0,hurtBox5,0);
    allSprites[6] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(341,66), Point(498,106),
                               Point(341,106),0,0,hurtBox6,0);
    allSprites[7] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(516,67), Point(681,106),
                               Point(516,106),0,0,hurtBox7,0);
    allSprites[8] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(707,66), Point(874,106),
                               Point(707,106),0,0,hurtBox8,0);
    allSprites[9] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(884,64), Point(1052,106),
                               Point(884,106),0,0,hurtBox9,0);
    allSprites[10] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(0,164), Point(126,181),
                               Point(0,181),0,0,hurtBox10,0);
    allSprites[11] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(187,166), Point(304,181),
                               Point(187,181),0,0,hurtBox11,0);
    allSprites[12] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(376,159), Point(488,181),
                               Point(376,181),0,0,hurtBox12,0);
    allSprites[13] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(556,160), Point(670,181),
                               Point(556,181),0,0,hurtBox13,0);
    allSprites[14] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(755,158), Point(847,181),
                               Point(755,181),0,0,hurtBox14,0);
    allSprites[15] = new Sprite(Global::GaneshGaitondeAnimations[Fire2], Point(977,156), Point(1019,181),
                               Point(977,181),0,0,hurtBox15,0);
}

void Fire1::UpdateSprite()
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

void Fire1::Creation()
{
    spread = 4;
    cap = 16;
    current = -1;
}

void Fire1::HandleHit(bool hit)
{
    if(hit == true)
    {
        this->hasDamaged = true;

    }
}

void Fire1::Render(SDL_Renderer* gRenderer)
{
    nextSprite->Render(gRenderer);
}

