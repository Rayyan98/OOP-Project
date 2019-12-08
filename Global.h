#pragma once
#include "Point.h"
#include "ACharacter.h"
#include <SDL_Mixer.h>

class Global
{
public:
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;
    static const int SCREEN_FPS;
    static const int SCREEN_TICKS_PER_FRAME;
    static const double dF;
    static int superCount;

    static SDL_Texture* healthBarTexture;
    static SDL_Texture* manaBarTexture;

    static ACharacter** allCharacters;
    static SDL_Texture* mainMenuTexture;
    static SDL_Texture* characterSelectTexture;
    static SDL_Texture* charPortraits;
    static SDL_Texture* LoadingScreenTexture;
    static SDL_Texture* charIcons;

    static SDL_Texture** GaneshGaitondeAnimations;
    static SDL_Texture** TrivediBabuAnimations;
    static SDL_Texture** PhoolanDeviAnimations;
    static SDL_Texture** RobertRotorAnimations;

    static bool LoadGaneshGaitonde(SDL_Renderer*);
    static bool LoadTrivediBabu(SDL_Renderer*);
    static bool LoadPhoolanDevi(SDL_Renderer*);
    static bool LoadRobertRotor(SDL_Renderer*);


    static Point CorrectedPos(Point, Point);
    static int CorrectWidth(int, int, int);
    static int CorrectHeight(int, int, int);
    static int FindIndOfChar(ACharacter*);

    static void LoadingScreen(SDL_Renderer*);
    static bool LoadImage(SDL_Texture*&, char[], SDL_Renderer*);

    static bool LoadBars(SDL_Renderer*);
    static bool InitCharIcons(SDL_Renderer*);
    static bool InitAllCharacters(SDL_Renderer*);
    static bool InitMainMenuBackGround(SDL_Renderer*);
    static bool InitCharacterSelectBackGround(SDL_Renderer*);
    static bool InitCharPortraits(SDL_Renderer*);
    static bool InitBackgroundSelect(SDL_Renderer* gRenderer);
    static SDL_Texture* stages;

    static Mix_Music* creditsMusic;

    static SDL_Texture** backgrounds;
    static bool LoadBackgrounds(SDL_Renderer*);

    static SDL_Texture* creditsScreen;
    static SDL_Texture* controlScreen;
    static bool InitCredits(SDL_Renderer*);
    static bool InitControls(SDL_Renderer*);


    static Mix_Music* mainMenuMusic;
    static Mix_Music* arenaMusic;
    static Mix_Music* currentMusic;

    static bool LoadMusic(Mix_Music*&, char[]);
    static bool LoadSound(Mix_Chunk*&, char[]);
    static bool InitMainMenuMusic();
    static bool InitArenaMusic();

    static void PlayMusic(Mix_Music* newMusic = 0);
    static Uint32 QueueMusic(Uint32 interval, void*);

    static int volume;
    static bool musicOnOff;

    static void Quit();
};
