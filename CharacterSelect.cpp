#include "CharacterSelect.h"
#include "floatAnchor.h"
#include "Global.h"
#include "PortraitButton.h"
#include "Figure.h"
#include "TextButton.h"
#include "ScreenFactory.h"

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

CharacterSelect::CharacterSelect(bool playerTwo)
{
    this->backGround = Global::characterSelectTexture;
    SDL_QueryTexture(this->backGround, NULL, NULL, &(this->backGroundRect).w, &(this->backGroundRect).h);
    int tempH = Global::CorrectHeight((this->backGroundRect.w), (this->backGroundRect.h), Global::SCREEN_WIDTH);
    if(tempH > Global::SCREEN_HEIGHT)
    {
        this->backGroundRect.w = Global::CorrectWidth(backGroundRect.w, backGroundRect.h, Global::SCREEN_HEIGHT);
        this->backGroundRect.h = Global::SCREEN_HEIGHT;
    }
    else
    {
        this->backGroundRect.h = tempH;
        this->backGroundRect.w = Global::SCREEN_WIDTH;;
    }
    floatAnchor tempAnchor(0.5, 0.5);
    Point temp = Global::CorrectedPos(tempAnchor.superImpose(this->backGroundRect.w, this->backGroundRect.h),
                                      Point(Global::SCREEN_WIDTH / 2, Global::SCREEN_HEIGHT / 2));
    this->backGroundRect.x = temp.x;
    this->backGroundRect.y = temp.y;

    this->figurePivotLeft = Point( 90 * backGroundRect.w / 640 + backGroundRect.x,
                                  int((335 * this->backGroundRect.h) / 369) + temp.y);
    this->figurePivotRight = Point(Global::SCREEN_WIDTH - CharacterSelect::figurePivotLeft.x,
                                   CharacterSelect::figurePivotLeft.y);

    this->selectInd = -1;
    this->numOfPortraits = 5;
    this->portraits = new PortraitButton*[numOfPortraits];
    this->smallFigures = new Figure*[numOfPortraits];
    this->bigFigures = new Figure*[numOfPortraits];
    this->names = new TextButton*[numOfPortraits];
    this->selectIndP2 = -1;

    if(playerTwo)
    {
        this->playerTwo = true;
        this->choosenP1 = this->choosenP2 = false;
    }
    else
    {
        this->playerTwo = false;
        this->choosenP1 = false;
        this->choosenP2 = true;
    }

    Point tempEnd(263, 1770);
    Point tempStart(tempEnd.x - 178, tempEnd.y - 331);
    for(int i = 1; i < numOfPortraits + 1; i++)
    {
        bigFigures[i%numOfPortraits] = new Figure(Global::charPortraits, tempStart, tempEnd,
                                                  Point(0,-360), 4, 1, 0, floatAnchor(0, 0));
        tempStart.x += 240;
        tempEnd.x += 240;
    }

    tempAnchor.y = 1.0;
    this->smallFigures = new Figure*[numOfPortraits];
    smallFigures[1] = new Figure(Global::charPortraits, Point(47, 194), Point(260, 318),
                                 Point(0,0), 1, 1, 0, tempAnchor);
    smallFigures[2] = new Figure(Global::charPortraits, Point(365, 151), Point(365+136,151+168),
                                 Point(0,0), 1, 1, 0, tempAnchor);
    smallFigures[3] = new Figure(Global::charPortraits, Point(611,156), Point(133+611,165+156),
                                 Point(0,0), 1, 1, 0, tempAnchor);
    smallFigures[4] = new Figure(Global::charPortraits, Point(895,141), Point(895+89,141+177),
                                 Point(0,0), 1, 1, 0, tempAnchor);
    smallFigures[0] = new Figure(Global::charPortraits, Point(1056, 157), Point(159+1056,164+157),
                                 Point(0,0), 1, 0, 0, tempAnchor);

    int heightOfNames = (20 * this->backGroundRect.h) / 369;
    Point tempPoint(figurePivotLeft.x, figurePivotLeft.y + (10 * heightOfNames) / 20);
    floatAnchor tempFloat(0.5, 0.5);
    names[0] = new TextButton("Ganesh Gaitonde", tempPoint, heightOfNames, 0, "gold", "null", tempFloat);
    names[1] = new TextButton("Robert Rotor", tempPoint, heightOfNames, 0, "gold", "null", tempFloat);
    names[2] = new TextButton("", tempPoint, heightOfNames, 0, "gold", "null", tempFloat);
    names[3] = new TextButton("Phoolan Devi", tempPoint, heightOfNames, 0, "gold", "null", tempFloat);
    names[4] = new TextButton("Trivedi Babu", tempPoint, heightOfNames, 0, "gold", "null", tempFloat);

    this->charIcons = new PortraitButton*[numOfPortraits];
    tempStart.x = 745;
    tempStart.y = 44;
    tempEnd.y = 238;
    tempEnd.x = 894;
    Point pos(200 * backGroundRect.w / 640, this->backGroundRect.h +
              this->backGroundRect.y - 45 * backGroundRect.w/ 640);
    int mod = 60 * backGroundRect.w / 640;
    int mod2 = 60 * backGroundRect.h / 369;
    int mod3 = 84 * backGroundRect.h / 369;
    for(int i = 0; i < numOfPortraits; i++)
    {
        charIcons[i] = new PortraitButton(Global::charIcons, tempStart, tempEnd, pos, mod2, mod3, tempFloat);
        tempStart.x += 233;
        tempEnd.x += 233;
        pos.x += mod;
    }
    NameBackGround = new Figure(Global::charIcons, Point(4, 107), Point(640, 214),
                                Point(0, 0), 1, 0, 0, floatAnchor(0,0));
    this->heading = new TextButton(string("Character Select"),
                                 Point(525 * Global::SCREEN_WIDTH / 640 ,65 * Global::SCREEN_HEIGHT / 480),
                                 40 * Global::SCREEN_HEIGHT / 480, 0, string("black"),
                                 string("null"), floatAnchor(1,0));
}

void CharacterSelect::Render(SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
    int NBG1 = 5 * backGroundRect.w / 640 + backGroundRect.x;
    int NBG2 = 6 * backGroundRect.h / 369;
    int NBG3 = 30 * backGroundRect.h / 369;

    if(selectInd > -1)
    {
        bigFigures[selectInd]->Render(gRenderer, Point(0 + backGroundRect.x, this->backGroundRect.y),
                                      this->backGroundRect.h, 0,choosenP1);
        if(!choosenP1)
        {
            int h1 = smallFigures[selectInd]->height * backGroundRect.h / 369;
            smallFigures[selectInd]->Render(gRenderer, this->figurePivotLeft, h1, 0, 0);
        }
        NameBackGround->Render(gRenderer, Point(NBG1, figurePivotLeft.y - NBG2),
                               NBG3, 0, 0);
        names[selectInd]->Render(gRenderer, 0);
    }
    if(selectIndP2 > -1)
    {
        int heightOfNames = (20 * this->backGroundRect.h) / 369;
        Point tempPoint(figurePivotRight.x, figurePivotRight.y + 10 * heightOfNames / 20);
        int tempa = backGroundRect.w - bigFigures[selectIndP2]->ProjectedWidth(this->backGroundRect.h);
        bigFigures[selectIndP2]->Render(gRenderer, Point(tempa + this->backGroundRect.x, this->backGroundRect.y),
                                        this->backGroundRect.h, 1,choosenP2);
        if(!choosenP2)
        {
            int h1 = smallFigures[selectIndP2]->height * backGroundRect.h / 369;
            smallFigures[selectIndP2]->Render(gRenderer, this->figurePivotRight, h1, 1, 0);
        }
        NameBackGround->Render(gRenderer, Point(Global::SCREEN_WIDTH - NBG1 - NameBackGround->ProjectedWidth(NBG3),
                                figurePivotLeft.y - NBG2), NBG3, 0, 0);
        names[selectIndP2]->Render(gRenderer, 0, tempPoint);
    }
    for(int i = 0; i < numOfPortraits; i++)
    {
//        cout << charIcons[i]->position.x << " " << charIcons[i]->position.y << endl;
        charIcons[i]->Render(gRenderer, i == selectInd || i == selectIndP2);
    }
    heading->Render(gRenderer, 0);

}

void CharacterSelect::RecieveInput(Uint32 type, SDL_Keycode& key)
{
    if(type == SDL_KEYDOWN)
    {
        switch (key)
        {
            case SDLK_ESCAPE:
                ProcedureOnQuit();
                break;
            case SDLK_a:
                if(!this->choosenP1)
                {
                    if(this->selectInd == -1)
                    {
                        this->selectInd = this->numOfPortraits - 1;
                    }
                    else if(this->selectInd > 0)
                    {
                        this->selectInd --;
                    }
                    else
                    {
                        this->selectInd = this->numOfPortraits - 1;
                    }
                    if(selectInd == selectIndP2 || selectInd == 2 || selectIndP2 == 2)
                    {
                        RecieveInput(type, key);
                    }
                }
                break;
            case SDLK_d:
                if(!this->choosenP1)
                {
                    if(this->selectInd == -1)
                    {
                        this->selectInd = 0;
                    }
                    else if(this->selectInd < numOfPortraits - 1)
                    {
                        this->selectInd ++;
                    }
                    else
                    {
                        this->selectInd = 0;
                    }
                    if(selectInd == selectIndP2 || selectInd == 2 || selectIndP2 == 2)
                    {
                        RecieveInput(type, key);
                    }
                }
                break;
            case SDLK_LEFT:
                if(!this->choosenP2)
                {
                    if(this->selectIndP2 == -1)
                    {
                        this->selectIndP2 = this->numOfPortraits - 1;
                    }
                    else if(this->selectIndP2 > 0)
                    {
                        this->selectIndP2 --;
                    }
                    else
                    {
                        this->selectIndP2 = this->numOfPortraits - 1;
                    }
                    if(selectInd == selectIndP2 || selectInd == 2 || selectIndP2 == 2)
                    {
                        RecieveInput(type, key);
                    }
                }
                break;
            case SDLK_RIGHT:
                if(!this->choosenP2)
                {
                    if(this->selectIndP2 == -1)
                    {
                        this->selectIndP2 = 0;
                    }
                    else if(this->selectIndP2 < numOfPortraits - 1)
                    {
                        this->selectIndP2 ++;
                    }
                    else
                    {
                        this->selectIndP2 = 0;
                    }
                    if(selectInd == selectIndP2 || selectInd == 2 || selectIndP2 == 2)
                    {
                        RecieveInput(type, key);
                    }
                }
                break;
            case SDLK_SPACE:
                if(!this->choosenP1 && selectInd > -1)
                {
                    this->choosenP1 = true;
                }
                if(this->choosenP1 && this->choosenP2)
                {
                    ProcedureOnSelect();
                }
                break;
            case SDLK_RETURN:
                if(!this->choosenP2 && this->selectIndP2 > -1)
                {
                    this->choosenP2 = true;
                }
                if(this->choosenP1 && this->choosenP2)
                {
                    ProcedureOnSelect();
                }
                break;
        }
    }
}

void CharacterSelect::ProcedureOnQuit()
{
    this->ifNextScreen = true;
    this->nextScreen = ScreenFactory::createScreen(screenMainMenu,0,0,0,0,0);
}

void CharacterSelect::ProcedureOnSelect()
{
    cout << " Procedure on Select from Character Select launched" << endl;
    ifNextScreen = true;
    nextScreen = ScreenFactory::createScreen(screenBackgroundSelect,0,0,selectInd,selectIndP2,playerTwo);
}

Screen* CharacterSelect::GetNextScreen()
{
    return this->nextScreen;
}

CharacterSelect::~CharacterSelect()
{
    cout << "Character Select Destroyed" << endl;
    delete [] portraits;
    delete [] smallFigures;
    delete [] bigFigures;
    delete [] names;
    delete [] charIcons;
}
