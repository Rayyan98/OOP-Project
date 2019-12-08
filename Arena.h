#pragma once
#include "Screen.h"
#include "Projectile.h"
#include "LinkedList.h"
#include "TextButton.h"
#include "PortraitButton.h"
#include "ScreenFactory.h"

class Arena : public Screen
{
    bool starting;
    bool ending;
    bool playerTwo;
    Character* char1;
    Character* char2;
    int char1num;
    int char2num;
    linkedList<Projectile> projectiles;
    TextButton* message;
    TextButton* name1;
    TextButton* name2;
    PortraitButton* pic1;
    PortraitButton* pic2;
    bool ifLoaded;
    int bg;


    int endCount;
    void SaveToFile(ofstream&);
    Arena();
    Arena(int, bool,int,int);
    void ProcedureOnQuitToCharSelect();
    void ProcedureOnQuitToMain();
    void ProcedureOnQuitToPause();
public:
    static int baseLine;
    static float gravity;
    void PlayMusic();
    ~Arena();
    void Render(SDL_Renderer*);
    Screen* GetNextScreen();
    void ReadFromFile(ifstream&);
    void RecieveInput(Uint32, SDL_Keycode&);

    friend ScreenFactory;
};
