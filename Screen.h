#pragma once
#include <SDL.h>
#include <fstream>

using namespace std;

class Screen
{
protected:
    SDL_Texture* backGround;
    SDL_Rect backGroundRect;
    bool ifNextScreen;
    Screen* nextScreen;
    Screen* overlyingScreen;
    Screen();
public:
    bool quit;
    bool IfMoveToNextScreen();
    virtual void Render(SDL_Renderer*) = 0;
    virtual void RecieveInput(Uint32, SDL_Keycode&) = 0;
    virtual Screen* GetNextScreen() = 0;
    virtual ~Screen();
    virtual void PlayMusic();
    virtual void SaveToFile(ofstream&);
    virtual void ReadFromFile(ifstream&);
};
