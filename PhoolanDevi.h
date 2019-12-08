#pragma once
#include "Point.h"
#include "Characters.h"
#include <SDL.h>
#include "CharacterFactory.h"
#include "Arena.h"

/*

    LoadImage(PhoolanDeviAnimations[getHitCrouch], "Sprites\\Karin\\CrouchHit.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[getHitStandingHigh], "Sprites\\Karin\\HeadHit.png", gRenderer);
    LoadImage(PhoolanDeviAnimations[getHitStandingLow], "Sprites\\Karin\\BodyHit.png", gRenderer);

*/
class PhoolanDevi : public Character
{
    int cCombo;
    int crouchKick1Status;

    PhoolanDevi();
    PhoolanDevi(Point, bool, bool);
        void Victory();
    void KnockDown();
    ~PhoolanDevi();
    Projectile* UpdateSprite();
    void RecieveInput(Uint32, int);
    void Render(SDL_Renderer*);
    bool HandleHit(int,int);

    void Stance();
    void Crouch();
    void Crouching();
    void Guarding();
    void CrouchGuarding();

    void WalkForward();
    void WalkBackward(bool justIn = false);
    void Jump();
    void CrouckKick();
    void CrouchLightJab();
    void ShortKick();
    void StrongJab();
    void CrouchTurn();
    void Turn();
    void JumpFromStand();
    void Jumping();
    void JumpJab();
    void JumpKick();
    void CrouchKick1();
    void Combo1();
    void Combo2();


    void GetHitCrouch(int);
    void GetHitStandingLow(int);
    void GetHitStandingHigh(int);
    bool HandleHit(int,int,int);

    friend CharacterFactory;
    friend Arena;
};
