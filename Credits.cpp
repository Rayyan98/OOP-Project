#include "Credits.h"
#include "Global.h"
#include "Point.h"
#include "floatAnchor.h"
#include "SDL_mixer.h"

Credits::Credits()
{
    if (Global::musicOnOff == true)
    {
        PlayMusic();
    }
    this->quit = false;
    this->backGround = Global::creditsScreen;
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

void Credits:: Render(SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, this->backGround, 0, &this->backGroundRect);
}

void Credits:: RecieveInput(Uint32 type,SDL_Keycode& key)
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

Screen* Credits::GetNextScreen()
{

}

void Credits::PlayMusic()
{
    Global::PlayMusic(Global::creditsMusic);
    Mix_VolumeMusic(Global::volume);
}

void Credits:: ProcedureOnQuit()
{
    Mix_HaltMusic();
    this->quit = true;
}


Credits::~Credits()
{
    //dtor
}
