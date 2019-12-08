#include "CharacterFactory.h"
#include "GaneshGaitonde.h"
#include "TrivediBabu.h"
#include "PhoolanDevi.h"
#include "RobertRotor.h"

enum{characterGanesh, characterTrivedi, characterPhoolan, characterRobert};

Character* CharacterFactory::createCharacter(int charType, Point pos, bool orientation, bool player2)
{
    if(charType == characterGanesh)
    {
        return new GaneshGaitonde(pos, orientation, player2);
    }
    else if(charType == characterTrivedi)
    {
        return new TrivediBabu(pos, orientation, player2);
    }
    else if(charType == characterPhoolan)
    {
        return new PhoolanDevi(pos, orientation, player2);
    }
    else if(charType == characterRobert)
    {
        return new RobertRotor(pos, orientation, player2);
    }
    return 0;
}

