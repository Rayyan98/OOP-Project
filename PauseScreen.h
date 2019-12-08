#pragma once
#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H
#include <SDL.h>
#include "TextButton.h"
#include "Screen.h"
#include <SDL_Mixer.h>
#include "Global.h"
#include "Point.h"
#include "floatAnchor.h"
#include <SDL_mixer.h>
#include "Characters.h"
#include "ScreenFactory.h"

class PauseScreen : public Screen
{
    public:
        ~PauseScreen();
        void Render(SDL_Renderer*);
        void RecieveInput(Uint32,SDL_Keycode&);
        Screen* GetNextScreen();

    private:
        void WriteToSaveFile();
        int char1num;
        int char2num;
        PauseScreen(Screen*, bool, int, int);
        TextButton** buttons;
        TextButton* title;
        int currentButton;
        int buttonsCount;
        void ProcedureOnQuit();
        void ProcedureOnCharSelect();
        void ProcedureOnMainMenu();
        void ProcedureOnSettings();
        void PlayMusic();
        Screen* prevScreen;
        Character* char1;
        Character* char2;
        bool player2;
        void ProcedureOnSave();

        friend ScreenFactory;
};

#endif // PAUSESCREEN_H
