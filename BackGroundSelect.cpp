#include "BackGroundSelect.h"
#include "float.h"
#include "ScreenFactory.h"

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena, screenCredits, screenControls};

BackGroundSelect::BackGroundSelect(bool player2,int p1, int p2)
{
    this->p1_choice = p1;
    this->p2_choice = p2;

    this->backGround = Global::characterSelectTexture;

    SDL_QueryTexture(this->backGround, 0, 0, &((this->backGroundRect).w), &(this->backGroundRect).h);
    this->backGroundRect.w = Global::CorrectWidth(backGroundRect.w, backGroundRect.h, Global::SCREEN_HEIGHT);
    this->backGroundRect.h = Global::SCREEN_HEIGHT;
    Point tempPoint = Global::CorrectedPos(floatAnchor(1,1).superImpose(backGroundRect.w, backGroundRect.h),
                                           Point(Global::SCREEN_WIDTH, Global::SCREEN_HEIGHT));

    floatAnchor tempAnchor(0.5, 0.5);
    Point temp = Global::CorrectedPos(tempAnchor.superImpose(this->backGroundRect.w, this->backGroundRect.h),
                                      Point(Global::SCREEN_WIDTH / 2, Global::SCREEN_HEIGHT / 2));
    this->backGroundRect.x = temp.x;
    this->backGroundRect.y = temp.y;

    this->figurePivotLeft = Point( 90 * backGroundRect.w / 640 + backGroundRect.x,
                                  int((335 * this->backGroundRect.h) / 369) + temp.y);
    this->figurePivotRight = Point(Global::SCREEN_WIDTH - BackGroundSelect::figurePivotLeft.x,
                                   BackGroundSelect::figurePivotLeft.y);

    this->ifNextScreen = false;
    this->selectInd = -1;
    this->numOfBackgrounds = 5;
    this->stage_Portraits = new PortraitButton*[numOfBackgrounds];
    this->stage = new Figure*[numOfBackgrounds];
    this->player2 = player2;

    floatAnchor tempFloat(0.5,0.5);
    Point pos(backGroundRect.w / 8,backGroundRect.h/10);
    int mod = 1 * backGroundRect.h / 5;
    int mod2 = 60 * backGroundRect.h / 369;
    int mod3 = 84 * backGroundRect.h / 369;

    stage_Portraits[0] = new PortraitButton(Global::stages,Point(0,0),Point(768,368),pos,mod2,mod3,tempFloat);
    pos.y = pos.y+mod;

    stage_Portraits[1] = new PortraitButton(Global::stages,Point(0,437),Point(768,761),pos,mod2,mod3,tempFloat);
    pos.y = pos.y+mod;

    stage_Portraits[2] = new PortraitButton(Global::stages,Point(0,830),Point(768,1185),pos,mod2,mod3,tempFloat);
    pos.y = pos.y+mod;

    stage_Portraits[3] = new PortraitButton(Global::stages,Point(0,1254),Point(768,1576),pos,mod2,mod3,tempFloat);
    pos.y = pos.y+mod;

    stage_Portraits[4] = new PortraitButton(Global::stages,Point(0,1646),Point(768,2017),pos,mod2,mod3,tempFloat);
    pos.y = pos.y+mod;

    stage[0] = new Figure(Global::stages,Point(0,0),Point(768,368),Point(831,0),2,1,0,floatAnchor(0,0));

    stage[1] = new Figure(Global::stages,Point(0,438),Point(768,760),Point(831,0),2,1,0,floatAnchor(0,0));

    stage[2] = new Figure(Global::stages,Point(0,829),Point(768,1185),Point(831,0),2,1,0,floatAnchor(0,0));

    stage[3] = new Figure(Global::stages,Point(0,1253),Point(768,1577),Point(831,0),2,1,0,floatAnchor(0,0));

    stage[4] = new Figure(Global::stages,Point(0,1646),Point(768,2016),Point(831,0),2,1,0,floatAnchor(0,0));




}

BackGroundSelect::~BackGroundSelect()
{
    cout << "back ground select destructor called" << endl;
    delete [] stage_Portraits;
}

void BackGroundSelect::RecieveInput(Uint32 type, SDL_Keycode& key)
{
    if(type == SDL_KEYDOWN)
    {
        switch(key)
        {
            case SDLK_ESCAPE:
                ProcedureOnQuit();
                break;
            case SDLK_RETURN:
                ProcedureOnSelect();
                break;
            case SDLK_DOWN:
                if (selectInd == -1)
                {
                    selectInd = 0;
                }
                else if (selectInd == 4)
                {
                    selectInd = 0;
                }
                else
                {
                    selectInd++;
                }
                break;
            case SDLK_UP:
                if (selectInd == -1)
                {
                    selectInd = 4;
                }
                else if (selectInd == 0)
                {
                    selectInd = 4;
                }
                else
                {
                    selectInd--;
                }
                break;
        }
    }
}

void BackGroundSelect::Render(SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
    Point pos(backGroundRect.w / 4,backGroundRect.h/10);
    if (selectInd != -1)
    {
//        stage[selectInd]->Render(gRenderer, Point(0 + backGroundRect.x, this->backGroundRect.y),
//                                      this->backGroundRect.h, 0,true);
        this->backGround = Global::backgrounds[selectInd];
        SDL_QueryTexture(this->backGround, NULL, NULL, &(this->backGroundRect).w, &(this->backGroundRect).h);
        int tempH = Global::CorrectWidth((this->backGroundRect.w), (this->backGroundRect.h), Global::SCREEN_HEIGHT);
        this->backGroundRect.h = Global::SCREEN_HEIGHT;
        this->backGroundRect.w = tempH;
        floatAnchor tempAnchor(0.5, 0.5);
        Point temp = Global::CorrectedPos(tempAnchor.superImpose(this->backGroundRect.w, this->backGroundRect.h),
                                          Point(Global::SCREEN_WIDTH / 2, Global::SCREEN_HEIGHT / 2));
        this->backGroundRect.x = temp.x;
        this->backGroundRect.y = temp.y;

    }
    SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
    for(int i = 0; i < numOfBackgrounds; i++)
    {
        stage_Portraits[i]->Render(gRenderer, i == selectInd);
    }
}

Screen* BackGroundSelect::GetNextScreen()
{
    return this->nextScreen;
}

void BackGroundSelect::ProcedureOnSelect()
{
//    cout << "Procedure on select called from back ground select" << endl;
    if(selectInd > -1)
    {
        ifNextScreen = true;
        nextScreen = ScreenFactory::createScreen(screenArena, selectInd,0, p1_choice, p2_choice,player2);

    }
//    cout << " procedure completed" << endl;
}

void BackGroundSelect::ProcedureOnQuit()
{
    ifNextScreen = true;
    nextScreen = ScreenFactory::createScreen(screenCharacterSelect,0,0,0,0,player2);
}
