#include "Controls.h"
#include "Global.h"
#include "Point.h"
#include "floatAnchor.h"

Controls::Controls()
{
    this->quit = false;
    this->backGround = Global::controlScreen;
    SDL_QueryTexture(this->backGround, NULL, NULL, &(this->backGroundRect).w, &(this->backGroundRect).h);
    int tempH = Global::CorrectHeight((this->backGroundRect.w), (this->backGroundRect.h), Global::SCREEN_WIDTH);
    this->backGroundRect.h = tempH;
    this->backGroundRect.w = Global::SCREEN_WIDTH;;
    floatAnchor tempAnchor(0.5, 0.5);
    Point temp = Global::CorrectedPos(tempAnchor.superImpose(this->backGroundRect.w, this->backGroundRect.h),
                                      Point(Global::SCREEN_WIDTH / 2, Global::SCREEN_HEIGHT / 2));
    this->backGroundRect.x = temp.x;
    this->backGroundRect.y = temp.y;

}

void Controls:: Render(SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
}

void Controls:: RecieveInput(Uint32 type,SDL_Keycode& key)
{
    if (type == SDL_KEYDOWN)
    {
        switch (key)
        {
            case SDLK_ESCAPE:
                ProcedureOnQuit();
                break;
        }
    }
}

Screen* Controls::GetNextScreen()
{

}

void Controls::PlayMusic()
{

}

void Controls:: ProcedureOnQuit()
{
    this->quit = true;
}


Controls::~Controls()
{
    //dtor
}

