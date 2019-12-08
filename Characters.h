#pragma once
#include "Point.h"
#include <SDL.h>
#include "Sprite.h"
#include "Projectile.h"
#include "Bars.h"

enum{sNormal, sCrouching, sJumping};
enum{mNone, mForward, mBackward};
enum{bNone, bLow, bHigh};
enum{iUp, iDown, iRight, iLeft, iSemiColon, iSpace, iKeyI, iKeyK, iKeyL};

class Character
{
protected:
    int health;
    int super;
    int countToTurn;
    Bars* healthBar;
    Bars* superBar;
    int movement;
    int negativeFrames;
    int blockType;
    bool ifAcceptingInput;
    Point position;
    float yVelocity;
    int state;
    bool alive;
    bool orientation;
    int currentAnimation;
    int currentAnimationInd;
    int currentAnimationCap;
    int spread;
    bool movedOnJump;
    int damage;
    bool hasDamaged;

    Sprite*** allAnimations;
    Sprite* nextSprite;

    void IncreaseSuper(int);
    void DecreaseHealth(int);

    Point oldPosition;

    Character();
    Character(Point, bool, bool);
public:
    void WriteToFile(ofstream&);
    void ReadFromFile(ifstream&);
    virtual ~Character();
    virtual void RecieveInput(Uint32, int) = 0;
    virtual Projectile* UpdateSprite() = 0;
    virtual void Render(SDL_Renderer*) = 0;

    virtual bool HandleHit(int, int, int) = 0;
    bool HasDamaged();
    int GetDamage();
    void PushBack(int hit = 0);
    virtual void KnockDown() = 0;
    virtual void Victory() = 0;

    bool GetStatus();
    Sprite* GetNextSprite();
};

