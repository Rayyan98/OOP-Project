#pragma once
#include <SDL.h>
#include "TextButton.h"
#include "Screen.h"
#include <SDL_Mixer.h>
#include "ScreenFactory.h"

class MainMenu : public Screen
{
private:
    TextButton** buttons;
    TextButton* title;
    int currentButton;
    int buttonsCount;
    Mix_Music* bgMusic;

    void ProcedureOnQuit();
    void ProcedureOnCampaign();
    void ProcedureOnContinue();
    void ProcedureOnPvsP();
    void ProcedureOnSettings();

    MainMenu();
public:
    ~MainMenu();
    void RecieveInput(Uint32, SDL_Keycode&);
    void Render(SDL_Renderer*);
    Screen* GetNextScreen();
    void PlayMusic();

    friend ScreenFactory;
};
