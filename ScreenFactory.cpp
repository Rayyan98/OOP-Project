#pragma once
#include "ScreenFactory.h"
#include "MainMenu.h"
#include "CharacterSelect.h"
#include "BackGroundSelect.h"
#include "SettingsScreen.h"
#include "Arena.h"
#include "PauseScreen.h"
#include "Credits.h"
#include "Controls.h"

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

Screen* ScreenFactory::createScreen(int screenType, int bg, Screen* prev, int cha1, int char2, bool plyaer2)
{
    if(screenType == screenMainMenu)
    {
        return new MainMenu();
    }
    else if(screenType == screenCharacterSelect)
    {
        return new CharacterSelect(plyaer2);
    }
    else if(screenType == screenBackgroundSelect)
    {
        return new BackGroundSelect(plyaer2, cha1, char2);
    }
    else if(screenType == screenArena)
    {
        return new Arena(bg, plyaer2, cha1, char2);
    }
    else if(screenType == screenPause)
    {
        return new PauseScreen(prev, plyaer2, cha1, char2);
    }
    else if(screenType == screenSettings)
    {
        return new SettingsScreen(prev);
    }
    else if(screenType == screenControls)
    {

        return new Controls();
    }
    else if(screenType == screenCredits)
    {
        return new Credits();
    }
}
