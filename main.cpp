#include "Global.h"
#include <iostream>
#include <SDL.h>
#include <sdl_image.h>
#include <SDL_Mixer.h>

#include "PortraitButton.h"
#include "Point.h"
#include "floatAnchor.h"
#include "ScreenFactory.h"
#include "TextButton.h"

using namespace std;

// 1366 768
// 640 480

enum{screenPause, screenSettings, screenMainMenu, screenCharacterSelect,
    screenBackgroundSelect, screenArena};

const int Global::SCREEN_WIDTH = 640;
const int Global::SCREEN_HEIGHT = 480;
const int Global::SCREEN_FPS = 120; // do not go less than 12
const int Global::SCREEN_TICKS_PER_FRAME = 1000/Global::SCREEN_FPS;
const double Global::dF = Global::SCREEN_FPS / float(120) ;
int TextButton::buttonAnimationFrames = 12 * Global::dF;
int PortraitButton::buttonAnimationFrames = 12 * Global::dF;

int Global::volume = 100;
bool Global:: musicOnOff = true;

bool Init(SDL_Window*&, SDL_Renderer*&);
void LoadMedia(SDL_Renderer* gRenderer);

bool Init(SDL_Window*& screen, SDL_Renderer*& gRenderer)
{
	if( SDL_Init( SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0 )
	{
		cout << "SDL could not initialize! SDL Error: %s\n "
             << SDL_GetError() << endl;
        return 1;
	}

    if(IMG_Init(IMG_INIT_PNG) < 0)
    {
		cout << "SDL IMG could not initialize! SDL IMG Error: %s\n "
             << SDL_GetError() << endl;
        return 1;
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n "
             << Mix_GetError() << endl;
        return 1;
    }

    screen = SDL_CreateWindow("Lyari Wars", 200, 200, Global::SCREEN_WIDTH,
                              Global::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(screen == 0)
    {
        cout << "Screen could not be created " << endl;
        return 1;
    }

    gRenderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

    if(gRenderer == 0)
    {
        cout << "Render could not be created " << endl;
        return 1;
    }

    return 0;
}

void LoadMedia(SDL_Renderer* gRenderer)
{
    Global::InitMainMenuBackGround(gRenderer);
    Global::InitAllCharacters(gRenderer);
    Global::InitCharacterSelectBackGround(gRenderer);
    Global::InitCharPortraits(gRenderer);
    Global::InitCharIcons(gRenderer);

    Global::LoadGaneshGaitonde(gRenderer);
    Global::LoadTrivediBabu(gRenderer);
    Global::LoadPhoolanDevi(gRenderer);
    Global::LoadRobertRotor(gRenderer);

    Global::InitMainMenuMusic();
    Global::InitArenaMusic();
    Global::InitBackgroundSelect(gRenderer);
    Global::LoadBars(gRenderer);

    Global::LoadBackgrounds(gRenderer);
    Global::InitCredits(gRenderer);
    Global::InitControls(gRenderer);

    cout << "LoadMedia Completed" << endl;
}

int main(int argc, char* argv[])
{
    SDL_Window* screen;
    SDL_Renderer* gRenderer;

    if(Init(screen, gRenderer))
    {
        cout << "Init failed " << endl;
    }

    Uint32 timerStart;
    Uint32 timerEnd;

    SDL_ShowCursor(0);

    Global::LoadingScreen(gRenderer);

    LoadMedia(gRenderer);

	SDL_Event event;
	bool gameover = 0;

    Screen* currentScreen = 0;

    currentScreen = ScreenFactory::createScreen(screenMainMenu,0,0,0,0,0);

	while (!gameover)
	{
	    timerStart = SDL_GetTicks();

		/* look for an event */
		while (SDL_PollEvent(&event) != 0)
        {
			/* an event was found */
			if(event.type == SDL_QUIT)
            {
				/* close button clicked */
					gameover = 1;
            }
            else if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
            {
//                cout << "key down " << SDL_KEYUP <<  endl;
                currentScreen->RecieveInput(SDL_KEYDOWN, event.key.keysym.sym);
            }
            else if(event.type == SDL_KEYUP)
            {
//                cout << "key up" << endl;
                currentScreen->RecieveInput(SDL_KEYUP, event.key.keysym.sym);
            }
		}

        if(currentScreen->IfMoveToNextScreen() == true)
        {
            Screen* temp = currentScreen->GetNextScreen();
            delete currentScreen;
            currentScreen = temp;
        }
        if(currentScreen->quit)
        {
//            delete currentScreen;
//            cout << " help " << endl;
            gameover = 1;
            continue;
        }

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer);

		currentScreen->Render(gRenderer);

		/* update the screen */

		SDL_RenderPresent(gRenderer);
        if(Global::superCount > -1)
        {
            Global::superCount--;
        }
		timerEnd = SDL_GetTicks();
		if(timerEnd < (Global::SCREEN_TICKS_PER_FRAME * (1 + 4 * (Global::superCount > -1))) + timerStart)
            SDL_Delay((Global::SCREEN_TICKS_PER_FRAME * (1 + 4 * (Global::superCount > -1))) + timerStart - timerEnd);
	}
	/* clean up */
//    cout << "hello " << endl;

	Global::Quit();
//    cout << "hello 2" << endl;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(screen);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();

    return 0;
}
