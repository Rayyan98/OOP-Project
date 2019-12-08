#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include "Screen.h"
#include <SDL.h>
#include "TextButton.h"
#include <SDL_mixer.h>
#include "ScreenFactory.h"

class SettingsScreen : public Screen
{
        SettingsScreen(Screen*);
    public:
        ~SettingsScreen();
        void Render(SDL_Renderer*);
        void RecieveInput(Uint32,SDL_Keycode&);
        Screen* GetNextScreen();

    private:
        void ProcedureOnControls();
        void ProcedureOnCredits();

        TextButton** buttons;
        TextButton* title;
        int currentButton;
        int buttonsCount;
        void ToggleMusicOnOff();
        void ProcedureOnQuit();
        Mix_Music* bgMusic;
        Screen* prevScreen;
        string music;

    friend ScreenFactory;
};

#endif // SETTINGSSCREEN_H
