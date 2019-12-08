#include "MainMenu.h"
#include "Global.h"
#include "TextButton.h"
#include "Point.h"
#include "floatAnchor.h"
#include <SDL_mixer.h>
#include "ScreenFactory.h"
#include <fstream>

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};


MainMenu::MainMenu()
{
    if (Global:: musicOnOff == true)
    {
        PlayMusic();
    }

    this->currentButton = -1;
    this->backGround = Global::mainMenuTexture;
    SDL_QueryTexture(this->backGround, 0, 0, &((this->backGroundRect).w), &(this->backGroundRect).h);
    this->backGroundRect.w = Global::CorrectWidth(backGroundRect.w, backGroundRect.h, Global::SCREEN_HEIGHT);
    this->backGroundRect.h = Global::SCREEN_HEIGHT;
    Point tempPoint = Global::CorrectedPos(floatAnchor(1,1).superImpose(backGroundRect.w, backGroundRect.h),
                                           Point(Global::SCREEN_WIDTH, Global::SCREEN_HEIGHT));
    this->backGroundRect.x = tempPoint.x;
    this->backGroundRect.y = tempPoint.y;
    this->title = new TextButton(string("Lyari Gang Wars"),
                                 Point(620 * Global::SCREEN_WIDTH / 640 ,10 * Global::SCREEN_HEIGHT / 480),
                                 60 * Global::SCREEN_HEIGHT / 480, 0, string("black"),
                                 string("null"), floatAnchor(1,0));

    tempPoint.x = 620 * Global::SCREEN_WIDTH / 640;
    tempPoint.y = 250 * Global::SCREEN_HEIGHT / 480;
    int diff = 60 * Global::SCREEN_HEIGHT / 480;
    int dH = 40 * Global::SCREEN_HEIGHT / 480;
    int sH = 52 * Global::SCREEN_HEIGHT / 480;
//    TextButton* Campaign = new TextButton(string("Campaign"), tempPoint, dH, sH, string("black"),
//                                 string("gold"), floatAnchor(1,0.5));
//    tempPoint.y += diff;
    TextButton* Continue = new TextButton(string("Continue"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(1,0.5));
//    tempPoint.y += diff;
    tempPoint.y += diff;
    TextButton* PvsP = new TextButton(string("start"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(1,0.5));
    tempPoint.y += diff;
    TextButton* Settings = new TextButton(string("Settings"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(1,0.5));
    tempPoint.y += diff;
    TextButton* Exit = new TextButton(string("Exit"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(1,0.5));

    this->buttonsCount = 4;
    this->buttons = new TextButton*[buttonsCount];
//    buttons[0] = Campaign;
    buttons[0] = Continue;
    buttons[1] = PvsP;
    buttons[2] = Settings;
    buttons[3] = Exit;
}

void MainMenu::Render(SDL_Renderer* gRenderer)
{
    if(overlyingScreen != 0)
    {
        if(overlyingScreen->quit == true)
        {
            delete overlyingScreen;
            overlyingScreen = 0;
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
}

MainMenu::~MainMenu()
{
    delete [] this->buttons;
    delete this->title;
}

Screen* MainMenu::GetNextScreen()
{
    return nextScreen;
}

void MainMenu::RecieveInput(Uint32 type, SDL_Keycode& key)
{
    if (overlyingScreen != 0)
    {
        overlyingScreen->RecieveInput(type, key);
    }
    else
    {
        if(type == SDL_KEYDOWN)
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
                    if(currentButton == 3)
                    {
                        ProcedureOnQuit();
                    }
//                    else if(currentButton == 0)
//                    {
//                        ProcedureOnCampaign();
//                    }
                    else if(currentButton == 1)
                    {
                        ProcedureOnPvsP();
                    }
                    else if(currentButton == 0)
                    {
                        ProcedureOnContinue();
                    }
                    else if(currentButton == 2)
                    {
                        ProcedureOnSettings();
                    }
            }
        }
    }
}

void MainMenu::ProcedureOnQuit()
{
//    this->ifNextScreen = true;
//    nextScreen = 0;
    this->quit = true;
}

void MainMenu::ProcedureOnCampaign()
{
    this->ifNextScreen = true;
    this->nextScreen = ScreenFactory::createScreen(screenCharacterSelect ,0,0,0,0,0);
}

void MainMenu::ProcedureOnContinue()
{
    ifstream f;
    f.open("save.txt");
    if(!f.is_open())
    {
        buttons[0]->ChangeWord("No Save");
        return;
    }
    int a;
    int p1;
    int p2;
    int bg;
    f >> a;
    char dump;
    if(a == 0)
    {
        buttons[0]->ChangeWord("No Save Found");
    }
    else
    {
        f >> dump;
        ifNextScreen = true;
        string t;
        string t2;
        bool booooool;
        f >> booooool;
        if(!booooool)
        {
            Mix_HaltMusic();
        }
        f >> dump;
        f >> dump;
        while (dump != '|')
        {
            t2 = t2+dump;
            f >> dump;
        }
        Global::musicOnOff = booooool;
        Global::volume = stoi(t2);
//        cout << dump;
        f >> bg;
//        cout << bg;
        f >> dump;
//        cout << dump;
        f >> p1;
//        cout << p1;
        f >> dump;
//        cout << dump;
//        int i = 0;
//        cout << "----------------------------------" << endl;
        f >> p2;
        f >> dump;
        nextScreen = ScreenFactory::createScreen(screenArena, bg,0,p1,p2,1);
        nextScreen->ReadFromFile(f);
    }
}


void MainMenu::ProcedureOnPvsP()
{
    this->ifNextScreen = true;
    this->nextScreen = ScreenFactory::createScreen(screenCharacterSelect,0,0,0,0,1);
}

void MainMenu::ProcedureOnSettings()
{
//    cout << "Procedure on Settings called";
    this->overlyingScreen = ScreenFactory::createScreen(screenSettings, 0,this,0,0,0);
}

void MainMenu:: PlayMusic()
{
    this->bgMusic = Global::mainMenuMusic;
    Global::PlayMusic(this->bgMusic);
    Mix_VolumeMusic(Global::volume);
}
