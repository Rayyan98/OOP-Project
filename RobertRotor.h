#pragma once
#include "Point.h"
#include "Characters.h"
#include <SDL.h>
#include "CharacterFactory.h"
#include "Arena.h"


class RobertRotor : public Character
{
    int cCombo;
    RobertRotor();
    RobertRotor(Point, bool, bool);
    ~RobertRotor();
    Projectile* UpdateSprite();
    void RecieveInput(Uint32, int);
    void Render(SDL_Renderer*);
    bool HandleHit(int,int, int);

    void Victory();
    void KnockDown();

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
    void ComboFierce();
    void ComboChain();


    void GetHitCrouch(int);
    void GetHitStandingLow(int);
    void GetHitStandingHigh(int);
//    bool HandleHit(int,int);

    /*
    void GetHitCrouch(int);
    void GetHitStandingLow(int);
    void GetHitStandingHigh(int);
    bool HandleHit(int,int);
    */
    friend CharacterFactory;
    friend Arena;
};

