#include "SettingsScreen.h"
#include "SDL_mixer.h"
#include "Global.h"
#include "TextButton.h"
#include "Point.h"
#include "floatAnchor.h"

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

SettingsScreen::SettingsScreen(Screen* prev)
{
    this->prevScreen = prev;
    this->quit = false;
    this->currentButton = -1;
    this->backGround = Global::mainMenuTexture;
    SDL_QueryTexture(this->backGround, 0, 0, &((this->backGroundRect).w), &(this->backGroundRect).h);
    this->backGroundRect.w = Global::CorrectWidth(backGroundRect.w, backGroundRect.h, Global::SCREEN_HEIGHT);
    this->backGroundRect.h = Global::SCREEN_HEIGHT;
    Point tempPoint = Global::CorrectedPos(floatAnchor(1,1).superImpose(backGroundRect.w, backGroundRect.h),
                                           Point(Global::SCREEN_WIDTH, Global::SCREEN_HEIGHT));
    this->backGroundRect.x = tempPoint.x;
    this->backGroundRect.y = tempPoint.y;
    this->title = new TextButton(string("Settings"),
                                 Point(Global::SCREEN_WIDTH / 2 ,Global::SCREEN_HEIGHT / 6),
                                 60 * Global::SCREEN_HEIGHT / 480, 0, string("black"),
                                 string("null"), floatAnchor(0.5,0.5));

    tempPoint.x = (Global::SCREEN_WIDTH / 2);
    tempPoint.y = (Global::SCREEN_HEIGHT / 3);
    int diff = 60 * Global::SCREEN_HEIGHT / 480;
    int dH = 40 * Global::SCREEN_HEIGHT / 480;
    int sH = 52 * Global::SCREEN_HEIGHT / 480;
    //dh = 40
    //sh = 52
    if (Global::musicOnOff == true)
    {
        this->music = "ON";
    }
    else
    {
        this->music = "OFF";
    }
    TextButton* ToggleMusic = new TextButton(string("Toggle Music ")+music, tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));
    tempPoint.y += diff;
    string v = "Volume "+to_string(Global:: volume);
    TextButton* Volume = new TextButton(v, tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));
    tempPoint.y += diff;
    TextButton* Credits = new TextButton(string("Credits"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));

    tempPoint.y += diff;
    TextButton* Controls = new TextButton(string("Controls"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));

    tempPoint.y += diff;
    TextButton* Back = new TextButton(string("Back"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));
    this->buttonsCount = 5;
    this->buttons = new TextButton*[buttonsCount];
    buttons[0] = ToggleMusic;
    buttons[1] = Volume;
    buttons[2] = Credits;
    buttons[3] = Controls;
    buttons[4] = Back;
}

void SettingsScreen:: Render(SDL_Renderer* gRenderer)
{

    if(overlyingScreen != 0)
    {
        if(overlyingScreen->quit == true)
        {
            delete overlyingScreen;
            overlyingScreen = 0;
            if (Global::musicOnOff == true)
            {
                prevScreen->PlayMusic();
                Mix_VolumeMusic(Global::volume);
            }
//            cout << "OverlyingScreen->quit != true"<<endl;
        }
        else
        {
            overlyingScreen->Render(gRenderer);
//            cout << "OverlyingScreen render function called"<<endl;
        }
    }
    else
    {
        SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
        title->Render(gRenderer);
        for(int i = 0; i < buttonsCount; i++)
        {
            buttons[i]->Render(gRenderer, i == this->currentButton);
        }
    }
//    cout << "Settings screen render function called" << endl;
}

void SettingsScreen::ProcedureOnControls()
{
    this->overlyingScreen = ScreenFactory::createScreen(screenControls,0,0,0,0,0);
}

void SettingsScreen::ProcedureOnCredits()
{
    this->overlyingScreen = ScreenFactory::createScreen(screenCredits,0,0,0,0,0);
}



SettingsScreen::~SettingsScreen()
{
    delete [] this->buttons;
    delete this->title;
}

void SettingsScreen:: RecieveInput(Uint32 type,SDL_Keycode& key)
{
    if (overlyingScreen != 0)
    {
        overlyingScreen->RecieveInput(type,key);
    }
    else
    {
        if (type == SDL_KEYDOWN)
        {
            switch (key)
            {
                case SDLK_ESCAPE:
                    ProcedureOnQuit();
                    break;
                case SDLK_DOWN:

                    if(this->currentButton < this->buttonsCount - 1)
                    {
                        this->currentButton++;
                    }
                    else
                    {
                        this->currentButton = 0;
                    }
                    break;
                case SDLK_UP:
                    if(this->currentButton == -1)
                    {
                        this->currentButton = this->buttonsCount - 1;
                    }
                    else if(this->currentButton > 0)
                    {
                        this->currentButton--;
                    }
                    else
                    {
                        this->currentButton = this->buttonsCount - 1;
                    }
                    break;
                case SDLK_RETURN:
                    if(currentButton == 0)
                    {
                        ToggleMusicOnOff();
                    }
                    else if(currentButton == 1)
                    {

                    }
                    else if(currentButton == 2)
                    {
                        ProcedureOnCredits();
                    }
                    else if(currentButton == 3)
                    {
                        ProcedureOnControls();
                    }
                    else if(currentButton == 4)
                    {
                        ProcedureOnQuit();
                    }
                    break;
                case SDLK_LEFT:
                    if (currentButton == 1)
                    {
                        if (Global::volume > 0)
                        {
                            Global::volume = Global::volume - 5;
                            Mix_VolumeMusic(Global::volume);
                            buttons[1]->ChangeWord("Volume " + to_string(Global::volume));
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    if (currentButton == 1)
                    {
                        if (Global::volume < 100)
                        {
                            Global::volume = Global::volume + 5;
                            Mix_VolumeMusic(Global::volume);
                            buttons[1]->ChangeWord("Volume " + to_string(Global::volume));
                        }
                    }
                    break;
            }
        }
    }
}

void SettingsScreen:: ProcedureOnQuit()
{
    this->quit = true;
}



Screen* SettingsScreen:: GetNextScreen()
{
    return this->nextScreen;
}

void SettingsScreen:: ToggleMusicOnOff()
{
    if (Mix_PlayingMusic() != 0)
    {
        Mix_HaltMusic();
        Global::musicOnOff = false;
        this->music = "OFF";
        buttons[0]->ChangeWord(string("Toggle Music ")+music);
    }
    else if (Mix_PlayingMusic() == 0)
    {
        prevScreen->PlayMusic();
        Mix_VolumeMusic(Global::volume);
        Global::musicOnOff = true;
        this->music = "ON";
        buttons[0]->ChangeWord(string("Toggle Music ")+music);
    }
}
