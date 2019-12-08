#ifndef CONTROLS_H
#define CONTROLS_H
#include "Screen.h"

class Controls : public Screen
{
    public:
        Controls();
        ~Controls();
        void Render(SDL_Renderer*);
        void RecieveInput(Uint32, SDL_Keycode&);
        Screen* GetNextScreen();
        void PlayMusic();

    protected:

    private:
        void ProcedureOnQuit();
};

#endif // CONTROLS_H
