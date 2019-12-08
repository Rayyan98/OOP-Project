#include "PauseScreen.h"
#include "ScreenFactory.h"
#include <fstream>

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

PauseScreen::PauseScreen(Screen* prev, bool p2, int char1num, int char2num)
{
    this->char1num = char1num;
    this->char2num = char2num;
    this->player2 = p2;
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
    this->title = new TextButton(string("Paused"),
                                 Point(Global::SCREEN_WIDTH / 2 ,Global::SCREEN_HEIGHT / 6),
                                 60 * Global::SCREEN_HEIGHT / 480, 0, string("black"),
                                 string("null"), floatAnchor(0.5,0.5));

    tempPoint.x = (Global::SCREEN_WIDTH / 2);
    tempPoint.y = (Global::SCREEN_HEIGHT / 3);
    int diff = 60 * Global::SCREEN_HEIGHT / 480;
    int dH = 30 * Global::SCREEN_HEIGHT / 480;
    int sH = 42 * Global::SCREEN_HEIGHT / 480;
    //dh = 40
    //sh = 52
    TextButton* Resume = new TextButton(string("Resume"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));
    tempPoint.y += diff;
    TextButton* CharacterSelect = new TextButton(string("Character select"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));

    tempPoint.y += diff;
    TextButton* mainmenu = new TextButton(string("Return to Main menu"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));

    tempPoint.y += diff;
    TextButton* save = new TextButton(string("Save"), tempPoint, dH, sH, string("black"), string("gold")
                                      ,floatAnchor(0.5,0.5));
    tempPoint.y += diff;
    TextButton* settings = new TextButton(string("Settings"), tempPoint, dH, sH, string("black"),
                                 string("gold"), floatAnchor(0.5,0.5));

    this->buttonsCount = 5;
    this->buttons = new TextButton*[buttonsCount];
    buttons[0] = Resume;
    buttons[1] = CharacterSelect;
//    buttons[2] = backGroundSelect;
    buttons[2] = mainmenu;
    buttons[4] = settings;
    buttons[3] = save;
}

PauseScreen::~PauseScreen()
{
    delete[] this->buttons;
    delete this->title;
//    delete this->char1;
}

Screen* PauseScreen:: GetNextScreen()
{
    return nextScreen;
}


void PauseScreen:: Render(SDL_Renderer* gRenderer)
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

void PauseScreen:: RecieveInput(Uint32 type,SDL_Keycode& key)
{
    if (overlyingScreen != 0)
    {
        overlyingScreen->RecieveInput(type, key);
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
                        ProcedureOnQuit();
                    }
                    else if(currentButton == 1)
                    {
                        ProcedureOnCharSelect();
                    }
                    else if(currentButton == 2)
                    {
                        ProcedureOnMainMenu();
                    }
                    else if(currentButton == 4)
                    {
                        ProcedureOnSettings();
                    }
                    else if(currentButton == 3)
                    {
                        ProcedureOnSave();
                    }
                    break;
            }
        }
    }
}

void PauseScreen:: ProcedureOnQuit()
{
    this->quit = true;
    ifNextScreen = false;
}

void PauseScreen:: ProcedureOnCharSelect()
{
    this->ifNextScreen = true;
    this->nextScreen = ScreenFactory::createScreen(screenCharacterSelect, 0,0,0,0,player2);
    this->quit = true;
}

void PauseScreen:: ProcedureOnMainMenu()
{
    this->ifNextScreen = true;
    this->nextScreen = ScreenFactory::createScreen(screenMainMenu,0,0,0,0,0);
    this->quit = true;
}

void PauseScreen:: ProcedureOnSettings()
{
    this->overlyingScreen = ScreenFactory::createScreen(screenSettings, 0,this,0,0,0);
}

void PauseScreen:: PlayMusic()
{
    prevScreen->PlayMusic();
}

void PauseScreen::ProcedureOnSave()
{
    cout << "procedure on save called" << endl;
    WriteToSaveFile();
}

void PauseScreen::WriteToSaveFile()
{
    ofstream fil;
    fil.open("save.txt");
    if(!fil.is_open())
    {
        cout << "failed to open save file " << endl;
    }
    prevScreen->SaveToFile(fil);

    fil.close();
    buttons[3]->ChangeWord("SAVED");
}
