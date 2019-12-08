#pragma once
#include "Screen.h"
#include "PortraitButton.h"
#include "Figure.h"
#include "Point.h"
#include "Characters.h"
#include "ScreenFactory.h"

class BackGroundSelect : public Screen
{
    int selectInd;
    int numOfBackgrounds;
    bool player2;
    PortraitButton** stage_Portraits;
    Figure** stage;

    Point figurePivotLeft;
    Point figurePivotRight;
    int p1_choice;
    int p2_choice;

    BackGroundSelect(bool,int,int);
    void ProcedureOnQuit();
    void ProcedureOnSelect();
public:
    ~BackGroundSelect();
    void Render(SDL_Renderer*);
    void RecieveInput(Uint32, SDL_Keycode&);
    Screen* GetNextScreen();

    friend ScreenFactory;
};
