#pragma once
#include <SDL.h>
#include "Screen.h"
#include "PortraitButton.h"
#include "Figure.h"
#include "TextButton.h"
#include "ScreenFactory.h"

class CharacterSelect : public Screen
{
    TextButton* heading;
    bool playerTwo;
    int selectInd;
    int selectIndP2;
    int numOfPortraits;
    bool choosenP1;
    bool choosenP2;
    PortraitButton** portraits;
    Figure** smallFigures;
    Figure** bigFigures;
    TextButton** names;
    PortraitButton** charIcons;
    Figure* NameBackGround;
    Point figurePivotLeft;
    Point figurePivotRight;

    void ProcedureOnQuit();
    void ProcedureOnSelect();

    CharacterSelect(bool playerTwo = 0);
public:
    ~CharacterSelect();
    void Render(SDL_Renderer*);
    Screen* GetNextScreen();
    void RecieveInput(Uint32, SDL_Keycode&);

    friend ScreenFactory;
};
