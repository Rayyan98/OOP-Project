#ifndef CREDITS_H
#define CREDITS_H
#include "Screen.h"

class Credits : public Screen
{
    public:
        Credits();
        ~Credits();
        void Render(SDL_Renderer*);
        void RecieveInput(Uint32, SDL_Keycode&);
        Screen* GetNextScreen();
        void PlayMusic();

    protected:

    private:
        void ProcedureOnQuit();
};

#endif // CREDITS_H
