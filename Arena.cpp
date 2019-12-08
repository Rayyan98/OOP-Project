#include "Arena.h"
#include "Global.h"
#include "Collision Detection.h"
#include "CharacterFactory.h"
#include "ScreenFactory.h"

int Arena::baseLine = 410;

enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

enum{characterGanesh, characterTrivedi, characterPhoolan, characterRobert};

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

float Arena::gravity = 0.18/* * Global::dF*/;

void Arena::ReadFromFile(ifstream& f)
{
    char dump;
    char1->ReadFromFile(f);
    char2->ReadFromFile(f);
}

Arena::Arena()
{

}

Arena::Arena(int bgScreen, bool playerTwo, int player1, int player2)
{
    this->bg = bgScreen;
    ifLoaded = false;
    if (Global::musicOnOff == true)
    {
        PlayMusic();
    }
    char1num = player1;
    char2num = player2;
    starting = false;
    message = 0;
    ending = false;
    char1 = 0;
    char2 = 0;
    this->playerTwo = playerTwo;
    this->backGround = Global::backgrounds[bgScreen];
    SDL_QueryTexture(this->backGround, NULL, NULL, &(this->backGroundRect).w, &(this->backGroundRect).h);
    int tempH = Global::CorrectWidth((this->backGroundRect.w), (this->backGroundRect.h), Global::SCREEN_HEIGHT);
    this->backGroundRect.h = Global::SCREEN_HEIGHT;
    this->backGroundRect.w = tempH;
    floatAnchor tempAnchor(0.5, 0.5);
    Point temp = Global::CorrectedPos(tempAnchor.superImpose(this->backGroundRect.w, this->backGroundRect.h),
                                      Point(Global::SCREEN_WIDTH / 2, Global::SCREEN_HEIGHT / 2));
    this->backGroundRect.x = temp.x;
    this->backGroundRect.y = temp.y;


    if (player1 == 0)
    {
        char1 = CharacterFactory::createCharacter(characterGanesh, Point(100,200), 0,0);
        name1 = new TextButton(string("Ganesh Gaitonde"), Point(80,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic1 = new PortraitButton(Global::charIcons, Point(747,72), Point(895,238), Point(15,10),70, 0, floatAnchor(0,0));
    }
    else if (player1 == 1)
    {
        char1 = CharacterFactory::createCharacter(characterRobert, Point(100,200), 0,0);
        name1 = new TextButton(string("Robert Rotor"), Point(80,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic1 = new PortraitButton(Global::charIcons, Point(964,44), Point(1127,236), Point(15,10),70, 0, floatAnchor(0,0));
    }
    else if (player1 == 3)
    {
        char1 = CharacterFactory::createCharacter(characterPhoolan, Point(100,200), 0,0);
        name1 = new TextButton(string("Phoolan Devi"), Point(80,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic1 = new PortraitButton(Global::charIcons, Point(1433,55), Point(1598,238), Point(15,10),70, 0, floatAnchor(0,0));

    }
    else if (player1 == 4)
    {
        char1 = CharacterFactory::createCharacter(characterTrivedi, Point(100,200), 0,0);
        name1 = new TextButton(string("Trivedi Babu"), Point(80,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic1 = new PortraitButton(Global::charIcons, Point(1667,64), Point(1832,238), Point(13,10),70, 0, floatAnchor(0,0));

    }
    endCount = -1;
    if (player2 == 0)
    {
        char2 = CharacterFactory::createCharacter(characterGanesh, Point(540,200), 1,1);
        name2 = new TextButton(string("Ganesh Gaitonde"), Point(380,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic2 = new PortraitButton(Global::charIcons,Point(3546,71), Point(3696,238), Point(560,10),70,0, floatAnchor(0,0));
    }
    else if (player2 == 1)
    {
        char2 = CharacterFactory::createCharacter(characterRobert, Point(540,200), 1,1);
        name2 = new TextButton(string("Robert Rotor"), Point(420,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic2 = new PortraitButton(Global::charIcons,Point(3312,45), Point(3477,238), Point(560,10),70,0, floatAnchor(0,0));
    }
    else if (player2 == 3)
    {
        char2 = CharacterFactory::createCharacter(characterPhoolan, Point(540,200), 1,1);
        name2 = new TextButton(string("Phoolan Devi"), Point(428,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic2 = new PortraitButton(Global::charIcons,Point(2848,54), Point(3007,238), Point(560,10),70,0, floatAnchor(0,0));
    }
    else if (player2 == 4)
    {
        char2 = CharacterFactory::createCharacter(characterTrivedi, Point(540,200), 1,1);
        name2 = new TextButton(string("Trivedi Babu"), Point(425,55), 20, 0, string("gold"),string("null"), floatAnchor(0,0));
        pic2 = new PortraitButton(Global::charIcons,Point(2608,65), Point(2772,238), Point(560,10),70,0, floatAnchor(0,0));
    }
}

void Arena::Render(SDL_Renderer* gRenderer)
{
    if(ending == true)
    {
        if(endCount == -1)
        {
            endCount = 240;
        }
        if(endCount > 0)
        {
            message->Render(gRenderer, 1);
            endCount--;
        }
        if(endCount == 0)
        {
            ProcedureOnQuitToCharSelect();
        }
    }
    if(overlyingScreen != 0)
    {
        if(overlyingScreen->quit == true)
        {
            if(overlyingScreen->IfMoveToNextScreen())
            {
                this->nextScreen = overlyingScreen->GetNextScreen();
                this->ifNextScreen = true;
            }
            delete overlyingScreen;
            overlyingScreen = 0;
//            cout << " hello " << endl;
//            if (charSelect == true)
//            {
//                ProcedureOnQuitToCharSelect();
//            }
        }
        else
        {
            overlyingScreen->Render(gRenderer);
//            cout << "OverlyingScreen render function called"<<endl;
        }
    }
    else
    {
//        cout << " yes ";
        SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
        Projectile* tempP = 0;
        tempP = char1->UpdateSprite();
        if(tempP != 0)
        {
            projectiles.pushAtHead(tempP);
            tempP = 0;
        }
        if(char2 != 0)
        {
            tempP = char2->UpdateSprite();
            if(tempP != 0)
            {
                projectiles.pushAtHead(tempP);
                tempP = 0;
            }

            int typeHit = CollisionDetection::Check(char1->GetNextSprite(), char2->GetNextSprite());
            if(typeHit == cHultHigh)
            {
                if(!char1->HasDamaged())
                {
                    bool b = char2->HandleHit(cHultHigh, char1->GetDamage(), 16);
                    char1->PushBack(b);
                }
            }
            else if(typeHit == cHultLow)
            {
                if(!char1->HasDamaged())
                {
                    bool b = char2->HandleHit(cHultLow, char1->GetDamage(), 16);
                    char1->PushBack(b);
                }
            }
            if(typeHit == cLowHult)
            {
                if(!char2->HasDamaged())
                {
                    bool b = char1->HandleHit(cHultLow, char2->GetDamage(), 16);
                    char2->PushBack(b);
                }
            }
            if(typeHit == cHighHult)
            {
                if(!char2->HasDamaged())
                {

                    bool b = char1->HandleHit(cHultHigh, char2->GetDamage() , 16);
                    char2->PushBack(b);
                }
            }
            if(typeHit == cHultHult)
            {
                char2->HandleHit(cHultHult, 8 , 8);
                char1->HandleHit(cHultHult, 8, 8);
            }
            if(typeHit == cHighHigh)
            {
                char2->HandleHit(cHighHigh, 8 , 8);
                char1->HandleHit(cHighHigh, 8, 8);
            }
            if(typeHit == cHighLow)
            {
                char2->HandleHit(cHighLow, 8 , 8);
                char1->HandleHit(cHighLow, 8, 8);
            }
            if(typeHit == cLowHigh)
            {
                char2->HandleHit(cLowHigh, 8 , 8);
                char1->HandleHit(cLowHigh, 8, 8);
            }
            if(typeHit == cLowLow)
            {
                char2->HandleHit(cLowLow, 8 , 8);
                char1->HandleHit(cLowLow, 8, 8);
            }
        }

        projectiles.update();
        projectiles.checkCollissions(char1);
        projectiles.checkCollissions(char2);
        projectiles.clean();

        if(!char1->GetStatus() && !char2->GetStatus() && !starting && !ending)
        {
            char1->KnockDown();
            char2->KnockDown();
            ending = true;
            message = new TextButton(string("Draw") , Point(Global::SCREEN_WIDTH / 2, 200), 70, 94, string("gold"), string("red"),
                                     floatAnchor(0.5,0.5));
        }
        else if(!char1->GetStatus() && !starting && !ending)
        {
            char1->KnockDown();
            char2->Victory();
            ending = true;
            message = new TextButton(string("P2 Wins") , Point(Global::SCREEN_WIDTH / 2, 200), 70, 94, string("gold"), string("red"),
                                     floatAnchor(0.5,0.5));
        }
        else if(!char2->GetStatus() && !starting && !ending)
        {
            char1->Victory();
            char2->KnockDown();
            ending = true;
            message = new TextButton(string("P1 Wins") , Point(Global::SCREEN_WIDTH / 2, 200), 70, 94, string("gold"), string("red"),
                                     floatAnchor(0.5,0.5));
        }

        char1->Render(gRenderer);
        if(char2 != 0)
        {
            char2->Render(gRenderer);
        }
        projectiles.show(gRenderer);
        name1->Render(gRenderer, 0);
        name2->Render(gRenderer, 0);
        pic1->Render(gRenderer, 0);
        pic2->Render(gRenderer, 0);
        if(message != 0)
        {
            message->Render(gRenderer);
        }
    }
}

Screen* Arena::GetNextScreen()
{
    return this->nextScreen;
}

void Arena::RecieveInput(Uint32 type, SDL_Keycode& key)
{
    if (overlyingScreen != 0)
    {
        overlyingScreen->RecieveInput(type, key);
    }
    else
    {
        if(type == SDL_KEYDOWN || type == SDL_KEYUP)
        {
            switch(key)
            {
            case SDLK_ESCAPE:
                if(type == SDL_KEYDOWN && char1->GetStatus() && char2->GetStatus())
                {
                    ProcedureOnQuitToPause();
                }
                break;
            }
            if(char1 != 0  && !starting && !ending)
            {
                switch(key)
                {
                case SDLK_w:
                    char1->RecieveInput(type, iUp);
                    break;
                case SDLK_s:
                    char1->RecieveInput(type, iDown);
                    break;
                case SDLK_a:
                    char1->RecieveInput(type, iLeft);
                    break;
                case SDLK_d:
                    char1->RecieveInput(type, iRight);
                    break;
                case SDLK_g:
                    char1->RecieveInput(type, iKeyL);
                    break;
                case SDLK_h:
                    char1->RecieveInput(type, iSemiColon);
                    break;
                case SDLK_f:
                    char1->RecieveInput(type, iKeyK);
                    break;
                case SDLK_t:
                    char1->RecieveInput(type, iKeyI);
                    break;
                case SDLK_LSHIFT:
                    char1->RecieveInput(type, iSpace);
                    break;
                }
            }
            if(char2 != 0 && !starting && !ending)
            {
                switch(key)
                {
                case SDLK_UP:
                    char2->RecieveInput(type, iUp);
                    break;
                case SDLK_DOWN:
                    char2->RecieveInput(type, iDown);
                    break;
                case SDLK_LEFT:
                    char2->RecieveInput(type, iLeft);
                    break;
                case SDLK_RIGHT:
                    char2->RecieveInput(type, iRight);
                    break;
                case SDLK_l:
                    char2->RecieveInput(type, iKeyL);
                    break;
                case SDLK_SEMICOLON:
                    char2->RecieveInput(type, iSemiColon);
                    break;
                case SDLK_k:
                    char2->RecieveInput(type, iKeyK);
                    break;
                case SDLK_o:
                    char2->RecieveInput(type, iKeyI);
                    break;
                case SDLK_RSHIFT:
                    char2->RecieveInput(type, iSpace);
                    break;
                }
            }
        }
    }
}

void Arena::ProcedureOnQuitToMain()
{
    ifNextScreen = true;
    nextScreen = ScreenFactory::createScreen(0,0,0,0,0,0);
}

void Arena::ProcedureOnQuitToCharSelect()
{
    ifNextScreen = true;
    nextScreen = ScreenFactory::createScreen(screenCharacterSelect,0,0,0,0,playerTwo);
}


void Arena::SaveToFile(ofstream& f)
{
    cout << "save to file called" << endl;
    f << 1 << "|";
    f << Global::musicOnOff;
    f << "|";
    f << Global::volume;
    f << "|";
    f << this->bg << "|";
    f << char1num << "|";
    f << char2num << "|";
    char1->WriteToFile(f);
    f << "|";
    char2->WriteToFile(f);
    f << "|";
}

void Arena:: ProcedureOnQuitToPause()
{
    this->overlyingScreen = ScreenFactory::createScreen(screenPause, 0,this,char1num,char2num,playerTwo);
}


Arena::~Arena()
{
    delete char1;
    if(char2 != 0)
    {
        delete char2;
    }
}

void Arena::PlayMusic()
{
    Global::PlayMusic(Global::arenaMusic);
    Mix_VolumeMusic(Global::volume);
}
