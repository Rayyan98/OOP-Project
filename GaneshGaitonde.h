#pragma once
#include "Point.h"
#include "Characters.h"
#include <SDL.h>
#include "CharacterFactory.h"
#include "Arena.h"


class GaneshGaitonde : public Character
{
    int cCombo;
    int crouchKick1Status;
    GaneshGaitonde();
    GaneshGaitonde(Point, bool, bool);
    ~GaneshGaitonde();
    Projectile* UpdateSprite();
    void RecieveInput(Uint32, int);
    void Render(SDL_Renderer*);

    void GetHitCrouch(int);
    void GetHitStandingLow(int);
    void GetHitStandingHigh(int);
    bool HandleHit(int,int, int);

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
    void Victory();
    void KnockDown();

    friend CharacterFactory;
    friend Arena;
};
