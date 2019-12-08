#pragma once
#include "Characters.h"

class CharacterFactory
{
public:
    //Factory Method
    static Character* createCharacter(int, Point, bool, bool);
};
