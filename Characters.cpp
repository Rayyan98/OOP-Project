#include "Characters.h"
#include "BarFactory.h"
#include <fstream>

enum{barHealth, barCombo};

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(Point position, bool orientation, bool player2)
{
    healthBar = BarFactory::createBar(barHealth, player2);
    superBar = BarFactory::createBar(barCombo, player2);
    movedOnJump = false;
    health = 100;
    super = 0;
    this->position = position;
    this->orientation = orientation;
    state = sJumping;
    blockType = bNone;
    movement = mNone;
    countToTurn = -1;
    ifAcceptingInput = true;
    negativeFrames = 0;
    yVelocity = 0;
    alive = true;
}

Sprite* Character::GetNextSprite()
{
    return nextSprite;
}

void Character::IncreaseSuper(int value)
{
    super += value;
    if(super > 100)
    {
        super = 100;
    }
    superBar->increase(value);
}

void Character::DecreaseHealth(int value)
{
    health -= value;
    if(health < 0)
    {
        health = 0;
    }
    if(health <= 0)
    {
        alive = false;
    }
    healthBar->decreaseBy(value);
}

bool Character::HasDamaged()
{
    return hasDamaged;
}

int Character::GetDamage()
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

void Character::PushBack(int hit)
{
    if(hit == 0)
    {
        position = oldPosition;
        int a[] = {1,-1};
        position.x -= a[orientation] * 1;
        negativeFrames += 20;
    }
    else if(hit == 1)
    {
        hasDamaged = true;
        IncreaseSuper(10);
    }
    else if(hit == 2)
    {
        position = oldPosition;
        int a[] = {1,-1};
        position.x -= a[orientation] * 1;
    }
}

void Character::ReadFromFile(ifstream& f)
{
    char dump;
    string posX = "";
    string posY = "";
    string health = "";
    string super = "";
    string a[] = {posX, posY, health, super};
    for(int i = 0; i < 4; i++)
    {
        f >> dump;
        while(dump != '|')
        {
            a[i] = a[i] + dump;
            f >> dump;
        }
    }
    this->position.x = stoi(a[0]);
    this->position.y = stoi(a[1]);
    this->health = stoi(a[2]);
    this->super = stoi(a[3]);
    healthBar->giveValue(this->health);
    superBar->giveValue(this->super);
}

bool Character::GetStatus()
{
    return alive;
}

void Character::WriteToFile(ofstream& f)
{
    cout << "writing character to file" << endl;
    f << this->position.x << "|" << this->position.y << "|"
        << this->health << "|" << this->super;
}
